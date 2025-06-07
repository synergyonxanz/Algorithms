#include <bits/stdc++.h>
using namespace std;
void computeLPS(vector<int> &lps, string pat)
{
    int i = 1;
    int len = 0;
    lps[0] = 0;
    while (i < pat.length())
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
            else
            {
                len = lps[len - 1];
            }
        }
    }
    return;
}
int main()
{
    string txt, pat;
    cin >> txt >> pat;
    int m = pat.length();
    int n = txt.length();
    vector<int> ans;

    vector<int> lps(m); // prefix function for the pattern
    computeLPS(lps, pat);

    int i = 0; // text index
    int j = 0; // pattern index
    while (i < n)
    {
        if (pat[j] == txt[i])
        {
            i++;
            j++;
        }

        if (j == m)
        {
            ans.push_back(i - j + 1); // store 1-based index as the ans
            j = lps[j - 1];
        }
        else if (i < n && pat[j] != txt[i])
        {
            if (j == 0)
            {
                i++;
            }
            else
            {
                j = lps[j - 1];
            }
        }
    }

    for (auto i : ans)
    {
        cout << i << " ";
    }

    return 0;
}