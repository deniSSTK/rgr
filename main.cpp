/**
* Done by:
 * Student Name: Denis Tkachenko
 * Student Group: 121
 * RGR 2
 */

/*
TODO: Delete examples after testing
input\output examples:

Input: %13~ABC%
Valid

Input: %123-%A%
Valid

Input: %13ABC%
Invalid

Input: 13~ABC%
Invalid

Input: %13~ABC
Invalid
*/

#include <iostream>
#include <string>
using namespace std;

bool isValidL(const string& input) {
    int state = 0;
    for (size_t i = 0; i < input.length(); ++i) {
        char c = input[i];

        if (state == 0) {
            if (c == '%') {
                state = 1;
            } else {
                return false;
            }
        }
        else if (state == 1) {
            if (isdigit(c)) {
                state = 2;
            } else {
                return false;
            }
        }
        else if (state == 2) {
            if (isdigit(c)) {
                continue;
            } else if (c == '~' || c == '-' || c == '%') {
                state = 3;
            } else {
                return false;
            }
        }
        else if (state == 3) {
            if (isupper(c) && c >= 'A' && c <= 'Z') {
                state = 4;
            } else {
                return false;
            }
        }
        else if (state == 4) {
            if (isupper(c) && c >= 'A' && c <= 'Z') {
                continue;
            } else if (c == '%') {
                state = 5;
            } else {
                return false;
            }
        }
        else if (state == 5) {
            return false;
        }
    }
    return state == 5;
}

int main() {
    string input;
    cout << "Input: ";
    cin >> input;

    if (isValidL(input)) {
        cout << "Valid" << endl;
    } else {
        cout << "Invalid" << endl;
    }

    return 0;
}
