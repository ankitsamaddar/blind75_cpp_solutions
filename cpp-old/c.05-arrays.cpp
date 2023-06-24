/*
int arr[5] = {1, 2, 3, 4, 5};
arr -> &arr[0]
&arr -> whole array
If arr starts from memory address 2000,
the value of arr would be the memory address of the first element of the array, which is 2000.
the integer is 4 bytes .
the value of arr+1 would be the memory address of the third element of the array, which would be 2004.
the value of arr+2 would be the memory address of the third element of the array, which would be 2008.
the value of &arr+1 would be the memory address of the next block of memory after the array, which would be 2020.
Similarly, the value of `&arr+2` would be the memory address of the second block of memory after the array, which would be 2040.
*/

/*
The value of &arr+1 is 2020 because of pointer arithmetic.
When we add 1 to a pointer, the pointer is incremented by the size of the data type it points to.

In this case, &arr is a pointer to an array of integers,
so adding 1 to it increments the pointer by the size of an integer array,
which is 5 * 4 = 20 bytes.

Therefore, the memory address of the next block of memory after the array arr is 2000 + 20 = 2020.
*/

/*
If arr starts from memory address 2000,
the value of `&arr+2` would be the memory address of the second block of memory after the array, which is 2040.
This is because adding 2 to &arr increments the pointer by 2 times the size of the array, which is 2 * 5 * 4 = 40 bytes.

Therefore, the memory address of the second block of memory after the array arr is 2000 + 40 = 2040.
*/
