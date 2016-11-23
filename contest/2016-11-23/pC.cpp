#include <bits/stdc++.h>
using namespace std;
map<string, int> cnt;
map<string, set<string> > used;
set<string> user;
struct Node{
    string name;
    int cnt;
    bool operator < (const Node  n) const {
        return cnt>n.cnt || ((cnt==n.cnt) && name<n.name);
    }
};
int main()
{
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        string in;
        getline(cin, in);
        stringstream ss(in);
        string name;
        ss >> name;
        user.insert(name);
        string word;
        while (ss >> word) {
            used[word].insert(name);
            cnt[word]++;
        }
    }
    int n = user.size();
    vector<Node > v;
    for (auto it = used.begin(); it != used.end(); it++) {
        auto str = it->first;
        auto s = it->second;
        if (s.size() == n) {
            v.push_back(Node{str,cnt[str]});
        }
    }
    sort(v.begin(),v.end());
    if(v.size()==0){
        cout<<"ALL CLEAR"<<endl;
    }else {
        for(int i=0;i<v.size();i++){
            cout<<v[i].name<<endl;
        }
    }
    return 0;
}

