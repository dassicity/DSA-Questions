// Leetcode problem two sums
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    int size = nums.size();

    sort(nums.begin(), nums.end());

    return nums;
}

int main()
{
    vector<int> nums{2, 4, 5, 6, 9, 7};

    twoSum(nums, 9);

    for (auto x : nums)
    {
        cout << x << ' ';
    }
    cout << endl;

    return 0;
}