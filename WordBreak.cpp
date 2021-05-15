#include<bits/stdc++.h>
using namespace std;

class Trie{
        public:
    bool isEnd;
    Trie* alp[26];
    
    Trie()
    {
        isEnd=false;
        
        for(int i=0;i<26;i++){
            alp[i] = NULL;
        }
    }
};

void insert(Trie *head , string& curr){
    Trie *current = head;
    
    for(int i=0;i<curr.length();i++){
        int index = curr[i] - 'a';
        if(current->alp[index] == NULL){
            current->alp[index] = new Trie();
        }
        current = current->alp[index];
    }
    current->isEnd  =true;
}
bool search(Trie* head , string& curr){
    Trie* current =  head;
    for(int i=0;i<curr.length();i++){
        int index = curr[i] - 'a';
        
        if(current->alp[index] == NULL) return false;
        current=current->alp[index];
    }
    return current->isEnd;
}


class Solution{
    public:
    int fun(string& A, Trie* head , int index = 0){
        if(index == A.length()) return true;
        
        string m="";
        
        for(int i=index ; i<A.size() ; i++){
            m.push_back(A[i]);
            
            if(search(head , m)){
                if(fun(A , head , i+1)){
                    return 1;
                }
            }
        }
        
        return 0;
    }
     
    int wordBreak(string A, vector<string> &B) {
        Trie* head = new Trie();
        
        for(int i=0;i<B.size();i++){
            insert(head , B[i]);
        }
        
        return fun(A,head);
        //code here
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    vector<string> dict;

    for(int i=0;i<n;i++){
        string S;
        cin>>S;
        dict.push_back(S);
    }
    string line;
    cin>>line;
    Solution ob;
    cout<<ob.wordBreak(line , dict)<<endl;
    }
}