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

	cout << "\nEnd of Program. Standby for destructor messages.\n\n";

	return 0;

}
