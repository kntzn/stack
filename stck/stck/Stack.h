#pragma once
#include <stdio.h>

typedef unsigned long long int arrln;
#define STK_SZ_DEFAULT 1000

template <typename dataType> class Stack
    {
    private:
        bool extendable;
        arrln len, currentLen;
        dataType* container;

    public:
        Stack (arrln Size = STK_SZ_DEFAULT, bool resizeable = true);

        dataType & top ();
    };



template<typename dataType>
inline Stack<dataType>::Stack (arrln Size, bool resizeable)
    {
    extendable = resizeable;
    len = Size;
    currentLen = 0;

    if (len == 0)
        {
        printf ("Failed to init stack:\n\tStack size must be greater than zero\n");
        return;
        }

    // Memory allocation
    container = (dataType*) calloc (len, sizeof (dataType));
    if (container == nullptr)
        printf ("Failed to init stack:\n\tFailed to allocate memory\n");
    else
        printf ("Successfully allocated %d bytes\n", len*sizeof (dataType));
    }

template<typename dataType>
inline dataType & Stack<dataType>::top ()
    {
    if (currentLen == 0)
        {
        printf ("Failed to top ():\n\tStack is empty\n");
        return container [0];
        }

    return container [currentLen-1];
    }
