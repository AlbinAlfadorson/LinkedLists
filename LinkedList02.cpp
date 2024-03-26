#include <iostream>
#include <random>
#include <ctime>
#include <conio.h>
#include <stdio.h>

using namespace std;

//-----------------------------------------------------------------------------------------------------------

struct A
{
    int key;
};
struct List
{
    A data;
    List* next;
};

//-----------------------------------------------------------------------------------------------------------

int RandData_for_List(unsigned long& seed, int& i);

//-----------------------------------------------------------------------------------------------------------

void Init(List** begin, unsigned long& seed, int length, int(*RandData_for_List)(unsigned long&, int&));
void add_begin(List** begin, unsigned long& seed, int& length, int(*RandData_for_List)(unsigned long&, int&));
void Insert(List** begin, unsigned long& seed, int& length, int(*RandData_for_List)(unsigned long&, int&));
void SOrtList(List** begin, int **Array, int length);
void Print(List* begin, int length);
void DelateListMemorY(List** begin);

//-----------------------------------------------------------------------------------------------------------

int main()
{
    setlocale(LC_ALL, "Russian");
    

    List* begin = NULL; // Начало списка (исток)
    begin = new List;
    begin->data.key = 0;
    begin->next = NULL;
    int* Array = new int;

    unsigned long seed = 1; // Стартовое значение данных для создания выборки рандомных значений в List
    int length = 1; // Изначальная длинна списка

    cout << "Пожалуйста, задайте длинну списка или он останется длинной равный 5, по умолчанию" << endl;
    cin >> length;
    cout << endl;


    Init(&begin, seed, length, &RandData_for_List);
    Print(begin, length);
    cout << endl;
    add_begin(&begin, seed, length, &RandData_for_List);
    Print(begin, length);

    Insert(&begin, seed, length, &RandData_for_List);
    Print(begin, length);
    
    SOrtList(&begin, &Array, length);
    Print(begin, length);

    DelateListMemorY(&begin);

    delete [] Array;

    _getch();
    return 0;
}



int RandData_for_List(unsigned long& seed, int& i)
{
    srand(time(NULL));

    seed = rand() / i;
    return seed;
}

//-----------------------------------------------------------------------------------------------------------

void Init(List** begin, unsigned long& seed, int length, int (*RandData_for_List)(unsigned long&, int&))
{

    List* end = (*begin);
    for (int i(length - (length - 1)); i <= length; i++)
    {

        RandData_for_List(seed, i);

        end->next = new List;
        end = end->next;
        end->data.key = seed;
        end->next = NULL;

    };

}

void add_begin(List** begin, unsigned long& seed, int& length, int(*RandData_for_List)(unsigned long&, int&))
{
    srand(time(NULL));
    List* past = new List;
    int somedata = (rand() % 10);
    past->data.key = RandData_for_List(seed, somedata);
    past->next = (*begin);
    (*begin) = past;
    length++;

}

void Insert(List** begin, unsigned long& seed, int& length, int(*RandData_for_List)(unsigned long&, int&))
{
    srand(time(NULL));
    int somedata = (rand() % 10);

    List* INS = new List;
    INS->data.key = RandData_for_List(seed, somedata);
    if ((*begin) == NULL)
    {
        (*begin) = INS;
        (*begin)->next = NULL;
        length++;
        return;

    };
    int ins;
    cout << endl;
    cout << "Если вы хотите вставить элемент в список, укажите место вставки от " << length - (length - 1) << " до" << length;
    cout << endl;
    cin >> ins;

    if (ins >= length)
    {
        return;
    }


    List* step = new List;
    step = (*begin);
    for (int i(0); i < ins - 2; i++)
    {
        step = step->next;

    }

    INS->next = step->next;
    step->next = INS;

    length++;
}

void SOrtList(List** begin, int **Array, int length)
{
    List* sortList = (*begin);

    if (sortList == NULL || sortList->next == NULL)
    {
        return;
    }

    const int A = length;

    int *Arraytemp = new int;

    List* SWAPdata = (*begin); 
    long long temp;
    SWAPdata = (*begin);
    for (int i(0); i < length; i++)
    {
        if (SWAPdata->next != NULL)
        {
           
            (*Array)[i] = SWAPdata->data.key;
            SWAPdata = SWAPdata->next;

        }
        
    }


    for (int i(0); i < length; i++)
    {
        for (int j(i + 1); j < length; j++)
        {
            if ((*Array)[i] > (*Array)[j])
            {
                swap((*Array)[i], (*Array)[j]);

            }
        }
    }


    for (int i(0); i < length; i++)
    {
        cout << endl << (*Array)[i] << endl;

    }
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


void DelateListMemorY(List** begin)
{
    List* t;
    List* L;
    if ((*begin) == NULL)
    {
        return;
    }


    while (begin)
    {
        t = (*begin);
        (*begin) = (*begin)->next;
        delete t;

    }
    begin = NULL;
}
