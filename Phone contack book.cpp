#include<bits/stdc++.h>
using namespace std;

//we are creating node for ease of implementation
struct Node{
    Node* links[26]={NULL};
    bool end=false;
    string contact;
    
    bool containskey(char ch){
        if(links[ch-'a']!=NULL)
        return true;
        
        return false;
    }
    
    void put(char ch,Node* node){
        links[ch-'a']=node;
    }
    
    Node* get(char ch){
        return links[ch-'a'];
    }
    
    void setend(string s){
        this->contact=s;
        end=true;
    }
    
    bool isend(){
        return end;
    }
};
class Trie{
    private:Node* root;
    
    public:
    
    Trie(){
        root=new Node;
    }
    
    void insert(string name,string phone){
        Node* node=root;
        for(int i=0;i<name.size();i++){
            if(!node->containskey(name[i]))
            node->put(name[i],new Node);
            
            node=node->get(name[i]);
        }
        node->setend(phone);
    }
    
    void print(Node* node,string &pre){
        if(node==NULL)
        return;
        
        if(node->isend())
        cout<<pre<<" "<<node->contact<<endl;
        
        for(int i=0;i<26;i++){
            if(node->links[i]!=NULL){
                string str=pre+(char)('a'+i);
                print(node->links[i],str);
            }
        }
    }
    void search(string prefix){
        Node* node=root;
        for(int i=0;i<prefix.size() && node;i++){
            node=node->get(prefix[i]);
        }
        if(node)
        print(node,prefix);
        else
        cout<<"no result"<<endl;
        
    }
};

int main(){
    Trie *t=new Trie;
    
    int n;
    cout<<"total number of contacts"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"name"<<"  "<<"phonenum"<<endl;
        string name,phone;
        cin>>name>>phone;
        
        t->insert(name,phone);
    }
    
    cout<<"number of queries to be done"<<endl;
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        cout<<"type prefix of name that you want to search"<<endl;
        string name;
        cin>>name;
        t->search(name);
    }
}
