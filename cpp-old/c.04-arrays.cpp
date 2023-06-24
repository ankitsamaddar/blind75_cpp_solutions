/*

*/

#include <iostream>

int main() {
	int arr[5] = {1, 2, 3, 4, 5};
	int* ptr = arr;

	for (int i = 0; i < 5; i++) {
		std::cout << "Address of arr[" << i << "]: "<<ptr<<": "<<arr[i]<<""<< std::endl;
		ptr++;
	}

	return 0;
	}
