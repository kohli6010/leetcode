# Leetcode - 76. Minimum Window Substring(Hard)

# Given two strings s and t, return the minimum window in s which will contain all the characters in t. If there is no such window in s that covers all characters in t, return the empty string "".

# Note that If there is such a window, it is guaranteed that there will always be only one unique minimum window in s.

# Example 1:

# Input: s = "ADOBECODEBANC", t = "ABC"
# Output: "BANC"

# Example 2:

# Input: s = "a", t = "a"
# Output: "a"

class Solution:
	def minWindow(self, s, t):
		windowStart, matched, subStrStart, characterFrequency = 0, 0, 0, {}
		minLen = len(s) + 1
		for char in t:
			if char not in characterFrequency:
				characterFrequency[char] = 0
			characterFrequency[char] += 1
		for windowEnd in range(len(s)):
			rightChar = s[windowEnd]
			if rightChar in characterFrequency:
				characterFrequency[rightChar] -= 1
				if characterFrequency[rightChar] >= 0:
					matched += 1

			while matched == len(t):
				if minLen > windowEnd - windowStart + 1:
					minLen = windowEnd - windowStart + 1
					subStrStart = windowStart

				leftChar = s[windowStart]
				windowStart += 1
				if leftChar in characterFrequency:
					if characterFrequency[leftChar] == 0:
						matched -= 1
					characterFrequency[leftChar] += 1
		if minLen > len(s):
			return ""
		else:
			return s[subStrStart: subStrStart + minLen]
			
solution = Solution()
print(solution.minWindow("aabdec", "abc"))