#include <iostream>
using namespace std;

int main() {
    int r,c;
    int arr[100][100];
    cout<<"Enter the number of rows and columns: "<<endl;
    cin>>r>>c;
    cout<<"Enter the elements: "<<endl;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin>>arr[i][j];

        }
        
    }
    

    cout<<"Sum of each row: "<<endl;
    for (int i = 0; i < r; i++)
    {
        int sum=0;
        for (int j = 0; j < c; j++)
        {
            sum=sum+arr[i][j];
        }
        cout<<"row "<<i+1<<": "<<sum<<endl;

    }
    

    cout<<"Sum of each column "<<endl;
    for (int j = 0; j < c; j++)
    {
        int sum=0;
        for (int i = 0; i < r; i++)
        {
            sum=sum+arr[i][j];
        }
        cout<<"column "<<j+1<<": "<<sum<<endl;

    }


    return 0;
}