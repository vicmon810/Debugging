# Bug Squashing

## Description :
My task is to debug a existing C program, with tons of bug in it. Currently there are 8 function in that C code. for sorting email, first name, last name and phone and searching. <br>
Here is what I did :
1. setLineCount and getLineCount: These functions are used to set and retrieve the global line count variable, which represents the number of contact entries in the file.
2. Sorting Functions:
    - `***sfn***`: Sorts the array of S structures by the first name field using a nested loop and the strcmp function.
    - `***sln***`: Sorts the array of S structures by the last name field using a nested loop and the strcmp function.
    - `***sem***`: Sorts the array of S structures by the email address field using a nested loop and the strcmp function.
    - `***sph***`: Sorts the array of S structures by the phone number field using a nested loop and a simple comparison.
3. Search Function : 
    - `***ffn***`: Searches for a given first name in the array of S structures by iterating through the array and comparing each element's first name field with the provided name.
    - `***fln***`: Searches for a given last name in the array of S structures by iterating through the array and comparing each element's last name field with the provided name.
    - `***fem***`: Searches for a given email address in the array of S structures by iterating through the array and comparing each element's email address field with the provided address.
    - `***fph***`: Searches for a given phone number in the array of S structures by iterating through the array and comparing each element's phone number field with the provided number.
4. File I/O Functions: 
    - `***readFromFile***`: Reads contact information from a file, allocates memory for the S structures, and populates the array with the read data.
    - `***freeMemory***`: Releases the allocated memory for the S structures and related fields.

5. Helper Functions:
    - `***handle_exception***`: Displays a message indicating that the requested information was not found.
    - `***correct***`: Displays the index of the found information in the sorted array.

## Algorithm: 
1. Sorting Functions:

    - Sorting by First Name (sfn), Sorting by Last Name (sln), Sorting by Email Address (sem), and Sorting by Phone Number (sph) all use the Bubble Sort algorithm.
    - Bubble Sort has a time complexity of O(n^2) in the worst case, where n is the number of elements in the array being sorted.
    - Therefore, all four sorting functions have the same time complexity of O(n^2) in the worst case.

2. Searching Function : 
    - Searching by First Name (ffn), Searching by Last Name (fln), Searching by Email Address (fem), and Searching by Phone Number (fph) all use linear search.
    - Linear search has a time complexity of O(n) in the worst case, where n is the number of elements in the array being searched.
    - Therefore, all four searching functions have the same time complexity of O(n) in the worst case.

# Usage: 
To run the program, navigate to the `***BUG***` directory and execute the command `***gcc -Wall main.c -o main***` to compile this code, then `***./main file.txt***` to run it, where `file.txt` is file you would like to processed. 

# Test: 

| Test Case | Test Summary                                                | Test Input                         | Expected Result                | Status |
| --------- | ---------------------------------------------------------- | ---------------------------------- | ------------------------------ | ------ |
| #1        | Enter correct first name should be able to return index     | Enter an existing name             | Return index of that name      | OK     |
| #2        | Enter first name not existing in that file                  | Enter a non-existing name          | Display a warning message      | OK     |
| #3        | Enter existing last name should return index                | Enter an existing last name        | Return index of that name      | OK     |
| #4        | Enter non-existing last name should pop out warning message | Enter a non-existing last name     | Display a warning message      | OK     |
| #5        | Enter existing email address should return index            | Enter an existing email address    | Return index of that email     | OK     |
| #6        | Non-existing email address detection                        | Enter an email address not in file | Display a warning message      | OK     |
| #7        | Existing phone number detection                             | Enter a phone number in the file   | Return index of that number    | OK     |
| #8        | Non-existing phone number detection                         | Enter a phone number not in file   | Display a warning message      | OK     |

