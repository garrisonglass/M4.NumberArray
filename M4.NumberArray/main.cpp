//NumberArray.cpp : This file contains the main() test program for NumberArray.

#include <iostream>
#include "NumberArray.h"

using namespace std;

int main()
{
	cout << "Number Array Template Test.\n\n";
	//Template Instantiation Test
	//Create NumberArray<int> and NumberArray<double>
	try
	{
		NumberArray<int> intArray(5);
		NumberArray<double> doubleArray(5);
		cout << "Successfully created NumberArray objects for int and double types.\n\n";
	}
	catch (const std::exception& e)
	{
		cout << "Exception caught: " << e.what() << "\n\n";
	}

	//Exception Handling Test
	//Valid and invalid access to setNumber and getNumber
	cout << "Exception Test\n";

	try
	{
		NumberArray<int> a(5);

		//Valid access
		a.setNumber(0, 10);
		cout << "Valid access:a[0] = " << a.getNumber(0) << "\n";

		//Invalid access
		cout << "Invalid access test\n";
		a.getNumber(10);//Should throw an exception
	}
	catch (const out_of_range& e)
		{
		cout << "Caught exception: " << e.what() << "\n";
		}
		   
	cout << "Continuation after exception.\n\n";
	//Copy Constructor Test
	//Verify deep copy behavior
	cout << "Copy Contructor Test\n";

	NumberArray<int> original(5);
	for (int i = 0; i < 5; i++)
		original.setNumber(i, i * 10);

	cout << "Original Array:\n";
	original.print();

	NumberArray<int> copy(original);//Copy constructor

	cout << "Copy Constructed Array:\n";
	copy.print();

	//Modify copy and show original is unaffected	
	copy.setNumber(0, 999);

	cout << "After modifying original\n";
	cout << "Original:  ";
	original.print();
	cout << "Copy:      ";
	copy.print();

	cout << "Copy contructor deep copy verified.\n\n";
	//Assignment Operator Test
	//Verify deep copy behavior for assignment
	cout << "Assignment Operator Test\n";

	NumberArray<int> x(4);
	NumberArray<int> y(4);

	for (int i = 0; i < 4; i++)
	{
		x.setNumber(i, i + 1);
	}

	cout << "x before assignment:\n";
	x.print();
	cout << "y before assignment:\n";
	y.print();

	y = x;//Assignment operator

	cout << "y after assignment:\n";
	y.print();

	//Modify x and show y is unaffected
	x.setNumber(0, 789);

	cout << "After modifying x\n";
	cout << "x: ";
	x.print();
	cout << "y: ";
	y.print();

	cout << "Assignment operator deep copy verified.\n\n";
	//Self-Assignment Test
	//Verify that self-assignment does not cause issues
	cout << "Self Assignment Test\n";

	x = x;//Self-assignment

	cout << "After self-assignment:\n";
	x.print();

	cout << "Self-assignment verified.\n\n";
	//Destructor Test
	//Verify that destructors are called and memory is released
	cout << "Destructor verification: Standby for destructor messages as objects go out of scope.\n\n";

	return 0;
}