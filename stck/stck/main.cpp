#include <stdlib.h>
#include "Stack.h"
#include <stack>
#include <time.h>

#define N_TST 10000000

int main ()
    {
    Stack <int> stk (1000, true, false);
    std::stack <int> stk_std;

    clock_t start = clock ();
    for (int i = 0; i < N_TST; i++)
        {
        stk_std.push (228);
        }
    for (int i = 0; i < N_TST; i++)
        {
        stk_std.pop ();
        }
    int std_rst = clock () - start;
    printf ("std: %d ms\n", std_rst);
    
    start = clock ();
    for (int i = 0; i < N_TST; i++)
        {
        stk.push (228);
        }
    for (int i = 0; i < N_TST; i++)
        {
        stk.pop ();
        }
    int stk_rst = clock () - start;
    printf ("stk: %d ms\n", stk_rst);

    printf ("stk is %lf times faster\n", double (std_rst) / double (stk_rst));

    system ("pause");
    }