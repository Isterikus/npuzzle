import numpy
import sys

class State(object):
	# SRAV NA NORMI
	def __init__(self, arg):
		self.field = arg['field']
		self.parent = arg['parent']

	def get_h(self):
		return self.h

	def get_g(self):
		return self.g

	def get_f(self):
		return self.g + self.h

	def set_h(self, h):
		self.h = h

	def set_g(self, g):
		self.g = g

	def get_parent(self):
		return self.parent

	def set_parent(self, parent):
		self.parent = parent
		self.g = parent.g + 1

	def equals(self, state):
		if state.field == self.field:
			return True
		else:
			return False

def error(err_key):
	print('ERROR MADAFAKA', err_key)
	exit()

n = 0
field_size = 0
field = []
file = "npuzzle-4-1.txt"

with open("data/" + file) as f:
	i = 0
	for line in f:
		if line[0] != '#' and not line[0].isdigit():
			print(line)
			error(1)
		elif line[0] == '#':
			pass
		elif n == 0:
			n = int(line)
			field_size = pow(n, 2)
			field = [0 for s in range(field_size)]
		else:
			line = [s for s in line.split(' ') if s != '']
			for j in range(n):
				field[i * n + j] = int(line[j])
			i += 1

print(n)
print(field)

def count_h(tmp_field):
	ret = 0
	for i in range(1, field_size):
		if tmp_field[i - 1] != i:
			ret += 1
	if tmp_field[field_size - 1] != 0:
		ret += 1
	return ret

now = 0

for i in range(field_size):
	if field[i] == 0:
		now = i

left_range = [i * n for i in range(n)]
right_range = [i * n - 1 for i in range(1, n + 1)]
top_range = [i for i in range(n)]
bottom_range = [i for i in range(field_size - n, field_size)]

def change_field(tmp_field, now, go_to):
	if go_to == 0:
		tmp_field[now], tmp_field[now - 1] = tmp_field[now - 1], tmp_field[now]
	elif go_to == 1:
		tmp_field[now], tmp_field[now - n] = tmp_field[now - n], tmp_field[now]
	elif go_to == 2:
		tmp_field[now], tmp_field[now + 1] = tmp_field[now + 1], tmp_field[now]
	elif go_to == 3:
		tmp_field[now], tmp_field[now + n] = tmp_field[now + n], tmp_field[now]
	return tmp_field

def get_state_with_min_f(elems):
	mn = sys.maxint
	ret = {}
	for elem in elems
		f = elem.g + elem.h
		if f < mn:
			mn = f
			ret = elem
	return ret

states = []

def get_neighbors(state):
	now = 0
	ret = []
	for i in range(field_size):
		if state.field[i] == 0:
			now = i
	if now not in left_range:
		tmp_field = state.field
		tmp_field[now - 1], tmp_field[now] = tmp_field[now], tmp_field[now - 1]
		ret.append(tmp_field)
	if now not in right_range:
		tmp_field = state.field
		tmp_field[now + 1], tmp_field[now] = tmp_field[now], tmp_field[now + 1]
		ret.append(tmp_field)
	if now not in top_range:
		tmp_field = state.field
		tmp_field[now - n], tmp_field[now] = tmp_field[now], tmp_field[now - n]
		ret.append(tmp_field)
	if now not in bottom_range:
		tmp_field = state.field
		tmp_field[now + n], tmp_field[now] = tmp_field[now], tmp_field[now + n]
		ret.append(tmp_field)
	return ret

def check_in(arr, state):
	for elem in arr:
		if elem.equals(state):
			return True
	return False

# def get_from(arr, state):
# 	for elem in arr:
# 		if elem.equals(state):
# 			return True
# 	return False

def search():
	op = []
	cl = []
	start_state = State({'field': field, 'parent': None})
	start_state.set_g(0)
	start_state.set_h(count_h(start_state.field))
	op.append(start_state)

	while len(op) > 0:
		x = get_state_with_min_f(op)
		if count_h(x.field) == 0:
			return x
		op.remove(x)
		cl.append(x)
		neighbors = get_neighbors(x)
		for neighbor in neighbors:
			if check_in(cl, neighbor):
				continue
			g = x.get_g() + 1
			if not check_in(op, neighbor):
				neighbor.set_h(count_h(neighbor.field))
				op.append(neighbor)
				g_cool = True
			else:
				g_cool = g < neighbor.get_g()

# while count_h(tmp_field) != 0:
# 	for _ in range(4):
# 		pass



























