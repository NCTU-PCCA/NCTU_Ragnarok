#include <bits/stdc++.h>
using namespace std;

int main()
{
#define int long long 
    int M, N;
    cin >> M >> N;
    int pre = 0;
    int now = 0;
    vector<int> diff;
    cin >> pre;
    for (int i = 1; i < M; i++) {
        cin >> now;
        diff.push_back(now - pre);
        pre = now;
    }
    vector<int> num;
    for (int i = 0; i < N; i++) {
        int t;
        cin >> t;
        num.push_back(t);
    }
   set<int> ans;
    for (int i = 0; i < (int)num.size() -M+1; i++) {
        int v = num[i + 1] - num[i];
        bool flag = false;
        for (int j = i + 1; j < (i + M - 1); j++) {
            int d = num[j + 1] - num[j];
            int t = (j - i - 1 + 1);
            if (d * diff[0] != v * diff[t]) {
                flag = true;
                break;
            }
        }
        if (flag)
            continue;
        else
            ans.insert(v);
    }
    cout << ans.size() << endl;
    for(auto it =ans.begin();it!=ans.end();it++){
        if(it!=ans.begin()) cout<<" ";
        cout<<*it;
    }
    cout << endl;
    return 0;
}
