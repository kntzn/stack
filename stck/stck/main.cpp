#include <stdlib.h>
#include "Stack.h"

int main ()
    {    
    Stack <int> stk (10);
    
    for (int i = 0; i < 15; i++)
        stk.push (2);

    stk.top () = 3;
    
    printf ("%d\n", stk.top ());

    // TODO:
    // push
    // pop
    // swap
    // top

    system ("pause");
    }