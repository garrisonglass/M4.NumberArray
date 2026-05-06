//NumberArray.cpp : This file contains the 'main' test program for NumberArray.

#include <iostream>
#include "NumberArray.h"

using namespace std;

int main()
{
	cout << "Number Array Template Test.\n\n";

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

	cout << "Exception Test\n";

	try
	{
		NumberArray<int> a(5);

		//Valid access
		a.setNumber(0, 10);
		cout << "Valid access:a[0] = " << a.getNumber(0) << "\n";

		//Invalid access
		cout << "Invalid access test\n";
		a.getNumber(10);
	}
			catch (const out_of_range& e)
			{
				cout << "Caught exception: " << e.what() << "\n";
			}
		   
	cout << "Continuation after exception.\n\n";

	cout << "Copy Contructor Test\n";

	NumberArray<int> original(5);
	for (int i = 0; i < 5; i++)
		original.setNumber(i, i * 10);

	cout << "Original Array:\n";
	original.print();

	NumberArray<int> copy(original);

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

	y = x;

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

	cout << "Self Assignment Test\n";

	x = x;

	cout << "After self-assignment:\n";
	x.print();

	cout << "Self-assignment verified.\n\n";

	cout << "Distructor verification: Standby for destructor messages as objects go out of scope.\n\n";

	return 0;
}

//		//Test 1: Create a NumberArray and set values, then display them
//	NumberArray a(3);
//	a.setNumber(0, 11.11);
//	a.setNumber(1, 22.22);
//	a.setNumber(2, 33.33);
//
//	cout << "Original Array:\n\n"
//		 << "a[0]: " << a.getNumber(0) << " \n"
//		 << "a[1]: " << a.getNumber(1) << " \n"
//		 << "a[2]: " << a.getNumber(2) << " \n"
//		 << endl;
//	//Test 2. Copy constructor test, b recieves a deep copy of a.
//	NumberArray b(a);
//
//	cout << "Copy Constructed Array:\n\n"
//		 << "b[0]: " << b.getNumber(0) << " \n"
//		 << "b[1]: " << b.getNumber(1) << " \n"
//		 << "b[2]: " << b.getNumber(2) << " \n"
//		 << endl;
//	//Test 3. Modify b and show that a is unaffected, proving that b is a deep copy of a.
//	b.setNumber(0, 44.44);
//	cout << "After modifying b[0]:\n\n"
//		 << "a[0]: " << a.getNumber(0) << " \n"
//		 << "b[0]: " << b.getNumber(0) << " \n"
//		 << endl;
//	//Test 4. Assignment operator test, c recieves a deep copy of a.
//	NumberArray c(3);
//	c.setNumber(0, 55.55);
//	cout << "Before assignment operator test:\n\n"
//		 << "a[0]: " << a.getNumber(0) << " \n"
//		 << "c[0]: " << c.getNumber(0) << " \n"
//		 << endl;
//
//	c = a;
//
//	cout << "After assignment operator test:\n\n"
//		 << "a[0]: " << a.getNumber(0) << " \n"
//		 << "c[0]: " << c.getNumber(0) << " \n"
//		 << endl;
//	//Test 5. Self-assignment test, c should remain unchanged after self-assignment.
//	c = c;
//
//	cout << "After self-assignment test:\n\n"
//		 << "c[0]: " << c.getNumber(0) << " \n"
//		 << endl;
//
//	cout << "\nEnd of Program. Standby for destructor messages.\n\n";
//
//	return 0;
//
//}
