/*
    Author: 0Alien0
    Country: Taiwan
    School: NCTU
*/
#include<bits/stdc++.h>

#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define SZ(x) ((int)((x).size()))
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

using namespace std;

typedef long long LL;

const int MOD = 1000000009;
const int HASH = 137;
const int NUM = 1000000;

const double pi = 3.14159265358979323846;
const double eps = 1e-7;

#define int LL

#undef int

int main(){
    #define int LL
    int N;double G;cin >> N >> G;
    pair<double,double> data[N];
    for(int i=0;i<N;i++)cin >> data[i].ff >> data[i].ss;
    double ans[N];
    for(int i=N-1;i>=0;i--)ans[i] = ((i==N-1)?0:ans[i+1])+2.0*cos(data[i].ss*pi/180.0)*G*data[i].ff;
    for(int i=0;i<N;i++)cout << fixed << setprecision(20) << sqrt(ans[i]) << endl;
    return 0;
}
