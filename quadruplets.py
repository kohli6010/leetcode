

# Quadruple Sum to Target (medium) #
# Given an array of unsorted numbers and a target number, find all unique quadruplets in it, whose sum is equal to the target number.

# Example 1:

# Input: [4, 1, 2, -1, 1, -3], target=1
# Output: [-3, -1, 1, 4], [-3, 1, 1, 2]
# Explanation: Both the quadruplets add up to the target.
# Example 2:

# Input: [2, 0, -1, 1, -2, 2], target=2
# Output: [-2, 0, 2, 2], [-1, 0, 1, 2]
# Explanation: Both the quadruplets add up to the target.

from typing import List

class Solution:
	def fourSum(self, nums: List[int], target:int) -> List[List[int]]:
		nums.sort()
		results = []
		for i in range(0, len(nums) - 3):
			if i>0 and nums[i] == nums[i-1]:
				continue
			for j in range(i+1, len(nums) - 2):
				if j>i+1 and nums[j] == nums[j-1]:
					continue
				self.searchPair(nums, target, i, j, results)
		return results

	def searchPair(self, nums, target, first, second, results):
		left = second + 1
		right = len(nums) - 1
		while(left < right):
			currentSum = nums[first] + nums[second] + nums[left] + nums[right]
			if currentSum == target:
				results.append([nums[first], nums[second], nums[left], nums[right]])
				left+=1
				right-=1
				while left < right and nums[left] == nums[left-1]:
					left+=1
				while left<right and nums[right] == nums[right+1]:
					right-=1
			elif currentSum < target:
				left+=1
			else:
				right-=1

solution = Solution()
print(solution.fourSum([4, 1, 2, -1, 1, -3], 1))



		