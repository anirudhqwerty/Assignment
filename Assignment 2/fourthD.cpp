#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;
    cin.ignore(); 

    string arr[n];
    cout << "Enter strings: "<<endl;
    for (int i = 0; i < n; i++) {
        getline(cin, arr[i]);
    }

    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = i + 1; j < n; j++) 
        {
            if (arr[i] > arr[j]) 
            {
                string temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    cout<<endl;

    cout << "Strings in alphabetical order: "<<endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }

    return 0;
}
