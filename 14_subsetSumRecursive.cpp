#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &nums, int sum, int target, int i, vector<int> &temp, vector<vector<int>> &ans)
{
    if (sum == target)
    {
        ans.push_back(temp);
        return;
    }
    if (i >= nums.size())
        return;
    temp.push_back(nums[i]);
    solve(nums, sum + nums[i], target, i + 1, temp, ans);
    temp.pop_back();
    solve(nums, sum, target, i + 1, temp, ans);
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int target;
    cin >> target;
    vector<vector<int>> ans;
    vector<int> temp;
    solve(nums, 0, target, 0, temp, ans);

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