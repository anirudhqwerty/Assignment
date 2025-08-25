#include<bits/stdc++.h>
using namespace std;

int main(){

     int n;
     cout<<"Enter Value of N: ";
     cin>>n;
     int arr[n];
     cout<<"Enter Non Zero elements of Matrix: "; 
     for(int i =0 ;i<n;i++){
          cin>>arr[i];
     }

     for(int i =0 ;i<n;i++){
          for(int j=0;j<n;j++){
               if(i==j){
                    cout << arr[i] <<" ";
               }
               else {
                    cout<<0<<" ";
               }
          }
          cout<<endl;
     }
     return 0;
}