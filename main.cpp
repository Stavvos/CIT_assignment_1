/*Written by liam henry
Date: 13/4/2018
Cit:020625*/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

int linearSearch (char*);
int BinarySearch (int*);
void display (int*);
void display2 (char*);
void Swap1 (int*);
void Swap2 (char*);



int main()
{
    ifstream inData ("Input.txt");

    int array1 [20];
    char array2 [15];

    if (!inData) //test to see if the file is availible
    {
        cout << "The Input data file could not be accessed, the program will now end. " << endl;
        return 1;
    }

    for (int i = 0; i < 20; i++) //input data into array one from txt file
        {
            inData >> array1 [i];
        }

    for (int j = 0; j < 15; j ++) // input data into array two from txt file
        {
            inData >> array2 [j];
        }

    display (array1); //run function
    display2(array2); //run function
    Swap1   (array1); //run function
    Swap2   (array2); //run function


    int result = linearSearch (array2); // a variable that recives the return integer from the linear search function.

    if(result >= 0) // search character found
    {
        cout << endl << "The character " << array2[result]
        << " was found at the element with index value " <<result << endl;
    }
    else // serach character not found
    {
        cout << "The search character wasn't found" << endl;
    }


    int result2 = BinarySearch(array1); // a variable that recives the return integer from the binary search function.


    if (result2 >= 0) //search integer found
    {
        cout << endl << "the integer " << array1 [result2]
        << " was found at the element with index value " << result2 << endl;
    }
    else
    {
        cout << endl << "The search integer wasn't found" << endl;
    }
    inData.close(); //close txt file

    return 0;
}

void display (int inArray1[]){
     //display numbers in array one
    cout << endl << "The numbers in array 1 are: " << endl;

    for (int f = 0; f < 20; f++)
    {
        cout << inArray1 [f] << " ";
    }

    cout << endl;
};

void display2 (char inArray2 []){
    //display characters in array two
    cout << endl << "The characters in array 2 are: "  << endl;;

    for (int h = 0; h < 15; h ++)
        {
            cout << inArray2 [h] << " ";
        }
    cout << endl;
};

void Swap1 (int inArray[]){ //bubble sort function for descending

    int swapHolder2 = -1, end2 = 19, length2 = 19;

    for (int counter = length2 - 1; counter > 0; counter --)
    {
        for (int i = 0; i < end2; i++)
        {
            if (inArray [i] < inArray [i +1])
            {
                swapHolder2 = inArray [i + 1];
                inArray [i + 1] = inArray [i];
                inArray [i] = swapHolder2;
            }
        }
    end2 --;
    }

    cout << endl << "The numbers in array 1 in descending order are: "  << endl;;

    for (int i = 0; i < 20; i ++)
        {
            cout << inArray [i] << " ";
        }
cout << endl;
}

void Swap2 (char inArray[]){ //bubble sort function for ascending
    int swapHolder = -1, end = 14, length = 14;

    for (int counter = length - 1; counter > 0; counter --)
    {
        for (int i = 0; i < end; i++)
        {
            if (inArray [i] > inArray [i +1])
            {
                swapHolder = inArray [i + 1];
                inArray [i + 1] = inArray [i];
                inArray [i] = swapHolder;
            }
        }
    end --;
    }

     cout << endl << "The characters in array 2 in ascending order are: "  << endl;;

    for (int i = 0; i < 15; i ++)
        {
            cout << inArray [i] << " ";
        }
cout << endl;
}

int linearSearch (char characterArray[]) // linear search for character array
{
    char userValue;
    cout << endl << "Please enter a charcter for the linear search: ";
    cin >> userValue;

    for (int i = 0; i < 15; i ++)
    {
        if (userValue == characterArray[i])
        {
            return i;
        }
    }
cout << endl;
    return -1; // used for an if test in the main, to determine if the character inputted by the user exsists within the array.
}

int BinarySearch (int integerArray[]) //Binary search for integer array
{
    int low = 0, high = 20 - 1, mid, userValue2 = 0;

    cout << endl <<"please enter an integer for the binary search: ";
    cin >> userValue2;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (userValue2 == integerArray [mid])
        {
            return mid;
        }
        else if (userValue2 < integerArray [mid]) // had to change > to < to work for descending
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1; // used for an if test in the main, to determine if the integer inputted by the user exsists within the array
}


