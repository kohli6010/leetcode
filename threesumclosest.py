# leetcode - 16. 3Sum Closest(medium)

# Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

# Example 1:

# Input: nums = [-1,2,1,-4], target = 1
# Output: 2
# Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
import math

class Solution:
	def threeSumClosest(self, nums, target):
		smallestDiff = math.inf
		nums.sort()
		for i in range(len(nums)-2):
			left = i + 1
			right = len(nums)-1
			while(left < right):
				targetDiff = target - nums[i] - nums[left] - nums[right]
				if targetDiff == 0:
					return target - targetDiff
				if abs(targetDiff) < abs(smallestDiff) or abs(targetDiff) == abs(smallestDiff) and targetDiff > smallestDiff:
					smallestDiff = targetDiff
				elif targetDiff > 0:
					left +=1
				else:
					right -= 1
		return target - smallestDiff
solution = Solution()
print(solution.threeSumClosest([-1,2,1,-4], 1))
			

