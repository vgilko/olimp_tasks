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

    getline(cin, messageTemplate);
    getline(cin, message);

    string newTemplate;

    if (messageTemplate == "") {
        if (message == "") {
            cout << "YES";
        } else {
            cout << "NO";
        }

        return;
    } else {
        if (message == "" && messageTemplate != "*") {
            cout << "NO";

            return;
        }
    }

    int messageStartIdx = 0;
    for (int tempIdx = 0; tempIdx < messageTemplate.size(); tempIdx++) {
        char currentTemplateSymb = messageTemplate[tempIdx];

        for (int messageIdx = messageStartIdx; messageIdx < message.size(); messageIdx++) {
            char currentMessageSymb = message[messageIdx];

            if (currentTemplateSymb == '*') {
                // если конец слова
                if (tempIdx == messageTemplate.size() - 1) {
                    cout << "YES";
                    return;
                }

                char nextTemplateSymb = messageTemplate[tempIdx + 1];

                while (message[messageIdx] != nextTemplateSymb && messageIdx < message.size()) {
                    messageIdx++;
                }

                messageStartIdx = messageIdx;
                currentMessageSymb = message[messageIdx];
                currentTemplateSymb = messageTemplate[tempIdx + 1];
            } else if (currentTemplateSymb == '?') {
                messageStartIdx = messageIdx + 1;

                break;
            }

            if (currentTemplateSymb != currentMessageSymb) {
                cout << "NO";
                return;
            } else {
                messageStartIdx += 1;
                break;
            }
        }


    }

    cout << "YES";
}


int main() {
    while (true) {
        taskTemplates();
        cout << "\n---\n";
    }

    return 0;
}