#include<bits/stdc++.h>
using namespace std;
class MyHashMap {
    struct ListNode{
        int ke;
        int va;
        ListNode* next;
        ListNode():ke(0),va(0),next(NULL) {}
        ListNode(int x, int y):ke(x),va(y),next(NULL){}
        ListNode(int x, int y, ListNode *next):ke(x),va(y),next(next){}
    };
    ListNode** table=NULL;
    int BUCKET=10000;
    int hash_function(int val)
    {
        return (val % BUCKET);
    }
public:
    MyHashMap() {
        table=new ListNode*[BUCKET];
        for(int i=0;i<BUCKET;i++){
            table[i]=NULL;
        }
    }
    
    void put(int key, int val) {
        int hf=hash_function(key);
        if(!table[hf]){
            table[hf]=new ListNode(key,val);
            return;
        }
        if(table[hf]->ke==key){
            table[hf]->va=val;
            return;
        }
        ListNode *ptr=table[hf];
        while(ptr->next){
            if(ptr->next->ke==key){
                ptr->next->va=val;
                return;
            }
            ptr=ptr->next;
        }
        ListNode *tmp=new ListNode(key,val);
        ptr->next=tmp;
    }
    
    int get(int key) {
        int hf=hash_function(key);
        ListNode *ptr=table[hf];
        while(ptr){
            if(ptr->ke==key){
                return ptr->va;
            }
            ptr=ptr->next;
        }
        return -1;
    }
    
    void remove(int key) {
        int hf=hash_function(key);
        if(!table[hf]){
            return;
        }
        if(table[hf]->ke==key){
            ListNode* tmp=table[hf];
            table[hf]=table[hf]->next;
            delete tmp;
            return;
        }
        ListNode *ptr=table[hf];
        while(ptr->next){
            if(ptr->next->ke==key){
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
