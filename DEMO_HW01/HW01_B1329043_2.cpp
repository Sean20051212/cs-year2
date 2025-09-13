#include <iostream>
#include <cstring>   // strcpy, strlen
#include <cstdlib>   // malloc, free
using namespace std;

int main() {
    int x , y = 0, z = 0;
    cout << "輸入學生總人數: ";
    cin >> x;
    cin.ignore(); // 忽略換行符號，不然getline會直接把換行符號當作名字輸入

    char** namelist = new char*[x]; // 使用new分配指標陣列的記憶體
    for (int i = 0; i < x; i++) {
        namelist[i] = new char[100]; // 使用new分配每個姓名的記憶體
    }

    // 輸入姓名
    for (int i = 0; i < x; i++) {
        cout << "輸入第 " << i + 1 << " 個學生姓名: ";
        cin.getline(namelist[i], 100); // 允許輸入有空格的名字
        if (strlen(namelist[i]) > y) {
            y = strlen(namelist[i]); // 找出最長的姓名長度
        }
        for (int j = 0; j < strlen(namelist[i]); j++) {
            if (namelist[i][j] == ' ' && j > z) {
                z = j; // 計算最遠的空格位置
                break;
            }
        }
    }

    // 動態宣告二維字元陣列
    char** arr = new char*[x]; // 使用new分配指標陣列的記憶體
    for (int i = 0; i < x; i++) {
        arr[i] = new char[y + 1];  // 使用new分配每個姓名的記憶體
        strcpy(arr[i], namelist[i]); // 複製姓名到新的二維陣列
    }

    delete[] namelist; // 釋放原本的指標陣列記憶體

    // 輸出
    cout << "\n輸出學生名單:\n";
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < strlen(arr[i]); j++) {
            if (arr[i][j] == ' ') {
                for (int k = 0; k < z-j; k++) cout << " ";
                continue; // 跳過本次，進下一個 j
            }
        }
        cout << arr[i] << endl;
    }

    // 釋放記憶體
    for (int i = 0; i < x; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
