bool findStringAnagrams(string str, string pattern)
{
    vector<int> resultIndices;

    int windowStart = 0, windowEnd;
    unordered_map<char, int> charFrequency;
    int matched = 0;

    for (int i = 0; i < pattern.length(); i++)
    {
        charFrequency[pattern[i]]++;
    }

    for (windowEnd = 0; windowEnd < str.length(); windowEnd++)
    {
        char rightChar = str[windowEnd];
        if (charFrequency.find(rightChar) != charFrequency.end())
        {
            charFrequency[rightChar]--;
            if (charFrequency[rightChar] == 0)
                matched++;
        }

        if (matched == (int)charFrequency.size())
            resultIndices.push_back(windowStart);

        if (windowEnd >= pattern.length() - 1)
        {
            char leftChar = str[windowStart++];
            if (charFrequency.find(leftChar) != charFrequency.end())
            {
                if (charFrequency[leftChar] == 0)
                    matched--;

                charFrequency[leftChar]++;
            }
        }
    }

    return resultIndices;
}
