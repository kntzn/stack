#include <stdlib.h>
#include "Stack.h"

int main ()
    {    
    Stack <int> stk (10);
   
    printf ("%d\n", stk.size ());
    printf ("%d\n", stk.empty ());

    for (int i = 0; i < 12; i++)
        {
        stk.push (2);
        //printf ("%d\n", stk.size ());
        }
    
    printf ("%d\n", stk.empty ());

    stk.top () = 3;
    
    printf ("%d\n", stk.top ());

    // TODO:
    
    // swap
    
    system ("pause");
    }