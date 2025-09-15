#include <iostream>
#include <queue>
using namespace std;

void firstNonRepeating(string str) {
    queue<char> q;
    int freq[26] = {0};

    for (char c : str) {
        if (c == ' ') continue;
        freq[c - 'a']++;
        q.push(c);

        while (!q.empty() && freq[q.front() - 'a'] > 1) {
            q.pop();
        }

        if (!q.empty()) {
            cout << q.front() << " ";
        } else {
            cout << -1 << " ";
        }
    }
    cout << endl;
}

int main() {
    string str;
    cout << "Enter string: ";
    getline(cin, str);

    firstNonRepeating(str);

    return 0;
}
