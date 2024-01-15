#include "Array.hpp"
#include <iostream>

void basicTest() {
	Array<int> intArray(5);

	for (unsigned int i = 0; i < intArray.size(); ++i) {
		intArray[i] = i * 10;
	}

	for (unsigned int i = 0; i < intArray.size(); ++i) {
		std::cout << "arr[" << i << "] = " << intArray[i] << std::endl;
	}
}

void nestedClassTest() {
	Array<std::string> stringArray(3);

	try {
		std::string value = stringArray[5];
	} catch (const Array<std::string>::IndexNotFound& e) {
		std::cerr << e.what();
	}
}

void otherTest() {
	Array<double> arr1(4);
	arr1[0] = 1.1;
	arr1[1] = 2.2;
	arr1[2] = 3.3;
	arr1[3] = 4.4;

	Array<double> arr2(arr1);

	for (unsigned int i = 0; i < arr2.size(); ++i) {
		std::cout << "arr[" << i << "] = " << arr2[i] << std::endl;
	}

	Array<double> arr3;
	arr3 = arr1;

	for (unsigned int i = 0; i < arr3.size(); ++i) {
		std::cout << "arr[" << i << "] = " << arr3[i] << std::endl;
	}
}

int main(void) {
	basicTest();
	nestedClassTest();
	otherTest();
	return (0);
}
