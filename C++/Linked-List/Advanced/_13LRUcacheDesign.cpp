#include <iostream>
#include <unordered_map>
using namespace std;

struct node
{
    int data;
    node *next;
    node *prev;
    node(int key)
    {
        prev=next=NULL;
    }
};

node *addToCache(int data,int size)
{
    unordered_map<int,node *>mp;
    if(mp.empty()==true)
    {
        node *head=new node(data);
        mp[data]=head;
    }
    if(mp.size()<size)
    {
        if(mp.find(data)==mp.end())
        {
            
        }
    }
}