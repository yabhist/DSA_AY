#include<bits/stdc++.h>
using namespace std;
class MyHashSet {
    struct ListNode{
        int val;
        ListNode* next;
        ListNode():val(0),next(NULL) {}
        ListNode(int x):val(x),next(NULL){}
        ListNode(int x, ListNode *next):val(x),next(next){}
    };
    ListNode* head=NULL;
public:
    MyHashSet() {
        head=new ListNode(-1);
    }
    
    void add(int key) {
        ListNode *tmp=new ListNode(key), *ptr=head;
        while(ptr->next){
            if(ptr->next->val==key){
                delete(tmp);
                return;
            }
            ptr=ptr->next;
        }
        ptr->next=tmp;
    }
    
    void remove(int key) {
        ListNode *ptr=head;
        while(ptr->next){
            if(ptr->next->val==key){
                ListNode *tmp=ptr->next;
                ptr->next=ptr->next->next;
                delete(tmp);
                break;
            }
            ptr=ptr->next;
        }
    }
    
    bool contains(int key) {
        ListNode *ptr=head;
        while(ptr){
            if(ptr->val==key){
                return true;
            }
            ptr=ptr->next;
        }
        return false;
    }
};
