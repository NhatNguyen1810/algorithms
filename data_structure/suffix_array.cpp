#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> sort_array(string s){
    int n = s.size(); 
    const int alphabet = 256; 

    vector<int> p(n), c(n); 
    vector<int> cnt(max(alphabet, n), 0); 

    // counting sort to sort the substring with length 1 
    for(int i = 0; i < n; i++){
        cnt[s[i]]++; 
    }
    for(int i = 1; i < alphabet; i++){
        cnt[i] += cnt[i-1]; 
    }

    //vector<int> output(max(alphabet))
    for(int i = 0 ; i < n; i++){
        p[--cnt[s[i]]] = i; 
        //cnt[s[i]]--; 
    }
    // store equivalance class 
    c[p[0]] = 0; 
    int classes = 1; 
    for(int i = 1; i < n; i++){
        if(s[p[i]] != s[p[i-1]]){
            classes++; 
        }
        c[p[i]] = classes - 1; 
    }

    //cout << "step 1" << endl; 


    // use the idea of radix sort to sort the remaining lengths of 2^k < n 

    vector<int> pn(n), cn(n); 
    for(int h = 0; (1 << h) < n ; ++h){
        for(int i = 0; i < n; i++){
            pn[i] = p[i] - (1 << h); 
            if(pn[i] < 0){
                pn[i] += n; 
            }

        }

        //cout << "step 2" << endl; 

        fill(cnt.begin(), cnt.begin() + classes, 0); 
        for(int i = 0; i < n; i++){
            cnt[c[pn[i]]]++; 
        }
        for(int i = 1; i < classes; i++){
            cnt[i] += cnt[i-1]; 
        }

        for(int i = n-1; i >= 0; i--){
            p[--cnt[c[pn[i]]]] = pn[i]; 
            //cnt[c[pn[i]]]--; 
        }

        //cout << "step 3" << endl; 

        cn[p[0]] = 0; 
        classes = 1; 
        for(int i = 0; i < n ; i++){
            pair<int,int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]}; 
            pair<int,int> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]}; 
            if(cur != prev){
                classes++; 
            }
            cn[p[i]] = classes - 1; 
        }

        //cout << "step 4" << endl;
        c.swap(cn); 
    }
    return p; 
}

vector<int> suffix_construction(string s){
    s += "$"; 
    //cout << "step 0" << endl; 
    vector<int> shift_sort = sort_array(s); 
    shift_sort.erase(shift_sort.begin()); 
    return shift_sort; 
}

int main(){
    string s = "aaba"; 
    vector<int> p = suffix_construction(s); 
    for(int x : p){
        cout << x << " "; 
    }
    cout << endl; 
    return 0; 
}