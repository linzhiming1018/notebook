#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int k;
    cin >> k;
    string str;
    cin >> str;
    reverse(str.begin(), str.end());
    reverse(str.begin(), str.begin() + k);
    reverse(str.begin() + k, str.end());
    cout << str << endl;
    return 0;
}
