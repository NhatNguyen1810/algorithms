#include <vector>
#include <iostream>

using namespace std; 
using ll = long long; 
struct vertex {
    int p; 
    char ch; 
    int link; 
    int go[26]; 
    int next[26]; 
    bool leaf = false; 

    vertex (int p = -1, char ch = '$') : p(p), ch(ch) {
        fill(begin(go), end(go), -1); 
        fill(begin(next), end(next), -1); 
    };
};

vector<vertex> trie(1);  

void add_string(string s){
    int v = 0; 

    for(int i = 0; i < s.size(); i++){
        int c = s[i] - 'a'; 
        if(trie[v].next[c] == -1){
            trie[v].next[c] = trie.size(); 
            trie.push_back(vertex (v, s[i])); 
        }

        v = trie[v].next[c]; 
    }

    trie[v].leaf = true; 
}

int go(int v, int ch); 
int get_link(int v){
    
    if(trie[v].link == -1){
        if(v == 0 || trie[v].p == 0){
            trie[v].link = 0; 
        }
        else{
            trie[v].link = go(get_link(trie[v].p), trie[v].ch); 
        }
    }
    return trie[v].link; 
}

int go(int v, int ch){
    int c = ch - 'a'; 
    if(trie[v].go[c] == -1){
        if(trie[v].next[c] != -1){
            trie[v].go[c] = trie[v].next[c]; 
        }
        else{
            trie[v].go[c] = v == 0 ? 0 : go(get_link(v), ch); 
        }
    }
    return trie[v].go[c];
}


int main(){
    vector<string> dict{"he", "she", "him", "her"}; 
    string s = "aheasheahimaher"; 
    //add_string(s); 
    for(string temp: dict){
        add_string(temp); 
    }
    cout << "vertex size " << trie.size() << endl; 
    for(int i = 0; i < trie.size(); i++){
        cout << "char " << trie[i].ch << " " << trie[i].leaf << endl; 
    }
    //vertex root = trie[0]; 
    int v = 0; 
    for(int i = 0; i < s.size(); i++){
        int c = s[i] - 'a'; 
        //int v = root.next[c]; 
        if(trie[v].next[c] != -1){
            v = trie[v].next[c]; 
            if(trie[v].leaf == true){
                cout << "found a word at index " << i << " " << s[i] << endl; 
            }
        }
        else{
            v = get_link(v); 
        }
    }
    return 0; 
}