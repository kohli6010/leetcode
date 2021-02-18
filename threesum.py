# Leetcode - 15. 3Sum(medium)

# Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

# Notice that the solution set must not contain duplicate triplets.

 

# Example 1:

# Input: nums = [-1,0,1,2,-1,-4]
# Output: [[-1,-1,2],[-1,0,1]]
# Example 2:

# Input: nums = []
# Output: []
# Example 3:

# Input: nums = [0]
# Output: []

from typing import List


class Solution:
	def threeSum(self, nums: List[int]) -> List[List[int]]:
		sums = []
		nums.sort()
		for i in range(len(nums)):
			if i > 0 and nums[i] == nums[i-1]:
				continue
			self.searchPair(nums, -nums[i], i+1, sums)
		return sums

	def searchPair(self, nums, target, left, sums):
		right = len(nums)- 1
		while(left < right):
			currentSum = nums[left] + nums[right]
			if currentSum == target:
				sums.append([-target, nums[left], nums[right]])
				left+=1
				right-=1
				while left < right and nums[left] == nums[left - 1]:
					left += 1
				while left < right and nums[right] == nums[right + 1]:
					right -=1
			elif target > currentSum:
				left+=1
			else:
				right-=1
solution = Solution()
print(solution.threeSum([-3, 0, 1, 2, -1, 1, -2]))




