#include <iostream>
#include <random>
#include <ctime>
#include <conio.h>

using namespace std;


struct A
{
    int key;
};
struct List
{
    A data;
    List* next;
};

int RandData_for_List(unsigned long& seed); // Метод для занесения в список случайных значений для последующей сортировки


void Init(List** begin, int seed, int length, int(*RandData_for_List)(unsigned long&));
void Print(List* begin, int length);

int main()
{

    List* begin = NULL; // Начало списка (исток)
    begin = new List;
    begin->data.key = 0;
    begin->next = NULL;

    unsigned long seed = 1; // Стартовое значение данных для создания выборки рандомных значений в List
    int length = 3; // Изначальная длинна списка

    cout << "Пожалуйста, задайте длинну списка или он останется длинной равный 5, по умолчанию" << endl;
    cin >> length;
    cout << endl;


    Init(&begin, seed, length, &RandData_for_List);
    Print(begin, length);



    _getch();
    return 0;
}

int RandData_for_List(unsigned long& seed)
{
    srand(time(0));

    seed = rand();
    return seed;
}



void Init(List** begin, int seed, int length, int (*RandData_for_List)(unsigned long&))
{

    List* end = (*begin);
    for (int i(length - (length - 1)); i <= length; i++)
    {
        
        //int RandData_for_List(unsigned long& seed);

        end->next = new List;
        end = end->next;
        end->data.key = (rand() + 1) * (i * (i - 1)) / i;
        seed = end->data.key;
        end->next = NULL;

    };

}

void Print(List* begin, int length)
{
    List* print = begin;

    for (int i(length - (length - 1)); i <= length; i++)
    {
        cout << print->data.key << " -> ";
        print = print->next;
    }
    cout << "NULL";

}
