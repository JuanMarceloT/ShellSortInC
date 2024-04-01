#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <ctime>
#include <algorithm>
#include <chrono>
#include <random>

void printArrGap(const std::vector<int> &arr, int gap)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (i % gap == 0)
            std::cout << " " << arr[i] << " ";
        else
            std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void printArr(const std::vector<int> &arr)
{
    std::cout << " ";
    for (int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void InsertionSort(std::vector<int> &arr, int gap, int n, int start)
{
    for (int i = start; i < n; i += gap)
    {
        int key = arr[i];
        int j = i - gap;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + gap] = arr[j];
            j -= gap;
        }
        arr[j + gap] = key;
    }
}

void ShellSorts(std::vector<int> &arr, std::vector<int> gaps)
{
    int n = arr.size();
    for (auto gap : gaps)
    {
        // printArrGap(arr, gap);
        for (int i = 0; i < gap; i++)
        {
            InsertionSort(arr, gap, n, i);
        }
    }
    // printArr(arr);
}

bool VerifySort(std::vector<int> &arr)
{
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i - 1] > arr[i]){
            std::cout<<"Error Sorting"<<std::endl;
            return false;
        }
    }
    return true;
}

// Shell sequence
std::vector<int> ShellGaps(int n)
{
    std::vector<int> gaps;
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        gaps.push_back(gap);
    }
    return gaps;
}

// Ciura gap sequence
std::vector<int> CiuraGaps(int n)
{
    std::vector<int> gaps = {1035711, 460316, 204585, 90927, 40412, 17961, 7983, 3548, 1577, 701, 301, 132, 57, 23, 10, 4, 1};
    while (gaps.back() >= n)
    {
        gaps.pop_back();
    }
    return gaps;
}

// Knuth gap sequence
std::vector<int> KnuthGaps(int n)
{
    std::vector<int> gaps;
    int gap = 1;
    while (gap < n)
    {
        gaps.push_back(gap);
        gap = 3 * gap + 1;
    }

    if (!gaps.empty())
    {
        std::reverse(gaps.begin(), gaps.end());
    }

    return gaps;
}

int main()
{
    std::ifstream file("entrada2.txt");
    std::string line;

    // reading file
    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::vector<std::string> tokens;
        std::string token;

        while (iss >> token)
        {
            tokens.push_back(token);
        }
        int size = std::stoi(tokens[0]);

        std::vector<int> numbers;
        for (size_t i = 1; i < tokens.size(); ++i)
        {
            numbers.push_back(std::stoi(tokens[i]));
        }

        // Shell gap sequence

        std::vector<int> shellTest(numbers);

        auto startShell = std::chrono::steady_clock::now();
        ShellSorts(shellTest, ShellGaps(shellTest.size()));
        auto endShell = std::chrono::steady_clock::now();

        // Ciura gap sequence

        std::vector<int> CiuraTest(numbers);

        auto startCiura = std::chrono::steady_clock::now();
        ShellSorts(CiuraTest, CiuraGaps(CiuraTest.size()));
        auto endCiura = std::chrono::steady_clock::now();

        // Knuth gap sequence

        std::vector<int> KnuthTest(numbers);
        auto startKnuth = std::chrono::steady_clock::now();
        ShellSorts(KnuthTest, KnuthGaps(KnuthTest.size()));
        auto endKnuth = std::chrono::steady_clock::now();


        // Verify Sort
        VerifySort(shellTest);
        VerifySort(CiuraTest);
        VerifySort(KnuthTest);
        

        // Print the execution times
        std::cout << "Sorting " << numbers.size() << std::endl;
        std::cout << "Shell Sort time: "
                  << std::chrono::duration_cast<std::chrono::nanoseconds>(endShell - startShell).count() / 1000000.0
                  << " milliseconds" << std::endl;
        std::cout << "Ciura Sort time: "
                  << std::chrono::duration_cast<std::chrono::nanoseconds>(endCiura - startCiura).count() / 1000000.0
                  << " milliseconds" << std::endl;
        std::cout << "Knuth Sort time: "
                  << std::chrono::duration_cast<std::chrono::nanoseconds>(endKnuth - startKnuth).count() / 1000000.0
                  << " milliseconds" << std::endl;
    }

    return 0;
}
