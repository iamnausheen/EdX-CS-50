# include <stdio.h>

int main(void)
{
    // Pointer to an entire array
    int integers[] = {1, 2, 3, 4, 5};
    // An array of 5 integer pointers = int*p[5], each element holds a memory address.
    // Pointer to an array of 5 integers: it holds the memory address of the first element of the array but can be used to access all elements
    int(*p)[] = &integers; //brackets give precedence to * operator
    printf("%p %p %p\n%i %i %i %i %i\n", p, *p, &integers, (*p)[0], (*p)[1], (*p)[2], (*p)[3], (*p)[4]);
/*
In most cases, you're correct that *p would dereference the pointer
 and give you the value it's pointing to.
 However, in this case p is a pointer to an array,
 not a pointer to a single integer.
 When you dereference p with *p, you're getting the array it points to. In C, an array essentially "decays" into a pointer to its first element when used in this context, which is why *p gives you the memory address of the first element. To access the individual elements of the array, you need to use (*p)[index].

If p were not a pointer to the array integers but simply just a pointer storing the memory address of the first element
we couldn't have accessed elements in this way, rather would have had to use pointer arithematic.
Therefore, p doesn't work as p[0], p[1] but rather (*p) - dereference the pointer, (*p)[0] go to location 0
(*p)[1] - go to one location ahead of *p, the [] do the pointer arithmetic for us.
*/



    int integers[] = {1, 2, 3, 4, 5};
    int* p = integers;
    printf("%p %i %p\n%i %i %i %i %i\n", p, *p, &integers, p[0], p[1], p[2], p[3], p[4]);

    /*
    The name integers is a constant pointer to the first element of the array.
    The compiler knows the size and location of the array at compile time,
    so it doesn't need to store the address separately.
    When you use integers, it automatically refers to the memory starting at the address of the first element.
    */

   /*
   Memory Allocation: Allocate a contiguous block of memory.
Initialization: Initialize the memory with default or specified values.
Pointer Management: Maintain a pointer to the start of the array.
In pseudocode:

function createArray(size, initialValue):
    array = allocateMemory(size * sizeof(int))
    for i from 0 to size - 1:
        array[i] = initialValue
    return array
This pseudocode outlines the basic steps.
The actual implementation would depend on the specifics of your language and its runtime environment.
   */

  /*
  So an array is a special type of pointer that doesn't need to store a memory address for accessing that memory

ddb
Yes, an array name acts like a constant pointer to the first element of the array. The memory address is known at compile time, so it doesn't need to store the address separately.

you
Because typically when I create a pointer to perhaps an integer I expect that pointer ti have it's own memory block which stores an address

ddb
You're correct! When you create a pointer to an integer, the pointer itself has its own memory block to store the address of the integer.

For example:

int x = 5;
int *p = &x;
Here, p is a pointer that has its own memory block, storing the address of x.

In contrast, the name of an array directly refers to the memory block allocated for the array elements,
so it doesn't need a separate memory block to store an address.
  */

/*
Do arrays and strings both behave in the same fashion

ddb
Yes, arrays and strings in C behave similarly.
A string is essentially an array of characters ending with a null terminator ('\0').
Both use contiguous memory blocks, and their names act as pointers to the first element.

you
So even a string or literally any other array for that matter would not need to store the memory address

ddb
Correct, the name of an array or a string in C acts as a constant pointer to the first element,
so it doesn't need a separate memory block to store the address.
The address is implicitly known and used by the compiler.
*/
}
