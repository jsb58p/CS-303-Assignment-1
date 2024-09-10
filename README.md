# CS-303-Assignment-1

1. Download/Copy Files
2. Set up/Main function
3. Run the code
4. Function Descriptions
5. Examples


# 1. Download/Copy Files
- Download or copy the Array_Modify.h and Array_Modify_Imp.cpp into the repository where the project running this program is stored.

- Ensure that the input file is also in the repository.


# 2. Set up/Main function
- Main file must contain the following preprocessor directive for access to program:

    	#include "Array_Modify.h"     



- Include the following preprocessor directive in main file for input/output to console:

    	#include <iostream>

- Declare an object of type Array_Modify inside main function:

The default constructor will use "A1input.txt" for the array initialization. To use a different file, use a string parameter when declaring the object to specify the file being used. Make sure to include the .txt extension.

Below is an example of declaring an object (numArray) of type Array_Modify with a parameter, then an example of declaring the object without a parameter:
		
  		Array_Modify numArray("A1input.txt"); //parameter

--

  		Array_Modify numArray; 		//no parameter, will use "A1input.txt" by default


- In order to handle out_of_range exceptions thrown by class member functions whose parameters may be invalid, main function should include try/catch block:

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
-
		int findNum(int, int position = 1);
	
A function to check if a certain integer exists in the array. If the number is present, returns the
index where the number is present. If the number is not present, returns -1.

**Parameter 1: int**

Integer to be searched for.

**Parameter 2: int**

Integer representing the repition of the integer being searched for. Default is 1. If there are n array elements containing the value from Parameter 1, then passing n for the second parameter will return
the index of the nth Parameter 1 value. If the value from Paramter 1 is not found, or the value passed for Parameter 2 is greater than n, then function returns -1.


*Exception thrown if Parameter 2 is outside the bounds of possibility (Parameter 2 is less than 1 or Parameter 2 is greater than the maximum size of the array).*

---
---	
**modifyNum()**
-		
		int* modifyNum(size_t, int);

A function that can modify the value of an integer when called with the index of the integer in
the array and returns a pointer to the new value and old value. Old value and new value are stored in a class member array of size 2.

- Use subscript operator, **[0]** or **[1]**, on the function to return new or old value. **[0]** returns the new value, **[1]** returns the old value. Using the function without the subscript operator will return the memory location of the array. 

**Parameter 1: size_t**

Index of integer being modified.

**Parameter 2: int**

New integer value to replace the integer at the index provided by Parameter 1.

*Exception thrown if parameter 1 is not a valid index*

---
---
**addNum()**
-
		void addNum(int);

A function that adds a new integer to the end of the array.

- Expands size of array if necessary to add new integer.

**Parameter 1: int**

Integer to be added to the end of the array.

---
---
**removeNum()**
-
	void removeNum(size_t);

A function which intakes an index of an array and removes the integer at that index.

**Parameter 1: size_t**

Index of array element to be removed.

*Exception thrown if Parameter 1 is not a valid index*

---
---

# 5. Examples

1. **The following example shows how the main file should be set up, how an object can be declared, and how a function can be called within the try/catch block.**
<img width="576" alt="1" src="https://github.com/user-attachments/assets/36416916-abdc-4c19-b6f3-a885335e083c">

**Line 8 contains a call to the function findNum(). Parameter 1 is passed to findNum() by the user. Parameter 2 defaults to the integer 1. An element containing the integer 5 occurs the first time at index 4. Therefore, the output is 4.**

---
2. **Line 8 contains the function findNum(), but Parameter 1 is being passed an integer value (0) that does not exist in the array.**
<img width="576" alt="findNum2" src="https://github.com/user-attachments/assets/3286c51c-0c77-4963-b7cf-10b93a38f8cd">

**Since the value being searched does not exist in the array, the value returned is -1**

---
3. **Line 8 contains the function findNum(). Parameter 1 passed by the user is a value of an integer that exists in the array. Parameter 2, passed by the user, is invalid because the integer 5 only exists in 1 position in the array.**
<img width="576" alt="findNum3" src="https://github.com/user-attachments/assets/3b30c2b2-76fe-44c1-9f45-a194e5efde96">

**Since integer 5 only exists in one index of the array, the second index for 5 cannot be found. Therefore, the function returns -1.**

---
4. **Line 8 contains the function addNum(). Parameter 1 passed by the user is the integer to be added to the end of the array.**

   **Line 9 contains the function findNum(). Parameter 1 passed by the user is a value that exists in the array. Parameter 2, passed by the user, is valid because the integer 5 exists in 2 positions in the array after executing line 8.**
<img width="584" alt="addNumfindNum1" src="https://github.com/user-attachments/assets/8acb3014-8a66-4f05-a8a1-ff2895b4c1f4">

**Outputs 100 as the return value of function findNum(), because that is the index position of the 2nd integer 5.**

---
5. **Line 8 uses function addNum() to add the integer 5 to the end of the array.**
   
   **Line 9 uses function removeNum(). The parameter passed by the user is the index of the integer to be removed from the array. In this case, the integer 5 is at index 4.**
   
   **Line 10 outputs the result of the function findNum(). The parameter 5 is passed by the user. The function will return the index of the first element of the array containing integer 5.**
<img width="576" alt="addNumremoveNumfindNum1" src="https://github.com/user-attachments/assets/14100eee-486c-494e-aedf-cdc3148d4f87">

   **The output is 99 because the function addNum() added the integer 5 to the end of the array, at index 100. Then the function removeNum() removes the element at index 4, which held the integer 5. All array elements after index 4 shift down one index.**

   **When function findNum() executes, the only integer 5 currently in the array is the result of the function addNum(). Since the array elements were shifted down as part of the function removeNum(), the integer 5 is found at index 99.**

---
6. **Line 8 uses function addNum() to add the integer 5 to the end of the array.**

   **Line 9 uses the function modifyNum() and outputs the returned value. Parameter 1 is passed by the user and is the index of the array to be modified.**

   **The subscript is [1], so the value returned will be the old integer value at that index.**

   **Line 10 uses the function findNum() to output the index of the first integer 5 in the array.**
<img width="576" alt="addNummodifyNumfindNum1" src="https://github.com/user-attachments/assets/5513093c-e565-49b7-8017-4c59920b949c">


   **The output from line 9 is 2. This is the old value at the index 1 before the modifyNum() function was called. The new value is 5**

   **The output from line 10 is 1. After modifying the the value at index 1 to hold integer 5, the first position to hold integer 5 is at index 1.**

---
7. **Line 8 uses function addNum() to add the integer 5 to the end of the array**

   **Line 9 uses the function modifyNum() and outputs the returned value. Parameter 1 is passed by the user and is the index of the array to be modified.**

   **The subscript is [0], so the value returned will be the new integer value at that index**

    **Line 10 uses the function removeNum(). Parameter 1 passed by the user is the index whose element is to be removed.**
    **However, in this case, Parameter 1 is not in the index range.**
<img width="576" alt="addNummodifyNumremoveNum1" src="https://github.com/user-attachments/assets/fe36cdc8-d76f-4350-9ec7-91bdd719f78e">

**The output from line 9 is 5. This is the old value of the element at the array index passed as Parameter 1 in the function modifyNum()**

**When line 10 executes, an exception thrown in the function removeNum(). Because Parameter 1 was not in range, the function executed code to throw an exception.**

**The catch block executes, and the following output informs the user that an out of range exception has occurred.** 

**The what() function on line 14 returns the error message from the function where the exception was thrown. Line 15 aborts the program.**

<img width="576" alt="abort1" src="https://github.com/user-attachments/assets/17e8a30b-3939-4207-b9f4-88a33638e74b">

---
8. **The following example shows all functions being used together.**

   **Line 8 uses function addNum() to add the integer 0 to the end of the array**

   **Line 9 modifies the integer at index 0 to have the value 0. The previous value was 1.**

   **Line 10 uses the function findNum() and outputs the results. Parameter 1 is 0, the integer being searched.**
   **Parameter 2 is 2, meaning the index of the second occurrance of the integer used as Parameter 1 will be returned.**

   **Line 11 uses the function removeNum() to remove the array element at the index passed as Parameter 1.**

   **Line 12 uses the function findNum(), and outputs the return value, the index of the first occurance of the integer 0.**

   **Line 13 uses the function findNum(), and outputs the return value, the index of the second occurrance of the integer 0.**
<img width="576" alt="allFunctions1" src="https://github.com/user-attachments/assets/be87ff43-26f8-4631-a81e-a884839f10f2">

**The output from line 10 is 100. After the function addNum() adds 0 to the end of the array, and function modifyNum() modifies the first array element to hold 0, the first occurance of the integer 0 is at index 0, and the second occurrance of the integer 0 is at index 100, hence the output.**

**The output from line 12 is 99. The function from line 11, removeNum(), removes the array element at index 0. Then, all array elements after 0 are shifted down one index. Since the 0 previously at index 0 has been removed and the second occurrance was shifted down one index, now the first occurance of 0 is at index 99.**

**The output from line 13 is -1. The function on line 13, findNum(), tries to search for the second occurance of 0. However, only one occurance exists after line 11 executes. Therefore, the second occurance cannot be found and the function returns -1.**

	
