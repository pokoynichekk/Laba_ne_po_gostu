#include <iostream>
#include "Math.h"
#include "windows.h"

int main()
{   
    setlocale(LC_ALL, "Russian");
    int menuOption;
    Math *math = new Math();
    for (;;)
    {
        std::cout << "1. Вывести все корни.\n2. Метод половинного деления.";
        std::cout << "\n3. Метод хорд.\n4. Метод Касательных";
        std::cout << "\n5. Метод итераций.\n6. Вывести отрезки.\n";
        std::cout << "\n7. Выход. \n\nВыберите пункт: ";
        std::cin >> menuOption;

        switch (menuOption)
        {
            case 1:
            {
                math->Find();
                system("pause");
                break;
            }
            case 2:
            {
                std::cout << math->DichotomyMethod(-2.8, 2.8, 0.001) << std::endl;
                system("pause");
                break;
            }
            case 3:
            {
                std::cout << math->SecantMethod(-2.8, 2.8, 0.001) << std::endl;
                system("pause");
                break;
            }
            case 4:
            {
                std::cout << math->NewtonsMethod(-2.8, 0.001) << std::endl;
                system("pause");
                break;
            }
            case 5:
            {
                std::cout << math->IterationMethod(1.2, 0.001) << std::endl;
                system("pause");
                break;
            }
            case 6:
            {
                math->FindPoints();
                system("pause");
                break;
            }
            case 7:
            {
                return 0;
            }
            default:
            {
                break;
            }
        }
        system("cls");
    }

}
