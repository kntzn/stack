#pragma once
#include <stdio.h>

typedef unsigned long long int arrln;
#define STK_SZ_DEFAULT 1000
#define STK_POISON 557

template <typename dataType> class Stack
    {
    private:
        bool extendable;
        arrln len, currentLen;
        dataType* container;
        
    public:
        Stack (arrln Size = STK_SZ_DEFAULT, bool resizeable = false);

        dataType & top ();

        bool push (dataType value);
        bool pop ();

        arrln size ();
        bool empty ();
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

    // Memory poisoning
    for (int i = 0; i < len; i++)
        container [i] = STK_POISON;
    }

template<typename dataType>
inline dataType & Stack<dataType>::top ()
    {
    if (currentLen == 0)
        {
        printf ("Failed to top ():\n\tStack is empty\n");

        // Weired
        int exeption_trigger = 1 / (currentLen);
        }
    else
        return container [currentLen - 1];
    }

template<typename dataType>
inline bool Stack<dataType>::push (dataType value)
    {
    if (currentLen >= len && !extendable)
        {
        printf ("Failed to push ():\n\tStack is full\n");
        return false;
        }
    
    container [currentLen] = value;
    currentLen++;

    return true;
    }

template<typename dataType>
inline bool Stack<dataType>::pop ()
    {
    if (currentLen == 0)
        {
        printf ("Failed to pop ():\n\tStack is empty\n");
        return false;
        }

    container [currentLen-1] = STK_POISON;
    currentLen--;

    return true;
    }

template<typename dataType>
inline arrln Stack<dataType>::size ()
    {
    return currentLen;
    }

template<typename dataType>
inline bool Stack<dataType>::empty ()
    {
    return (currentLen == 0);
    }
