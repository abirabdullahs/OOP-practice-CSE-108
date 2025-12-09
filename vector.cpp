#include <bits/stdc++.h>
using namespace std;

class vector{
  private:
    double n;
    double *elements;
    
    
  public:
    vector(double num, double arr[]){
      n = num;
      
      elements = (double *) malloc (n* sizeof(double));
      for(int i=0; i<n; i++){
        elements[i] = arr[i];
      }
    }
    
    ~vector(){
      free(elements);
      cout<<"vector destroyed"<<endl;
    }
    
    
    void add(vector &v){
      for(int i=0; i<n; i++){
        elements[i] += v.elements[i];
      }
    }
    
    
    void add(double value){
      for(int i=0; i<n; i++){
        elements[i] += value;
      }
    }
    
    
    void 
    
}

int main()
{
    cout << "Hello, Dcoder!";
}
