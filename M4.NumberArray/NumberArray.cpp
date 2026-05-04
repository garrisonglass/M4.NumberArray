//NumberArray.cpp : This file contains the implementation of the NumberArray class.

#include "NumberArray.h"
#include <stdexcept>
#include <iostream>
using namespace std;


/*
 Constructor
 Allocates a dynamic array of the specified size. If the size
 is less than or equal to 0, throws exception.
 Initializes all elements of the array to 0.0.
*/
template <typename T>
NumberArray<T>::NumberArray(int size)
	: size(size),
	  data(nullptr)
{
	if (size <= 0)
	{
		throw std::invalid_argument("Size must be greater than 0.");
	}
		
	data = new T[size] {};

}

/*
Destructor
Releases the dynamically allocated array. A confirmation
message is printed so the test program can verify that the
destructor executed at the correct time.
*/
template <typename T>
NumberArray<T>::~NumberArray()
{
	delete[] data;
	cout << "Destructor called for object at memory " << this << ". Memory released.\n";
}
/*
Copy constructor
Creates a deep copy of another NumberArray by allocating new memory and copying each element.
*/
NumberArray::NumberArray(const NumberArray& other)
	: size(other.size),
	  data(nullptr)
{
	data = new double[size];
	for (int i = 0; i < size; i++)
		data[i] = other.data[i];
}
/*
Assignment operator
Handles self-assignment, releases old memory, allocates new memory, and copies data from the other NumberArray.
*/
NumberArray& NumberArray::operator=(const NumberArray& other)
{
	if (this == &other)
	{
		return *this;
	}
		//Release existing memory
		delete[] data;
		//Allocate new memory and copy data
		size = other.size;
		data = new double[size];
		//Deep copy of the elements
		for (int i = 0; i < size; i++)
		{
			data[i] = other.data[i];
		}
	return *this;
}

/*Mutator: setNumber
Stores a value at the given index only if the index is
within valid bounds (index < 0 or >= size). Invalid indices throws an exception.
*/
void NumberArray::setNumber(int index, double value)
{
	if (index < 0 || index >= size)
	{
		throw out_of_range("Index is out of bounds.");
	}	
	data[index] = value;
}
/*
Accessor: getNumber
Returns the value stored at the given index. If the index is
invalid, throws an exception.
*/
double NumberArray::getNumber(int index) const
{
	if(index < 0 || index >= size)
	{
		throw out_of_range("Index is out of bounds.");
	}
		return data[index];
	
}
/*
getMin
Scans the array and returns the smallest value. Because the
constructor initializes all elements to 0.0, the array will always
contain valid numeric data.
*/
double NumberArray::getMin() const
{
	double min = data[0];

	for (int i = 1; i < size; i++)
	{
		if (data[i] < min)
			min = data[i];
	}
	return min;
}
/*
getMax
Scans the array and returns the largest value. No values are
pre-stored; the result is computed dynamically each time.
*/
double NumberArray::getMax() const
{
	double max = data[0];

	for (int i = 1; i < size; i++)
	{
		if (data[i] > max)
			max = data[i];
	}
	return max;
}
/*
getAverage
Computes the average by summing all elements and dividing by
the number of elements. The array will always have at
least one element because the constructor enforces a valid size.
*/
double NumberArray::getAvg() const
{
	double sum = 0.0;

	for (int i = 0; i < size; i++)
		sum += data[i];
	return sum / size;
}
/*
print
//Displays all values in the array.
*/
void NumberArray::print() const
{
	for (int i = 0; i < size; i++)
		cout << data[i] << " ";

	cout << endl;
}

