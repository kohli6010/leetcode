# Given an array with positive numbers and a target number, find all of its contiguous subarrays whose product is less than the target number.

# Example 1:

# Input: [2, 5, 3, 10], target=30 
# Output: [2], [5], [2, 5], [3], [5, 3], [10]
# Explanation: There are six contiguous subarrays whose product is less than the target.
# Example 2:

# Input: [8, 2, 6, 5], target=50 
# Output: [8], [2], [8, 2], [6], [2, 6], [5], [6, 5] 
# Explanation: There are seven contiguous subarrays whose product is less than the target.

from collections import deque

def findSubarray(arr, target):
	result = []
	product = 1
	left = 0
	for right in range(len(arr)):
		product *= arr[right]
		while product >= target and left < len(arr):
			product/= arr[left]
			left+=1
		tempList= deque()
		for i in range(right, left - 1, - 1):
			tempList.appendleft(arr[i])
			result.append(list(tempList))
	return result

print(findSubarray([2, 5, 3, 10], 30))