// В стиле С
#include <iostream>

using namespace std;


// -------------- structs ---
struct data
{
    int a;
};

struct List
{
    data A;
    List *next;
};


int main()
{
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


    return 0;
}
