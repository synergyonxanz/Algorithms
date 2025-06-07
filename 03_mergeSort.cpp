#include <bits/stdc++.h>
using namespace std;
void merge1(vector<int> &nums, int start, int end, int mid)
{
    vector<int> temp(end - start + 1);
    int i = start;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= end)
    {
        if (nums[i] < nums[j])
        {
            temp[k] = nums[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = nums[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        temp[k] = nums[i];
        i++;
        k++;
    }
    while (j <= end)
    {
        temp[k] = nums[j];
        j++;
        k++;
    }

    for ( i = 0, j = start; i < temp.size(); i++, j++)
    {
        nums[j] = temp[i];
    }
}
void mergeSort(vector<int> &nums, int start, int end)
{
    if (end - start + 1 <= 1)
    {
        return;
    }
    int mid = (start + end) / 2;
    mergeSort(nums, start, mid);
    mergeSort(nums, mid + 1, end);

    merge1(nums, start, end, mid);
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

    mergeSort(nums, 0, nums.size() - 1);

    for (auto i : nums)
    {
        cout << i << " ";
    }

    return 0;
}