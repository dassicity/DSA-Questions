// Leetcode problem two sums
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    int size = nums.size();
    vector<int> ans;

    sort(nums.begin(), nums.end());

    for (int i = nums.size(); i > 0; i--)
    {
        if (nums[i] <= target)
        {
            int rem = target - nums[i];
            for (int j = i; j > 0; j--)
            {
                if (nums[j] == rem)
                {
                    ans.push_back(i);
                    ans.push_back(j);
                }
            }
        }
    }

    return ans;
}

int main()
{
    vector<int> nums{2, 4, 5, 6};

    vector<int> result = twoSum(nums, 9);

    for (auto x : result)
    {
        cout << x << ' ';
    }
    cout << endl;

    return 0;
}