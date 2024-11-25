#include <iostream>
using namespace std;

// Проверяем на високосный год
bool leapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return true;
    return false;
}

int getDaysInMonth(int month, int year) {
    if (month == 2) {
        if (leapYear(year)) return 29;
        return 28;
    }
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }
    return 31;
}

int main() {
    
    setlocale(LC_ALL, "russian");
    
    int year, month, dayOfWeek = 1; // 1 = понедельник
    string months[] = {
        "Январь", "Февраль", "Март", "Апрель", "Май", "Июнь",
        "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь"
    };

    cout << "Введите год: ";
    cin >> year;

    // Исключение
    if (year < 1) {
        cout << "Год должен быть больше 0!" << endl;
        return 1;
    }

    // Рассчитываем первый день года
    for (int i = 1; i < year; i++) {
        if (leapYear(i)) {
            dayOfWeek += 366;
        } else {
            dayOfWeek += 365;
        }
    }
    dayOfWeek %= 7; // 0 = воскресенье, 1 = понедельник, ...

    // Вывод календаря
    for (int month = 1; month <= 12; month++) {
        cout << "\n" << months[month - 1] << ":\n";
        cout << "Пн Вт Ср Чт Пт Сб Вс\n";

        int daysInMonth = getDaysInMonth(month, year);

        // Печать пустых дней
        for (int i = 0; i < dayOfWeek; i++) {
            cout << "   ";
        }

        // Печать дней месяца
        for (int day = 1; day <= daysInMonth; day++) {
            if (day < 10) cout << " "; // Для выравнивания чисел
            cout << day << " ";
            dayOfWeek = (dayOfWeek + 1) % 7;
            if (dayOfWeek == 0) cout << endl;
        }

        if (dayOfWeek != 0) cout << endl;
    }

    return 0;
}