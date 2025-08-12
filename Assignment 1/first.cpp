#include <iostream>
using namespace std;

int arr[100];
int n=0;

void create(){
    cout<<"Enter the number of the elements: "<<endl;
    cin>>n;
    cout<<"Enter the elements: "<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
}

void display(){
    cout<<"The elements are :"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";

    }
    cout<<endl;
    
}


void insert(){
    int pos , val;
    cout<<"Enter the value and the position to insert the element at: "<<endl;
    cin>>val>>pos;
    
    for (int i = n; i>pos; i--)
    {
        arr[i] = arr[i-1];

    }

    arr[pos-1] = val;
    n++;
    
}


void del(){
    int pos;
    cout<<"Enter the position to delete: "<<endl;
    cin>>pos;
    for (int i = pos-1; i < n -1; i++)
    {
        arr[i]=arr[i+1];
    }
    n--;
    
}

void search(){
    int key;
    bool found = false;
    cout<<"Enter the element to search: "<<endl;
    cin>>key;
    for (int i = 0; i < n; i++)
    {
        if(arr[i]==key){
            cout<<"Element found at the position "<< i+1 <<endl;
            found=true;
        }
    }

    if(!found){
        cout<<"element not found"<<endl;
    }
}

int main() {
    int choice;
    do{
        cout<<"-- MENU --"<<endl;
        cout<<"1. Create"<<endl;
        cout<<"2. Display"<<endl;
        cout<<"3. Insert"<<endl;
        cout<<"4. Delete"<<endl;
        cout<<"5. Search"<<endl;
        cout<<"6. EXIT"<<endl;
        cout<<"Enter your choice: "<<endl;
        cin>>choice;

        switch(choice){
            case 1: create(); break;
            case 2: display(); break;
            case 3: insert(); break;
            case 4: del(); break;
            case 5: search(); break;
            case 6: cout << "Good Bye!!"<<endl; break;
            default: cout << "Invalid choice!"; 

        }

    }
    while(choice!=6);
    return 0;
}