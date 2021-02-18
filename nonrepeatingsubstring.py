# Given a string, find the length of the longest substring which has no repeating characters.

# Example

# Input: String="aabccbb"
# Output: 3
# Explanation: The longest substring without any repeating characters is "abc".

# Input: String="abbbb"
# Output: 2
# Explanation: The longest substring without any repeating characters is "ab".

# Input: String="abccde"
# Output: 3
# Explanation: Longest substrings without any repeating characters are "abc" & "cde".

# my approach

# class Solution:
#        def lengthOfLongestSubstring(self, string):
#             maxLen = 0
#             windowStart = 0
#             characterIndexes = {}
#             for windowEnd in range(len(string)):
#                 leftChar = string[windowEnd]
#                 if leftChar not in characterIndexes:
#                     characterIndexes[leftChar] = windowEnd
#                     maxLen = max(maxLen, windowEnd - windowStart + 1)
#                 else:
#                     if characterIndexes[leftChar] < windowStart:
#                         characterIndexes[leftChar] = windowEnd
#                     else:
#                         windowStart = characterIndexes[leftChar] + 1
#             return maxLen
# solution = Solution()
# print(solution.lengthOfLongestSubstring(""))
        
# solution

class Solution:
    def lengthOfLongestSubstring(self, string):
        maxLen = 0
        windowStart = 0
        charIndexMap = {}
        for windowEnd in range(len(string)):
            rightChar = string[windowEnd]
            if rightChar in charIndexMap:
                windowStart = max(windowStart, charIndexMap[rightChar] + 1)
            charIndexMap[rightChar] = windowEnd
            maxLen = max(maxLen, windowEnd - windowStart + 1)
        return maxLen

solution = Solution()
print(solution.lengthOfLongestSubstring("tmmzuxt"))