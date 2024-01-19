/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

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


int RandData_for_List(unsigned long *seed); // Метод для занесения в список случайных значений для последующей сортировки




void Init(List **begin, int seed, int length, int(*RandData_for_List)(unsigned long *));
void Print(List *begin, int length);

int main()
{
   srand(time(0));
   
   List* begin = NULL; // Начало списка (исток)
   begin = new List;
   begin->data.key = 0;
   begin->next = NULL;
   
   unsigned long seed  = 1; // Стартовое значение данных для создания выборки рандомных значений в List
   int length = 3; // Изначальная длинна списка
   
   cout << "Пожалуйста, задайте длинну списка или он останется длинной равный 5, по умолчанию" << endl;
   cin >> length;
   cout << endl;
   
   
  // Init(*begin, seed, length, int(*RandData_for_List)(unsigned long *));
  // void Print(List *begin, int length);
   
   
   
   

    getch();
    return 0;
}

int RandData_for_List(unsigned long &seed)
{
    seed = seed * 1103515245 + 12345; // Линейный конгруэнтный метод
    return (seed / 65536) % 32777;    // Возвращаем значение в диапазоне 0 - 32776
}



void Init(List **begin, int seed, int length, int (*RandData_for_List)(unsigned long *))
{
   
   for(int i(length - (length - 1)); i <= length; i++)
   {

   int RandData_for_List(unsigned long &seed);
   (*begin)->next = new List;
   (*begin) = (*begin)->next;
   (*begin)->data.key = seed;
   (*begin)->next = NULL;
   
   };
   
}

void Print(List *begin, int length)
{
    List *print = begin;
    
    for(int i(length - (length - 1)); i <= length; i++)
    {
        cout << print->data.key << " -> ";
        print = print->next;
    }
    cout << "NULL";
    
}
