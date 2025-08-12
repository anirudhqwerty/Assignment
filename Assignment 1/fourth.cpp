#include <iostream>
using namespace std;

void reverseArray(int arr[] , int n){
    for (int i = 0; i < n/2; i++)
    {
        int temp =  arr[i];
        arr[i] =  arr[n-i-1];
        arr[n-i-1]=temp;
    }
    cout<<"Array after reversing "<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";

    }
    cout<<endl;
}


void multiplyMatrices(int A[10][10], int B[10][10], int C[10][10], int r1, int c1, int r2, int c2){
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            C[i][j]=0;
        }
        
    }

    for (int i = 0; i < r1; i++) 
    {
        for (int j = 0; j < c2; j++) 
        {
            for (int k = 0; k < c1; k++) 
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    
    
}


void transposeMatrix(int mat[10][10], int rows, int cols, int trans[10][10]){
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            trans[j][i] = mat[i][j];
        }
    }
}


int main() {
    int arr[100],n;
    
    cout<<"Enter the number of the elements: "<<endl;
    cin>>n;
    cout<<"Enter the elements: "<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    reverseArray(arr,n);
    
    int r1,c1,r2,c2;
    cout<<"Enter the rows and columns of first matrix: "<<endl;
    cin>>r1>>c1;
    cout<<"Enter the rows and columns of second martix: "<<endl;
    cin>>r2>>c2;

    int A[10][10], B[10][10], C[10][10];
    cout<< "Enter the first matrix: "<<endl;
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            cin >> A[i][j];

    cout<<"Enter the second matrix: "<<endl;
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            cin >> B[i][j];

    multiplyMatrices(A,B,C,r1,c1,r2,c2);

    cout << "Multiplied Matrix: "<<endl;
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    int trans[10][10];
    transposeMatrix(A,r1,c1,trans);
    cout<<"Transpose of the first matrix"<<endl;
    for (int i = 0; i < c1; i++) {
        for (int j = 0; j < r1; j++) {
            cout << trans[i][j] << " ";
        }
        cout << endl;
    }

  
    return 0;
}