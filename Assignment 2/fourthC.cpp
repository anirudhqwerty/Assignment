#include <iostream>
using namespace std;

bool isVowel(char c){
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

int main() {
    string str , finalstr="";
    cout<<"Enter the string: "<<endl;
    getline(cin,str);

    for (int i = 0; str[i]!='\0'; i++)
    {
        if (!isVowel(str[i]))
        {
            finalstr = finalstr + str[i];
        }
        
    }
    
    cout<<"String without vowels :"<<finalstr<<endl;

    return 0;
}