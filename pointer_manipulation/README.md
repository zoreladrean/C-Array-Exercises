# Pointer Manipulation Example in C

This program demonstrates pointer operations and their effects on variables. This is useful for understanding basic pointer operations in C, including assignment, dereferencing, and manipulation of values through pointers.


1.  **Pointer Assignment**: Shows how pointers can be assigned to variables using the address-of operator (`&`)
    
2.  **Dereferencing**: Demonstrates accessing and modifying values through pointers using the dereference operator (`*`)
    
3.  **Pointer Reassignment**: Illustrates how pointers can be redirected to different variables
    
4.  **Value Manipulation**: Shows how changes through pointers affect the original variables


>-   Pointers store memory addresses rather than values
    
>-   The `*` operator is used to access the value at a pointer's address
    
>-   The `&` operator gets the address of a variable
    
>-   Multiple pointers can reference the same variable
    
>-   Changes made through a pointer affect the original variable

---
### Code:
```c
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
```
---
## 📊 Execution Trace Table

| Step | Code                              | x   | y   | ptr1 → | ptr2 → | *ptr1 | *ptr2 | Output |
|------|-----------------------------------|-----|-----|--------|--------|-------|-------|--------|
| 0    | int *ptr1, *ptr2, x=5, y=10;      | 5   | 10  | —      | —      | —     | —     | —      |
| 1    | ptr1 = &x;                        | 5   | 10  | x      | —      | 5     | —     | —      |
| 2    | printf("%d\n", *ptr1);            | 5   | 10  | x      | —      | 5     | —     | 5      |
| 3    | ptr2 = &y;                        | 5   | 10  | x      | y      | 5     | 10    | —      |
| 4    | y += 2;                           | 5   | 12  | x      | y      | 5     | 12    | —      |
| 5    | printf("%d\n", *ptr2);            | 5   | 12  | x      | y      | 5     | 12    | 12     |
| 6    | *ptr1 += 5;                       | 10  | 12  | x      | y      | 10    | 12    | —      |
| 7    | *ptr2 /= 2;                       | 10  | 6   | x      | y      | 10    | 6     | —      |
| 8    | printf("%d\n", x);                | 10  | 6   | x      | y      | 10    | 6     | 10     |
| 9    | printf("%d\n", y);                | 10  | 6   | x      | y      | 10    | 6     | 6      |
| 10   | x = *ptr1 * *ptr2;                | 60  | 6   | x      | y      | 60    | 6     | —      |
| 11   | ptr2 = ptr1;                      | 60  | 6   | x      | x      | 60    | 60    | —      |
| 12   | printf("%d\n", *ptr2);            | 60  | 6   | x      | x      | 60    | 60    | 60     |
| 13   | ptr1 = &y;                        | 60  | 6   | y      | x      | 6     | 60    | —      |
| 14   | y = *ptr2 - 2;                    | 60  | 58  | y      | x      | 58    | 60    | —      |
| 15   | printf("%d\n", y);                | 60  | 58  | y      | x      | 58    | 60    | 58     |
| 16   | printf("%d\n", x);                | 60  | 58  | y      | x      | 58    | 60    | 60     |
| 17   | ptr1 = ptr2;                      | 60  | 58  | x      | x      | 60    | 60    | —      |
| 18   | printf("%d\n", *ptr1);            | 60  | 58  | x      | x      | 60    | 60    | 60     |
| 19   | printf("%d\n", *ptr2);            | 60  | 58  | x      | x      | 60    | 60    | 60     |
| 20   | x = x * 3;                        | 180 | 58  | x      | x      | 180   | 180   | —      |
| 21   | printf("%d\n", x);                | 180 | 58  | x      | x      | 180   | 180   | 180    |

---
## 🖼 Memory Diagram (ASCII style)

### Step 1: `ptr1 = &x;`


### Step 5: After `y += 2;`

`x = 5        y = 12
ptr1 → x     ptr2 → y` 

### Step 7: After `*ptr1 += 5; *ptr2 /= 2;`

`x = 10       y = 6
ptr1 → x     ptr2 → y` 

### Step 10: After `x = *ptr1 * *ptr2;`

`x = 60       y = 6
ptr1 → x     ptr2 → y` 

### Step 11: After `ptr2 = ptr1;`

`x = 60       y = 6
ptr1 → x     ptr2 → x` 

### Step 14: After `y = *ptr2 - 2;`

`x = 60       y = 58
ptr1 → y     ptr2 → x` 

### Step 20: After `x = x * 3;`

`x = 180      y = 58
ptr1 → x     ptr2 → x`

---
### Program Output:
```text
5
12
10
6
60
58
60
60
60
180
```