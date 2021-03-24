# Leetcode - 259 three sum smaller(medium)

# Given an array arr of unsorted numbers and a target sum, count all triplets in it such that arr[i] + arr[j] + arr[k] < target where i, j, and k are three different indices. Write a function to return the count of such triplets.

# Example 1:

# Input: [-1, 0, 2, 3], target=3 
# Output: 2
# Explanation: There are two triplets whose sum is less than the target: [-1, 0, 3], [-1, 0, 2]
# Example 2:

# Input: [-1, 4, 2, 1, 3], target=5 
# Output: 4
# Explanation: There are four triplets whose sum is less than the target: 
#    [-1, 1, 4], [-1, 1, 3], [-1, 1, 2], [-1, 2, 3]

class Solution: 
	def tripletsWithSmallerSum(self, arr, target):
		count = 0
		arr.sort()
		for i in range(len(arr) - 2):
			count+=self.searchPair(arr, target-arr[i], i)
		
		return count
	
	def searchPair(self, arr, target, first):
		count = 0
		left, right = first + 1, len(arr) - 1
		while(left < right):
			currentSum = arr[left] + arr[right]
			if currentSum < target:
				count += right - left
				left+=1
			else:
				right-=1
		return count
solution = Solution()
print(solution.tripletsWithSmallerSum([-1, 4, 2, 1, 3], 5))

