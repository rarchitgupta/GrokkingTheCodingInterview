string findSubstring(string str, string pattern)
{
    int windowStart = 0, windowEnd;
    int matched = 0;
    unordered_map<char, int> charFrequency;
    int minLength = str.length() + 1, subStrStart = 0;

    for (auto chr : pattern)
        charFrequency[chr]++;

    for (windowEnd = 0; windowEnd < str.length(); windowEnd++)
    {
        char rightChar = str[windowEnd];
        if (charFrequency.find(rightChar) != charFrequency.end())
        {
            charFrequency[rightChar]--;
            if (charFrequency[rightChar] >= 0)
                matched++;
        }

        while (matched == pattern.length())
        {
            if (minLength > windowEnd - windowStart + 1)
            {
                minLength = windowEnd - windowStart + 1;
                subStrStart = windowStart;
            }

            char leftChar = str[windowStart++];
            if (charFrequency.find(leftChar) != charFrequency.end())
            {
                if (charFrequency[leftChar] == 0)
                    matched--;
                charFrequency[leftChar]++;
            }
        }
    }

    return minLength > str.length() ? "" : str.substr(subStrStart, minLength);
}
