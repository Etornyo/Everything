#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;

    map<string, int> phoneBook;
    for (int i = 0; i < n; i++) {
        string name;
        int phoneNumber;
        cin >> name >> phoneNumber;
        phoneBook[name] = phoneNumber;
    }

    string query;
    while (cin >> query) {
        if (phoneBook.find(query) != phoneBook.end()) {
            cout << query << "=" << phoneBook[query] << endl;
        } else {
            cout << "Not found" << endl;
        }
    }
   
    return 0;
}

