int findMaxSumSubArray(int k, int arr[])
{
    int windowSum = 0;
    int maxSum = 0;
    int windowStart = 0;

    for (int windowEnd = 0; windowEnd < arr.size(); windowEnd++)
    {
        int windowSum += arr[windowEnd];
        if (windowEnd >= k - 1)
        {
            maxSum = max(maxSum, windowSum);
            windowSum -= arr[windowStart];
            windowStart++;
        }
    }

    return maxSum;
}
