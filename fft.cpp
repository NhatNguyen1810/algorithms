#include <iostream>
#include <vector>
#include <complex>
using namespace std; 
#define PI acos(-1.0)


void fft(vector<complex<double>>& array){
    if(array.size() == 1){
        return;
    }

    int n = array.size(); 

    vector<complex<double>> even; 
    vector<complex<double>> odd; 
    for(int i = 0 ; i < array.size() ; i++){
        if(i % 2 == 0){
            even.push_back(array[i]); 
        }
        else{
            odd.push_back(array[i]); 
        }
    }

    fft(even);
    fft(odd); 

    // Complex w0 = exp(2*PI*I/n);

    double ang = 2*PI/n; 
    complex<double> w0 (1); 
    complex<double> wn (cos(ang), sin(ang)); 
    for(int i = 0 ; i < array.size() / 2 ; i++){
        array[i] = even[i] + w0*odd[i]; 
        array[i + array.size()/2] = even[i] - w0*odd[i]; 
        w0 *= wn;
    }
}


void inverse_fft(vector<complex<double>>& array){
    if(array.size() == 1){
        return;
    }

    int n = array.size();

    vector<complex<double>> even; 
    vector<complex<double>> odd; 
    for(int i = 0 ; i < array.size() ; i++){
        if(i % 2 == 0){
            even.push_back(array[i]); 
        }
        else{
            odd.push_back(array[i]); 
        }
    }

    fft(even);
    fft(odd); 


    double ang = -2*PI/n; 
    complex<double> w0 (1); 
    complex<double> wn (cos(ang), sin(ang)); 
    for(int i = 0 ; i < array.size() / 2 ; i++){
        array[i] = even[i] + w0*odd[i]; 
        array[i + array.size()/2] = even[i] - w0*odd[i]; 
        w0 *= wn;
    }
}

vector<int> multiply(vector<int>& a, vector<int>& b){

    cout << "testing multiply" << endl; 
    vector<complex<double>> fa(a.begin(), a.end()); 
    vector<complex<double>> fb(b.begin(), b.end()); 

    int total_size = a.size() + b.size();
    int degree = 1; 
    while(degree < total_size){
        degree *= 2; 
    } 

    fa.resize(degree); 
    fb.resize(degree); 

    // for(int i = a.size() ; i < degree; i++){
    //     a.push_back(0); 
    // }
    // for(int i = b.size() ; i < degree ; i++){
    //     b.push_back(0); 
    // }
    fft(fa); 
    fft(fb); 

    cout << "testing fft" << endl; 

    vector<complex<double>> c(degree, 0); 
    for(int i = 0 ; i < degree; i++){
        c[i] = fa[i]*fb[i]; 
    }
    inverse_fft(c); 

    cout << "testing inverse fft" << endl; 
    vector<int> result (degree, 0); 
    for(int i = 0; i < degree; i++){
        result[i] = ((double) 1.0/(double)degree)*c[i].real();
    }
    return result; 

}

int main(){
    vector<int> a {1,0,1}; 
    vector<int> b {-1, 0, 1};
    vector<int> c = multiply(a,b); 
    for(int i = 0; i < c.size(); i++){
        cout << c[i] << " "; 
    }
    cout << endl; 
    return 0; 
}