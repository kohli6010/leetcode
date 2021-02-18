# Leetcode 567. Permutation in String(Medium)

# Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.

# Example 1:

# Input: s1 = "ab" s2 = "eidbaooo"
# Output: True
# Explanation: s2 contains one permutation of s1 ("ba").

# Example 2:

# Input:s1= "ab" s2 = "eidboaoo"
# Output: False

class Solution:
	def checkInclusion(self, s1, s2):
		matched, windowStart, characterFrequency = 0, 0, {}
		for windowEnd in range(len(s1)):
			leftChar = s1[windowEnd]
			if leftChar not in characterFrequency:
				characterFrequency[leftChar] = 1
			else:
				characterFrequency[leftChar] += 1
		
		for windowEnd in range(len(s2)):
			leftChar = s2[windowEnd]
			if leftChar in characterFrequency:
				characterFrequency[leftChar] -= 1
				if characterFrequency[leftChar] == 0:
					matched += 1
			if matched == len(characterFrequency):
					return True
			if windowEnd >= len(s1) - 1:
				leftChar = s2[windowStart]
				windowStart += 1
				if leftChar in characterFrequency:
					if characterFrequency[leftChar] == 0:
						matched -= 1
					characterFrequency[leftChar] += 1
		return False	
solution = Solution()
# print(solution.checkInclusion("ab", "eidbaooo"))
# print(solution.checkInclusion("ab", "eidboaoo"))	

print(solution.checkInclusion("adc", "dcda"))	




