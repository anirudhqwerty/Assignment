#include<bits/stdc++.h>
using namespace std;

int main(){

     int n;
     cout<<"Enter Value of N: ";
     cin>>n;
     int arr[(3*n)-2];
     cout<<"Enter Non Zero elements of Tridiagonal Matrix: "; 
     // n + n-1 + n-1 = 3*n - 2 elements
     for(int i =0 ;i<(3*n)-2;i++){
          cin>>arr[i];
     }

     for(int i =0 ;i<n;i++){
          for(int j=0;j<n;j++){
               if(i==j ){
                    cout << arr[i] <<" ";
               }
                    else if(abs(i-j)==1){
                         if(i>j){
                         //This is Lower DIAGONAL
                         cout<< arr[n+(i-1)] << " ";
                         }
                         else{
                              // THis is Upper Diagonal
                              cout<< arr[(2*n-1) + i] << " ";
                         }
                    
               }
               
               else {
                    cout<<0<<" ";
               }
          }
          cout<<endl;
     }
     return 0;
}
