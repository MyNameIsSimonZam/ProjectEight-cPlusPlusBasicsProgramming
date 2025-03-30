#include <iostream>

void task1();
void task2();
void task3();
void task11();
void task12();
void task13();
void task14();
void task21();
void task22();
void task23();
void task24();

void pW1();
void pW2();
void pW3();
void pW4();
void pW5();
void pW6();
void pW7();
void pW8();
void pW9();
void pW10();


int main() {
	int choice;
	std::cout << "Choose a task to run:\n";
	std::cout << "1. Задача 1. Орехи.\n";
	std::cout << "2. Задача 2. ЗОЖ.\n";
	std::cout << "3. Задача 3. Постоянный покупатель.\n";
	std::cout << "11. Задача 1. Ку!\n";
	std::cout << "12. Задача 2. Компьютерное зрение.\n";
	std::cout << "13. Задача 3. Метеостанция.\n";
	std::cout << "14. Задача 4. Аккуратность.\n";
	std::cout << "21. Задача 1. Ход конём.\n";
	std::cout << "22. Задача 2. Автопилот.\n";
	std::cout << "23. Задача 3. Лифт.\n";
	std::cout << "24. Задача 4. Убийца Photoshop.\n";
	std::cout << "Or choose the number of the practical work to run:\n";
	std::cout << "31. Задание 1. Космический симулятор.\n";
	std::cout << "32. Задание 2. Immolate Improved!\n";
	std::cout << "33. Задание 3. Игрушечная история.\n";
	std::cout << "34. Задание 4. Убийца Steam.\n";
	std::cout << "35. Задание 5. Кенийский бегун.\n";
	std::cout << "36. Задание 6. Маятник.\n";
	std::cout << "37. Задание 7. Друзья Оушена.\n";
	std::cout << "38. Задание 8. Биолаборатория 2.0*.\n";
	std::cout << "39. Задание 9. Яйца*.\n";
	std::cout << "310. Задание 10. Тяжело в учении, легко в бою*.\n";
	std::cout << "Enter your choice: ";
	std::cin >> choice;

	switch (choice) {
	case 1:
		task1();
		break;
	case 2:
		task2();
		break;
	case 3:
		task3();
		break;
	case 11:
		task11();
		break;
	case 12:
		task12();
		break;
	case 13:
		task13();
		break;
	case 14:
		task14();
		break;
	case 21:
		task21();
		break;
	case 22:
		task22();
		break;
	case 23:
		task23();
		break;
	case 24:
		task24();
		break;
	case 31:
		pW1();
		break;
	case 32:
		pW2();
		break;
	case 33:
		pW3();
		break;
	case 34:
		pW4();
		break;
	case 35:
		pW5();
		break;
	case 36:
		pW6();
		break;
	case 37:
		pW7();
		break;
	case 38:
		pW8();
		break;
	case 39:
		pW9();
		break;
	case 310:
		pW10();
		break;
	default:
		std::cout << "Invalid choice. Exiting...\n";
	}
	return 0;
}