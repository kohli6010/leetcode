# Given an array of characters where each character represents a fruit tree, you are given two baskets and your goal is to put maximum number of fruits in each basket. The only restriction is that each basket can have only one type of fruit.

# You can start with any tree, but once you have started you can’t skip a tree. You will pick one fruit from each tree until you cannot, i.e., you will stop when you have to pick from a third fruit type.

# Write a function to return the maximum number of fruits in both the baskets.

# Examples

# Input: Fruit=['A', 'B', 'C', 'A', 'C']
# Output: 3
# Explanation: We can put 2 'C' in one basket and one 'A' in the other from the subarray ['C', 'A', 'C']

# Input: Fruit=['A', 'B', 'C', 'B', 'B', 'C']
# Output: 5
# Explanation: We can put 3 'B' in one basket and two 'C' in the other basket. 
# This can be done if we start with the second letter: ['B', 'C', 'B', 'B', 'C']

def fruitsInBasket(fruits):
	maxLen = 0
	windowStart = 0
	fruitsInEachBasket = {}
	for windowEnd in range(len(fruits)):
		leftFruit = fruits[windowEnd]
		if leftFruit not in fruitsInEachBasket:
			fruitsInEachBasket[leftFruit] = 0
		fruitsInEachBasket[leftFruit] += 1
		while len(fruitsInEachBasket) > 2:
			rightFruit = fruits[windowStart]
			fruitsInEachBasket[rightFruit] -= 1
			if fruitsInEachBasket[rightFruit] == 0:
				del fruitsInEachBasket[rightFruit]
			windowStart += 1
		maxLen = max(maxLen, windowEnd - windowStart + 1)
	return maxLen

print(fruitsInBasket([1,2,1]))