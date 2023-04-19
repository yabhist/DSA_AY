#include<bits/stdc++.h>
using namespace std;
class Skiplist {
    struct Node{
        Node* next;
        Node* down;
        int val;
        Node(int val,Node* next=NULL,Node* down=NULL): val(val),next(next),down(down){}   
    };
    Node* head=NULL;
    int totlev=1;
    int ct=0;
    int getlev(){
        int tmp=1;
        while(rand()%2 && tmp<totlev){
            tmp++;
        }
        return tmp;
    }
public:
    Skiplist() {
        head=new Node(-1);
    }
    
    bool search(int target) {
        Node* p=head;
        while(p){
            while(p->next){
                if(p->next->val==target){
                    return true;
                }
                if(p->next->val > target){
                    break;
                }    
                p=p->next;
            }
            p=p->down;
        }
        return false;
    }
    
    void add(int num) {
        int lev=getlev();
        Node* p=head;
        for(int i=0;i<totlev-lev;i++){
            p=p->down;
        }
        stack<Node*>st;
        while(p){
            while(p->next){
                if(p->next->val >= num){
                    break;
                }
                p=p->next;
            }
            p->next=new Node(num,p->next,NULL);
            st.push(p->next);
            p=p->down;
        }
        Node* q=st.top();
        st.pop();
        while(!st.empty()){
            st.top()->down=q;
            q=st.top();
            st.pop();
        }
        ct++;
        if(ct>(1<<(totlev-1))){
            head= new Node(-1,NULL,head);
            totlev++;
        }
    }
    
    bool erase(int num) {
        bool ans=false;
        Node* p=head;
        Node* q=NULL;
        while(p){
            while(p->next){
                if(p->next->val < num){
                    p=p->next;
                }
                else if(p->next->val==num){
                    if(!q || p->next==q){
                        q=p->next->down;
                        Node* tmp=p->next;
                        p->next=p->next->next;
                        delete tmp;
                        ans=true;
                        break;// only one deletion in one row (...!q...)
                    }
                    else{
                        p=p->next;
                    }
                }
                else{
                    break;
                }
            }
            p=p->down;
        }
        ct--;
        return ans;
    }
};

int main(){

}