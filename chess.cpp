#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int k, l, m, n;
	cout << "Введите пары натуральных чисел, не превосходящие восьми." << endl;
	cout << "Первая пара: ";
	cin >> k >> l;
	cout << "Вторая пара: ";
	cin	>> m >> n;
	if (((k + l) % 2) == ((m + n) % 2))
		cout << "Поля одного цвета" << endl;
	else
		cout << "Поля разного цвета" << endl;

    char figure;
    cout << "Введите фигуру (ф - ферзь, л - ладья, с - слон, к - конь): ";
    cin >> figure;
    int razngor = abs(m - k);
    int raznvert = abs(n - l);
    bool ygroza = false;
    switch (figure) {
    case 'ф':
        ygroza = (razngor == 0 or raznvert == 0 or razngor == raznvert);
        break;
    case 'л':
        ygroza = (raznvert == 0 or razngor == 0);
        break;
    case 'с':
        ygroza = (razngor == raznvert);
        break;
    case 'к':
        ygroza = ((razngor == 2 and raznvert == 1) or (razngor == 1 and raznvert == 2));
        break;
    default:
        cout << "Неверно указана фигура.";
        return 0;
    }
    cout << "Фигура " << figure << " " << (ygroza ? "угрожает" : "не угрожает");
    cout << " полю (" << m << ", " << n << ")." << endl;

    bool onestep = (razngor == 0 or raznvert == 0 or razngor == raznvert);
    if (onestep) {
        cout << "Можно одним ходом попасть с поля (" << k << ", " << l << ") на поле (" << m << ", " << n << ").";
    }
    else {
        int firstmovegor = k, firstmovever = l;
        if (razngor > 0) {
            if (m > k) {
                firstmovegor++;
            }
            else {
                firstmovegor--;
            }
        }
        if (raznvert > 0) {
            if (n > l) {
                firstmovever++;
            }
            else {
                firstmovever--;
            }
        }
        cout << "Нельзя одним ходом попасть с поля (" << k << ", " << l << ") на поле (" << m << ", " << n << ").";
        cout << " Первый ход приводит на поле (" << firstmovegor << ", " << firstmovever << ").";
    }
    return 0;
}