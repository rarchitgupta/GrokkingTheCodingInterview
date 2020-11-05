int findLength(const string &str, int k)
{
    int maxLength = 0;
    int windowStart = 0;
    int windowEnd;
    unordered_map<char, int> charFrequency;

    for (windowEnd = 0; windowEnd < str.length(); windowEnd++)
    {
        char rightChar = str[windowEnd];
        charFrequency[rightChar]++;

        while ((int)charFrequency.size() > k)
        {
            char leftChar = str[windowStart];
            charFrequency[leftChar]--;
            if (charFrequency[leftChar] == 0)
                charFrequency.erase(leftChar);

            windowStart++;
        }

        maxLength = max(maxLength, windowEnd - windowStart + 1);
    }

    return maxLength;
}
