/*
    Author: 0Alien0
    School: NCTU
*/
#include<bits/stdc++.h>

#define FI freopen("in.txt", "r", stdin)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ff first
#define ss second
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

//int dx[] = {-1,0,1,0};
//int dy[] = {0,1,0,-1};

#define MAX_NUMBER 2100000

bool prime[MAX_NUMBER];

void BuildPrime(int N){
  for(LL i=2;i<N;i++)prime[i] = true;
  for(LL i=2;i<N;i++){
    if(prime[i]){for(LL j=i*i;j<N;j+=i)prime[j] = false;}
  }
}

bool Palindrome(bool number[],int L){
    for(int i=0;i<L/2;i++){
        if(number[i] != number[L-i-1]){
            return false;
        }
    }
    return true;
}

int main(){
    IOS;
    string S;
    BuildPrime(MAX_NUMBER);
    while(cin >> S){
        int N = 0;
        for(int i=0;i<S.size();i++){
            N*=2;
            N+=S[i]-48;
        }
        for(int i=N;i<MAX_NUMBER;i++){
            if(prime[i]){
                int tmp = i,pointer = 0;
                bool number[30];
                while(tmp > 0){
                    number[pointer++] = tmp%2;
                    tmp/=2;
                }
                if(Palindrome(number,pointer)){
                    for(int i=0;i<pointer;i++)cout << number[i];cout << endl;
                    break;
                }
            }
        }
    }
    return 0;
}
