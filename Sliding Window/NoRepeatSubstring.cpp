int findLength(string str)
{
    int maxLength = 0;
    int windowStart = 0;
    int windowEnd;

    unordered_map<char, int> charFrequency;

    for (windowEnd = 0; windowEnd < str.length(); windowEnd++)
    {
        char rightChar = str[windowEnd];

        if (charFrequency.find(rightChar) != charFrequency.end())
            windowStart = max(windowStart, charFrequency[rightChar] + 1);

        charFrequency[rightChar] = windowEnd;

        maxLength = max(maxLength, windowEnd - windowStart + 1);
    }

    return maxLength;
}
