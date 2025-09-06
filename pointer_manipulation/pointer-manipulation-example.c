#include <stdio.h>

int main ( void ) {

    int *ptr1, *ptr2, x = 5, y = 10;

    ptr1 = &x; // here we are pointing ptr1 to variable x
    printf ( "%d\n", *ptr1 ); //this prints 5 which is the value of x

    ptr2 = &y; // and ptr2 pointing to variable y
    y += 2; // y is now  12
    printf( "%d\n", *ptr2 ); // prints 12 because we are pointing to the value of y

    *ptr1 += 5; // adds 5 to x
    *ptr2 /= 2; // divides y by 2
    printf ( "%d\n", x ); // prints 10
    printf ( "%d\n", y ); // prints 6

    x = *ptr1 * *ptr2; // x = value of x * value of y = 10 * 6 = 60
    ptr2 = ptr1; // now ptr2 and ptr1 are both pointing to x
    printf ( "%d\n", *ptr2 ); // prints 60 which is the value of x

    ptr1 = &y; // ptr1 is now pointing to y
    y = *ptr2 - 2; // y = (*ptr2 - 2) = (x - 2) = 60 - 2 = 58
    printf ( "%d\n", y ); // y = 58
    printf ( "%d\n", x ); // x is still 60

    ptr1 = ptr2; // ptr1 now is also pointing to x, same as ptr2
    printf ( "%d\n", *ptr1 ); // value of x which is 60
    printf ( "%d\n", *ptr2 ); // also value of x which is 60

    x = x * 3;
    printf ( "%d\n", x );

    return 0;
}