#include <iostream>
#include <string>
#include <sstream> //converted integer to string
#include <cassert>
#include <cmath> //pow
using namespace std;

//Summary: Write and test a function which  sorts three numbers in increasing order. The values passed in should be integer values between 0 and 100, inclusive. The prototype for this function is:
//Precondition: Values are passed in as variables to hold the increasing order
//Postcondition: Values are stored from greatest to lowest values
void sort(int& numA, int& numB, int& numC);

//Summary: Write and test a function which determines the number of digits in an integer. The values passed in should be integer values between -10000 and 10000, inclusive.  The prototype for this function is:
//Precondition: values ranged passed in should include only values from -10000 and 10000
//Postcondition: The integer value will be passed into a string while checking the index and returning the length of the string
void numDigits(int  valA, int& n);  

//summary: Write and test the function which calculates area (a) , volume (v) . The values passed in should be double  values greater than 0 and less than 10000, inclusive.  The prototype for this function is:
//Preconditions: The radius passed in should be positive and also can't be above 10000
//Postcondition: Function will change the area and volume by pass by reference
void computeSphere(double& a, double& v, double r);

//Write and test a function which swaps the entered values. The values passed in should be positive integer values.
//Preconditions: Function will pass in positive numbers only
//Postconditions: The function will swap the two values passed in
void swap(int& A, int& B);



int main()
{
    const float EPSILON = .01;
    int valA, valB, valC;//Variables being passed to my function
    int n;
    double area, volume;
    double value1, value2;
    
    
    
    sort(valA = 1, valB = 3, valC = 1);//Initialize my variable to a given value
    assert(valA == 3 && valB == 1 && valC == 1);
    sort(valA = 1, valB = 2, valC = 3);
    assert(valA == 3 && valB == 2 && valC == 1);
    sort(valA = 1, valB = 1, valC = 1);
    assert(valA == 1 && valB == 1 && valC == 1);
    
    numDigits(10000 , n);
    assert(n == 5);
    numDigits(999, n);
    assert(n == 3);
    numDigits(3278, n);
    assert(n == 4);
    
    computeSphere(area, volume, 5);
    assert(fabs(314.159 - area) < EPSILON); 
    assert(fabs(523.598 - volume) < EPSILON);
    computeSphere(area, volume, 10);
    assert(fabs(1256.64 - area) < EPSILON);
    assert(fabs(4188.79 - volume) < EPSILON);
    computeSphere(area, volume, 2);
    assert(fabs(50.2654 - area) < EPSILON);
    assert(fabs(33.5103 - volume) < EPSILON);
    
    swap(value1 = 5, value2 = 10);
    assert(value1 == 10);
    assert(value2 == 5);
    swap(value1 = 2, value2 = 3);
    assert(value1 == 3);
    assert(value2 == 2);
    swap(value1 = 7, value2 = 7);
    assert(value1 == 7);
    assert(value2 == 7);
    
    
    return 0;
   
}

void sort(int& numA, int& numB, int& numC)
{
    //Store my variables to an array so I can swap my values 
    //An error that I encountered was setting numB = numC then numC = numB causing for an error
    int arr[3] = {numA, numB, numC};
    if((arr[0] > arr[1]) && (arr[0] > arr[2]))
    {
        numA = arr[0];
        if(arr[1] > arr[2])
        {
            numB = arr[1];
            numC = arr[2];
        }
        else if(arr[2] > arr[1])
        {
            numB = arr[2];
            numC = arr[1];
        }
        //If the variable are equal then I just set them to eachother
        else
        {
             numB = arr[2];
             numC = arr[1]; 
        }
    }
    else if((arr[1] > arr[0]) && (arr[1] > arr[2]))
    {
        numA = arr[1];
        if(arr[0] > arr[2])
        {
            numB = arr[0];
            numC = arr[1];
        }
        else if(arr[2] > arr[0])
        {
            numB = arr[2];
            numC = arr[0];
        }
        else
        {
            numB = arr[2];
            numC = arr[0];
        }
        
    }
    else if((arr[2] > arr[0]) && (arr[2] > arr[1]))
    {
        numA = arr[2];
        if(arr[1] > arr[0])
        {
            numB = arr[1];
            numC = arr[0];
        }
        else if(arr[0] > arr[1])
        {
            numB = arr[0];
            numC = arr[1];
        }
        else
        {
            numB = arr[1];
            numC = arr[0];
        }
    }
    return;
}
void numDigits(int valA, int& n)
{
   assert(valA <= 10000 && valA >= -10000);
   stringstream ss;
   ss << valA;
   string value = ss.str();
   n = 0;
   for(int i = 0; i < value.length(); i++)
   {
        n++;
   }
}

void computeSphere(double& a, double& v, double r)
{
    assert(r > 0 && r < 1000);
    const double PI = 3.14159;
    a = (4) * (PI) * pow(r, 2);
    v = (4.0/3.0) * (PI) * pow(r, 3);
    
}
void swap(int& A, int& B)
{
    assert(A > 0 && B > 0);
    int temp;
    temp = A;
    A = B;
    B = temp;
}
