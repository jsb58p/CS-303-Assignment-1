# CS-303-Assignment-1

1. Download/Copy Files
2. Set up Main function
3. Run the code


# 1
-Download or copy the Array_Modify.h and Array_Modify_Imp.cpp into the repository where the project running this program is stored.

-Ensure that the input file is also in the repository.

# 2
-Main function must contain the following preprocessor directive for access to program:

    #include "Array_Modify.h"     



-Include the following preprocessor directive for input/output to console:

    #include <iostream>


-In order to handle exceptions thrown by class member functions, main function should include try/catch block:

        try{
        /*this is where member functions should be called*/
        }
        catch(std::out_of_range& ex){
        std::cerr << "Out of range exception has ocurred" << std::endl;
		std::cerr << ex.what() << std::endl;
		abort();
        }

# 3
-Declare an object of type Array_Modify:

The default constructor will use "A1input.txt" for the array initialization. To use a different file, use a string parameter when declaring the object to specify the file being used. Make sure to include the .txt extension.

Below is an example of declaring an object of type Array_Modify with an without a parameter:
		Array_Modify numArray("A1input.txt"); //parameter

  		Array_Modify numArray; 		//no parameter


<img width="1152" alt="ScreenShot1" src="https://github.com/user-attachments/assets/a8fe6124-4e57-4424-b45a-99c1b7ce0006">
