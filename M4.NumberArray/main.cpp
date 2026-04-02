// NumberArray.cpp : This file contains the 'main' function. 

#include <iostream>
#include "NumberArray.h"


using namespace std;

int main()
{
	cout << "Number Array Test Program 2\n\n";
	//Test 1: Create a NumberArray and set values, then display them
	NumberArray a(3);
	a.setNumber(0, 11.11);
	a.setNumber(1, 22.22);
	a.setNumber(2, 33.33);

	cout << "Original Array:\n\n"
		 << "a[0]: " << a.getNumber(0) << " \n"
		 << "a[1]: " << a.getNumber(1) << " \n"
		 << "a[2]: " << a.getNumber(2) << " \n"
		 << endl;
	//Test 2. Copy constructor test, b recieves a deep copy of a.
	NumberArray b(a);

	cout << "Copy Constructed Array:\n\n"
		 << "b[0]: " << b.getNumber(0) << " \n"
		 << "b[1]: " << b.getNumber(1) << " \n"
		 << "b[2]: " << b.getNumber(2) << " \n"
		 << endl;
	//Test 3. Modify b and show that a is unaffected, proving that b is a deep copy of a.
	b.setNumber(0, 44.44);
	cout << "After modifying b[0]:\n\n"
		 << "a[0]: " << a.getNumber(0) << " \n"
		 << "b[0]: " << b.getNumber(0) << " \n"
		 << endl;
	//Test 4. Assignment operator test, c recieves a deep copy of a.
	NumberArray c(3);
	c.setNumber(0, 55.55);
	cout << "Before assignment operator test:\n\n"
		 << "a[0]: " << a.getNumber(0) << " \n"
		 << "c[0]: " << c.getNumber(0) << " \n"
		 << endl;

	c = a;

	cout << "After assignment operator test:\n\n"
		 << "a[0]: " << a.getNumber(0) << " \n"
		 << "c[0]: " << c.getNumber(0) << " \n"
		 << endl;
	//Test 5. Self-assignment test, c should remain unchanged after self-assignment.
	c = c;

	cout << "After self-assignment test:\n\n"
		 << "c[0]: " << c.getNumber(0) << " \n"
		 << endl;

	cout << "\nEnd of Program. Standby for destructor messages.\n\n";

	return 0;

}
