# CS-303-Assignment-1

1. Download/Copy Files
2. Set up Main function
3. Run the code
4. Function Descriptions
5. Examples


# 1. Download/Copy Files
-Download or copy the Array_Modify.h and Array_Modify_Imp.cpp into the repository where the project running this program is stored.

-Ensure that the input file is also in the repository.

# 2. Set up Main function
-Main function must contain the following preprocessor directive for access to program:

    #include "Array_Modify.h"     



-Include the following preprocessor directive for input/output to console:

    #include <iostream>

-Declare an object of type Array_Modify:

The default constructor will use "A1input.txt" for the array initialization. To use a different file, use a string parameter when declaring the object to specify the file being used. Make sure to include the .txt extension.

Below is an example of declaring an object (numArray) of type Array_Modify with a parameter, then an example of declaring the object without a parameter:
		
  		Array_Modify numArray("A1input.txt"); //parameter

  		Array_Modify numArray; 		//no parameter, will use "A1input.txt" by default


-In order to handle out_of_range exceptions thrown by class member functions whose parameters may be invalid, main function should include try/catch block:

        try{
        /*this is where member functions should be called*/
        }
        catch(std::out_of_range& ex){
        std::cerr << "Out of range exception has ocurred" << std::endl;
		std::cerr << ex.what() << std::endl;
		abort();
        }

# 3. Run the code


After all previous steps have been completed, the user may use the object to access class member functions.
-
Functions can be called within the try/catch block to handle out_of_range exceptions.


# 4. Function Descriptions
**findNum()**

		int findNum(int, int position = 1);
	
A function to check if a certain integer exists in the array. If the number is present, returns the
index where the number is present. If the number is not present, returns -1.

Parameter 1: int
-
Integer to be searched for.

Parameter 2: int
-
Integer representing the repition of the integer being searched for. Default is 1. If there are n array elements containing the value from Parameter 1, then passing n for the second parameter will return
the index of the nth Parameter 1 value. If the value from Paramter 1 is not found, or the value passed for Parameter 2 is greater than n, then function returns -1.

-Exception thrown if Parameter 2 is outside the bounds of possiblility (Parameter 2 is less than 1 or Parameter 2 is greater than the maximum size of the array). 

---
---	
**modifyNum**
		
		int* modifyNum(size_t, int);



<img width="1152" alt="ScreenShot1" src="https://github.com/user-attachments/assets/a8fe6124-4e57-4424-b45a-99c1b7ce0006">
