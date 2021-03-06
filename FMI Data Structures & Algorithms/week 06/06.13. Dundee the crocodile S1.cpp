// github.com/andy489

// https://www.hackerrank.com/contests/sda-exam-27-01-19-/challenges/dundee-the-crocodile/problem

#include <iostream>
#include <sstream>
#include <set>

using namespace std;

int main() {
    multiset<string> words;
    int sentences(2);
    string sentence;

    while (sentences--) {
        getline(cin, sentence);
        istringstream istr(sentence);
        while (istr >> sentence) {
            words.insert(sentence);
        }
    }

    for (const auto &word : words) {
        int count = words.count(word);
        if (count == 1) cout << word << '\n';
    }

    return 0;
}
