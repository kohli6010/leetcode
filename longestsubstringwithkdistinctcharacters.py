def longestSubstringWithKDistinctCharacters(k, str):
	maxLen = 0
	windowStart = 0
	characterFrequency = {}
	for windowEnd in range(0, len(str)):
		rightChar = str[windowEnd]
		if rightChar not in characterFrequency:
			characterFrequency[rightChar] = 0
		characterFrequency[rightChar] += 1
		
		while len(characterFrequency) > k:
			leftChar = str[windowStart]
			characterFrequency[leftChar] -= 1
			if characterFrequency[leftChar] == 0:
				del characterFrequency[leftChar]
			windowStart += 1
		maxLen = max(maxLen, windowEnd - windowStart + 1)
	return maxLen

print(longestSubstringWithKDistinctCharacters(2, "araaci"))
