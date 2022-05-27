

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 
using ll = long long; 


void counting_sort(vector<int>& arr){
    int min_elem = INT_MAX; 
    int max_elem = -1; 
    int n = arr.size(); 
    for(int i = 0; i < arr.size(); i++){
        min_elem = min(min_elem, arr[i]); 
    }
    for(int i = 0; i < arr.size(); i++){
        max_elem = max(max_elem, arr[i]); 
    }
    int total_size = max_elem + 1;
    cout << max_elem << " " << min_elem << endl; 
    //vector<int> counting(occurence, 0); 
    vector<int> counting(max_elem + 1, 0); 
    //counting[0] = arr[0]; 
    for(int i = 0; i < n; i++){
        counting[arr[i]]++; 
    }
    
    for(int i = 1; i < total_size; i++){
        counting[i] += counting[i-1]; 
    }

    vector<int> output(n, 0); 

    for(int i = n-1; i >= 0; i--){
        output[counting[arr[i]] - 1] = arr[i];  
        counting[arr[i]]--;
    }

    for(int i = 0; i < n ; i++){
        arr[i] = output[i]; 
    }
}

int main(){
    vector<int> arr {2,1,3,6,4,3,9}; 

    counting_sort(arr); 

    for(int x: arr) {
        cout << x << " "; 
    }
    cout << endl; 

    return 0; 
}