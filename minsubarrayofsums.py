import math

def minSubArrayOfSumS(s, arr):
	minLen = math.inf
	windowSum = 0
	windowStart = 0
	for windowEnd in range(0, len(arr)):
		windowSum += arr[windowEnd]
		while windowSum >= s:
			minLen = min(minLen, (windowEnd - windowStart) + 1)
			windowSum -= arr[windowStart]
			windowStart += 1
	
	return minLen;

print(minSubArrayOfSumS(7, [2, 1, 5, 2, 3, 8]))