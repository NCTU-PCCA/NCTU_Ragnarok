/*************************************************************************
	> File Name: pF.cpp
	> Author: fuyu0425/a0919610611
	> School: National Chiao Tung University
	> Team: NCTU_Ragnorok
	> Mail: a0919610611@gmail.com
	> Created Time: 廿十六年五月四日 (週三) 十九時四分48秒
 ************************************************************************/
#define op_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#include <bits/stdc++.h>
using namespace std;
string s1,s2;
int ln_s1,ln_s2;
set<string>ss;
void build(string &s1,string &s2,int index1,int index2,string now)
{
//        cout<<ln_s1<<" "<<ln_s2<<" "<<index1<<" "<<index2<<" "<<now<<endl;
        if((int)now.size()==ln_s1+ln_s2) 
        {
            ss.insert(now);
            return ;
        }
        if(index1<ln_s1)
        {
            string in=now+s1[index1];
            build(s1,s2,index1+1,index2,in);
        }
//        cout<<"now="<<now<<endl;
        if(index2<ln_s2)
        {
            string in=now+s2[index2];
//            cout<<"in="<<in<<endl;
            build(s1,s2,index1,index2+1,in);
        }
}
int main()
{
    op_io;

    int T;
    cin>>T;
    while(T--)
    {
        ss.clear();
        cin>>s1>>s2;
        ln_s1=s1.size();
        ln_s2=s2.size();
        string in="";
        build(s1,s2,0,0,in);
        set<string>::iterator it;
        for(it=ss.begin();it!=ss.end();it++)
        {
            cout<<*it<<endl;
        }
        cout<<endl;

    }
    return 0;
}
