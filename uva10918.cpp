#include <iostream>
using std::cout;
using std::cin;

int main() {
    int* f = new int[31] {0};
    int* g = new int[31] {0};
    f[0] = 1; g[1] = 1;
    for (int i = 2; i < 31; i++) {
        f[i] = f[i - 2] + 2 * g[i - 1];
        g[i] = f[i - 1] + g[i - 2];
    }

    delete g;

    // n介於0到30之間(含)
    int n;
    while (cin >> n) {
        if (n == -1) {
            break;
        }

        cout << f[n] << "\n";

    }

    delete f;

    return 0;
}

