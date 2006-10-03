import gtk
import goocanvas
import hippo
import cairo

from sugar.canvas.CanvasView import CanvasView
from sugar.canvas.MenuShell import MenuShell
from view.home.MeshBox import MeshBox
from view.home.HomeGroup import HomeGroup
from view.home.FriendsBox import FriendsBox
import sugar

class HomeWindow(gtk.Window):
	def __init__(self, shell):
		gtk.Window.__init__(self)
		self._shell = shell

		self.realize()
		self.window.set_type_hint(gtk.gdk.WINDOW_TYPE_HINT_DESKTOP)

		self._nb = gtk.Notebook()
		self._nb.set_show_border(False)
		self._nb.set_show_tabs(False)

		self.add(self._nb)
		self._nb.show()

		menu_shell = MenuShell(shell.get_grid())

		self._add_page(HomeGroup(shell))

		canvas = hippo.Canvas()
		box = FriendsBox(shell, menu_shell)
		canvas.set_root(box)
		self._nb.append_page(canvas)
		canvas.show()

		canvas = hippo.Canvas()
		box = MeshBox(shell, menu_shell)
		canvas.set_root(box)
		self._nb.append_page(canvas)
		canvas.show()

	def _add_page(self, group):
		view = CanvasView()
		self._nb.append_page(view)
		view.show()

		model = goocanvas.CanvasModelSimple()
		root = model.get_root_item()
		view.set_model(model)

		bg = goocanvas.Rect(width=1900, height=1200,
							line_width=0, fill_color='#e2e2e2')
		root.add_child(bg)
		root.add_child(group)

	def set_zoom_level(self, level):
		if level == sugar.ZOOM_HOME:
			self._nb.set_current_page(0)
		elif level == sugar.ZOOM_FRIENDS:
			self._nb.set_current_page(1)
		elif level == sugar.ZOOM_MESH:
			self._nb.set_current_page(2)