int findFruitCountofTwoTypes(const vector<char> &arr)
{
    int maxCount = 0;
    int windowStart = 0;
    int windowEnd;
    unordered_map<char, int> fruitFrequency;

    for (windowEnd = 0; windowEnd < arr.size(); windowEnd++)
    {
        fruitFrequency[arr[windowEnd]]++;

        while ((int)fruitFrequency.size() > 2)
        {
            fruitFrequency[arr[windowStart]]--;
            if (fruitFrequency[arr[windowStart]] == 0)
                fruitFrequency.erase(arr[windowStart]);

            windowStart++;
        }
        maxCount = max(maxCount, windowEnd - windowStart + 1);
    }
    return maxCount;
}
