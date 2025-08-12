#include <iostream>
using namespace std;

int main() {

    int arr[100],n;
    
    cout<<"Enter the number of the elements: "<<endl;
    cin>>n;
    cout<<"Enter the elements: "<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(arr[i]==arr[j]){
                for(int k=j;k<n-1;k++){
                    arr[k]=arr[k+1];
                }
                n--;
                j--;
            }
        }
        
    }

    cout<<"Array after removing duplicates: "<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";

    }
    cout<<endl;
    
    return 0;
}