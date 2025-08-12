#include <iostream>
#include <algorithm>
using namespace std;

int binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target){
             return mid;
        }
        else if (arr[mid] > target) {
            right = mid - 1;
        }
        else{
            left = mid + 1;
        } 
    }
    return -1;
}

int main() {
    int arr[100],size;
    cout<<"What is the size of the array? "<<endl;
    cin>>size;
    cout<<"What are the elements of the array?"<<endl;
    for (int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }

    sort(arr, arr + size);
    
    int target;
    cout << "What element do you want to find? "<<endl;
    cin >> target;
    int index = binarySearch(arr, size, target);
    if (index != -1) cout << "Found at index " << index <<" after sorting"<< endl;
    else cout << "Not found" << endl;
}
