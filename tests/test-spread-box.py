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

#!/usr/bin/python
import pygtk
pygtk.require('2.0')
import gobject

from sugar.session.UITestSession import UITestSession

session = UITestSession()
session.start()

import sys
import random

import gtk
import hippo

from sugar.graphics.spreadbox import SpreadBox
from sugar.graphics.iconcolor import IconColor
from sugar.graphics.canvasicon import CanvasIcon

def _create_icon():
	color = IconColor()

	icon = CanvasIcon(size=100, color=color,
					  icon_name='stock-buddy')
	box.add(icon)

	return (len(box.get_children()) < 15)

window = gtk.Window()
window.connect("destroy", lambda w: gtk.main_quit())
window.show()

canvas = hippo.Canvas()

box = SpreadBox(background_color=0xe2e2e2ff)
canvas.set_root(box)

window.add(canvas)
canvas.show()

gobject.timeout_add(500, _create_icon)

gtk.main()