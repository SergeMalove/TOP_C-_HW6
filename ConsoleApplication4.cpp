#include <iostream>
#include <vector>

//Создайте любую структуру(сами решите) с разными полями. Создайте три объекта этой структуры в main и дайте
//пользователю возможность заполнить эти структуры(то есть чтобы он вводил данные с клавиатуры).
//Дополнительно: напишите функцию для вывода структуры на экран и выведите получившиеся структуры.
//Еще дополнительно: попробуйте сделать ввод структуры через функцию : функция принимает структуру по ссылке 
//и уже в функции пользователь вводит данные.Такой подходит позволит вам не дублировать код три раза (когда 
//вы вводите данные структуры).
//Ответ представить в виде cpp файла.

struct smartPhone
{
    std::string brand;
    std::string model;
    double screenSize;
    int memoryVolume;
    bool wirelessCharge;
};

void fillPhoneList(std::vector<smartPhone>& smartPhones)
{
    int listSize = 0;

    std::cout << "Введите количество элементов в списке: ";

    std::cin >> listSize;
    std::cout << std::endl;

    for (int i = 0; i < listSize; ++i)
    {
        smartPhone smartPhone;
        int wirlessChargeFlag;

        std::cout << "Введите марку телефона: ";
        std::cin >> smartPhone.brand;
        std::cout << "Введите модель телефона: ";
        std::cin >> smartPhone.model;
        std::cout << "Введите диаганаль экрана: ";
        std::cin >> smartPhone.screenSize;
        std::cout << "Введите объем памяти: ";
        std::cin >> smartPhone.memoryVolume;
        std::cout << "Есть ли беспроводная зарядка? (Нет - 0, Да - любой символ): ";
        std::cin >> wirlessChargeFlag;

        if (wirlessChargeFlag == 0)
        {
            smartPhone.wirelessCharge = false;
        }
        else
        {
            smartPhone.wirelessCharge = true;
        }

        smartPhones.push_back(smartPhone);
        std::cout << std::endl;
    }
}

void printPhoneList(const std::vector<smartPhone>& smartPhones)
{
    for (smartPhone smartPhone : smartPhones)
    {
        std::cout << "Марка телефона: " << smartPhone.brand << std::endl;
        std::cout << "Модель телефона: " << smartPhone.model << std::endl;
        std::cout << "Диаганаль экрана: " << smartPhone.screenSize << std::endl;
        std::cout << "Объем памяти: " << smartPhone.memoryVolume << std::endl;
        if (smartPhone.wirelessCharge == true)
        {
            std::cout << "Беспроводная зарядка: есть" << std::endl;
        }
        else
        {
            std::cout << "Беспроводная зарядка: нет" << std::endl;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    std::vector<smartPhone> smartPhones;

    fillPhoneList(smartPhones);
    printPhoneList(smartPhones);
}