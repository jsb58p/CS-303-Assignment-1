#include <iostream> 
#include <fstream>
#include <string>
#include "Array_Modify.h"

void Array_Modify::initializeArray() {
	int value = 0;
	inputFile.open(fileName);
	maxIndex = 0;
	numbers = new int[capacity];
	/*processes data while end of file is not reached*/
	while (!inputFile.eof()) {
		/*statement checks whether array bounds have been reached*/
		if (maxIndex + 1 == capacity) {
			int* temp = numbers;	//pointer to temporarily hold location of old array while elements are copied to new array
			capacity *= 2;			//increase capacity for creation of new array
			numbers = new int[capacity];
			for (int i = 0; i < maxIndex; i++) {	//placing values in new array
				numbers[i] = temp[i];
			}
			delete[] temp; //delete the old array
		}
		/*statement to detect spaces, which indicates the end of an integer*/
		if (inputFile.peek() == ' ' || inputFile.peek() == '\n') {
			numbers[maxIndex] = value;		//assigns the current integer from "value" to the element at maxIndex
			value = 0;					//resets value to 0 in preparation for next element.
			inputFile.ignore(1, ' ');   //ignore the space between current and next integer
			
			maxIndex++;	//once the end of an integer has been reached, the maxIndex, counting the number of integers

		}
		/*Following statement detects whether end of file has been reached*/
		else if(!inputFile.eof()) {
			value *= 10;				//multiply value by 10, this allows for correct decimal placement for integers with multiple digits
			value += inputFile.get() - 48;	//adds the next digit ("- 48" converts value from char to int)
			
			
		}
		/*This statement detects when the end of file is reached*/
		else if (inputFile.eof()) {
			numbers[maxIndex] = value;	//assigns "value" to the last index of the array when end of file is reached
			
		}
	}
}

int* Array_Modify::findNum(int integer) const {
	int listIndex = 0;		//index for array of found integers
	int listCapacity = 10;	//initial capacity of array
	int* listArray = new int[listCapacity];
	//cout << endl << integer << " is found at index: " << endl;
	for (int i = 0; i <= maxIndex; i++) {	//iterates through array
		if (numbers[i] == integer) {		//detects when the value of the current array element is equal to the integer being searched
			//cout << i << endl;
			listArray[listIndex] = i;
			listIndex++;
			if (listIndex + 1 == listCapacity) { //checks if array has been filled
				int* temp = listArray;	//pointer to temporarily hold location of old array while elements are copied to new array
				listCapacity *= 2;			//increase capacity for creation of new array
				listArray = new int[listCapacity];
				for (int i = 0; i < listIndex; i++) {	//placing values in new array
					listArray[i] = temp[i];
				}
				delete[] temp; //delete the old array
			}
		}
	}
	if (listIndex == 0) {			//statement handles situation where no number is found
		listArray[0] = -1;
		//cout << endl << integer << " was not found in the array." << endl;
	}
	return listArray;
}

int* Array_Modify::modifyNum(size_t index, int newValue) {
	if (index<0 || index>maxIndex) {
		throw out_of_range("In function modifyNum, the value of index is out of range.");
	}
	int numSwap[2];	//creates new array size 2 for storing new value and old value
	numSwap[0] = newValue;	//first element contains new value
	numSwap[1] = numbers[index];	//second element contains old value
	numbers[index] = newValue; //assigns new value to the chosen array element
	//cout << endl << "Old Value: " << numSwap[1]
	//	<< endl << "New Value: " << numSwap[0]
	//	<< endl;
	return numSwap;			//returns pointer to the array containing the new and old value
}


void Array_Modify::addNum(int numAdded) {
	/*following statement detects if array capacity has been reached*/
	if (maxIndex + 1 == capacity) {
		int* temp = numbers;	//pointer to temporarily hold location of old array while elements are copied to new array
		capacity *= 2;			//increase capacity for creation of new array
		numbers = new int[capacity];
		for (int i = 0; i < maxIndex; i++) {	//placing values in new array
			numbers[i] = temp[i];
		}
		delete[] temp; //delete the old array
	}
	maxIndex++;			
	numbers[maxIndex] = numAdded;	//assign numAdded to the last element of the array
}


void Array_Modify::removeNum(size_t index) {
	if (index<0 || index>maxIndex) {
		throw out_of_range("In function removeNum, the value of index is out of range.");
	}
	while (index <= maxIndex) {
		numbers[index] = numbers[index + 1];	//shifts array elements down one index, starting with the one being removed
		index++;
	}
	maxIndex--;		//decrement maxIndex to account for 1 less element
}

void Array_Modify::showArray() const {
	for (int i = 0; i <= maxIndex; i++) {	//outputs the elements of the array
		if (i % 10 == 0) {					//10 elements per row
			cout << endl;
		}
		cout << setw(5) << left << numbers[i];
	}
	cout << endl;

}
