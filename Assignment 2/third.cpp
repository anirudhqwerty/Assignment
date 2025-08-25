#include<bits/stdc++.h>
using namespace std;

int missingNumber (vector<int> arr){
     int n = arr.size();
     int sum = (n*(n+1))/2;
     int sumOfArrayElements = 0;
     for(int i = 0 ; i < n ; i++){
          sumOfArrayElements += arr[i];
     }
     return sum - sumOfArrayElements;
}

int main(){

     vector<int> arr = {0,1,2,5,4};
     int missingNum = missingNumber(arr);
     cout<<"The Number missing is:  "<<missingNum;
     return 0;

     
}