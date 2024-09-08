#ifndef H_Array_Modify
#define H_Array_Modify

using namespace std;


class Array_Modify {
public:

	void initializeArray();
	/*initializes array using values from input file*/
	
	int* findNum(int) const;
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

Array_Modify(string file) {
		fileName = file;
		initializeArray();
	}
~Array_Modify() {
	delete[] numbers;
}
private:
	fstream inputFile;
	string fileName = "A1input.txt"; //identifier for the file being accessed and modified
	int maxIndex; //contains the number of elements in the array (minus 1)
	int capacity = 10; //array capacity, default 10
	int* numbers;//points to array gathered from input file
};

#endif
