#include <iostream>
using namespace std;

void printArr(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void shellsortAdd(int x[], int n, int h, int initial) {
    for (int i = initial; i < n; i += h) {
        for (int j = i - h; j >= 0; j -= h) {
            if (x[j + h] < x[j]) {
                int temp = x[j + h];
                x[j + h] = x[j];
                x[j] = temp;
            }
        }
    }
}


int GetMaxNumberLessThan(int arr[], int x){
    int i = 0;
    while (true) {
        if (arr[i] > x) {
            return i - 1;
        }
        i++;
    }
}



bool VerifySort(int arr[], int size){
    for(int i = 1;i < size;i++){
        if(arr[i] < arr[i - 1])
            return false;
    }

    return true;
}

void ShellSort(int x[], int size){
    
    int shell[] = {1, 2, 4, 8, 16, 32, 64, 128, 256};

    printArr(x, size);
    
    int index = GetMaxNumberLessThan(shell, size);
    int i = 0;
    do {
        shellsortAdd(x, size, shell[index], i);
        i++;
        index--;
    } while (index >= 0);

    if(VerifySort(x, size))
        printArr(x, size);
    else
        std::cout<<"Sort ERROR";
}

int main() {
    int shell[] = {1, 2, 4, 8, 16, 32, 64, 128, 256};
    int x[] = {1, 3, 5, 2, 1, 2, 6, 2, 5, 8, 1, 5, 6, 2, 45, 62, 4, 6, 2, 3, 6, 2, 3, 4, 6, 7, 3, 56, 22, 4, 234, 2};
    int size = sizeof(x) / sizeof(x[0]);    

    ShellSort(x,size);



    return 0;
}
