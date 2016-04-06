/*
    Author: 0Alien0
    School: NCTU
*/
#include<bits/stdc++.h>

#define FI freopen("in.txt", "r", stdin)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define F first
#define S second
#define EPS 1E-7
#define INF 0x7FFFFFFF
#define PI 3.1415926535897932384626433832795

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef vector<int> VII;
typedef vector<LL> VLL;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;

//int dx[]={1,0,-1,0};              int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};    int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};   int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};        int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

bool cmp(pair<string,VII> _A,pair<string,VII> _B){
    VII A=_A.S;
    VII B=_B.S;
    reverse(A.begin(),A.end());reverse(B.begin(),B.end());
    if(A.size() > B.size()){
        for(int i=0;i<A.size();i++){
            if(i >= B.size()){
                if(A[i] > 1)return true;
                else if(A[i] < 1)return false;
            }
            else{
                if(A[i] > B[i])return true;
                else if(A[i] < B[i])return false;
            }
        }
    }
    else{
        for(int i=0;i<B.size();i++){
            if(i >= A.size()){
                if(1 > B[i])return true;
                else if(1 < B[i])return false;
            }
            else{
                if(A[i] > B[i])return true;
                else if(A[i] < B[i])return false;
            }
        }
    }
    return _A.F < _B.F;
}

int main(){
    IOS;
    int N;
    string trash;
    vector<pair<string,VII>> profile;
    cin >> N;
    getline(cin,trash);
    for(int i=0;i<N;i++){
        string S,tmp;
        pair<string,VII> data;
        getline(cin,S);
        stringstream ss(S);
        ss >> tmp;data.F=tmp.substr(0,tmp.size()-1);
        while(1){
            ss >> tmp;
            if(tmp == "class")break;
            if(tmp == "lower")data.S.PB(0);
            else if(tmp == "middle")data.S.PB(1);
            else data.S.PB(2);
        }
        profile.PB(data);
    }
    sort(profile.begin(),profile.end(),cmp);
    for(auto i:profile){
        cout << i.F << endl;
    }
    return 0;
}
