#include <iostream>

using namespace std;

int main() {
    string str;
    getline(cin, str);
    int count = 0;
    for (const char &c: str) {
        if (c >= '0' && c <= '9') {
            ++count;
        }
    }
    int oldLength = str.length();
    str.resize(str.length() + 5 * count);
    for (int i = oldLength - 1, j = str.length() - 1; i >= 0; --i) {
        if (str[i] >= '0' && str[i] <= '9') {
            str.replace(j - 5, 6, "number");
            j -= 6;
        } else {
            str[j] = str[i];
            --j;
        }
    }
    cout << str << endl;
    return 0;
}
