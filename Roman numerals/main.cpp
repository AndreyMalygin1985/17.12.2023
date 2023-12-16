#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>

using namespace std;

// Написать функцию, которая принимает строку — запись натурального числа(до 4000)
// и возвращает строку, содержащую запись этого числа римскими цифрами.//
// Например, из строки
// "961"
// должна получиться строка
// "CMLXI"

static string int_to_roman(int num) {
    vector<int> val = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
    vector<string> syms = { "M", "CM", "D", "CD", "C", "XC", "L", 
                            "XL", "X", "IX", "V", "IV", "I" };

    string roman_num = "";
    int i = 0;
    while (num > 0) {
        for (int j = 0; j < num / val[i]; j++) {
            roman_num += syms[i];
            num -= val[i];
        }
        i++;
    }
    return roman_num;
}

int main()
{
    SetConsoleOutputCP(1251);

    int num;
    cout << "Введите натуральное число (до 4000): ";
    cin >> num;

    string roman_num = int_to_roman(num);
    cout << "Римская запись числа: " << num << " - " << roman_num << endl;
}