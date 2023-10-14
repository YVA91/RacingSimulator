#include <iostream>
#include <locale>
#include <Windows.h>
#include <vector>
#include <algorithm>

#include "Ground.h"
#include "Camal.h"
#include "Camal_Fast.h"
#include "Centour.h"
#include "Boots.h"
#include "Broomstick.h"
#include "Air.h"
#include "Eagle.h"
#include "Сarpet.h"

class Game {

public:
    int choosing_type_race() {
        std::cout << "1. Гонка для наземного транспорта\n" << "2. Гонка для воздушного транспорта\n" << "3. Гонка для наземного и воздушного транспорта\n";
        int typeRace;
        std::cout << "Выберите тип гонки: ";
        std::cin >> typeRace;
        if ((typeRace != 1) && (typeRace != 2) && (typeRace != 3)) {
            std::cout << "Попытка выбрать неправильный тип гонки" << std::endl;
            choosing_type_race();
        }
        return typeRace;
   }

    int set_distance() {
        int d;
        std::cout << "Укажите длину дистанции (должна быть положительна):\n";
        std::cin >> d;
        return d;
    }

    void set_registration_menu(int* racerArr, int typeR, int distance) {

        int t;
        int count = 0;
        for (int i = 0; i < 8; i++) {
            if (racerArr[i] != 0) {
                count++;
            }
        }
        if (count >= 2) {
            std::cout << "1. Зарегистрировать транспорт\n";
            std::cout << "2. Начать гонку\n";
        }
        else {
            std::cout << "Должно быть зарегистрировано хотя бы 2 транспортных средства\n";
            std::cout << "1. Зарегистрировать транспорт\n";

        }

        std::cout << "Выберите действие: ";
        std::cin >> t;
        
        if (t == 1) {
            createArrCheck(racerArr, typeR, distance);
        }
        else if (t == 2 && count >= 2) {
        }
        else {
            std::cout << "Попытка выбрать неправильный тип" << std::endl;
            set_registration_menu(racerArr, typeR, distance);
        }
    }

    std::string tell_who(int who) {
        std::string str;
        switch (who)
        {
        case 1:
            return str = "Верблюд";
            break;
        case 2:
            return str = "Верблюд-быстроход";
            break;
        case 3:
            return str =  "Кентавр";
            break;
        case 4:
            return str = "Ботинки-вездеходы";
            break;
        case 5:
            return str = "Ковёр-самолёт";
            break;
        case 6:
            return str = "Орёл";
            break;
        case 7:
            return str = "Метла";
            break;
        }
    }
    
    int* createArrCheck(int* racerArr, int typeR, int distance) {

        switch (typeR)
        {
        case 1:
            std::cout << "Гонка для наземного транспорта. ";
            break;
        case 2:
            std::cout << "Гонка для воздушного транспорта. ";
            break;
        case 3:
            std::cout << "Гонка для наземного ивоздушного транспорта. ";
            break;
        }
        std::cout << "Расстояние: " << distance << std::endl;

        for (int i = 0; i < 8; i++) {
            if (racerArr[i] == 0) {
                break;
            }
            else {
                std::cout << "Зарегистрированные транспортные средства: ";
                break;
            }
        }

        for (int i = 0; i < 8; i++) {
            if (racerArr[i] == 0) {
                break;
            }
            else {
                std::cout << tell_who(racerArr[i]);
            }
            std::cout << ", ";
        }

        for (int i = 0; i < 8; i++) {
            if (racerArr[i] == 0) {
                break;
            }
            else {
                std::cout << std::endl;
                break;
            }
        }

        std::cout << "1. Верблюд\n" <<
            "2. Верблюд-быстроход\n" <<
            "3. Кентавр\n" <<
            "4. Ботинки-вездеходы\n" <<
            "5. Ковёр-самолёт\n" <<
            "6. Орёл\n" <<
            "7. Метла\n" <<
            "0. Закончить регистрацию\n" <<
            "Выберите транспортное средство или 0 для окончания регистрации:";
        int c;
        std::cin >> c;

        if (c == 0) {
            set_registration_menu(racerArr, typeR, distance);
            return racerArr;
        }
        else if ((typeR == 1 && (c == 5 || c == 6 || c == 7)) || (typeR == 2 && (c == 1 || c == 2 || c == 3 || c == 4)) || (c < 0 || c >= 8) ) {
            std::cout << "Попытка зарегистрировать неправильный тип транспортного средства " << std::endl;
            createArrCheck(racerArr, typeR, distance);
        }
        else {
            bool exists;
            for (int i = 0; i < 8; i++) {
                if (racerArr[i] == c) {
                    exists = false;
                    break;
                }
                else {
                    exists = true;
                }
            }
            if (exists) {
                for (int i = 0; i < 8; i++) {
                    if (racerArr[i] == 0) {
                        racerArr[i] = c;
                        std::cout << tell_who(c) << " успешно зарегистрирован!" << std::endl;
                        break;
                    }
                }
                createArrCheck(racerArr, typeR, distance);
            }
            else {
                std::cout << tell_who(c) << " уже зарегистрирован!" << std::endl;
                createArrCheck(racerArr, typeR, distance);
            }
        }
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Game game;
    
    bool next = false;
    std::cout << "Добро пожаловать в гоночный симулятор\n";

    do
    {
        int* racerArr = new int[8] {};
        int typeR = game.choosing_type_race();
        int distance = game.set_distance();

        int* newArr = game.createArrCheck(racerArr, typeR, distance);

        Camal camal(distance);
        Camal_Fast camal_Fast(distance);
        Centour centour(distance);
        Boots boots(distance);
        Carpet carpet(distance);
        Eagle eagle(distance);
        Broomstick broomstick(distance);

        std::cout << "Результаты гонки:" << std::endl;

        struct finish
        {
            std::string name;
            double time;
        };

        int count = 0;
        for (int i = 0; i < 8; i++) {
            if (newArr[i] != 0) {
                count++;
            }
        }

        std::vector<finish>result(count);

        for (int i = 0; i < count; i++) {
            int k = newArr[i];
            switch (k)
            {
            case 1:
                result.at(i).name = "Верблюд";
                result.at(i).time = camal.start_race();
                break;
            case 2:
                result.at(i).name = "Верблюд-быстроход";
                result.at(i).time = camal_Fast.start_race();
                break;
            case 3:
                result.at(i).name = "Кентавр";
                result.at(i).time = centour.start_race();
                break;
            case 4:
                result.at(i).name = "Ботинки-вездеходы";
                result.at(i).time = boots.start_race();
                break;
            case 5:
                result.at(i).name = "Ковер-самолет";
                result.at(i).time = carpet.start_race();
                break;
            case 6:
                result.at(i).name = "Орел";
                result.at(i).time = eagle.start_race();
                break;
            case 7:
                result.at(i).name = "Метла";
                result.at(i).time = broomstick.start_race();
                break;
            default:
                break;
            }
        }

        std::sort(result.begin(), result.end(), [](finish a, finish b) {
            return a.time < b.time;
            });

        for (int i = 0; i < count; i++) {
            std::cout << (i + 1) << ". " << result[i].name << " " << result[i].time << std::endl;
        }

        std::cout << "1. Провести еще одну гонку" << std::endl;
        std::cout << "2. Выйти" << std::endl;

        int choice;
        std::cin >> choice;

        if (choice == 1) {
            next = true;
        }
        else if (choice == 2) {
            return 0;
        }
        else {
            std::cout << "Попытка выбрать неправильный тип" << std::endl;
        }

        delete[] racerArr;
    }
    while (next);
}

