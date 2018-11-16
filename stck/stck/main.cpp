#include <stdlib.h>
#include "Stack.h"

int main ()
    {    
    Stack <int> stk (10);
   

    for (int i = 0; i < 12; i++)
        stk.push (2);
    for (int i = 0; i < 12; i++)
        stk.pop ();

    stk.top () = 3;
    
    printf ("%d\n", stk.top ());

    // TODO:
    
    // swap
    
    system ("pause");
    }