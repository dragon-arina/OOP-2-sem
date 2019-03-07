#include <iostream>
#include "Complex1.h"
#include <string>
using namespace std;

int FIRST(){
    T calculator;
    int choice;
    string check;
    cout << "Какую операцию хотите выполнить?\n1. Сложение комплексных чисел\n2. Вычитание комплексных чисел\n3. Умножение комплексных чисел\n4. Деление комплексных чисел\n5. Умножение комплексного числа на вещественное число\nВведите номер выбранной операции:  ";
    again:
    cin >> check;
    if (check.length() != 1 || check[0] < '1' || check[0] > '5')
    {
        cerr << "Ошибка ввода!\nВведите номер выбранной операции заново: ";
        goto again;
    }

    choice = stop(check);
     if(choice != 5){
         cout << "\nАлгебраическая форма комплексного числа z = x + y*i\n";
         cout << "\nВведите х для первого числа: ";
         calculator.x1 = Enter();
         cout << "Введите y для первого числа: ";
         calculator.y1 = Enter();
         cout << "Введите х для второго числа: ";
         calculator.x2 = Enter();
         cout << "Введите y для второго числа: ";
         calculator.y2 = Enter();

         switch (choice){
             case 1:calculator.sum();
                 break;
             case 2: calculator.difference();
                 break;
             case 3: calculator.multiplication();
                 break;
             case 4: calculator.div();
                 break;
         }
     }
     else {
         cout << "Алгебраическая форма комплексного числа z = x + y*i\n";
         cout << "Введите х для комплексного числа: ";
         calculator.x1 = Enter();
         cout << "Введите y для комплексного числа: ";
         calculator.y1 = Enter();
         cout << "Введите вещественное число на которе будете умножать: ";
         calculator.alfa = Enter();
         calculator.pr_alfa();
     }
}


float Enter(){
    string check;
    again_1:
    cin >> check;
    for (int i = 0; i < proverka.length(); i++) {
        if ((proverka[i] < '0') || (proverka[i] > '9') && (proverka[i] != ',')) {
            cout << "Ошибка ввода!\nВведите число заново: ";
            goto again_1;
        }
    }
    return stof(proverka);
}




void T::sum() {
    if (y1 + y2 >= 0)
        cout << "\nСумма: " << x1 + x2 << "+" << y1 + y2 << "*i\n";
    else
        cout << "\nСумма: " << x1 + x2 << y1 + y2 << "*i\n";
}

void T::difference() {
    if (y1 - y2 >= 0)
        cout << "\nРазность: " << x1 - x2 << "+" << y1 - y2 << "*i\n";
    else
        cout << "\nРазность: " << x1 - x2 << y1 - y2 << "*i\n";
}

void T::multiplication() {
    if (x1 * y2 + x2 * y1 >= 0)
        cout << "\nПроизведение: " << x1 * x2 - y1 * y2 << "+" << x1 * y2 + x2 * y1 << "*i\n";
    else
        cout << "\nПроизведение: " << x1 * x2 - y1 * y2 << x1 * y2 + x2 * y1 << "*i\n";
}


void T::div(){
    if ((double)(x2 * y1 - x1 * y2) / (x2 * x2 + y2 * y2) >= 0)
        cout << "\nЧастное: " << (x1 * x2 + y1 * y2) / (x2 * x2 + y2 * y2) << "+" << (x2 * y1 - x1 * y2) / (x2 * x2 + y2 * y2) << "*i\n";
    else
        cout << "\nЧастное: " << (x1 * x2 + y1 * y2) / (x2 * x2 + y2 * y2) << (x2 * y1 - x1 * y2) / (x2 * x2 + y2 * y2) << "*i\n";
}

void T::pr_alfa() {
    if (y1 * alfa >= 0)
        cout << "\nПроизведение: " <<  (x1 * alfa) << "+" << (y1 * alfa) << "*i\n";
    else
        cout << "\nПроизведение: " <<  (x1 * x2 - y1 * y2) << (x1 * y2 + x2 * y1) << "*i\n";
}
