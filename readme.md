# 目錄
(按照題目順序排列)

* [uVA 10473](#uva-10473)
* [uVA 11455](#uva-11455)
* [uVA 12626](#uva-12626)
* [uVA 10064](#uva-10064)
* [uVA 10918](#uva-10918)

# uVA 10473
## 程式碼
[uva10473.cpp](https://github.com/Huanying04/CppFinalHW/blob/master/uva10473.cpp)
```cpp
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

```

## 解題心得


## 簡單說明
10進位數與16進位數的互相轉換，可輸入多行資料直到輸入負數則結束執行。<br>
在此程式中使用迴圈將使用者輸入接收為string類型，並確認第一個字元是否為負號。如是則跳出迴圈，如否則繼續執行程式。<br>
後續則檢測輸入是否以0x作開頭，來決定是要做16轉10還是10轉16的動作。


## 輸入測資畫面
![](https://github.com/Huanying04/CppFinalHW/blob/master/img/uva10473-1.PNG)


# uVA 11455
## 程式碼
[uva11455.cpp](https://github.com/Huanying04/CppFinalHW/blob/master/uva11455.cpp)
```cpp
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
```


## 解題心得
因為做了這個程式我才學會了四邊形的條件，感覺還滿值得的。

## 簡單說明
輸入四邊形四個邊的長度來檢測是屬於正方形、矩形、四邊形還是無法組成四邊形。<br>
四邊形的構成條件是四邊形最長邊需小於其他三邊長度和，如果不滿足則必不是四邊形。


## 輸入測資畫面
![](https://github.com/Huanying04/CppFinalHW/blob/master/img/uva11455-1.PNG)


# uVA 12626
## 程式碼
[uva12626.cpp](https://github.com/Huanying04/CppFinalHW/blob/master/uva12626.cpp)
```cpp
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
```

## 解題心得


## 簡單說明
輸入字串，檢測可以組成幾個MARGARITA<br>
只要簡單遍歷整個字串並統計M、A、R、G、I、T字母的數量就能得出結果了。


## 輸入測資畫面
![](https://github.com/Huanying04/CppFinalHW/blob/master/img/uva12626-1.PNG)


# uVA 10064
## 程式碼
[uva10064.cpp](https://github.com/Huanying04/CppFinalHW/blob/master/uva10064.cpp)
```cpp
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
```

## 解題心得
看不懂

## 簡單說明
雖然不知道為什麼，但是只要輸出輸入的若干數的平均值和中位數(可能不是這個名字，因為中位數如果是奇數的話是要取中間兩個值的平均，但這邊只要取中間比較小的那個就好)就好了

## 輸入測資畫面
![](https://github.com/Huanying04/CppFinalHW/blob/master/img/uva10064-1.PNG)<br>
![](https://github.com/Huanying04/CppFinalHW/blob/master/img/uva10064-2.PNG)<br>
(圖二的測資來自 https://www.udebug.com/UVa/10064 )



# uVA 10918
## 程式碼
[uva10918.cpp](https://github.com/Huanying04/CppFinalHW/blob/master/uva10918.cpp)
```cpp
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
```

## 解題心得
好難

## 簡單說明
3\*n的矩形中滿整2*1的矩形有幾種填法?<br>
設f(n)為填滿整個3\*n矩形的方法數，g(n)為填滿除了一個角落的3\*n矩形的方法數。
```
********   AA*******   AA******   A*******
******** = BB******* + B******* + A*******
********   CC*******   B*******   BB******
  f(n)   =  f(n-2)   +  g(n-1)  +  g(n-1)

********   A********   AA*******
******** = A******** + BB*******
 *******    ********    CC******
  g(n)   =   f(n-1)  +   g(n-2)
```
f(0)=1, f(1)=0, g(0)=0, f(1)=1<br>
當n為奇數時結果必為0


## 輸入測資畫面
![](https://github.com/Huanying04/CppFinalHW/blob/master/img/uva10918-1.PNG)


# 還沒做完……或許?