int findMinSubArray(int s, const vector<int> &arr)
{
    int minLength = INT_MAX;
    int windowSum = 0;
    int windowStart = 0;

    for (int windowEnd = 0; windowEnd < arr.size(); windowEnd++)
    {
        windowSum += arr[windowEnd];
        while(windowSum >= s)
        {
            minLength = min(minLength, windowEnd - windowStart + 1);
            windowSum -= arr[windowStart];
            windowStart++;
        }
    }

    return minLength;
}
