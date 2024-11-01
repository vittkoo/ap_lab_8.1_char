#define _CRT_SECURE_NO_WARNINGS 
#include <iostream> 
#include <cstring>

using namespace std;

int Count(char* s) {
    int k = 0;
    char* t;
    int pos = 0;

    while (t = strstr(s + pos, "while")) {
        k++;
        pos = t - s + 5; // зсув на довжину "while"
    }

    return k;
}

char* Change(char* s) {
    char* t = new char[strlen(s) * 2 + 1];
    char* p;
    int pos1 = 0;
    *t = 0;

    while (p = strstr(s + pos1, "while")) {
        strncat(t, s + pos1, p - s - pos1); // копіюємо частину до заміни
        strcat(t, "***"); // додаємо заміну
        pos1 = p - s + 5; // зсув на довжину "while"
    }
    strcat(t, s + pos1); // додаємо залишок рядка

    strcpy(s, t); // копіюємо змінений рядок назад

    return t;
}

int main() {
    char str[101];

    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    cout << "String contained " << Count(str) << " occurrences of \"while\"" << endl;

    char* ModifiedStr = Change(str);

    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << ModifiedStr << endl;

    delete[] ModifiedStr;
    return 0;
}
