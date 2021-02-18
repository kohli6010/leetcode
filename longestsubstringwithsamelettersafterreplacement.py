# Given a string with lowercase or uppercase letters only, if you are allowed to replace no more than ‘k’ letters with any letter, find the length of the longest substring having the same letters after replacement.

# Examples

# Input: String="aabccbb", k=2
# Output: 5
# Explanation: Replace the two 'c' with 'b' to have a longest repeating substring "bbbbb".

# Input: String="abbcb", k=1
# Output: 4
# Explanation: Replace the 'c' with 'b' to have a longest repeating substring "bbbb".

# Input: String="abccde", k=1
# Output: 3
# Explanation: Replace the 'b' or 'd' with 'c' to have the longest repeating substring "ccc".

# Input:
# s = "ABAB", k = 2

# Output:
# 4

# Explanation:
# Replace the two 'A's with two 'B's or vice versa.


class Solution:
	def characterReplacement(self, s, k):
		maxLen, windowStart, maxRepeatingLetterCount = 0, 0, 0
		characterFrequency = {}
		for windowEnd in range(len(s)):
			rightChar = s[windowEnd]
			if rightChar not in characterFrequency:
				characterFrequency[rightChar] = 0
			characterFrequency[rightChar] += 1
			maxRepeatingLetterCount = max(maxRepeatingLetterCount, characterFrequency[rightChar])
			if (windowEnd - windowStart + 1 - maxRepeatingLetterCount) > k:
				leftChar = s[windowStart]
				characterFrequency[leftChar] -= 1
				windowStart += 1
			maxLen = max(maxLen, windowEnd - windowStart + 1)
		return maxLen

solution = Solution()
print(solution.characterReplacement("abbcb", 1))
