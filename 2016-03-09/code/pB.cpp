#include<bits/stdc++.h>
#define MAX_LENGTH 10000
using namespace std;
char word[MAX_LENGTH+1];
bool you[10];
bool nested_palindrome(int L,long long k){
  if(L == 1){
    if(word[0] == '?'){
      int c=0;
      for(int i=0;i<10;i++){
        if(you[i])c++;
        if(c == k){word[0]=i+48;break;}
      }
      if(c != k)return false;
    }
    else if(k > 1)return false;
    if(strlen(word) != L && word[L] !='?' && word[L-1] == word[L])return false;
    return true;
  }
  for(int i=0;i<L/2;i++){
    if(word[i] == '?' && word[L-1-i] != '?')word[i]=word[L-1-i];
    else if(word[i] != '?' && word[L-1-i] == '?')word[L-1-i]=word[i];
    else if(word[i] != word[L-1-i])return false;
  }
  if(word[L/2] == '?'){
    int N=k%9;if(N == 0)N=9;
    long long M=(k-1)/9+1;
    if(!nested_palindrome(L/2,M))return false;
    word[L/2]=N-(N <= (word[L/2-1]-48))+48;
  }
  else{
    you[word[L/2]-48]=false;
    if(!nested_palindrome(L/2,k))return false;
  }
  for(int i=0;i<L/2;i++){
    if(word[L-1-i] == '?')word[L-1-i]=word[i];
  }
  if(strlen(word) != L && word[L] !='?' && word[L-1] == word[L])return false;
  return true;
}
int main(){
  while(1){
    long long k;
    scanf("%lld",&k);
    if(k == 0)break;
    scanf("%s",word);
    you[0]=false;for(int i=1;i<10;i++)you[i]=true;
    int tmp=strlen(word);
    bool explode=false;
    while(tmp > 0){
      if(tmp%2 == 0){explode=true;break;}
      tmp/=2;
    }
    if(!nested_palindrome(strlen(word),k) || explode || word[0] == '0')printf("-1\n");
    else printf("%s\n",word);
  }
  return 0;
}
