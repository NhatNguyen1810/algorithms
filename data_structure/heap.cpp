#include <iostream>
#include <vector>
using namespace std; 

vector<int> heap_array(0); 


void swap(int& a,int& b){
  int c = a; 
  a = b; 
  b = c; 
}

void shiftup(vector<int>& arr, int i); 
void insert(vector<int>& arr, int v){
  heap_array.push_back(v); 
  // for(int i = heap_array.size()/2 - 1; i >= 0; i--){
  //   shiftdown(arr, i); 
  // }
  shiftup(arr, arr.size() - 1); 
}

void shiftdown(vector<int>& arr, int i){
  int left = 2*i; 
  int right = 2*i + 1 < arr.size() ? 2*i + 1 : -1; 
  int switch_index = -1; 
  
  if(arr[i] > arr[left]){
    switch_index = left; 
    //swap(arr[i], arr[switch_index]); 
  }
  if(right != -1){
    if(arr[switch_index == -1 ? i : switch_index] > arr[right]){
      switch_index = right; 
      //swap(arr[i], right); 
    }
  }
  swap(arr[i], arr[switch_index]); 

  shiftdown(arr, switch_index); 
  
}


void shiftup(vector<int>& arr, int i){

  if(i == 0){
    return; 
  }


  int parent = (i-1)/2; 

  
  if(arr[parent] > arr[i]){
    swap(arr[i], arr[parent]); 
  }

  shiftup(arr, parent); 
  
}


void del_elem(vector<int>& arr){


}


int main(){

  vector<int> val{4,1,2, 0,7,8,9,}; 
  

  for(int x: val){
    insert(heap_array, x); 
  }

  cout << "get min " << heap_array[0] << endl; 

  cout << "get size " << heap_array.size() << endl; 


  return 0; 
}