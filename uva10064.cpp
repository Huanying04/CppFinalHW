#include <iostream>
#include <algorithm>
#include <math.h>
using std::cout;
using std::cin;

int main() {
    int friendCount;
    while (cin >> friendCount) {
        if (friendCount == 0) {
            cout << "-1\n";
            continue;
        }

        int sum = 0;
        int* coordinates = new int[friendCount];
        for (int i = 0; i < friendCount; i++) {
            cin >> coordinates[i];
            sum += coordinates[i];
        }

        std::sort(coordinates, coordinates + friendCount);
        printf("%.2f %.2f\n", (float) sum / friendCount, (float) coordinates[(int) std::ceil(friendCount / 2.0) - 1]);

        delete coordinates;
    }

    return 0;
}