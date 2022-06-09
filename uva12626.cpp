#include <iostream>
#include <string.h>
#include <algorithm>
using std::cout;
using std::cin;
using std::string;

int main() {
    int testcase;
    cin >> testcase;
    while (testcase--) {
        string pizza;
        cin >> pizza;
        int* ingredient = new int[6] {0}; // M, A, R, G, I, T

        for (int i = 0; i < pizza.length(); i++) {
            switch (pizza.at(i)) {
                case 'M':
                    ingredient[0]++;
                    break;
                case 'A':
                    ingredient[1]++;
                    break;
                case 'R':
                    ingredient[2]++;
                    break;
                case 'G':
                    ingredient[3]++;
                    break;
                case 'I':
                    ingredient[4]++;
                    break;
                case 'T':
                    ingredient[5]++;
                    break;
            }
        }

        ingredient[1] /= 3;
        ingredient[2] /= 2;

        cout << *std::min_element(ingredient, ingredient + 6) << "\n";

        delete ingredient;
    }

    return 0;
}