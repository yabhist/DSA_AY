#include<bits/stdc++.h>
using namespace std;
class MyHashSet {
    struct ListNode{
        int va;
        ListNode* next;
        ListNode():va(0),next(NULL) {}
        ListNode(int x):va(x),next(NULL){}
        ListNode(int x, ListNode *next):va(x),next(next){}
    };
    ListNode** table=NULL;
    int BUCKET=10000;
    int hash_function(int val)
    {
        return (val % BUCKET);
    }
public:
    MyHashSet() {
        table=new ListNode*[BUCKET];
        for(int i=0;i<BUCKET;i++){
            table[i]=NULL;
        }
    }
    
    void add(int val) {
        int hf=hash_function(val);
        if(!table[hf]){
            table[hf]=new ListNode(val);
            return;
        }
        if(table[hf]->va==val){
            return;
        }
        ListNode *ptr=table[hf];
        while(ptr->next){
            if(ptr->next->va==val){
                return;
            }
            ptr=ptr->next;
        }
        ListNode *tmp=new ListNode(val);
        ptr->next=tmp;
    }
    
    bool contains(int val) {
        int hf=hash_function(val);
        ListNode *ptr=table[hf];
        while(ptr){
            if(ptr->va==val){
                return true;
            }
            ptr=ptr->next;
        }
        return false;
    }
    
    void remove(int val) {
        int hf=hash_function(val);
        if(!table[hf]){
            return;
        }
        if(table[hf]->va==val){
            ListNode* tmp=table[hf];
            table[hf]=table[hf]->next;
            delete(tmp);
            return;
        }
        ListNode *ptr=table[hf];
        while(ptr->next){
            if(ptr->next->va==val){
                ListNode *tmp=ptr->next;
                ptr->next=ptr->next->next;
                delete(tmp);
                return;
            }
            ptr=ptr->next;
        }
    }
};

int main(){
    
}