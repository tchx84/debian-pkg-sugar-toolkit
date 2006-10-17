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

import gtk
import hippo

from sugar.graphics.bubble import Bubble
from sugar.graphics.iconcolor import IconColor
from sugar.graphics import style

class LinksView(hippo.Canvas):
	def __init__(self, model, browser):
		hippo.Canvas.__init__(self)

		self._bubbles = {}
		self._browser = browser

		self._box = hippo.CanvasBox()
		style.apply_stylesheet(self._box, 'links.Box')
		self.set_root(self._box)

		for link in model:
			self._add_link(link)

		model.connect('link_added', self._link_added_cb)
		model.connect('link_removed', self._link_removed_cb)

	def _add_link(self, link):
		if len(self._bubbles) == 0:
			self.show()

		color = IconColor(link.buddy.get_color())

		bubble = Bubble(color=color)
		style.apply_stylesheet(bubble, 'links.Bubble')
		self._box.append(bubble)

		text = hippo.CanvasLink(text=link.title)
		text.connect('activated', self._link_activated_cb, link)
		style.apply_stylesheet(text, 'links.Text')
		bubble.append(text, hippo.PACK_EXPAND)

		self._bubbles[link] = bubble

	def _remove_link(self, link):
		bubble = self._bubbles[link]
		self._box.remove(bubble)

		del self._bubbles[link]

		if len(self._bubbles) == 0:
			self.hide()

	def _link_added_cb(self, model, link):
		self._add_link(link)

	def _link_removed_cb(self, model, link):
		self._removed_link(link)

	def _link_activated_cb(self, link_item, link):
		self._browser.load_url(link.url)