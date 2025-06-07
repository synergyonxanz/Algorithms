#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    sort(v.begin(), v.end());
    int key;
    cin>>key;

    int left = 0;
    int right = n - 1;
    while(left <= right)
    {
        int mid = left + (right - left) / 2;
        if(v[mid] == key)
        {
            cout<<"Found at : "<<mid<<endl;
            return 0;
        }
        else if(key < v[mid])
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    cout<<"Not Found";

    return 0;
}