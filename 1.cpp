#include <iostream>
using namespace std;
class StringOperations {
private:
    string str;

public:
    StringOperations(string str) {
        this->str = str;
    }

    bool isEqual(string otherStr) {
        return str == otherStr;
    }

    string copyString() {
        return str;
    }

    string concatenate(string otherStr) {
        return str + otherStr;
    }

    friend ostream& operator<<(ostream& os, StringOperations& stringOps) {
        os << stringOps.str;
        return os;
    }

    string reverseString() {
        string reversedStr = "";
        for (int i = str.length() - 1; i >= 0; i--) {
            reversedStr += str[i];
        }
        return reversedStr;
    }

    bool isPalindrome() {
        string reversedStr = reverseString();
        return str == reversedStr;
    }
    int findSubString(string subStr) {
        int occurrences = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str.substr(i, subStr.length()) == subStr) {
                occurrences++;
            }
        }
        return occurrences;
    }
};

int main() {
    string str = "Hello, World!";
    StringOperations stringOps(str);

    // i. Equality
    bool isEqual = stringOps.isEqual("Hello, World!");
    cout << "Is the string equal to 'Hello, World!'? " << isEqual << endl;

    // ii. String Copy
    string copiedStr = stringOps.copyString();
    cout << "Copied string: " << copiedStr << endl;

    // iii. Concatenation
    string concatenatedStr = stringOps.concatenate("Welcome to C++ Programming!");
    cout << "Concatenated string: " << concatenatedStr << endl;

    // iv. << To display a string
    cout << stringOps << endl;

    // v. >> To reverse a string
    string reversedStr = stringOps.reverseString();
    cout << "Reversed string: " << reversedStr << endl;

    // vi. Function to determine whether a string is a palindrome
    bool isPalindrome = stringOps.isPalindrome();
    cout << "Is the string a palindrome? " << isPalindrome << endl;

    // Find occurrence of a sub-string: Use Operator Overloading
    string subStr = "llo";
    int occurrences = stringOps.findSubString(subStr);
    cout << "Number of occurrences of substring '" << subStr << "': " << occurrences << endl;
    return 0;}
