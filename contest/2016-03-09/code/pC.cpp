#include<bits/stdc++.h>
using namespace std;

int main(){
  while(1){
    string S;
    cin >> S;
    int L=S.size();
    if(S[0] == '0' && L == 1)break;

    int Satellites[1000]={};
    for(int i=1;i<L;i++){
      int _count=0;
      for(int j=0;j<i;j++){
        if(Satellites[j] == 1 && i%j == 0)_count++;
      }
      _count%=2;
      if(_count != S[i]-48)Satellites[i]=1;
      else Satellites[i]=0;
    }
    int flag=0;
    for(int i=0;i<L;i++)if(Satellites[i]){if(flag)cout << " ";cout << i;flag=1;}
    cout << endl;
  }
  return 0;
}
