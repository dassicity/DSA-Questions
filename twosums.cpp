// Leetcode problem two sums
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    int size = nums.size();
    int flag = 0;
    vector<int> ans;
    for (int i = 0; i < size; i++)
    {
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