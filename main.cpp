#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <ctime>

void printArr(const std::vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void shellsortAdd(std::vector<int>& x, int h, int initial, int size) {
    for (int i = initial; i < size; i += h) {
        for (int j = i - h; j >= 0; j -= h) {
            if (x[j + h] < x[j]) {
                int temp = x[j + h];
                x[j + h] = x[j];
                x[j] = temp;
            }
        }
    }
}

int GetMaxNumberLessThan(std::vector<int>& arr, int x) {
    int i = 0;
    while (true) {
        if (arr[i] > x) {
            return i - 1;
        }
        i++;
    }
}

bool VerifySort(std::vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

void ShellSort(std::vector<int>& x) {
    std::vector<int> shell = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824};

    int size = x.size();

    int index = GetMaxNumberLessThan(shell, size);
    int i = 0;

    // Start measuring time
    clock_t begin = clock();

    do {
        shellsortAdd(x, shell[index], i, size);
        i++;
        index--;
    } while (index >= 0);

    // Stop measuring time and calculate the elapsed time
    clock_t end = clock();
    double elapsed = double(end - begin) / CLOCKS_PER_SEC;

    if (VerifySort(x))
        std::cout << "To sort " << size << " elements, take " << elapsed << " seconds" << std::endl;
    else
        std::cout << "Sort ERROR" << std::endl;
}

int main() {
    std::ifstream file("entrada2.txt");
    std::string line;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::vector<std::string> tokens;
        std::string token;

        // Read tokens and store them in a vector
        while (iss >> token) {
            tokens.push_back(token);
        }
        int size = std::stoi(tokens[0]);

        // Process tokens and convert to integers
        std::vector<int> numbers;
        for (size_t i = 1; i < tokens.size(); ++i) {
            numbers.push_back(std::stoi(tokens[i]));
        }

        ShellSort(numbers);
    }

    return 0;
}
