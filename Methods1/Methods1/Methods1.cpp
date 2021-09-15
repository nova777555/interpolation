﻿//Чукавин Владимир Дмитриевич, группа Б02, вариант 21
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

//функция f(x)
double f(double x) {
    return x * x * cos(2 * x) + 1;
}

//функция h(x)
double h(double x) {
    return f(x) * abs(x);
}

//интерполяция функции при помощи полинома Лагранжа
double L_interpolation(vector<double> X, vector<double>f_X, double x) {
    double ans = 0;
    for (int i = 0; i < X.size(); i++) {
        //нахождение i-го множителя Лагранжа
        double l = 1;
        for (int j = 0; j < X.size(); j++) 
            if (j != i) {
                l = l * (x - X[j]);
                l = l / (X[i] - X[j]);
            }
        ans += l * f_X[i];
    }
    return ans;
}

int main()
{
    cout << setprecision(15);
    const double PI = 3.14159265358979323846;
    setlocale(LC_ALL, "Russian");
    double a = -10;
    double b = 10;
    int n = 11;
    //Задаем точку, значение в которой будем проверять результаты
    double x = 3.14;
    vector<double> X, f_X;
    cout << "-----------------------------------------------" << endl;
    cout << "Рассмотрим функцию f(x)=x^2cos2x+1" << endl;
    cout << "-----------------------------------------------" << endl;
    //Задаем интерполяционную таблицу: 
    //1.1) Рассмотрим интервал [-10,10] с узлами в целых четных точках: -10 -8 -6 и т.д.
    for (int i = -10; i < 11; i+=2) {
        X.push_back(i);
        f_X.push_back(f(i));
    }
    cout << "1.1) Рассмотрим интервал [-10,10] с узлами в целых четных точках: -10 -8 -6 и т.д."<<endl;
    double Lf = L_interpolation(X, f_X, x);
    cout<<"Полученное значение в точке "<<x<<" - "<<Lf << endl;
    cout <<"Точное значение в точке " << x << " - " << f(x) << endl;
    cout << "Абсолютная погрешность = " << abs(f(x) - Lf) << endl;
    cout << "-----------------------------------------------" << endl;
    //1.2) Рассмотрим интервал [-10,10] с узлами, полученных по формуле 3.2 (всего 11 узлов)
    for (int i = 0; i < n; i++) {
        
        X[i] = (cos((2 * i + 1) * PI / (2 * n + 2)) * (b - a) + b + a) * 1 / 2;
        f_X[i]=(f(X[i]));
    }
    cout << "1.2) Рассмотрим интервал [-10,10] с узлами, полученных по формуле 3.2 (всего 11 узлов)" << endl;
    Lf = L_interpolation(X, f_X, x);
    cout << "Полученное значение в точке " << x << " - " << Lf << endl;
    cout << "Точное значение в точке " << x << " - " << f(x) << endl;
    cout << "Абсолютная погрешность = " << abs(f(x) - Lf) << endl;
    cout << "-----------------------------------------------" << endl;
    X.clear(); f_X.clear();
    //1.3) Рассмотрим интервал [-10,10], на котором увеличим кол-во узлов до 41 с шагом 0.5
    n = 41;
    for (int i = 0; i < n; i++) {
        X.push_back(0.5*i-10);
        f_X.push_back(f(X[i]));
    }
    cout << "1.3) Рассмотрим интервал [-10,10], на котором увеличим кол-во узлов до 41 с шагом 0.5" << endl;
    Lf = L_interpolation(X, f_X, x);
    cout << "Полученное значение в точке " << x << " - " << Lf << endl;
    cout << "Точное значение в точке " << x << " - " << f(x) << endl;
    cout << "Абсолютная погрешность = " << abs(f(x) - Lf) << endl;
    cout << "-----------------------------------------------" << endl;
    //1.4) Рассмотрим интервал [-10,10] с узлами, полученных по формуле 3.2 (всего 41 узел)
    for (int i = 0; i < n; i++) {

        X[i] = (cos((2 * i + 1) * PI / (2 * n + 2)) * (b - a) + b + a) * 1 / 2;
        f_X[i] = (f(X[i]));
    }
    cout << "1.4) Рассмотрим интервал [-10,10] с узлами, полученных по формуле 3.2 (всего 41 узел)" << endl;
    Lf = L_interpolation(X, f_X, x);
    cout << "Полученное значение в точке " << x << " - " << Lf << endl;
    cout << "Точное значение в точке " << x << " - " << f(x) << endl;
    cout << "Абсолютная погрешность = " << abs(f(x) - Lf) << endl;
    cout << "-----------------------------------------------" << endl;
    n = 11;
    X.clear(); f_X.clear();
    cout << "Рассмотрим функцию h(x)=|x|*f(x) = |x|*x^2*cos2x+1" << endl;
    cout << "-----------------------------------------------" << endl;
    //Задаем интерполяционную таблицу: 
    //2.1) Рассмотрим интервал [-10,10] с узлами в целых четных точках: -10 -8 -6 и т.д.
    for (int i = -10; i < 11; i+=2) {
        X.push_back(i);
        f_X.push_back(h(i));
    }
    cout << "2.1) Рассмотрим интервал [-10,10] с узлами в целых четных точках: -10 -8 -6 и т.д." << endl;
    Lf = L_interpolation(X, f_X, x);
    cout << "Полученное значение в точке " << x << " - " << Lf << endl;
    cout << "Точное значение в точке " << x << " - " << h(x) << endl;
    cout << "Абсолютная погрешность = " << abs(h(x) - Lf) << endl;
    cout << "-----------------------------------------------" << endl;
    //2.2) Рассмотрим интервал [-10,10] с узлами, полученных по формуле 3.2 (всего 11 узлов)
    for (int i = 0; i < n; i++) {

        X[i] = (cos((2 * i + 1) * PI / (2 * n + 2))*(b-a)+b+a)*1/2;
        f_X[i] = (h(X[i]));
    }
    cout << "2.2) Рассмотрим интервал [-10,10] с узлами, полученных по формуле 3.2 (всего 11 узлов)" << endl;
    Lf = L_interpolation(X, f_X, x);
    cout << "Полученное значение в точке " << x << " - " << Lf << endl;
    cout << "Точное значение в точке " << x << " - " << h(x) << endl;
    cout << "Абсолютная погрешность = " << abs(h(x) - Lf) << endl;
    cout << "-----------------------------------------------" << endl;
    X.clear(); f_X.clear();
    //2.3) Рассмотрим интервал [-10,10], на котором увеличим кол-во узлов до 41 с шагом 0.5
    n = 41;
    for (int i = 0; i < n; i++) {
        X.push_back(0.5 * i - 10);
        f_X.push_back(h(X[i]));
    }
    cout << "2.3) Рассмотрим интервал [-10,10], на котором увеличим кол-во узлов до 41 с шагом 0.5" << endl;
    Lf = L_interpolation(X, f_X, x);
    cout << "Полученное значение в точке " << x << " - " << Lf << endl;
    cout << "Точное значение в точке " << x << " - " << h(x) << endl;
    cout << "Абсолютная погрешность = " << abs(h(x) - Lf) << endl;
    cout << "-----------------------------------------------" << endl;
    //2.4) Рассмотрим интервал [-10,10] с узлами, полученных по формуле 3.2 (всего 41 узел)
    for (int i = 0; i < n; i++) {

        X[i] = (cos((2 * i + 1) * PI / (2 * n + 2)) * (b - a) + b + a) * 1 / 2;
        f_X[i] = (h(X[i]));
    }
    cout << "Рассмотрим интервал [-10,10] с узлами, полученных по формуле 3.2 (всего 41 узел)" << endl;
    Lf = L_interpolation(X, f_X, x);
    cout << "Полученное значение в точке " << x << " - " << Lf << endl;
    cout << "Точное значение в точке " << x << " - " << h(x) << endl;
    cout << "Абсолютная погрешность = " << abs(h(x) - Lf) << endl;
    cout << "-----------------------------------------------" << endl;
    cin >> n;
}


