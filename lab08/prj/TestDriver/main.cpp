#include <iostream>
#include <iomanip>
#include <clocale>
#include "ModulesPRR.h"

using namespace std;

int main()
{
    system("chcp 65001 & cls");

    float X[5] = { 6.9, 3.65, 10, 0.2, 39 };
    float Z[5] = { -0.8, 0.8, 0, 4, -4 };

    double exResult[5] = { 0, 5.546188, 7.877115, 4.087077, 14.469048 };
    double doneResult = 0;
    double delta = 0.00005;
    bool testResult = false;

    for (int i = 0; i < 5; i++) {
        doneResult = s_calculation(X[i], Z[i]);
        if (abs(exResult[i]) >= abs(doneResult))  { testResult = abs(exResult[i]) - abs(doneResult) <= delta; }
        else                                      { testResult = abs(doneResult) - abs(exResult[i]) <= delta; }

        cout << "Тестові значення №" << i + 1 << " : "
             << "X = " << X[i]
             << "    Z = " << Z[i]
             << endl;
        cout << "Очікуваний результат: " << exResult[i] << endl;
        cout << "Отриманий результат: " << doneResult << endl;
        cout << boolalpha << "Тестовий результат: " << testResult << endl << endl;
    }
    getchar();
    return 0;
}
