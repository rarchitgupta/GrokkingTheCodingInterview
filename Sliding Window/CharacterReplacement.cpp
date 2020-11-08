int findLength(string str, int k)
{
    int maxLength = 0;
    int windowStart = 0;
    int windowEnd;
    int maxFrequencyLetterCount = 0;

    unordered_map<char, int> charFrequency;

    for (windowEnd = 0; windowEnd < str.size(); windowEnd++)
    {
        char rightChar = str[windowEnd];
        charFrequency[rightChar]++;
        maxFrequencyLetterCount = max(maxFrequencyLetterCount, charFrequency[rightChar]);

        if (windowEnd - windowStart + 1 - maxFrequencyLetterCount > k)
        {
            char leftChar = str[windowStart];
            charFrequency[leftChar]--;
            windowStart++;
        }

        maxLength = max(maxLength, windowEnd - windowStart + 1);
    }

    return maxLength;
}
