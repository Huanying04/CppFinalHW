#include <iostream>
#include <math.h>
#include <algorithm>
using std::cout;
using std::cin;
using std::pow;

int sort(int* arr) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4 - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return 0;
}

int main() {
    int testcase;
    cin >> testcase;
    while (testcase) {
        int* edges = (int*) malloc(4 * sizeof(int));
        cin >> edges[0] >> edges[1] >> edges[2] >> edges[3];

        if (edges[0] == edges[1] && edges[1] == edges[2] && edges[2] == edges[3] && edges[3] == edges[0]) {
            cout << "square\n";
        }else if (edges[0] == edges[2] && edges[1] == edges[3]) {
            cout << "rectangle\n";
        }else if (sort(edges) || (edges[0] + edges[1] + edges[2] > edges[3])) {
            // 因為四邊形最長邊需小於其他三邊長度和，故先sort再比較
            // sort回傳值必為0 (false)
            cout << "quadrangle\n";
        }else {
            cout << "banana\n";
        }

        free(edges);

        testcase--;
    }

    return 0;
}