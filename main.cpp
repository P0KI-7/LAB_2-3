#include <iostream>
#include <windows.h>

using namespace std;

void inputData(float* p, int n);
float average(const float* p, int n);
float minValue(const float* p, int n);
float maxValue(const float* p, int n);
float* filterAbroveAverage(float* p, int n, int& newCount);

int main()
{
    SetConsoleOutputCP(65001); // Переключаем консоль в UTF-8
    SetConsoleCP(65001);

    int n, newCount;
    cout << "\n=== Анализ сенсора ===\n";
    cout << "Введите количетво измерений: ";
    cin >> n;
    float* data = new float[n];
    inputData(data,n);
    
    cout << "Среднее значение: " << average(data,n) << endl;
    cout << "Минимум: " << minValue(data,n) << endl;
    cout << "Максимум: " << maxValue(data,n) << endl;
    //cout << "Значения выше среднего:\n" << filterAbroveAverage(data,n,newCount) << endl;
    delete[] data;
    
    return 0;
}

void inputData(float* p, int n)
{
    cout << "Введите значения:\n";
    for (int i = 0; i < n; ++i)
    {
        cin >> *(p + i);
    }
}

float average(const float* p, int n)
{
    float sum = 0;
    for (int i = 0; i < n; ++i)
    {
        sum += *(p+i);
    }
    return sum / n;
}

float minValue(const float* p, int n)
{
    float min = *p;
    for (int i = 1; i < n; ++i)
    {
        if (min > *(p+i)) min = *(p+i);
    }
    return min;
}

float maxValue(const float* p, int n)
{
    float max = *p;
    for (int i = 1; i < n; ++i)
    {
        max = (max < *(p+i)) ? *(p+i) : max;
    }
    return max;
}