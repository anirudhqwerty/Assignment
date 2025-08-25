#include<bits/stdc++.h>
using namespace std;

int main(){

     int n;
     cout<<"Enter Value of N: ";
     cin>>n;
     int arr[n*(n+1)/2];
     cout<<"Enter Non Zero elements of Lower Diagonal Matrix: "; 
    
     for(int i=0;i<n*(n+1)/2;i++){
          cin >> arr[i];
     }     

     for(int i=0;i<n;i++){
          for(int j=0;j<n;j++){
               if(i==j){// printing diagonal portion of matrix
                    cout << arr[((i*(i+1))/2) + i]<<" ";
               }
               else if(i>j){
                    // printing non diagonal non zero portion
                    cout<< arr[((i*(i+1))/2) + j] <<" ";
               }
               else {
                    // printing zero to upper part making it a lower diagonal mat
                    cout<< 0 <<" ";
               }
               
          }
          cout<<endl;
     }
     return 0;
}