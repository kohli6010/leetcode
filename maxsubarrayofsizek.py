def maxSubArraySumOfSizeK(k, arr):
	maxSum = 0
	windowStart = 0
	windowSum = 0
	for windowEnd,_ in enumerate(arr):
		windowSum += arr[windowEnd]
		if windowEnd >= k - 1:
			if windowSum > maxSum:
				maxSum = windowSum
			windowSum -= arr[windowStart]
			windowStart += 1
	return maxSum

print(maxSubArraySumOfSizeK(3, [2, 1, 5, 1, 3, 2]))