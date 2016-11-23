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

char special[9] = "bcdgknpt";
char special2[4] = "aou";

bool in(char ch){
    for(int i=0;i<8;i++)if(ch == special[i])return true;
    return false;
}

#undef int

int main(){
    #define int LL
    string S;getline(cin,S);
    string ans,now;
    stringstream ss(S);
    while(ss >> now){
        int small = 1000;char ch;
        bool big = (now[0] <= 'Z');
        if(big)now[0] ^= 32;
        for(int i=0;i<8;i++){
            int result = abs(now[0]-special[i]);
            if(result < small){small = result;ch = special[i];}
        }
        now[0] = ch;
        if(big)now[0] ^= 32;

        bool mm = false;
        for(int i=1;i<now.size();i++){
            if(now[i] == '-'){mm = true;continue;}
            big = (now[i] <= 'Z');if(big)now[i] ^= 32;
            if(mm && in(now[i])){now[i] = (now[0] <= 'Z'?now[0]^32:now[0]);}
            if(big)now[i] ^= 32;
        }

        big = (now[now.size()-1] <= 'Z');if(big)now[now.size()-1] ^= 32;
        if(in(now[now.size()-1])){
            int small = 1000;
            for(int i=0;i<3;i++){
                int result = abs(now[now.size()-1]-special2[i]);
                if(result < small){small = result;ch = special2[i];}
            }
            if(big)now[now.size()-1] ^= 32;
            now += ch;now += "h";
        }

        ans += now + " ";
    }
    for(int i=0;i<ans.size()-1;i++){
        if(ans[i] != '-')cout << ans[i];
    }
    return 0;
}
