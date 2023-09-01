#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

struct StringInfo {
    string str;
    int length;

    StringInfo(string s, int len) : str(s), length(len) {}
};

bool compareStrings(const StringInfo &a, const StringInfo &b) {
    if (a.length == b.length) {
        return false; // Maintain original order for equal length strings
    }
    return a.length < b.length;
}

int main() {
    int N;
    cin >> N;
    cin.ignore(); // Consume newline character

    for (int i = 0; i < N; i++) {
        string input;
        getline(cin, input);

        int maxWords = 50; // Maximum number of words
        StringInfo strings[maxWords];

        istringstream iss(input);

        string word;
        int wordCount = 0;
        while (iss >> word && wordCount < maxWords) {
            strings[wordCount++] = StringInfo(word, word.length());
        }

        stable_sort(strings, strings + wordCount, compareStrings);

        for (int j = 0; j < wordCount; j++) {
            cout << strings[j].str;
            if (j != wordCount - 1) {
                cout << " ";
            }
        }

        cout << endl;
    }

    return 0;
}
