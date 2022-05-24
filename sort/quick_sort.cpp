#include <iostream>
#include <vector>

using namespace std; 

void swap(int& a, int& b){
    int c = a; 
    a = b; 
    b = c; 
}

int partition(vector<int>& arr, int left, int right){
    // pick the pivot
    int pivot = arr[right]; 
    int low = left; 
    int high = pivot - 1; 

    // call pivot_val be arr[pivot]
    // bring elements less then pivot_val to the left 
    // bring elements greater than pivot_val to the right 
    // return the exact position of povit_val in arr 

    while(true){
        while(low <= high && arr[low] < pivot){
            low++; 
        }
        while(low <= high && arr[high] > pivot){
            high--; 
        }
        if(low >= high){
            break; 
        }
        swap(arr[low], arr[high]); 
        low++; 
        high--; 
    }
    swap(arr[low], arr[right]); 
    return low; 
}

void quick_sort(vector<int>& arr, int left, int right){

    if(left < right){
        int pivot = partition(arr, left, right); 
        quick_sort(arr, left, pivot - 1); 
        quick_sort(arr, pivot + 1, right); 
    }
    
}


int main(){

    vector<int> a{7,6,5,4,3,2,1}; 
    

    quick_sort(a, 0, 6); 
    

    for(int i = 0; i < a.size(); i++){
        cout << a[i] << " "; 
    }
    cout << endl; 

    return 0; 
}