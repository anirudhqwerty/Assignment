#include<bits/stdc++.h>
using namespace std;

// Concept of Inversion
// when i<j Arr[i] > arr[j] => this here is called inversion0

int inversions(vector<int> arr){
     int n = arr.size();
     int inversionCount = 0;

     for(int i = 0; i<n-1 ; i++){

          for(int j= i+1;j<n;j++){
     // Check if pair (i,j) is out of Order

               if(arr[i]>arr[j]){
                    inversionCount++;
               }
          }
     }

     return inversionCount;
}

int main(){
    vector<int> arr1 = {2, 4, 1, 3, 5}; // Inversions: (2,1), (4,1), (4,3) -> 3
    vector<int> arr2 = {5, 4, 3, 2, 1}; // Worst case: 10 inversions

    cout << "Inversions in [2, 4, 1, 3, 5]: " << inversions(arr1) << endl;
    cout << "Inversions in [5, 4, 3, 2, 1]: " << inversions(arr2) << endl;

}