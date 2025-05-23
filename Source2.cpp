#include <iostream>
#include <cmath>

/*Задача 1. Ход конём
В рамках разработки шахматного искусственного интеллекта стоит новая задача.
По заданным вещественным координатам коня и второй точки программа должна определить,
может ли конь ходить в эту точку.
Используйте как можно меньше конструкций if и логических операторов. Обеспечьте контроль ввода.

Пример
Ввод:

Введите местоположение коня:
0.071;
0.118.
Введите местоположение точки на доске:
0.213;
0.068.

Вывод:
Конь в клетке (0, 1). Точка в клетке (2, 0).
Да, конь может ходить в эту точку.*/

void task21() {
	float x, y;
	float x1, y1;

	std::cout << "Enter the knight place (from 0 till 0.8): ";
	std::cin >> x >> y;
	std::cout << "Enter the point place (from 0 till 0.8): ";
	std::cin >> x1 >> y1;

	if (x >= 0.8 || x < 0 || y >= 0.8 || y < 0 || x1 >= 0.8 || x1 < 0 || y1 >= 0.8 || y1 < 0) {
		std::cout << "Error. You entered the incorrect numbers\n";
	}
	else {
		x = int(x * 10);
		y = int(y * 10);
		x1 = int(x1 * 10);
		y1 = int(y1 * 10);

		int dx = x1 - x;
		int dy = y1 - y;

		if (abs(dx) == 2 && abs(dy) == 1 || abs(dx) == 1 && abs(dy) == 2) std::cout << "Yes, it can";
		else std::cout << "No, it can't";
	}
}

/*Задача 2. Автопилот
Одна из базовых частей программы автопилота пассажирских самолётов — контроль угла тангажа.
Угол тангажа — это угол между продольной осью самолёта и горизонтом. Если тангаж положительный,
нос самолёта смотрит вверх, если отрицательный, нос смотрит вниз и самолёт пикирует.
При больших и малых углах тангажа можно потерять управление.
У самолёта SKB-1 допустимый угол тангажа лежит в пределах от -0,28 до 0,28 радиан.
Вам поручено написать код, который проверяет, лежит ли введённый пользователем угол в этих пределах.
Пользователь вводит угол в градусах. Используйте как можно меньше конструкций if.
Обеспечьте контроль ввода.

Примеры
Ввод:
Введите угол тангажа в градусах: -28.
Вывод:
Угол небезопасен!
Ввод:
Введите угол тангажа в градусах: 724.
Вывод:
Угол безопасен.*/

void task22() {
	float angle;
	std::cout << "Enter the angle of inclination in degrees: ";
	std::cin >> angle;
	angle /= 57.296;

	if (fabs(fmod(angle, 6.28)) > abs(0.28)) std::cout << "The angle is not safe\n";
	else std::cout << "The angle is safe\n";

	std::cout << angle * 3.14 / 180;
}

/*Задача 3. Лифт
В Объединённых Арабских Эмиратах находится самый высокий небоскрёб Земли — Burj Khalifa (163).
Он оборудован скоростными пассажирскими лифтами, но вот беда:
иногда они дают сбой и застревают между этажами. В этом случае известно число H — высота пола
остановившейся кабины лифта над уровнем земли.
Чтобы команда лифтёров знала, куда ей ехать, шейх поручил вам написать программу,
которая по известному H определяет, на каком этаже находится большая часть кабины.
Известно, что расстояние между этажами Burj Khalifa равно 3,975 м,
а этаж на уровне земли имеет номер 1. На ввод программа принимает вещественное число H,
на экран выводит целое число — номер этажа. Не используйте при решении условный оператор,
кроме как для обеспечения контроля ввода.
*/

void task23() {
	float h;
	do {
		std::cout << "Enter the H: ";
		std::cin >> h;
		if (h > 163 * 3.975 || h < 0) std::cout << "Error! This H is not exist. Reset\n";
	} while (h > 163 * 3.975 || h < 0);

	std::cout << "The floor number is: " << round(h / 3.975) << "\n";

}

/*Задача 4. Убийца Photoshop
Вы разрабатываете новый крутой графический редактор. Один из инструментов редактора
позволяет делать градиент — плавный переход между двумя точками разной яркости.
Яркость точки определяется целым числом от 0 до 255, где 0 — чёрный, 255 — белый,
а всё, что между ними — оттенки серого.
Напишите код для расчёта яркости точки градиента между двумя заданными точками.
Пользователь вводит яркость левой границы градиента, потом яркость правой границы и параметр:
число от 0 до 1, которое означает интересующую нас точку.
Например, если параметр равен 0.5, то искомая точка находится ровно посередине между
левой и правой границами, если параметр равен 0, то искомая точка совпадает с левой границей,
и, наконец, если параметр равен 1, то искомая точка совпадает с правой границей.
Программа должна вывести число — яркость искомой точки. Обеспечьте контроль ввода.

Пример
Ввод:
Введите яркость левой границы градиента: 10.
Введите правую границу градиента: 255.
Введите положение точки между границами: 0.7.
Вывод:
Яркость точки: 181.5.*/

void task24() {
	int left;
	int right;
	float point;

	do {
		std::cout << "Enter a number for the left board (0 - 255): ";
		std::cin >> left;
		if (left < 0 || left > 255)	std::cout << "Error\n";
	} while (left < 0 || left > 255);

	for (bool i = false; i != true;) {	 // специально нестандартно сделал, чтобы поиграться с for
		std::cout << "Enter a number for the right board (" << left << " - 255): ";
		std::cin >> right;
		if (right < left || right > 255) std::cout << "Error\n";
		else i = true;
	}

	do {
		std::cout << "Enter a point between boards (from 0.0 to 1.0): ";
		std::cin >> point;
		if (point < 0 || point > 1) std::cout << "Error\n";
	} while (point < 0 || point > 1);

	float result = (right - left) * point + left;
	std::cout << "Point brightness: " << result << "\n";
}






