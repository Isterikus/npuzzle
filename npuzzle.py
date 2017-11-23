# import numpy
import sys
import copy
import time
import math
from subprocess import call

# DEFINE GLOBAL VARS | READING FIELD

n = 0
field_size = 0
field = []
file = "npuzzle-4-3.txt"

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
			initial_field = [0 for s in range(field_size)]
		else:
			line = [s for s in line.split(' ') if s != '']
			for j in range(n):
				initial_field[i * n + j] = int(line[j])
			i += 1

goal = [i for i in range(1, field_size)]
goal.append(0)
left_range = [i * n for i in range(n)]
right_range = [i * n - 1 for i in range(1, n + 1)]
top_range = [i for i in range(n)]
bottom_range = [i for i in range(field_size - n, field_size)]

# DEFINE STATE CLASS
class State(object):
	# SRAV NA NORMI
	def __init__(self, field):
		self.field = field
		self.setH()

	def getH(self):
		return self.h

	def getG(self):
		try:
			return self.g
		except:
			self.g = self.parent.getG() + 1
			return self.g

	def getF(self):
		return self.g + self.h

	def setH(self):
		# if not self.checkPattern():
			# self.h = self.getPatternDatabase()
		# else:
		self.h = self.getManhattan() + self.getLinearConflict()# + self.getOutOf()

	def setG(self, g):
		self.g = g

	def getParent(self):
		return self.parent

	def setParent(self, parent):
		self.parent = parent

	def checkPattern(self):
		for i in range(n):
			if self.field[i] != i + 1:
				return False
			if self.field[i * n] != i * n + 1:
				return False
		return True

	def getPatternDatabase(self):
		ret = 0
		for i in range(n):
			for j in range(n):
				if (self.field[i * n + j] in [i+1 for i in top_range]) or (self.field[i * n + j] in [i+1 for i in left_range]):
					pl_i = (self.field[i * n + j]) // n
					pl_j = (self.field[i * n + j]) % n - 1
					if pl_i == 1 and (self.field[i * n + j]) % n == 0:
						pl_i = 0
					if pl_j == -1:
						pl_j = n-1
					# print('---------------------------------- ', self.field[i * n + j])
					# print('i = ', i, ' j = ', j)
					# print('plI = ', pl_i, ' plJ = ', pl_j)
					# print('pl = ', abs(i - pl_i) + abs(j - pl_j))
					ret += abs(i - pl_i) + abs(j - pl_j)
		# for i in range(n):
		# 	for j in range(i, n):
		# 			pass
		# 		if self.field[i] > self.field[j]:
		# 			ret += 2
		# 		if self.field[i * n] > self.field[j * n]:
		# 			ret += 2
		# print(self.field)
		# print(ret)
		# exit()
		return ret

	def getManhattan(self):
		ret = 0
		for i in range(n):
			for j in range(n):
				pos = i * n + j
				if (self.field[pos] == 0):
					pl_i = n - 1
					pl_j = n - 1
				elif self.field[pos] % n == 0:
					pl_i = self.field[pos] // n - 1
					pl_j = n - 1
				else:
					pl_i = self.field[pos] // n
					pl_j = self.field[pos] % n - 1
				# print('I = ', i, ' | J = ', j, ' | PL_I = ', pl_i, ' | PL_J = ', pl_j, ' | FIE = ', self.field[i * n + j], ' | REZ = ', abs(i - pl_i) + abs(j - pl_j))
				ret += abs(i - pl_i) + abs(j - pl_j)
		return ret

	# need to check
	def getEuclidean(self):
		ret = 0
		for i in range(n):
			for j in range(n):
				pl_i = self.field[i * n + j] // n
				pl_j = self.field[i * n + j] % n - 1
				ret += math.sqrt(math.pow(i - pl_i, 2) + math.pow(j - pl_j, 2))
		return ret

	def getLinearConflict(self):
		ret = 0
		for i in range(n):
			for j in range(n):
				if self.field[i * n + j] != 0 and self.field[i * n + j] % n == j + 1:
					for l in range(i, n):
						if self.field[l * n + j] != 0 and self.field[l * n + j] % n == j + 1:
							if self.field[i * n + j] > self.field[l * n + j]:
								ret += 2
				if self.field[i * n + j] != 0 and (self.field[i * n + j] - 1) // n == i:
					for k in range(j, n):
						if self.field[i * n + k] != 0 and (self.field[i * n + k] - 1) // n == i:
							if self.field[i * n + j] > self.field[i * n + k]:
								ret += 2
		return ret

	def	getOutOf(self):
		ret = 0
		for i in range(n):
			for j in range(n):
				pl_i = self.field[i * n + j] // n
				pl_j = self.field[i * n + j] % n - 1
				if (pl_i != i):
					ret += 1
				if (pl_j != j):
					ret += 1
		return ret

	def findNeighbors(self):
		now = 0
		ret = []
		for i in range(field_size):
			if self.field[i] == 0:
				now = i
		if now not in left_range:
			tmp_field = copy.copy(self.field)
			tmp_field[now - 1], tmp_field[now] = tmp_field[now], tmp_field[now - 1]
			tmp_state = State(tmp_field)
			# print(tmp_field)
			ret.append(tmp_state)
		if now not in right_range:
			tmp_field = copy.copy(self.field)
			tmp_field[now + 1], tmp_field[now] = tmp_field[now], tmp_field[now + 1]
			tmp_state = State(tmp_field)
			ret.append(tmp_state)
		if now not in top_range:
			tmp_field = copy.copy(self.field)
			tmp_field[now - n], tmp_field[now] = tmp_field[now], tmp_field[now - n]
			tmp_state = State(tmp_field)
			# print_field(tmp_field, 0)
			ret.append(tmp_state)
		if now not in bottom_range:
			tmp_field = copy.copy(self.field)
			tmp_field[now + n], tmp_field[now] = tmp_field[now], tmp_field[now + n]
			tmp_state = State(tmp_field)
			ret.append(tmp_state)
		return ret

def print_field(fie, flag=1):
	if flag:
		print('---------------------------------------------------')
	for i in range(n):
		for j in range(n):
			sys.stdout.write(str(fie[i * n + j]) + ' ')
		sys.stdout.write('\n')

initialState = State(initial_field)
initialState.setG(0)
initialState.setParent(None)
print_field(initialState.field)
print("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++")
to_c = ""
for el in initialState.field:
	to_c += "," + str(el)
to_c = to_c[1:]
print(to_c)
# print('L = ', initialState.getLinearConflict())
# exit()
visitedStates = [initialState]
best_solution = None
newLimit = 1000000


def checkInVisited(current):
	for state in visitedStates:
		if state.field == current.field:
			return True
	return False

def solveIDAStar():
	global newLimit
	global visitedStates
	limit = initialState.getH()
	result = None
	while result == None:
		visitedStates.append(initialState)
		newLimit = 1000000 # Fix this
		result = limitedSearch(initialState, limit)
		limit = newLimit
		print('nL = ', newLimit)
		# if newLimit != 12:
			# exit()
		visitedStates = []
	return result

def wtf(field):
	j = 1
	for j in range(1, field_size):
		if field[j - 1] != j:
			return False
	if field[-1] != 0:
		return False
	return True

def limitedSearch(current, limit):
	global newLimit
	global best_solution
	global visitedStates
	for s in current.findNeighbors():
		# print_field(s.field)
		if wtf(s.field):
			s.setParent(current)
			return s
		if not checkInVisited(s):
			s.setG(current.getG() + 1)
			s.setParent(current)
			currentCost = s.getH() + s.getG()
			if currentCost <= limit:
				visitedStates.append(s)
				solution = limitedSearch(s, limit)
				if (solution != None) and (best_solution == None or solution.getG() < best_solution.getG()):
					best_solution = solution
			else:
				if currentCost < newLimit:
					newLimit = currentCost
	return None


def print_way(node):
	count = 0
	while node != None:
		print_field(node.field)
		node = node.getParent()
		count += 1
	print(count - 1)

def search(node, g, bound):
	f = g + node.getH()
	if f > bound:
		return f
	if node.field == goal:
		# print_way(node)
		return 'FOUND'
	mn = 1000000
	for succ in node.findNeighbors():
		if node.getParent() and succ.field == node.getParent().field:
			continue
		succ.setParent(node)
		if g + 1 + succ.getH() <= bound:
			t = search(succ, g + 1, bound)
			if t == 'FOUND':
				return t
			if t < mn:
				mn = t
	return mn

def ida_star():
	bound = initialState.getH()
	# print_field(initialState.field)
	start_time = time.time()
	while True:
		# print('BOUND = ', bound)
		t = search(initialState, 0, bound)
		# print("--- %s seconds ---" % (time.time() - start_time))
		if t == 'FOUND':
			print('PYTHON TIME: %s' % (time.time() - start_time))
			break
			# if t == 1000000:
			# print(t)
			# exit()
		bound += 2
	call(["./a.out", str(n), to_c])
# solveIDAStar()
ida_star()
