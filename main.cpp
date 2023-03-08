//
// Created by avmd on 08.03.23.
//

#include <string>
#include <iostream>
#include <regex>

using namespace std;

void taskTemplates() {
    string messageTemplate;
    string message;

    cin >> messageTemplate;
    cin >> message;

    string newTemplate;

    for (auto symb: messageTemplate) {
        if (symb == '?') {
            newTemplate.append("([a-z]|\\.){1}");
        } else if (symb == '*') {
            newTemplate.append("([a-z]|\\.)+");
        } else {
            newTemplate.push_back(symb);
        }
    }

    bool isFound = regex_search(message, std::regex(newTemplate));

    cout << (isFound ? "YES" : "NO");
}


int main() {
    taskTemplates();

    return 0;
}