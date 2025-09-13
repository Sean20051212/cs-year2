#include <iostream>
#include <cstring>   // strcpy, strlen
#include <cstdlib>   // malloc, free
using namespace std;

void bubblesort (char* namelist[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            char last1 = namelist[j][strlen(namelist[j]) - 1]; // 取最後一個字元(扣除'\0')
            char last2 = namelist[j + 1][strlen(namelist[j + 1]) - 1]; // 取最後一個字元(扣除'\0')

            if (last1 > last2) { 
                char* temp = namelist[j];
                namelist[j] = namelist[j + 1];
                namelist[j + 1] = temp;
            }
        }
    }

}

int main() {
    cout << "目前使用malloc/free來分配/釋放記憶體空間\n";
    int n , m;
    cout << "輸入學生總人數: ";
    cin >> n;
    cout << "輸入姓名最大長度: ";
    cin >> m;

    char** namelist1 = (char**)malloc(n * sizeof(char*)); // 分配二維陣列的記憶體

    for (int i = 0; i < n; i++) {
        namelist1[i] = (char*)malloc((m + 1) * sizeof(char)); // 分配每個姓名的記憶體
        cin >> namelist1[i];
    }

    bubblesort(namelist1, n);

    cout << "\n依據姓名最後一個字元排序後的結果:\n";
    for (int i = 0; i < n; i++) {
        cout << namelist1[i] << endl;
        free(namelist1[i]); // 釋放每個姓名的記憶體
    }

    free(namelist1); // 釋放指標陣列的記憶體

    cout << "目前使用new/delete來分配/釋放記憶體空間\n";
    cout << "輸入學生總人數: ";
    cin >> n;
    cout << "輸入姓名最大長度: ";
    cin >> m;

    char** namelist2 = new char*[n]; // 使用new分配指標陣列的記憶體
    for (int i = 0; i < n; i++) {
        namelist2[i] = new char[m + 1]; // 使用new分配每個姓名的記憶體
        cin >> namelist2[i];
    }

    bubblesort(namelist2, n);

    cout << "\n依據姓名最後一個字元排序後的結果:\n";
    for (int i = 0; i < n; i++) {
        cout << namelist2[i] << endl;
        delete[] namelist2[i]; // 使用delete釋放每個姓名的記憶體
    }

    delete[] namelist2; // 使用delete釋放指標陣列的記憶體



    return 0;
}
