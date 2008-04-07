# Copyright (C) 2007, One Laptop Per Child
#
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2 of the License, or (at your option) any later version.
#
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public
# License along with this library; if not, write to the
# Free Software Foundation, Inc., 59 Temple Place - Suite 330,
# Boston, MA 02111-1307, USA.

import gobject
import gtk

from sugar.graphics import style
from sugar.graphics.palette import Palette, ToolInvoker
from sugar.graphics.toolbutton import ToolButton
from sugar.graphics.icon import Icon

_PREVIOUS_PAGE = 0
_NEXT_PAGE = 1

class _TrayViewport(gtk.Viewport):
    __gproperties__ = {
        'scrollable'      : (bool, None, None, False,
                             gobject.PARAM_READABLE),
        'can-scroll-prev' : (bool, None, None, False,
                             gobject.PARAM_READABLE),
        'can-scroll-next' : (bool, None, None, False,
                             gobject.PARAM_READABLE),
    }

    def __init__(self, orientation):
        self.orientation = orientation
        self._scrollable = False
        self._can_scroll_next = False
        self._can_scroll_prev = False

        gobject.GObject.__init__(self)

        self.set_shadow_type(gtk.SHADOW_NONE)

        self.traybar = gtk.Toolbar()
        self.traybar.set_orientation(orientation)
        self.traybar.set_show_arrow(False)
        self.add(self.traybar)
        self.traybar.show()

        self.connect('size_allocate', self._size_allocate_cb)

        if self.orientation == gtk.ORIENTATION_HORIZONTAL:
            adj = self.get_hadjustment()
        else:
            adj = self.get_vadjustment()
        adj.connect('changed', self._adjustment_changed_cb)
        adj.connect('value-changed', self._adjustment_changed_cb)
            
    def scroll(self, direction):
        if direction == _PREVIOUS_PAGE:
            self._scroll_previous()
        elif direction == _NEXT_PAGE:
            self._scroll_next()

    def _scroll_next(self):
        if self.orientation == gtk.ORIENTATION_HORIZONTAL:
            adj = self.get_hadjustment()
            new_value = adj.value + self.allocation.width
            adj.value = min(new_value, adj.upper - self.allocation.width)
        else:
            adj = self.get_vadjustment()
            new_value = adj.value + self.allocation.height
            adj.value = min(new_value, adj.upper - self.allocation.height)

    def _scroll_previous(self):
        if self.orientation == gtk.ORIENTATION_HORIZONTAL:
            adj = self.get_hadjustment()
            new_value = adj.value - self.allocation.width
            adj.value = max(adj.lower, new_value)
        else:
            adj = self.get_vadjustment()
            new_value = adj.value - self.allocation.height
            adj.value = max(adj.lower, new_value)

    def do_size_request(self, requisition):
        child_requisition = self.child.size_request()
        if self.orientation == gtk.ORIENTATION_HORIZONTAL:
            requisition[0] = 0
            requisition[1] = child_requisition[1]
        else:
            requisition[0] = child_requisition[0]
            requisition[1] = 0

    def do_get_property(self, pspec):
        if pspec.name == 'scrollable':
            return self._scrollable
        elif pspec.name == 'can-scroll-next':
            return self._can_scroll_next
        elif pspec.name == 'can-scroll-prev':
            return self._can_scroll_prev

    def _size_allocate_cb(self, viewport, allocation):
        bar_requisition = self.traybar.get_child_requisition()
        if self.orientation == gtk.ORIENTATION_HORIZONTAL:
            scrollable = bar_requisition[0] > allocation.width
        else:
            scrollable = bar_requisition[1] > allocation.height

        if scrollable != self._scrollable:
            self._scrollable = scrollable
            self.notify('scrollable')

    def _adjustment_changed_cb(self, adjustment):
        if adjustment.value <= adjustment.lower:
            can_scroll_prev = False
        else:
            can_scroll_prev = True

        if adjustment.value + adjustment.page_size >= adjustment.upper:
            can_scroll_next = False
        else:
            can_scroll_next = True

        if can_scroll_prev != self._can_scroll_prev:
            self._can_scroll_prev = can_scroll_prev
            self.notify('can-scroll-prev')

        if can_scroll_next != self._can_scroll_next:
            self._can_scroll_next = can_scroll_next
            self.notify('can-scroll-next')


class _TrayScrollButton(ToolButton):
    def __init__(self, icon_name, scroll_direction):
        ToolButton.__init__(self)
        self._viewport = None

        self._scroll_direction = scroll_direction

        self.set_size_request(style.GRID_CELL_SIZE, style.GRID_CELL_SIZE)

        self.icon = Icon(icon_name = icon_name,
                         icon_size=gtk.ICON_SIZE_SMALL_TOOLBAR)
        # The alignment is a hack to work around gtk.ToolButton code
        # that sets the icon_size when the icon_widget is a gtk.Image
        alignment = gtk.Alignment(0.5, 0.5)
        alignment.add(self.icon)
        self.set_icon_widget(alignment)
        alignment.show_all()

        self.connect('clicked', self._clicked_cb)

    def set_viewport(self, viewport):
        self._viewport = viewport
        self._viewport.connect('notify::scrollable',
                               self._viewport_scrollable_changed_cb)

        if self._scroll_direction == _PREVIOUS_PAGE:
            self._viewport.connect('notify::can-scroll-prev',
                                   self._viewport_can_scroll_dir_changed_cb)
            self.set_sensitive(self._viewport.props.can_scroll_prev)
        else:
            self._viewport.connect('notify::can-scroll-next',
                                   self._viewport_can_scroll_dir_changed_cb)
            self.set_sensitive(self._viewport.props.can_scroll_next)


    def _viewport_scrollable_changed_cb(self, viewport, pspec):
        self.props.visible = self._viewport.props.scrollable

    def _viewport_can_scroll_dir_changed_cb(self, viewport, pspec):
        if self._scroll_direction == _PREVIOUS_PAGE:
            sensitive = self._viewport.props.can_scroll_prev
        else:
            sensitive = self._viewport.props.can_scroll_next

        self.set_sensitive(sensitive)

    def _clicked_cb(self, button):
        self._viewport.scroll(self._scroll_direction)

    viewport = property(fset=set_viewport)

class HTray(gtk.HBox):
    def __init__(self, **kwargs):
        gobject.GObject.__init__(self, **kwargs)
        self.set_direction(gtk.TEXT_DIR_LTR)

        scroll_left = _TrayScrollButton('go-left', _PREVIOUS_PAGE)
        self.pack_start(scroll_left, False)

        self._viewport = _TrayViewport(gtk.ORIENTATION_HORIZONTAL)
        self.pack_start(self._viewport)
        self._viewport.show()

        scroll_right = _TrayScrollButton('go-right', _NEXT_PAGE)
        self.pack_start(scroll_right, False)

        scroll_left.viewport = self._viewport
        scroll_right.viewport = self._viewport

    def get_children(self):
        return self._viewport.traybar.get_children()

    def add_item(self, item, index=-1):
        self._viewport.traybar.insert(item, index)

    def remove_item(self, item):
        self._viewport.traybar.remove(item)

    def get_item_index(self, item):
        return self._viewport.traybar.get_item_index(item)

class VTray(gtk.VBox):
    def __init__(self, **kwargs):
        gobject.GObject.__init__(self, **kwargs)

        # FIXME we need a go-up icon
        scroll_left = _TrayScrollButton('go-left', _PREVIOUS_PAGE)
        self.pack_start(scroll_left, False)

        self._viewport = _TrayViewport(gtk.ORIENTATION_VERTICAL)
        self.pack_start(self._viewport)
        self._viewport.show()

        # FIXME we need a go-down icon
        scroll_right = _TrayScrollButton('go-right', _NEXT_PAGE)
        self.pack_start(scroll_right, False)

        scroll_left.viewport = self._viewport
        scroll_right.viewport = self._viewport

    def get_children(self):
        return self._viewport.traybar.get_children()

    def add_item(self, item, index=-1):
        self._viewport.traybar.insert(item, index)

    def remove_item(self, item):
        self._viewport.traybar.remove(item)

    def get_item_index(self, item):
        return self._viewport.traybar.get_item_index(item)

class TrayButton(ToolButton):
    def __init__(self, **kwargs):
        ToolButton.__init__(self, **kwargs)

class _IconWidget(gtk.EventBox):
    __gtype_name__ = "SugarTrayIconWidget"

    def __init__(self, icon_name=None, xo_color=None):
        gtk.EventBox.__init__(self)

        self._palette = None

        self.set_app_paintable(True)

        self._icon = Icon(icon_name=icon_name, xo_color=xo_color,
                          icon_size=gtk.ICON_SIZE_LARGE_TOOLBAR)
        self.add(self._icon)
        self._icon.show()

    def do_expose_event(self, event):
        if self._palette and self._palette.is_up():
            invoker = self._palette.props.invoker
            invoker.draw_rectangle(event, self._palette)

        gtk.EventBox.do_expose_event(self, event)

    def set_palette(self, palette):
        if self._palette is not None:        
            self._palette.props.invoker = None
        self._palette = palette
        self._palette.props.invoker = ToolInvoker(self)

    def get_icon(self):
        return self._icon

class TrayIcon(gtk.ToolItem):
    __gtype_name__ = "SugarTrayIcon"

    def __init__(self, icon_name=None, xo_color=None):
        gtk.ToolItem.__init__(self)

        self._icon_widget = _IconWidget(icon_name, xo_color)
        self.add(self._icon_widget)
        self._icon_widget.show()

        self.set_size_request(style.GRID_CELL_SIZE, style.GRID_CELL_SIZE)

    def set_palette(self, palette):
        self._icon_widget.set_palette(palette)

    def set_tooltip(self, text):
        self.set_palette(Palette(text))

    def get_icon(self):
        return self._icon_widget.get_icon()
    icon = property(get_icon, None)

