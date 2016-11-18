#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> prime;
 int MAXN = 1e7+1000;
 int MOD = 1e9 + 7;
bool notprime[10000000+10000];
void build_prime()
{
    for (int i = 2; i <= MAXN; i++) {
        if (!notprime[i]) {
            prime.push_back(i);
        }
        for (int j = 0; j < prime.size() && i * prime[j] <= MAXN; j++) {
            notprime[i * prime[j]] = true;
            if (i % prime[j] == 0) {
                break;
            }
        }
    }
}
#undef int
int main()
{
#define int long long
    int MAXX = 1e14+1000;
    build_prime();
    vector<pair<long long   , long long   > > vv;
    for (int i = 0; i < prime.size(); i++) {
        int xx = prime[i];
            xx = xx * prime[i];
        while ( xx <= MAXX && xx>=0) {
            vv.push_back(make_pair(xx, prime[i]));
            xx = xx * prime[i];
            int a=log2(xx);
            int b=log2(prime[i]);
            int c=a+b;
            if(c>=64) break;
        }
    }
    sort(vv.begin(),vv.end());
    vector< pair<long long , long long > > vvv;
    int ans=1;
    for(int i=0;i<vv.size();i++){
         ans=(ans%MOD*vv[i].second)%MOD;
         vvv.push_back(make_pair(vv[i].first,ans));
    }
    int T;
    cin >> T;
    int kase = 1;
    while (T--) {
        cout << "Case " << kase++ << ": ";
        int in;
        cin >> in;
        if(in<4) {cout<<"1"<<endl; continue;}
        pair<int,int> p=make_pair(in,INT_MAX);
        auto it = upper_bound(vvv.begin(),vvv.end(),p);
        it--;
        cout<<it->second<<endl;
        
        
    }
}
