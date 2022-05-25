#include <string>
#include <vector>
#include <iostream>

using namespace std; 


void preprocess(string p, vector<int>& pi){
    int j = 0; 
    
    for(int i = 0; i < p.size(); i++){
        j = pi[i-1]; 

        while(j > 0 && p[i] != p[j]){
            j = pi[j-1]; 
        }
        
        if(p[i] == p[j]){
            j++; 
        }

        pi[i] = j; 
    }

}


int main(){
    string t = "helloabcworld"; 
    string p = "abc"; 
    vector<int> pi(p.size(), 0); 
    preprocess(p, pi); 
    int i = 0; 
    int j = 0; 
    while(i < t.size() && j < p.size()){
        if(t[i] == p[j]){
            i++; 
            j++; 
            continue; 
        }

        while(j > 0 && t[i] != p[j]){
            j = pi[j-1]; 
        }

        if(j == 0){
            i++; 
        }
    }

    if(j == p.size()){
        cout << "yes at index : " << i - j <<  endl; 
    }

    else{
        cout << "no " << endl; 
    }


    return  0; 

}