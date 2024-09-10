#ifndef H_Array_Modify
#define H_Array_Modify
#include <fstream>


class Array_Modify {
public:
	int findNum(int, int position = 1) const;
	/*function to find array index with matching input integer.
	Returns array element containing input integer*/

	int* modifyNum(size_t, int);
	/*Modify the number in an array.
	Returns old number and new number*/

	void addNum(int);
	/*Add number to end of array*/

	void removeNum(size_t);
	/*Intakes index of an array and 
	removes the integer at that index*/

Array_Modify() {			//constructor with no parameters
		initializeArray();
	}

Array_Modify(std::string file) {	//constructor with file name string as parameter
		fileName = file;
		initializeArray();
	}
~Array_Modify() {
	delete[] numbers;
}
private:
	std::fstream inputFile;
	std::string fileName = "A1input.txt"; //identifier for the file being accessed and modified
	size_t maxIndex; //contains the number of elements in the array (minus 1)
	int capacity = 10; //array capacity, default 10
	int* numbers;//points to array gathered from input file
	int numSwap[2];	//array size 2 for storing new value and old value from function modifyNum

	void initializeArray();
	/*initializes array using values from input file*/
};

#endif
