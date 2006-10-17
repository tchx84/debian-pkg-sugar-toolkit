# Copyright (C) 2006, Red Hat, Inc.
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

import hippo
import gobject

from view.BuddyIcon import BuddyIcon
from sugar.graphics.canvasicon import CanvasIcon
from sugar.graphics import style
from sugar.presence import PresenceService
import conf


class FriendView(hippo.CanvasBox):
	def __init__(self, shell, menu_shell, buddy, **kwargs):
		hippo.CanvasBox.__init__(self, **kwargs)

		self._pservice = PresenceService.get_instance()
		self._activity_registry = conf.get_activity_registry()

		self._buddy = buddy
		self._buddy_icon = BuddyIcon(shell, menu_shell, buddy)
		style.apply_stylesheet(self._buddy_icon, 'friends.FriendIcon')
		self.append(self._buddy_icon)

		self._activity_icon = CanvasIcon()
		style.apply_stylesheet(self._activity_icon, 'friends.ActivityIcon')
		self._activity_icon_visible = False

		if self._buddy.is_present():
			self._buddy_appeared_cb(buddy)

		self._buddy.connect('current-activity-changed', self._buddy_activity_changed_cb)
		self._buddy.connect('appeared', self._buddy_appeared_cb)
		self._buddy.connect('disappeared', self._buddy_disappeared_cb)
		self._buddy.connect('color-changed', self._buddy_color_changed_cb)

	def _get_new_icon_name(self, activity):
		# FIXME: do something better here; we probably need to use "flagship"
		# services like mDNS where activities default services are marked
		# somehow.
		for serv in activity.get_services():
			act = self._activity_registry.get_activity_from_type(serv.get_type())
			if act:
				return act.get_icon()
		return None

	def _remove_activity_icon(self):
		if self._activity_icon_visible:
			self.remove(self._activity_icon)
			self._activity_icon_visible = False

	def _buddy_activity_changed_cb(self, buddy, activity=None):
		if not activity:
			self._remove_activity_icon()
			return

		# FIXME: use some sort of "unknown activity" icon rather
		# than hiding the icon?
		name = self._get_new_icon_name(activity)
		if name:
			self._activity_icon.props.icon_name = name
			self._activity_icon.props.color = buddy.get_color()
			if not self._activity_icon_visible:
				self.append(self._activity_icon)
				self._activity_icon_visible = True
		else:
			self._remove_activity_icon()

	def _buddy_appeared_cb(self, buddy):
		activity = self._buddy.get_current_activity()
		self._buddy_activity_changed_cb(buddy, activity)

	def _buddy_disappeared_cb(self, buddy):
		self._buddy_activity_changed_cb(buddy, None)

	def _buddy_color_changed_cb(self, buddy, color):
		self._activity_icon.props.color = buddy.get_color()