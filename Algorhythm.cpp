#include <iostream>
#include <chrono>
using Comparison = bool (*)(int, int);

bool Ascending(int x, int y) 
{
    return x > y;
}

bool Descending(int x, int y)
{
    return x < y;
}
void Sort(int numbers[], int count, Comparison f)
{
    for (int i = 0; i < count; ++i)
    {
        for (int j = i + 1; j < count; ++j)
        {
            if (f(numbers[i], numbers[j]))
            {
                int temp;
                temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
        }
    }
}
void CountDownRecursive(int n)
{
    // base case
    if (n == 0)
    {
        std::cout << "fire!" << std::endl;
        return;
    }

    // recursive case
    std::cout << n << std::endl;
    CountDownRecursive(n - 2);
}
void Logarithmic(int n)
{
    size_t i = 0;
    while (n >= 1)
    {
        n /= 2;
        std::cout << ++i << std::endl;
    }
}
void Logarithmic2(int n)
{
    size_t count = 0;
    for (int i = 1; i <= n; i *= 2)
    {
        std::cout << ++count << std::endl;
    }
}
void LogarithmicRecursive(int n)
{
    if (n < 1)
    {
        return;
    }

    LogarithmicRecursive(n / 2);
}
void LogLinearRecursive(int numbers[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    if (n < 1) 
    {
        return;
    }
    LogLinearRecursive(numbers, n / 2);

}
void DoSomethingRecursive(int n)
{
    if (n == 0)
    {
        return;
    }

    DoSomethingRecursive(n - 1);
    DoSomethingRecursive(n - 1);
}
int main()
{
    const int COUNT_OF_ARRAY{ 10 };
    int scores[COUNT_OF_ARRAY]{20, 10, 40, 30, 50, 70, 45, 85, 100, 150};
#if 0
    // 현재시간
    auto startTime = std::chrono::system_clock::now();
    Sort(scores, COUNT_OF_ARRAY, Ascending);
    auto endTime = std::chrono::system_clock::now();
    // 현재시간
    for (int i = 0; i < COUNT_OF_ARRAY; ++i)
    {
        std::cout << scores[i] << std::endl;
    }
    auto duration = endTime - startTime;
    std::cout << "Sort() Time " << duration.count() << "ms" << std::endl;
#endif
    LogLinearRecursive(scores, COUNT_OF_ARRAY);
}
