#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    cout << "hello" << endl;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        int small = i;
        for (int j = i + 1; j < n; j++)
        {
            if (nums[j] < nums[small])
            {
                small = j;
            }
        }
        int temp = nums[small];
        nums[small] = nums[i];
        nums[i] = temp;
    }

    for (auto i : nums)
    {
        cout << i << " ";
    }

    return 0;
}