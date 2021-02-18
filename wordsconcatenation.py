# Leetcode - 30. Substring with Concatenation of All Words(Hard)

# You are given a string s and an array of strings words of the same length. Return all starting indices of substring(s) in s that is a concatenation of each word in words exactly once, in any order, and without any intervening characters.

# You can return the answer in any order.

# Example 1:

# Input: s = "barfoothefoobarman", words = ["foo","bar"]
# Output: [0,9]
# Explanation: Substrings starting at index 0 and 9 are "barfoo" and "foobar" respectively.
# The output order does not matter, returning [9,0] is fine too.

# Example 2:

# Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
# Output: []

# Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
# Output: [6,9,12]

class Solution:
	def findSubstring(self, s, words):
		if len(words) == 0 or len(words[0])==0:
			return []
		wordFrequency = {}
		resultIndices = []
		wordCount = len(words)
		wordLength = len(words[0])
		for word in words: 
			if word not in wordFrequency:
				wordFrequency[word] = 0
			wordFrequency[word] += 1
		for windowStart in range((len(s)- wordCount * wordLength)+1):
			wordSeen = {}
			for windowEnd in range(0, wordCount):
				nextWordIndex = windowStart + windowEnd * wordLength
				nextWord = s[nextWordIndex : nextWordIndex + wordLength]
				if nextWord not in wordFrequency:
					break
				if nextWord not in wordSeen:
					wordSeen[nextWord] = 0
				wordSeen[nextWord] += 1

				if wordSeen[nextWord] > wordFrequency[word]:
					break

				if windowEnd + 1 == wordCount:
					resultIndices.append(windowStart)
		return resultIndices

solution = Solution()
print(solution.findSubstring("barfoofoobarthefoobarman",["bar","foo","the"]))
		

