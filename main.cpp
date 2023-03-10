//
// Created by avmd on 08.03.23.
//

#include <string>
#include <iostream>
#include <regex>

using namespace std;

vector<vector<string>> testCases = {
        {"k*t",        "kat",                      "YES"},
        {"k*t",        "kt",                       "YES"},
        {"k*t",        "ktt",                      "YES"},
        {"k*t",        "kfjdslk.fjdsalaffdfdat",   "YES"},
        {"k*",         "kfjdslkfjdsalaffd.fdat",   "YES"},
        {"k*",         "k",                        "YES"},
        {"k*",         "kkkkkk",                   "YES"},
        {"*",          "",                         "YES"},
        {"*",          "qewrtersvcsdfsd",          "YES"},
        {"*",          "a",                        "YES"},
        {"*",          ".",                        "YES"},
        {"k*",         "a",                        "NO"},
        {"k*",         ".",                        "NO"},
        {"k*",         "",                         "NO"},
        {"*t",         "",                         "NO"},
        {"*t",         "at",                       "YES"},
        {"*t",         "aa",                       "NO"},
        {"*t",         "aaaaaaat",                 "YES"},
        {"*t",         "t",                        "YES"},
        {"*t",         "tttttttt",                 "YES"},
        {"t",          "tttttttt",                 "NO"},
        {"t",          "t",                        "YES"},
        {"tfdfsdfds.", "tfdfsdfds.",               "YES"},
        {"ttttt",      "t",                        "NO"},
        {"",           "",                         "YES"},
        {"",           "q",                        "NO"},
        {"",           "qvcfddsfdsgds",            "NO"},
        {"",           "qvcfddsfdsgds",            "NO"},
        {"f",          "",                         "NO"},
        {"ffdfdsfsf",  "",                         "NO"},
        {"?",          "",                         "NO"},
        {"?",          "a",                        "YES"},
        {"?a",         "a",                        "NO"},
        {"?a",         "",                         "NO"},
        {"?a",         "aa",                       "YES"},
        {"?aaa",       "aa",                       "NO"},
        {"?aaa",       "aaa",                      "NO"},
        {"?aaa",       "aaaa",                     "YES"},
        {"?aaa",       "baaa",                     "YES"},
        {"a?a",        "aaaa",                     "NO"},
        {"a?a",        "aaa",                      "YES"},
        {"a?a",        "aba",                      "YES"},
        {"a?a",        "aa",                       "NO"},
        {"a?a",        "aab",                      "NO"},
        {"a?a",        "",                         "NO"},
        {"a?",         "",                         "NO"},
        {"a?",         "a",                        "NO"},
        {"a?",         "aa",                       "YES"},
        {"a?",         "ab",                       "YES"},
        {"a?",         "",                         "NO"},
        {"a?",         "afkjfghfgjkhfkjdshfsdfds", "NO"},
        {"a?",         "afkjfghfgjkhfkjdshfsdfds", "NO"},
        {"a?",         "aaa",                      "NO"},
        {"a?",         "abb",                      "NO"},
};


string isValidMessage(string messageTemplate, string message) {
    if (messageTemplate == "") {
        if (message == "") {
            return "YES";
        } else {
            return "NO";
        }

    } else {
        if (message == "" && messageTemplate != "*") {
            return "NO";
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
                    return "YES";
                }

                char nextTemplateSymb = messageTemplate[tempIdx + 1];

                while (message[messageIdx] != nextTemplateSymb && messageIdx < message.size()) {
                    messageIdx++;
                }

                messageStartIdx = messageIdx;
                currentMessageSymb = message[messageIdx];
                currentTemplateSymb = messageTemplate[tempIdx + 1];
            } else if (currentTemplateSymb == '?') {
                if (tempIdx == messageTemplate.size() - 1 &&
                    messageIdx != message.size() - 1) {
                    return "NO";
                }
                messageStartIdx = messageIdx + 1;

                break;
            }

            if (currentTemplateSymb != currentMessageSymb) {
                return "NO";
            } else {
                messageStartIdx += 1;
                break;
            }
        }
    }

    return "YES";
}


string isValidMessageNextGen(string messageTemplate, string message) {
    if (messageTemplate == "") {
        if (message == "") {
            return "YES";
        } else {
            return "NO";
        }

    } else {
        if (message == "" && messageTemplate != "*") {
            return "NO";
        }
        if (messageTemplate == "*") {
            return "YES";
        }
    }

    int templateIdx = 0;
    int messageIdx = 0;
    for (; messageIdx < message.size(); ++messageIdx) {
        while (messageIdx < message.size() && templateIdx < messageTemplate.size() &&
               messageTemplate[messageIdx] == message[messageIdx]) {
            ++messageIdx;
            ++templateIdx;
        }

        if (messageIdx == message.size() &&
            templateIdx == messageTemplate.size()) {
            return "YES";
        }

        if (message.size() - messageIdx - 1 > 1) {
            if (messageTemplate[templateIdx] == '*') {
                return "YES";
            }

            return "NO";
        }

        if (messageTemplate[templateIdx] == '*') {
            if (templateIdx == messageTemplate.size() - 1) {
                return "YES";
            }

            char nextTemplateSymb = messageTemplate[templateIdx + 1];

            while (message[messageIdx] != nextTemplateSymb &&
                   messageIdx < message.size()) {
                ++messageIdx;
            }
        } else if (messageTemplate[templateIdx] == '?') {
            ++messageIdx;
            ++templateIdx;

            bool isLastSymb = messageIdx == message.size() - 1;
            bool isTemplateLastSymb = templateIdx == messageTemplate.size() - 1;

            if (isLastSymb) {
                if (!isTemplateLastSymb &&
                    messageTemplate[templateIdx + 1] != '*') {
                    return "NO";
                } else {
                    return "YES";
                }
            }
        }
    }

    if (messageIdx >= message.size()) {
        return "YES";
    }

    return "NO";
}

string
isValid3Gen(string templateMessage, string message) {
    if (templateMessage == "") {
        if (message == "") {
            return "YES";
        }

        return "NO";
    }

    if (templateMessage == "*") {
        return "YES";
    }

    if (message == "" && templateMessage != "*") {
        return "NO";
    }

    if (templateMessage.size() == 2 &&
        templateMessage[0] == '*' &&
        templateMessage[1] == message[message.size() - 1]) {
        return "YES";
    }

    int templateSymbolsChecked = 0;
    int validSymbolsAmount = 0;
    int messageIdx = 0;
    for (int idx = 0; idx < templateMessage.size(); ++idx, ++messageIdx) {
        char templateSymb = templateMessage[idx];

        if (idx == message.size()) {
            if (templateSymb == '*') {
                templateSymbolsChecked = templateMessage.size();
            }

            break;
        }

        ++templateSymbolsChecked;

        if (templateSymb == message[messageIdx]) {
            ++validSymbolsAmount;
        } else {
            if (templateSymb == '?' && idx < message.size()) {
                ++validSymbolsAmount;
                continue;
            }

            if (templateSymb == '*') {
                if (idx == templateMessage.size() - 1) {
                    validSymbolsAmount = message.size();
                    break;
                }

                char nextTemplateSymb = templateMessage[idx + 1];
                bool isSymbFound = false;
                for (messageIdx = message.size() - 1; messageIdx >= idx; --messageIdx) {
                    if (message[messageIdx] == nextTemplateSymb) {
                        isSymbFound = true;

                        ++templateSymbolsChecked;
                        validSymbolsAmount += messageIdx - idx;

                        --messageIdx;

                        break;
                    }
                }

                if (!isSymbFound) {
                    break;
                }
            }
        }

    }

    return validSymbolsAmount == message.size() &&
           templateSymbolsChecked == templateMessage.size() ? "YES" : "NO";
}

string isValid4Gen(string templateMessage, string message) {
    deque<char> tmpltQ;
    deque<char> msgQ;

    for (auto c: templateMessage) {
        tmpltQ.push_back(c);
    }

    for (auto c: message) {
        msgQ.push_back(c);
    }

    while (!tmpltQ.empty() && !msgQ.empty()) {
        char templateSymb = (char) tmpltQ.front();
        char messageSymb = (char) message.front();

        if (messageSymb == templateSymb || templateSymb == '?') {
            tmpltQ.pop_front();
            msgQ.pop_front();
        } else if (templateSymb == '*') {
            tmpltQ.pop_front();

            if (tmpltQ.empty()) {
                return "YES";
            }

            char templateNextSymb = tmpltQ.front();

            while (!msgQ.empty()) {
                if (msgQ.front() == templateNextSymb) {
                    msgQ.pop_front();
                    tmpltQ.pop_front();
                    break;
                }

                msgQ.pop_front();
            }

            if (msgQ.front() != templateNextSymb) {
                return "NO";
            }
        } else {
            return "NO";
        }
    }

    return tmpltQ.empty() && msgQ.empty()
           ? "YES" : "NO";
}

void taskTemplates() {
    string messageTemplate;
    string message;

    getline(cin, messageTemplate);
    getline(cin, message);

    cout << isValidMessage(messageTemplate, message);
}


void testIsValidMessage() {
    vector<vector<string>> invalidTestCases;

    for (auto &testCase: testCases) {
        string result = isValid4Gen(testCase[0], testCase[1]);

        if (result != testCase[2]) {
            invalidTestCases.push_back(testCase);
        }
    }

    if (!invalidTestCases.empty()) {
        cout << testCases.size() - invalidTestCases.size() << "/" << testCases.size() << " test passed\n";

        for (auto &testCase: invalidTestCases) {
            cout << testCase[0] << " | " << testCase[1] << " | " << testCase[2] << endl;
        }
    }
}

int main() {
//    while (true) {
//        taskTemplates();
//        cout << "\n---\n";
//    }

    testIsValidMessage();

    return 0;
}