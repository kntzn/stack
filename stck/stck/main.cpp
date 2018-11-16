#include <stdlib.h>
#include "Stack.h"
#include <stack>

int main ()
    {    
    Stack <int> stk (5, true);
   
    for (int i = 0; i < 10; i++)
        stk.push (i);

    for (int i = 0; i < 10; i++)
        {
        printf ("%d\n", stk.top ());
        stk.pop ();
        }
    //std::stack <int> std_stk;
    

    // TODO:
    
    // swap
    
    system ("pause");
    }