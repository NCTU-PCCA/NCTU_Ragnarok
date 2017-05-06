#include <bits/stdc++.h>
using namespace std;

int LIS(vector<int>& v)
{
    vector<int> ans;
    for (auto& i : v) {
        auto it = lower_bound(ans.begin(), ans.end(), i);
        if (ans.size() == 0 || i >= ans.back())
            ans.push_back(i);
        else {
            *it = i;
        }
    }
    return ans.size();
}
