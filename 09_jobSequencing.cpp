#include <bits/stdc++.h>
using namespace std;
struct Job
{
    char id;
    int deadline;
    int profit;
};
int main()
{
    int n;
    cin >> n;
    vector<Job> jobs(n);
    int i, j;
    int maxDeadline = 0;
    for (i = 0; i < n; i++)
    {
        cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
        maxDeadline = max(maxDeadline, --jobs[i].deadline);
    }

    sort(jobs.begin(), jobs.end(), [&](Job j1, Job j2)
         {
        if(j1.profit == j2.profit) return j1.id < j2.id;
        return j1.profit > j2.profit; });

    vector<char> ans(maxDeadline + 1, 'X');
    vector<bool> free(maxDeadline + 1, true);

    for (auto job : jobs)
    {
        i = job.deadline;
        while (i >= 0)
        {
            if (free[i])
                break;
            i--;
        }
        cout << i << " " << job.id << endl;
        if (i >= 0)
        {
            ans[i] = job.id;
            free[i] = false;
        }
    }

    for (auto job : ans)
    {
        if (job == 'X')
            continue;
        cout << (job) << " ";
    }

    return 0;
}