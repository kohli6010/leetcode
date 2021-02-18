# Leetcode - 26. Remove Duplicates from Sorted Array(easy)

# Given a sorted array nums, remove the duplicates in-place such that each element appears only once and returns the new length.

# Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

# Example 1:

# Input: nums = [1,1,2]
# Output: 2, nums = [1,2]
# Explanation: Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the returned length.


from typing import List


class Solution:
   def removeDuplicates(self, nums: List[int]) -> int:
      nextNonDuplicate = 1
      i=1
      while i < len(nums):
         if nums[nextNonDuplicate - 1] != nums[i]:
               nums[nextNonDuplicate] = nums[i]
               nextNonDuplicate += 1
         i+=1
      return nextNonDuplicate
    
solution = Solution()
print(solution.removeDuplicates())         
        