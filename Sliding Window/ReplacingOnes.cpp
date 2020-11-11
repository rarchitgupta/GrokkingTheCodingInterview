int findLength(const<vector> &arr, int k)
{
    int maxLength = 0;
    int windowStart = 0;
    int windowEnd;
    int maxOnesCount = 0;

    for (windowEnd = 0; windowEnd < str.size(); windowEnd++)
    {
        if (arr[windowEnd] == 1)
            maxOnesCount++;

        if (windowEnd - windowStart + 1 > k)
        {
            if (arr[windowStart] == 1)
                maxOnesCount--;

            windowStart++;
        }

        maxLength = max(maxLength, windowEnd - windowStart + 1);
    }

    return maxLength;
}
