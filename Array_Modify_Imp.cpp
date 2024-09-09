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
		if (inputFile.peek() == ' ' || inputFile.peek() == '\n' || inputFile.peek() == '\r') {
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

int Array_Modify::findNum(int integer, int position) const {
    if (position<1 || position>maxIndex) {
		throw std::out_of_range("In function findNum, the value of position is out of range.");
	}
	int numPosition = 0;	//counts number of times the entered integer has been found
	for (int i = 0; i <= maxIndex; i++) {	//iterates through array
		if (numbers[i] == integer) {		//detects when the value of the current array element is equal to the integer being searched
			numPosition++;
			if(numPosition == position){    //if numPosition has incremented to equal the 
			    return i;
			}
		}
	}
	
	return -1; //return -1 if integer is not found
}

int* Array_Modify::modifyNum(size_t index, int newValue) {
	if (index<0 || index>maxIndex) {
		throw std::out_of_range("In function modifyNum, the value of index is out of range.");
	}
	numSwap[0] = newValue;	//first element contains new value
	numSwap[1] = numbers[index];	//second element contains old value
	numbers[index] = newValue; //assigns new value to the chosen array element
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
		throw std::out_of_range("In function removeNum, the value of index is out of range.");
	}
	while (index <= maxIndex) {
		numbers[index] = numbers[index + 1];	//shifts array elements down one index, starting with the one being removed
		index++;
	}
	maxIndex--;		//decrement maxIndex to account for 1 less element
}
