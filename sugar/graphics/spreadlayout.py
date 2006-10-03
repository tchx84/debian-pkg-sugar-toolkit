import random
import math

import cairo

class SpreadLayout:
	DISTANCE_THRESHOLD = 120.0

	def __init__(self):
		pass

	def _get_distance(self, icon1, icon2):
		[icon1_x, icon1_y] = self._constraints[icon1]
		[icon2_x, icon2_y] = self._constraints[icon2]

		a = icon1_x - icon2_x
		b = icon1_y - icon2_y

		return math.sqrt(a * a  + b * b)

	def _get_repulsion(self, icon1, icon2):
		[icon1_x, icon1_y] = self._constraints[icon1]
		[icon2_x, icon2_y] = self._constraints[icon2]

		f_x = icon1_x - icon2_x
		f_y = icon1_y - icon2_y

		return [f_x, f_y]

	def _spread_icons(self):
		self._stable = True

		for icon1 in self._icons:
			vx = 0
			vy = 0

			[x, y] = self._constraints[icon1]

			for icon2 in self._icons:
				if icon1 != icon2:
					distance = self._get_distance(icon1, icon2)
					if distance <= IconLayout.DISTANCE_THRESHOLD:
						self._stable = False
						[f_x, f_y] = self._get_repulsion(icon1, icon2)
						vx += f_x
						vy += f_y

			new_x = x + vx
			new_y = y + vy

			new_x = max(self._x1, new_x)
			new_y = max(self._y1, new_y)

			[width, height] = icon1.get_size_request()
			new_x = min(self._x2 - width, new_x)
			new_y = min(self._y2 - height, new_y)

			self._constraints[icon1] = [new_x, new_y]

			matrix = cairo.Matrix(1, 0, 0, 1, 0, 0)
			matrix.translate(new_x - (width / 2), new_y - (height / 2))
			icon1.set_transform(matrix)

	def update(self):
		tries = 10
		self._spread_icons()
		while not self._stable and tries > 0:
			self._spread_icons()
			tries -= 1

	def layout(self, box):
		[width, height] = box.get_allocation()
		for item in box.get_children():
			x = int(random.random() * width)
			y = int(random.random() * height)
			box.move(item, x, y)