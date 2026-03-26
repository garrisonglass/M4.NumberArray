// NumberArray.cpp : This file contains the 'main' function. 

#include <iostream>
#include "NumberArray.h"
#include <random>

using namespace std;

int main()
{
	cout << "Number Array Test Program 2\n\n";
	NumberArray a(3);
	a.setNumber(0, 11.11);
	a.setNumber(1, 22.22);
	a.setNumber(2, 33.33);

	cout << "Original Array:\n\n"
		 << "a[0]: " << a.getNumber(0) << " \n"
		 << "a[1]: " << a.getNumber(1) << " \n"
		 << "a[2]: " << a.getNumber(2) << " \n"
		 << endl;
	//copy constructor test
	NumberArray b(a);

	cout << "Copy Constructed Array:\n\n"
		 << "b[0]: " << b.getNumber(0) << " \n"
		 << "b[1]: " << b.getNumber(1) << " \n"
		 << "b[2]: " << b.getNumber(2) << " \n"
		 << endl;

	b.setNumber(0, 44.44);
	cout << "After modifying b[0]:\n\n"
		 << "a[0]: " << a.getNumber(0) << " \n"
		 << "b[0]: " << b.getNumber(0) << " \n"
		 << endl;
	NumberArray c(3);
	c.setNumber(0, 55.55);
	c = a;

	cout << "After assignment operator test:\n\n"
		 << "a[0]: " << a.getNumber(0) << " \n"
		 << "c[0]: " << c.getNumber(0) << " \n"
		 << endl;
	c = c;

	cout << "After self-assignment test:\n\n"
		 << "c[0]: " << c.getNumber(0) << " \n"
		 << endl;




	///*
	//Test 1: Default constructor
	//Creates an array using MAX_SIZE and initializes all values
	//to 0.0. Print verifies correct initialization.
	//*/
	//cout << "Default Constructor Test\n";
	//NumberArray a1;
	//a1.print();

	///*
	//Test 2: Parameterized constructor
	//Creates a smaller array and verifies that all elements
	//start at 0.0.
	//*/
	//cout << "\nPerameterized Constructor Test, size 10\n";
	//NumberArray a2(10);
	//a2.print();

	///*
	//Test 3: Fill array with random values
	//Uses <random> to generate floating point values and stores
	//them using setNumber().
	//*/
	//cout << "\nRandom Number Test\n";

	//random_device rd;
	//mt19937 gen(rd());
	//uniform_real_distribution<> dis(1.0, 100.0);

	//for (int i = 0; i < a2.getSize(); i++)
	//{
	//	a2.setNumber(i, dis(gen));
	//}
	//a2.print();

	///*
	//Test 4: Out-of-bounds behavior
	//setNumber() should ignore invalid indices.
	//getNumber() should return the static default value (0.0).
	//*/
	//cout << "\nOut of Bounds Test\n";
	//a2.setNumber(-10, 50.0);//Invalid index, should be ignored
	//a2.setNumber(500, 50.0);//Invalid index, should be ignored

	//cout << "GetNumber(-10): " << a2.getNumber(-10) << endl;
	//cout << "GetNumber(500): " << a2.getNumber(500) << endl;

	///*
	//Test 5: Statistical functions
	//Verifies that min, max, and average are computed correctly
	//from the current contents of the array.
	//*/
	//cout << "\nStatisticl Test\n";

	//cout << "Min: " << a2.getMin() << endl;
	//cout << "Max: " << a2.getMax() << endl;
	//cout << "Avg: " << a2.getAvg() << endl;

	///*
	//End of main()
	//When main ends, destructors for a1 and a2 will run.
	//The destructor prints a message confirming memory release.
	//*/
	cout << "\nEnd of Program. Standby for destructor messages.\n\n";

	return 0;

}
