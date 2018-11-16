#include <stdlib.h>
#include "Stack.h"

int main ()
    {    
    Stack <int> stk (5, true);
   
    for (int i = 0; i < 7; i++)
        stk.push (i);
    
    stk.shrink_to_fit ();

    printf ("%d\n", stk.size ());
    //std::stack <int> std_stk;
    

    // TODO:
    
    // swap
    
    system ("pause");
    }