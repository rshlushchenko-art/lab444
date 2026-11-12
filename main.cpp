#include <iostream>
#include <sstream> // Перевірка цілого числа без дробової частини
#include <string>
using namespace std;

// Допоміжне введення одного цілого числа.
bool ReadInteger(int &value);
// Proc12: упорядкування трьох чисел через параметри-посилання.
void SortInc3(double &A, double &B, double &C);
// Proc34: перевірка парності цілого числа.
bool Even(int K);
// Integer24: введення номера дня року з перевіркою.
bool InputDay(int &K);
// Integer24: обчислення номера дня тижня.
int WeekDay(int K);
// Integer24: виведення результату.
void OutputDay(int day);
// Процедури для пунктів меню.
void task_Proc12(); // Два набори дійсних чисел
void task_Proc34(); // П'ять цілих чисел
void task_Integer24(); // Номер дня тижня

int main()
{
    int menu = 0;
    cout << "1 - Proc12. SortInc3\n";
    cout << "2 - Proc34. Even\n";
    cout << "3 - Integer24. Week day\n";
    cout << "Select task: ";
    if (!ReadInteger(menu))
    {
        cout << "Error: enter an integer menu number.\n";
        return 0;
    }
    // Одноразовий вибір завдання без циклу.
    switch (menu)
    {
    case 1: task_Proc12(); break;
    case 2: task_Proc34(); break;
    case 3: task_Integer24(); break;
    default: cout << "Error: select 1, 2 or 3.\n";
    }
    return 0;
}

// Визначення всіх функцій розміщено після main().
bool ReadInteger(int &value)
{
    string token;
    if (!(cin >> token))
        return false;
    istringstream input(token);
    char extra = '\0';
    // Відхиляємо текст, переповнення int і записи на кшталт 7.5.
    return (input >> value) && !(input >> extra);
}

void SortInc3(double &A, double &B, double &C)
{
    double temp = 0.0;
    // Після цих трьох порівнянь A <= B <= C.
    if (A > B)
    {
        temp = A; A = B; B = temp;
    }
    if (A > C)
    {
        temp = A; A = C; C = temp;
    }
    if (B > C)
    {
        temp = B; B = C; C = temp;
    }
}

bool Even(int K)
{
    return K % 2 == 0; // Нуль і від'ємні парні також враховуються.
}

bool InputDay(int &K)
{
    cout << "K (1..365) = ";
    if (!ReadInteger(K))
        return false;
    return K >= 1 && K <= 365;
}

int WeekDay(int K)
{
    return K % 7; // 0 - неділя, 1 - понеділок, ..., 6 - субота.
}

void OutputDay(int day)
{
    cout << "Day (0=Sun, 1=Mon, ..., 6=Sat) = " << day << '\n';
}

void task_Proc12()
{
    cout << "\nProc12. SortInc3\n";
    double A1 = 0.0, B1 = 0.0, C1 = 0.0;
    double A2 = 0.0, B2 = 0.0, C2 = 0.0;
    cout << "A1 B1 C1 (-100..100) = ";
    if (!(cin >> A1 >> B1 >> C1))
    {
        cout << "Error: enter real numbers.\n";
        return;
    }
    cout << "A2 B2 C2 (-100..100) = ";
    if (!(cin >> A2 >> B2 >> C2))
    {
        cout << "Error: enter real numbers.\n";
        return;
    }
    // Позитивна перевірка кожної межі також відхиляє NaN.
    if (!(A1 >= -100 && A1 <= 100 && B1 >= -100 && B1 <= 100
          && C1 >= -100 && C1 <= 100 && A2 >= -100 && A2 <= 100
          && B2 >= -100 && B2 <= 100 && C2 >= -100 && C2 <= 100))
    {
        cout << "Error: values must be in [-100, 100].\n";
        return;
    }
    SortInc3(A1, B1, C1); // Перший виклик
    SortInc3(A2, B2, C2); // Другий виклик
    cout << "Set 1: " << A1 << ' ' << B1 << ' ' << C1 << '\n';
    cout << "Set 2: " << A2 << ' ' << B2 << ' ' << C2 << '\n';
}

void task_Proc34()
{
    cout << "\nProc34. Even\n";
    int K1 = 0, K2 = 0, K3 = 0, K4 = 0, K5 = 0;
    cout << "Five integers (-100..100) = ";
    if (!ReadInteger(K1) || !ReadInteger(K2) || !ReadInteger(K3)
        || !ReadInteger(K4) || !ReadInteger(K5))
    {
        cout << "Error: enter five integers.\n";
        return;
    }
    if (K1 < -100 || K1 > 100 || K2 < -100 || K2 > 100
        || K3 < -100 || K3 > 100 || K4 < -100 || K4 > 100
        || K5 < -100 || K5 > 100)
    {
        cout << "Error: values must be in [-100, 100].\n";
        return;
    }
    // bool при додаванні дає 1 для true і 0 для false.
    int count = Even(K1) + Even(K2) + Even(K3) + Even(K4) + Even(K5);
    cout << "Even count = " << count << '\n';
}

void task_Integer24()
{
    cout << "\nInteger24. Week day\n";
    int K = 0;
    if (!InputDay(K))
    {
        cout << "Error: K must be an integer in [1, 365].\n";
        return; // За помилки розрахунок не виконується.
    }
    OutputDay(WeekDay(K)); // Окремі функції розрахунку і виведення.
}
