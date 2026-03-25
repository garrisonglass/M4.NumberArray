// NumberArray.cpp : This file contains the 'main' function. 

#include <iostream>
#include "NumberArray.h"
#include <random>

using namespace std;

int main()
{
	cout << "Number Array Test Program\n\n";

	/*
	Test 1: Default constructor
	Creates an array using MAX_SIZE and initializes all values
	to 0.0. Print verifies correct initialization.
	*/
	cout << "Default Constructor Test\n";
	NumberArray a1;
	a1.print();

	/*
	Test 2: Parameterized constructor
	Creates a smaller array and verifies that all elements
	start at 0.0.
	*/
	cout << "\nPerameterized Constructor Test, size 10\n";
	NumberArray a2(10);
	a2.print();

	/*
	Test 3: Fill array with random values
	Uses <random> to generate floating point values and stores
	them using setNumber().
	*/
	cout << "\nRandom Number Test\n";

	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<> dis(1.0, 100.0);

	for (int i = 0; i < a2.getSize(); i++)
	{
		a2.setNumber(i, dis(gen));
	}
	a2.print();

	/*
	Test 4: Out-of-bounds behavior
	setNumber() should ignore invalid indices.
	getNumber() should return the static default value (0.0).
	*/
	cout << "\nOut of Bounds Test\n";
	a2.setNumber(-10, 50.0);//Invalid index, should be ignored
	a2.setNumber(500, 50.0);//Invalid index, should be ignored

	cout << "GetNumber(-10): " << a2.getNumber(-10) << endl;
	cout << "GetNumber(500): " << a2.getNumber(500) << endl;

	/*
	Test 5: Statistical functions
	Verifies that min, max, and average are computed correctly
	from the current contents of the array.
	*/
	cout << "\nStatisticl Test\n";

	cout << "Min: " << a2.getMin() << endl;
	cout << "Max: " << a2.getMax() << endl;
	cout << "Avg: " << a2.getAvg() << endl;

	/*
	End of main()
	When main ends, destructors for a1 and a2 will run.
	The destructor prints a message confirming memory release.
	*/
	cout << "\nEnd of Program. Standby for destructor messages.\n\n";

	return 0;

}
