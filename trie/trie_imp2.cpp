#include<bits/stdc++.h>
using namespace std;
class Trie{
    struct Node{
        Node* links[26];
        int cntEndWith=0;
        int cntPrefix=0;

        bool containsKey(char ch){
            return links[ch-'a']!=NULL;
        }
        void put(char ch, Node* node){
            links[ch-'a']=node;
        }
        Node* get(char ch){
            return links[ch-'a'];
        }
        void increaseEnd(){
            cntEndWith++;
        }
        void increasePrefix(){
            cntPrefix++;
        }
        void deleteEnd(){
            cntEndWith--;
        }
        void reducePrefix(){
            cntPrefix--;
        }
        int getEnd(){
            return cntEndWith;
        }
        int getPrefix(){
            return cntPrefix;
        }
    };
    Node* root=NULL;
public:

    Trie(){
        root=new Node();
    }

    void insert(string &word){
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
    }

    int countWordsEqualTo(string &word){
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                return 0;
            }
            node=node->get(word[i]);
        }
        node->getEnd();
    }

    int countWordsStartingWith(string &word){
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                return 0;
            }
            node=node->get(word[i]);
        }
        node->getPrefix();
    }

    void erase(string &word){
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                return;
            }
            node=node->get(word[i]);
            node->reducePrefix();
        }
        node->deleteEnd();
    }
};

int main(){
    
}