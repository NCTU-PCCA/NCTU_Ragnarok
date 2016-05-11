/*************************************************************************
	> File Name: pE.cpp
	> Author: fuyu0425/a0919610611
	> School: National Chiao Tung University
	> Team: NCTU_Ragnorok
	> Mail: a0919610611@gmail.com
	> Created Time: 廿十六年五月四日 (週三) 十九時57分七秒
 ************************************************************************/
#define op_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    bool has_num;
    int num;
    int no;
    Node * left,*right;
    Node()
    {
        has_num=0;
        num=0;
        no=0;
        left=right=NULL;
    }
};
Node* root;
void insert(int &num,int& no,Node* nd=NULL,int pos=31)
{
//    cout<<pos<<endl;
    if (nd==NULL) nd=root;
    if(pos==-1) 
    {
        if(nd->has_num==false)
        nd->no=no;
        else nd->no=min(nd->no,no);
        nd->has_num=1;
        nd->num=num;
        return ;
    }
    int t=num &(1<<(pos));
    if(t) 
    {
        if(nd->left==NULL)
        {
            nd->left=new Node;
        }
        insert(num,no,nd->left,pos-1);
    }else
    {
        if(nd->right==NULL)
        {
            nd->right=new Node;
        }
        insert(num,no,nd->right,pos-1);
    }

}
int query(int x)
{
    Node *p=root;
    for(int i=31;i>=-1;i--)
    {
        if(i==-1)
        {
            return p->no;
        }
        if(x&(1<<i))
        {
            if(p->right)
            {
                p=p->right;

            }else
            {
                p=p->left;
            }
        }else
        {
            if(p->left)
            {
                p=p->left;
            }else
            {
                p=p->right;
            }
        }
    }
}
int main()
{
//    op_io;
    int T;
    cin>>T;
    while(T--)
    {
        int n,q;
        root=new Node;
        cin>>n>>q;
        for(int i=1;i<=n;i++)
        {
            int in;
            cin>>in;
            insert(in,i);
        }
        for(int i=1;i<=q;i++)
        {
            int in;
            cin>>in;
            cout<<query(in)<<endl;
        }

        delete root;
        cout<<endl;
    }
    return 0;
}
