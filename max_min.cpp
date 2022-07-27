#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int> &nums)
{
    int duplicate;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == nums[i + 1])
        {
            duplicate = nums[i];
            break;
        }
    }
    return duplicate;
}
