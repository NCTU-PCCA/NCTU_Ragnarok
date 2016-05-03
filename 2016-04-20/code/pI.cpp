/*************************************************************************
	> File Name: pI.cpp
	> Author: fuyu0425/a0919610611
	> School: National Chiao Tung University
	> Team: NCTU_Ragnorok
	> Mail: a0919610611@gmail.com
	> Created Time: 2016年04月20日 (週三) 22時08分10秒
 ************************************************************************/
#include <bits/stdc++.h>
using namespace std;
vector<int> e[3001];
bool bfs(int id)
{
    bool visited[3001]={};
    int d[3001]={};
    queue<int> s;
    s.push(id);
    visited[id]=true;
    while(!s.empty())
    {
        int t=s.front();
        s.pop();
        for(int i=0;i<e[t].size();i++)
        {
            if(!visited[e[t][i]])
            {
               d[e[t][i]]=d[t]+1;
               s.push(e[t][i]);
               visited[e[t][i]]=true;
 //              cout<<d[e[t][i]]<<endl;
               if(d[e[t][i]]>6) return false;
            }
        }
    }
    return true;
}
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
    int T;
    cin>>T;
    while(T--)
        {
        int n;
	cin>>n;
   	 for(int i=1;i<=3000;i++) e[i].clear();
        map<string,int> ID;
        int index=0;
        for(int i=1;i<=n;i++)
        {
            string a,b;
            cin>>a>>b;
             if(!ID.count(a))ID[a]=++index;
             if(!ID.count(b))ID[b]=++index;
             e[ID[a]].push_back(ID[b]);
             e[ID[b]].push_back(ID[a]);
        }
//	cout<<"index="<<index<<endl;
        int ans=0;
        for(int i=1;i<=index;i++)
        {
            if(!bfs(i))
            {
                ans++;
            }
        }
        double per=(double) ans/(double) index; 
	//cout<<per<<endl;
        if(per<=0.05)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
