#include <iostream> 
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** a, int k, int n, int Low, int High, int i = 0, int j = 0);
void Print(int** a, int k, int n, int i = 0, int j = 0);
int MaxInColumn(int** a, const int k, int j, int i = 0);
int SumMaxOddColumns(int** a, const int k, const int n, int j = 0);

int main() {
    srand((unsigned)time(NULL));
    int Low = 7;
    int High = 65;
    int k, n;
    cout << "k = "; cin >> k;
    cout << "n = "; cin >> n;

    int** a = new int* [k];
    for (int i = 0; i < k; i++)
        a[i] = new int[n];

    Create(a, k, n, Low, High);
    Print(a, k, n);

    int sumMax = SumMaxOddColumns(a, k, n);
    cout << "Sum of max elements in odd columns = " << sumMax << endl;

    for (int i = 0; i < k; i++)
        delete[] a[i];
    delete[] a;
    return 0;
}

// Рекурсивное создание массива
void Create(int** a, int k, int n, int Low, int High, int i, int j) {
    if (i >= k) return;               // Базовый случай для строк
    if (j >= n) {                     // Переход на новую строку
        Create(a, k, n, Low, High, i + 1, 0);
        return;
    }
    a[i][j] = Low + rand() % (High - Low + 1);
    Create(a, k, n, Low, High, i, j + 1); // Переход к следующему элементу в строке
}

// Рекурсивный вывод массива
void Print(int** a, int k, int n, int i, int j) {
    if (i >= k) return;               // Базовый случай для строк
    if (j >= n) {                     // Завершение строки и переход на следующую
        cout << endl;
        Print(a, k, n, i + 1, 0);
        return;
    }
    cout << setw(4) << a[i][j];
    Print(a, k, n, i, j + 1);         // Переход к следующему элементу в строке
}

// Рекурсивная функция для нахождения максимума в столбце
int MaxInColumn(int** a, const int k, int j, int i) {
    if (i == k - 1)
        return a[i][j];
    int maxElem = MaxInColumn(a, k, j, i + 1);
    return (a[i][j] > maxElem) ? a[i][j] : maxElem;
}

// Рекурсивная функция для суммирования максимумов нечетных столбцов
int SumMaxOddColumns(int** a, const int k, const int n, int j) {
    if (j >= n)
        return 0;
    int maxElem = MaxInColumn(a, k, j);
    return maxElem + SumMaxOddColumns(a, k, n, j + 2);
}
