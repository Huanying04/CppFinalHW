#include <iostream>
#include <string.h>
#include <math.h>
using std::cout;
using std::cin;
using std::string;

int hexToDec(string hex) {
    int sum = 0;
    for (int i = hex.length() - 1; i >= 0; i--) {
        char ch = hex[i];
        if ('0' <= ch && ch <= '9') {
            sum += (ch - '0') * std::pow(16, hex.length() - i - 1);
        }else {
            sum += (ch - 'A') * std::pow(16, hex.length() - i - 1);
        }
    }
    return sum;
}

string decToHex(int dec) {
    if (dec == 0) return "0x0";
    char digits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    string hex;
    while (dec != 0) {
        hex = (digits[dec % 16]) + hex;
        dec /= 16;
    }
    return string("0x").append(hex);
}

int main() {
    string str;
    while (cin >> str) {
        if (str[0] == '-')
            break;
        if (str.rfind("0x", 0) == 0) {
            // 轉換base 16 -> base 10
            cout << hexToDec(str.substr(2, str.length())) << "\n";
            continue;
        }
        // 轉換 base 10 -> base 16
        cout << decToHex(atoi(str.c_str())) << "\n";
    }

    return 0;
}
