#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cout << "Enter the string: ";
    getline(cin, str);

    int start = 0, end = str.length() - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }

    cout << "Reversed string:  " << str << endl;
}
