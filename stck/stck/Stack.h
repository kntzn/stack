#pragma once
#include <stdio.h>

typedef unsigned long long int arrln;
#define STK_SZ_DEFAULT 1000
#define STK_POISON 557

template <typename dataType> class Stack
    {
    private:
        bool extendable, debug_output;
        arrln len, currentLen;
        dataType* container;
        
        bool extend ();

    public:
        // Constructor and destructor
        Stack (arrln Size = STK_SZ_DEFAULT, bool resizeable = false, bool debug = true);
        ~Stack ();

        // Getters
        dataType & top ();

        // Modifiers
        bool push (dataType value);
        bool pop ();
        bool shrink_to_fit ();

        // Size getters
        arrln size ();
        bool empty ();
    };



template<typename dataType>
inline bool Stack<dataType>::extend ()
    {
    // Memory allocation
    dataType* newContainer = (dataType*) calloc (2*len, sizeof (dataType));
    if (newContainer != nullptr)
        {
        for (int i = 0; i < len; i++)
            newContainer [i] = container [i];

        free (container);

        container = newContainer;
        
        len *= 2;

        return true;
        }
    else
        printf ("Failed to extend stack:\n\tFailed to allocate memory\n");

    return false;
    }

template<typename dataType>
inline Stack<dataType>::Stack (arrln Size, bool resizeable, bool debug)
    {
    extendable = resizeable;
    len = Size;
    currentLen = 0;
    debug_output = debug;

    if (debug_output)
        printf ("Stk debug enabled\n");
    
    if (len == 0)
        {
        printf ("Failed to init stack:\n\tStack size must be greater than zero\n");
        return;
        }

    // Memory allocation
    container = (dataType*) calloc (len, sizeof (dataType));
    if (container == nullptr)
        if (debug_output)
            printf ("Failed to init stack:\n\tFailed to allocate memory\n");
    else if (debug_output)
            printf ("Successfully allocated %d bytes\n", unsigned long long int (len * sizeof (dataType)));

    // Memory poisoning
    for (int i = 0; i < len; i++)
        container [i] = STK_POISON;
    }

template<typename dataType>
inline Stack<dataType>::~Stack ()
    {
    free (container);
    }

template<typename dataType>
inline dataType & Stack<dataType>::top ()
    {
    if (currentLen == 0)
        {
        if (debug_output)
            printf ("Failed to top ():\n\tStack is empty\n");

        return STK_POISON;
        }
    else
        return container [currentLen - 1];
    }

template<typename dataType>
inline bool Stack<dataType>::push (dataType value)
    {
    if (currentLen >= len)
        {
        if (!extendable)
            {
            if (debug_output)
                printf ("Failed to push ():\n\tStack is full\n");
            return false;
            }
        else
            extend ();
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
        if (debug_output)
            printf ("Failed to pop ():\n\tStack is empty\n");
        return false;
        }

    container [currentLen-1] = STK_POISON;
    currentLen--;

    return true;
    }

template<typename dataType>
inline bool Stack<dataType>::shrink_to_fit ()
    {
    // Memory allocation
    dataType* newContainer = (dataType*) calloc (currentLen, sizeof (dataType));
    if (newContainer != nullptr)
        {
        for (int i = 0; i < currentLen; i++)
            newContainer [i] = container [i];

        free (container);

        container = newContainer;

        len = currentLen;

        return true;
        }
    else if (debug_output)
        printf ("Failed to shrink stack:\n\tFailed to allocate memory\n");

    return false;
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
