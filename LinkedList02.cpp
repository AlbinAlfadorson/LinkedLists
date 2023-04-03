#include <iostream>
#include <random>

using namespace std;


// -------------- structs ---
struct Data
{
    int a;

};

struct List
{
    Data A;
    List *next;
};


int main()
{

   // Вариант определения размера списка №_1
   /*int N = rand();*/


   // Вариант определения размера списка №_2
   int N(0);
   cin >> N;

   Data *dataA = new Data[N];
   for(int i(0); i < N; i++)
   {
       Data D;
       D.a = i;
       *(dataA) = D;
       cout << dataA->a << " ";
       *(dataA + i);

   }



   List *Begin = NULL;
   Begin = new List;
   Begin-> A.a = 11;
   Begin->next = NULL;

   List *End = new List;
   End = NULL;
   End = Begin;

   for(int i(0); i < 5; i++)
   {
       End->next = new List;
       End = End->next;
       End->A.a = i;
       End->next = NULL;
       cout << End->A.a;

   }
   delete [] dataA;


    return 0;
}
