pair<int, int> findPair(vector<int> arr, int targetSum)
{
    int left = 0, right = arr.size() - 1;
    while (left < right)
    {
        int currentSum = arr[left] + arr[right];
        if (currentSum == targetSum)
            return make_pair(left, right);
        else if (currentSum < targetSum)
            left++;
        else if (currentSum > targetSum)
            right++;
    }

    return make_pair(-1, -1);
}
