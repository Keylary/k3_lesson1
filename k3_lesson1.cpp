#include <iostream>
#include <fstream>
#include <optional>
#include <tuple>
#include <vector>
#include <algorithm>
#include <string>

// Задание 1. Создайте структуру Person с 3 полями: фамилия, имя, отчество. Поле отчество должно быть опционального типа, т.к. не у всех людей есть отчество.
// Перегрузите оператор вывода данных для этой структуры. Также перегрузите операторы < и == (используйте tie).

struct Person
{
    Person() {}
    Person(std::string sn, std::string n, std::string pn) : surname(sn), name(n), patronymic(pn) { }
    std::string surname = "Mew";
    std::string name = "Woof";
    std::string patronymic;
    std::optional<std::string> getfullname() {
            if (!patronymic.empty())
                return surname + "\t" + name + "\t" + patronymic + "\t";
                return surname + "\t" + name + "\t\t";
       
    };
};

std::ostream& operator<<(std::ostream& os, Person& p) {
    return os << *p.getfullname();
}

bool operator==(const Person& p1, const Person& p2)
{
    return tie(p1.surname, p1.name, p1.patronymic) ==
        tie(p2.surname, p2.name, p2.patronymic); 
}

bool operator<(const Person& p1, const Person& p2)
{
    return tie(p1.surname, p1.name, p1.patronymic) <
        tie(p2.surname, p2.name, p2.patronymic);
}

// Задание 2. Создайте структуру PhoneNumber с 4 полями:
//·         код страны(целое число)
//·         код города(целое число)
//·         номер(строка)
//·         добавочный номер(целое число, опциональный тип)
// Для этой структуры перегрузите оператор вывода.Необходимо, чтобы номер телефона выводился в формате : +7(911)1234567 12, 
// где 7 – это номер страны, 911 – номер города, 1234567 – номер, 12 – добавочный номер.Если добавочного номера нет, то его выводить не надо.

struct PhoneNumber {
    int p_country = 45;
    int p_town = 83;
    int p_number = 1234567;
    int p_extention =0;
    std::optional<std::string> getfullnumber() { 
        std::string result; 
        result = '+' + std::to_string(p_country) + '(' + std::to_string(p_town) + ')' + std::to_string(p_number);
        if (p_extention) result = result + ' ' + std::to_string(p_extention); 
        return result;
    }
};
std::ostream& operator<<(std::ostream& os, PhoneNumber& p) {
    return os << *p.getfullnumber() << std::endl;
}




//
//class Less {
//public:
//    bool operator() (const int& left, const int& right) {
//        return left < right;
//    }
//};





int main()
{
   


        //std::vector<int> numbers = { 3,4,1,5,2 };
        //Less less;      //создаём функциональный объект, т. е. функтор
        //sort(numbers.begin(), numbers.end(), less);   //передаём функтор в алгоритм сортировки
        //for (const int& n : numbers) {
        //    std::cout << n << " ";
        //}
    



   // ifstream file("PhoneBook.txt"); // путь к файлу PhoneBook.txt
    // PhoneBook book(file);
    //cout << book;

    //cout << "------SortByPhone-------" << endl;
    //book.SortByPhone();
    //cout << book;

    //cout << "------SortByName--------" << endl;
    //book.SortByName();
    //cout << book;

    //cout << "-----GetPhoneNumber-----" << endl;
    //auto print_phone_number = // лямбда функция, которая принимает фамилию и выводит номер телефона этого человека, либо строку с ошибкой

    //// вызовы лямбды
    //print_phone_number("Ivanov");
    //print_phone_number("Petrov");

    //cout << "----ChangePhoneNumber----" << endl;
    //book.ChangePhoneNumber(Person{ "Kotov", "Vasilii", "Eliseevich" }, PhoneNumber{ 7, 123, "15344458", std::nullopt });

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

