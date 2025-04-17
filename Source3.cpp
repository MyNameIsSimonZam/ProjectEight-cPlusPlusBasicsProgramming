#include <iostream>
#include <cmath>
#include <iomanip>

/*Задание 1. Космический симулятор
Что нужно сделать
Вы пишете симулятор космических полётов. Ваш звездолёт массой m килограмм
включает двигатель с силой тяги F ньютонов на t секунд. Напишите программу,
которая по заданным F, m и t покажет, на каком расстоянии от первоначального
положения окажется космический корабль через t секунд. Обеспечьте контроль ввода.
Примечание: космический корабль находится в открытом космосе.
Напоминаем, что расстояние можно рассчитать по формуле:	a * pow(t)/2, где a=F/m.
Рекомендации по выполнению
Для операции возведения в степень удобно использовать функцию std::pow.
Что оценивается
• Правильно использована формула.
• В расчётах используются переменные типа float.*/

void pW1()
{
	float f, m, t;

	do
	{
		std::cout << "Enter the mass: ";
		std::cin >> m;
		std::cout << "Enter the power: ";
		std::cin >> f;
		std::cout << "Enter the time: ";
		std::cin >> t;
		if (m <= 0 || f <= 0 || t <= 0)
			std::cout << "Error... Excepted a number > 0\n";
	} while (m <= 0 || f <= 0 || t <= 0);

	float a = f / m;
	float s = a * pow(t, 2) / 2;

	std::cout << "The distance is: " << s << "\n";
}

/*
Задание 2. Immolate Improved!
Что нужно сделать
Мы придумываем фэнтезийную онлайн-игру в жанре RPG. В орка стреляют огненными шарами разной степени мощности,
но у него есть очки здоровья и показатель сопротивляемости магии. Очки здоровья,
сопротивляемость магии и мощность огненного шара — это вещественные числа от нуля до единицы включительно.
Чем больше мощность, тем больше урон здоровью, но чем больше сопротивляемость магии, тем урон меньше.
Например, если сопротивляемость равна нулю (0%), то будет нанесён урон, равный мощности огненного шара.
Если сопротивляемость равна единице (100%), урон будет равен нулю, даже если мощность заклинания максимальна.

Напишите программу, в которой пользователь сначала задаёт количество здоровья и сопротивляемость магии орка,
а после стреляет в него огненными шарами разной мощности, пока орк не погибнет.
Мощность удара вводится с клавиатуры с каждым выстрелом. После каждого заклинания программа выводит на экран
итоговый урон от удара и оставшиеся очки здоровья орка. Показатель сопротивляемости магии не изменяется при попадании.
Обеспечьте контроль ввода.

Обратите внимание, что сопротивляемость обозначает только долю от повреждения, которая приходится на орка. Пример:
Урон 0.1, сопротивляемость 0.5, по орку будет нанесено 0.05 урона;
Урон 0.2, сопротивляемость 0.5, по орку будет нанесено 0.1 урона;
Урон 1, сопротивляемость 0.2, по орку будет нанесено 0.8 урона.*/

void pW2() {
	float health, protection, damage;

	do
	{
		std::cout << "Enter a health: ";
		std::cin >> health;
		std::cout << "Enter a protection: ";
		std::cin >> protection;
		if (health <= 0 || protection <= 0)
			std::cout << "Error... Excepted a number > 0\n";
	} while (health <= 0 || protection <= 0);

	while (health > 0) {
		std::cout << "Enter a damage: ";
		std::cin >> damage;
		if (damage <= 0)
			std::cout << "Error... Excepted a number > 0\n";
		else {
			float thisDamage = damage - (damage * protection);
			health -= thisDamage;
			std::cout << "The damage is " << damage << ", the protection is " << protection << ", the orc will take " << thisDamage << " damage\n";
			std::cout << "The " << health << " health left" << "\n";
		}
	}
}

/*Задание 3. Игрушечная история
Что нужно сделать
Вы решили открыть бизнес по производству игровых деревянных кубиков для детей.
Вы узнали, что лучше всего продаются кубики со стороной 5 см в наборах по несколько штук,
причём кубиков в наборе должно быть достаточно, чтобы сложить из них один большой куб.
Для изготовления кубиков к вам в мастерскую поступают деревянные бруски в форме
прямоугольных параллелепипедов любых размеров.

Для оптимизации бизнес-процессов напишите программу, которая по заданным размерам
исходного бруска определяет, сколько кубиков из него можно изготовить,
можно ли из них составить набор для продажи и если можно, то максимальное число кубиков в этом наборе.
Все кубики должны быть из цельного дерева без использования клея. Размеры бруска — вещественные числа.
Обеспечьте контроль ввода.

Например:
Из бруска 20x35x5 можно изготовить 28 кубиков.

Из 28 кубиков можно собрать набор из 27 кубиков.

Пример выполнения
Введите размеры бруска:
X: 5
Y: 35,76
Z: 35,05
Вывод:
Из этого бруска можно изготовить 49 кубиков.
Из них можно составить набор из 27 кубиков.

Рекомендации по выполнению
• Кубики изготавливаются только цельными, не из нескольких частей бруска.
Минимальный размер бруска — 5x5x5 см. Подумайте как проще разбить брусок на такие кубики.
• Минимальный размер набора — 2x2x2 = 8 кубиков.

Что оценивается
• Правильно считается количество кубиков, которое можно получить из бруска.
• Количество кубиков в наборе не превышает количество кубиков, полученное из бруска.
*/

void pW3() {
	float x, y, z;

	do
	{
		std::cout << "Enter x: ";
		std::cin >> x;
		std::cout << "Enter y: ";
		std::cin >> y;
		std::cout << "Enter z: ";
		std::cin >> z;

		if (x < 5.0f || y < 5.0f || z < 5.0f)
			std::cout << "Error... Excepted 5 and more\n";

	} while (x < 5.0f || y < 5.0f || z < 5.0f);

	int cubeCount = x * y * z / 125;
	int setCount = std::cbrt(x * y * z);
	setCount = std::pow(setCount, 3);
	setCount /= 125;

	std::cout << "Count of cube " << cubeCount << "\n";
	if (cubeCount >= 8) std::cout << "We can make a set with " << setCount << "\n";
	else std::cout << "We can't make a set" << "\n";
}

/*Задание 4. Убийца Steam
Что нужно сделать
Вы пишете программу-инсталлятор для компьютерной игры.
Пока обновление скачивается, пользователю нужно показать прогресс загрузки, чтобы он мог решить,
подождать ему у экрана компьютера или заварить чай.
Напишите программу, принимающую на вход размер файла обновления в мегабайтах и скорость интернет-соединения
в мегабайтах в секунду. В каждую секунду программа показывает, сколько процентов от общего объёма обновления уже скачано,
до тех пор, пока файл не загрузится. После установки обновления программа выводит время в секундах, которое заняло скачивание.
Обеспечьте контроль ввода.
Пример выполнения
Ввод:

Укажите размер файла для скачивания: 123
Какова скорость вашего соединения? 27

Вывод:

Прошло 1 сек. Скачано 27 из 123 МБ (21%).
Прошло 2 сек. Скачано 54 из 123 МБ (43%).
Прошло 3 сек. Скачано 81 из 123 МБ (65%).
Прошло 4 сек. Скачано 108 из 123 МБ (87%).
Прошло 5 сек. Скачано 123 из 123 МБ (100%).

Рекомендации по выполнению
Обратите внимание, что проценты это целые числа.

Что оценивается
• Программа работает корректно с любыми заданными значениями.
• Количество процентов не вводит в заблуждение пользователя.
Например, не должно выводиться 100%, если файл ещё не загрузился.*/

void pW4() {
	int fileSize, connectionSpeed;

	do
	{
		std::cout << "Enter the file size: ";
		std::cin >> fileSize;
		std::cout << "Enter connection speed: ";
		std::cin >> connectionSpeed;

		if (fileSize <= 0 || connectionSpeed <= 0)
			std::cout << "Error... Excepted more then 0...\n";

	} while (fileSize <= 0 || connectionSpeed <= 0);

	int alreadyDownload = 0;

	for (int i = 1; alreadyDownload < fileSize; i++) {

		alreadyDownload += connectionSpeed;

		if (alreadyDownload > fileSize) alreadyDownload = fileSize;

		int percent = alreadyDownload * 100 / fileSize;

		std::cout << i << " second have passed. " << alreadyDownload << " of " << fileSize << " Mb downloaded (" << percent << "%)\n";

	}
}

/*Задание 5. Кенийский бегун
Что нужно сделать
Самуэль родился в Кении, и когда он немного подрос, то решил сделать карьеру профессионального бегуна.
Во время тренировок на стадионе он стал запоминать свой темп на каждом километре
с помощью простых наручных часов с секундной стрелкой. После тренировки он хотел бы узнать свой средний темп бега,
но не может этого сделать: в Кении дети, решившие стать бегунами, обычно не ходят в школу. Помогите Самуэлю.
Напишите программу для расчёта среднего темпа бега. Темп измеряется в секундах на километр и означает количество времени,
которое бегун потратит на преодоление одного километра. Программа должна получить на вход количество километров,
покрытое за тренировку, и темп в секундах на каждый из этих километров. На выходе программа выводит на экран средний
темп в минутах и секундах за всю тренировку. Обеспечьте контроль ввода.

Пример выполнения
Ввод:

Привет, Сэм! Сколько километров ты сегодня пробежал? 6
Какой у тебя был темп на километре 1? 305
Какой у тебя был темп на километре 2? 291
Какой у тебя был темп на километре 3? 343
Какой у тебя был темп на километре 4? 255
Какой у тебя был темп на километре 5? 279
Какой у тебя был темп на километре 6? 312

Вывод:
Твой средний темп за тренировку: 4 минуты 58 секунд.

Рекомендации по выполнению
Чтобы добиться требуемого результата, необходимо воспользоваться функцией округления.

Что оценивается
Важно, чтобы время среднего темпа было выведено в формате «минуты и секунды», как в примере.*/

void pW5() {

	int kilometersAmount, currentTemp, sumOfTime = 0;

	do
	{
		std::cout << "Enter kilometres amount: ";
		std::cin >> kilometersAmount;

		if (kilometersAmount <= 0)
			std::cout << "Error... Excepted more then 0...\n";

	} while (kilometersAmount <= 0);

	for (int kilometersCount = 1; kilometersCount <= kilometersAmount; ++kilometersCount) {

		do
		{
			std::cout << "Enter a current temp: ";
			std::cin >> currentTemp;

			if (currentTemp <= 0)
				std::cout << "Error... Excepted more then 0...\n";
			else {
				sumOfTime += currentTemp;
			}
		} while (currentTemp <= 0);
	}

	std::cout << "Your average temp is: " << sumOfTime / kilometersAmount / 60 << " minutes and " << sumOfTime / kilometersAmount % 60 << " seconds." << "\n";			 // НАДО ДОДЕЛАТЬ, НЕ РАБОТАЕТ

}

/*Задание 6. Маятник
Что нужно сделать
Известно, что амплитуда качающегося маятника с каждым разом затухает на 8,4% от амплитуды прошлого колебания.
Если качнуть маятник, он, строго говоря, никогда не остановится: его амплитуда будет уменьшаться до тех пор,
пока мы не сочтём такой маятник остановившимся. Напишите программу, определяющую, сколько раз качнётся маятник,
прежде чем он, по нашему мнению, остановится. Программа получает на вход начальную амплитуду колебания
в сантиметрах и конечную амплитуду его колебаний, которая считается остановкой маятника. Обеспечьте контроль ввода.
Рекомендации по выполнению
Считаем, что затухание происходит на каждое качание.

Что оценивается
• Программа правильно считает количество затуханий.
• Цикл не бесконечный.

*/

void pW6() {

	float startOscillationAmplitude, finishOscillationAmplitude;

	do {
		std::cout << "Enter an start amplitude of oscillation: ";
		std::cin >> startOscillationAmplitude;
		std::cout << "Enter an finish amplitude of oscillation: ";
		std::cin >> finishOscillationAmplitude;

		if (startOscillationAmplitude <= 0 || finishOscillationAmplitude <= 0)
			std::cout << "Error... Excepted more then 0...\n";

	} while (startOscillationAmplitude <= 0 || finishOscillationAmplitude <= 0);

	int i = 0;

	for (; startOscillationAmplitude >= finishOscillationAmplitude; ++i) {
		startOscillationAmplitude *= 0.916;
	}
	std::cout << "The pendulum has swung: " << i << " times\n";

}

/*Задание 7. Друзья Оушена* (дополнительное задание)

Что нужно сделать
Банковский сейф оборудован механическим кодовым замком, состоящим из N крутящихся ручек,
каждая из которых имеет K положений.
Существует только одна комбинация положений всех N ручек, которая открывает сейф.
Чтобы его открыть, достаточно перебрать все существующие комбинации.
На проверку одной комбинации уходит в среднем T секунд, где T — вещественное число.
Напишите программу, которая по заданным N, K и T определяет время,
которое потребуется для перебора всех комбинаций и гарантированного открытия сейфа.
Не используйте циклы. Обеспечьте контроль ввода.

Рекомендации по выполнению
Для решения этого задания нужно вспомнить комбинаторику.

Что оценивается
Правильно определяется количество комбинаций.

*/

void pW7() {
	int n, k;
	float t;

	do {
		std::cout << "Enter amount of handle: ";
		std::cin >> n;
		std::cout << "Enter amount of position: ";
		std::cin >> k;
		std::cout << "Enter the check time for one combination: ";
		std::cin >> t;

		if (n <= 0 || k <= 0 || t <= 0)
			std::cout << "Error... Excepted more then 0...\n";

	} while (n <= 0 || k <= 0 || t <= 0);

	float absolutCheckTime = std::pow(k, n) * t;

	std::cout << "You need " << absolutCheckTime << " seconds\n";

}

/*Задание 8. Биолаборатория 2.0* (дополнительное задание)
Что нужно сделать
Благодаря вашей помощи компания «Терран Биотех» вышла на финишную прямую в борьбе
со всемирной эпидемией коринебактерий. Однако прошлая симуляция была недостаточно точной,
да и новая версия антибиотика работает по-другому.
В чашку Петри добавляется W капель воды, D капель чистого антибиотика и подселяется N коринебактерий.
Известно, что каждую минуту количество бактерий изменяется прямо пропорционально
концентрации антибиотика в растворе по формуле Nnew = 2 × Nold − Nold × D / W,
где Nold — количество коринебактерий минуту назад,
Nnew — их новое количество, а D / W — концентрация действующего антибиотика.
При этом каждую минуту 20% от всего количества антибиотика разлагается и больше не действует.

Напишите программу, которая получает на вход значения W, D и Nold и симулирует процесс в течение 20 минут,
для каждой минуты выводя на экран текущую концентрацию антибиотика и количество живых коринебактерий в чашке Петри.
Обеспечьте контроль ввода.

Что оценивается
• Количество измеряется в целых числах.
• Ничто не уходит в отрицательные значения.
• Цикл не бесконечный.*/

void pW8() {
	int w, nold;
	float d;

	do {
		std::cout << "Enter amount of water: ";
		std::cin >> w;
		std::cout << "Enter amount of antibiotic: ";
		std::cin >> d;
		std::cout << "Enter amount of bacteria: ";
		std::cin >> nold;

		if (w <= 0 || d <= 0 || nold <= 0)
			std::cout << "Error... Excepted more then 0...\n";

	} while (w <= 0 || d <= 0 || nold <= 0);

	for (int i = 1; i <= 20; ++i) {
		int nnew = 2 * nold - nold * d / w;
		d *= 0.8;
		std::cout << std::fixed << std::setprecision(2) << i << " minutes: Antibiotic concentration is " << d << "; " << "\t" << "Living bacteria amount are " << nnew << "\n";
		nold = nnew;
	}
}

/*Задание 9. Яйца* (дополнительное задание)
Что нужно сделать
В рамках программы колонизации Марса компания «Спейс Инжиниринг» вывела особую породу черепах,
которые должны размножаться, откладывая яйца в марсианском грунте.
Откладывать яйца слишком близко к поверхности опасно из-за радиации, а слишком глубоко опасно
из-за давления грунта и недостатка кислорода. Вообще, факторов много,
но специалисты проделали большую работу и предположили, что уровень опасности для черепашьих яиц
рассчитывается по формуле D = x^3 − 3x^2 − 12x + 10, где x — глубина кладки в метрах,
а D — уровень опасности в условных единицах. Для тестирования гипотезы нужно взять пробу грунта на безопасной,
согласно формуле, глубине.
Напишите программу, находящую такое значение глубины х, при котором уровень опасности наиболее близок к нулю,
учитывая допустимое отклонение. На вход программе подаётся максимально допустимое отклонение
уровня опасности от нуля, а программа должна рассчитать приблизительное значение х,
удовлетворяющее этому отклонению. Известно, что глубина точно больше нуля и меньше четырёх метров.
Обеспечьте контроль ввода.

Пример выполнения
Введите максимально допустимый уровень опасности: 0,01
Вывод:
Приблизительная глубина безопасной кладки: 0,732422 метра

Рекомендации по выполнению
• Отрицательный уровень опасности — это тоже плохо. Нужно найти наиболее близкий к нулю уровень опасности.
• Здесь не обязательно считать корни кубического уравнения. Достаточно найти решение на отрезке от 0 до 4.

Что оценивается
Для поиска решения не используется полный перебор.*/

void pW9() {

	float dangerDeviation;

	do {
		std::cout << "Enter danger deviation: ";
		std::cin >> dangerDeviation;

		if (dangerDeviation < 0)
			std::cout << "Error... Excepted more then 0...\n";

	} while (dangerDeviation < 0);

	float left = 0.0f, right = 4.0f;
	float f_left = left * left * left - 3 * left * left - 12 * left + 10;
	float x = (left + right) / 2;
	float dx = x * x * x - 3 * x * x - 12 * x + 10;

	while (abs(dx) > dangerDeviation && (right - left) > 1e-7f) {
		x = (left + right) / 2;
		dx = x * x * x - 3 * x * x - 12 * x + 10;
		if (dx * f_left > 0) {
			left = x;
			f_left = dx;
		}
		else {
			right = x;
		}
	}

	std::cout << "Approximate safe masonry depth: " << x << " meters\n";

}

/*Задание 10. Тяжело в учении, легко в бою* (дополнительное задание)
Что нужно сделать
Вы встретились со своим старым другом, который тоже изучает программирование, правда, в другом учебном заведении.
За чашкой кофе он пожаловался, что сумасбродный препод дал задание написать программу,
которая из двух введённых чисел определяет наибольшее, не используя при этом условных операторов и циклов.
Радуясь, что на вашем курсе такого не требуют, вы всё-таки решаете помочь своему другу. Напишите для него эту программу.

Рекомендации по выполнению
Попробуйте решить это задание с помощью арифметических операций и простых математических функций.

Что оценивается
Решение не является просто функцией std::max.
*/

void pW10() {
	int a, b;

	std::cout << "Enter a first number: ";
	std::cin >> a;
	std::cout << "Enter a second number: ";
	std::cin >> b;

	int max = (a + b + std::abs(a - b)) / 2;

	std::cout << max << " is the biggest";

}





