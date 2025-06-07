#include <bits/stdc++.h>
using namespace std;

void subsetSum(vector<vector<int>> &ans, vector<int> &nums, vector<int> &temp, int sum, int target, int i)
{
    if (sum == target)
    {
        ans.push_back(temp);
        return;
    }

    for (int j = i; j < nums.size(); j++)
    {
        if (nums[j] + sum <= target)
        {
            temp.push_back(nums[j]);
            subsetSum(ans, nums, temp, sum + nums[j], target, j + 1);
            temp.pop_back();
        }
    }
}

int main()
{
    int n;
    int target;
    cin >> n >> target;
    vector<int> a(n);
    int i;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<vector<int>> ans;
    vector<int> temp;
    subsetSum(ans, a, temp, 0, target, 0);
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}