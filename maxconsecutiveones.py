# leetcode: 1004. Max Consecutive Ones III

# Given an array A of 0s and 1s, we may change up to K values from 0 to 1.
# Return the length of the longest (contiguous) subarray that contains only 1s. 

#  Examples

# Input: A = [1,1,1,0,0,0,1,1,1,1,0], K = 2
# Output: 6
# Explanation: 
# [1,1,1,0,0,1,1,1,1,1,1]
# Bolded numbers were flipped from 0 to 1.  The longest subarray is underlined.

# Input: A = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], K = 3
# Output: 10
# Explanation: 
# [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
# Bolded numbers were flipped from 0 to 1.  The longest subarray is underlined.

class Solution:
	def longestOnes(self, A, K):
		maxLen, windowStart, numberOfOnes = 0, 0, 0
		for windowEnd in range(len(A)):
			leftBit = A[windowEnd]
			if leftBit == 1:
				numberOfOnes += 1
			while ((windowEnd - windowStart + 1) - numberOfOnes) > K:
				rightDigit = A[windowStart]
				if rightDigit == 1:
					numberOfOnes -= 1
				windowStart += 1
			maxLen = max(maxLen, windowEnd - windowStart + 1)
		return maxLen


solution = Solution()
print(solution.longestOnes([0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], 3))