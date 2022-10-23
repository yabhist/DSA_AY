#include<bits/stdc++.h>
using namespace std;

class hash_
{
        int BUCKET;
        list<int>* table;
    public:
        hash_(int val);
        void insert(int val);
        void del(int val);
        void display();
        void access(int i , int j);
        void search(int val);
        int hash_function(int val)
        {
            return (val % BUCKET);
        }
};

hash_::hash_(int b)
{
    this->BUCKET=b;
    table = new list<int>[BUCKET];
}
void hash_::insert(int val)
{
    int index=hash_function(val);
    table[index].push_back(val);
}
void hash_::del(int val)
{
    int index=hash_function(val);
    list<int>::iterator it;
    for(it=table[index].begin();it!=table[index].end();it++)
    {
        if(*it==val)
        {
            break;
        }
    }
    if(it!=table[index].end())
    {
        table[index].erase(it);
    }
}
void hash_::display()
{
    for(int i=0;i<BUCKET;i++)
    {
        cout<<i;
        for(auto j:table[i])
        {
            cout<< "-->" << j;
        }
        cout<<'\n';
    }
    cout<<'\n';
}
void hash_::search(int val)
{
    int index=hash_function(val);
    list<int>::iterator it;
    int ct=0;
    for(it=table[index].begin();it!=table[index].end();it++)
    {
        if(*it==val)
        {
            break;
        }
        ct++;
    }
    if(it!=table[index].end())
    {
        cout<<index<<' '<<ct<<'\n';
    }
    cout<<'\n';
}
void hash_::access(int i, int j)
{
    list<int>::iterator it=table[i].begin();
    for(int k=0;k<j;k++)
    {
        it++;
    }
    cout<<*it<<'\n';
    cout<<'\n';
}
int main()
{
    int a[]={15,11,27,8,12};
    hash_ h(7);
    int size=sizeof(a)/sizeof(a[0]);
    for(int i=0;i<size;i++)
    {
        h.insert(a[i]);
    }
    h.display();
    h.search(8);
    h.access(1,1);
    h.del(12);
    h.display();
}