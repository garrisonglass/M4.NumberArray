//NumberArray.h : This file contains the declaration of the NumberArray class.

#ifndef NUMBERARRAY_H
#define NUMBERARRAY_H

#include <stdexcept>
#include <iostream>

template <typename T>
class NumberArray

{
private:
	int     size; //Number of elements in the array
	T* data; //Pointer to dynamically allocated array

	

public:
	/*
	Constructor: allocates memory and initializes all elements
	to 0.0. Throws an exception if the size is invalid.
	*/
	NumberArray(int size);

	/*
	Destructor: releases allocated memory and prints a message
	confirming that the destructor executed.
	*/
	~NumberArray();

	/*
	Copy constructor (Rule of three): creates a deep copy of another NumberArray
	*/
	NumberArray(const NumberArray<T>& other);

	/*
	Assignment operator (Rule of three): assigns one NumberArray to another, ensuring proper memory management
	*/
	NumberArray<T>& operator=(const NumberArray<T>& other);

	/*
	Mutator: stores a value at the given index only if the index
	is within bounds. Throws an exception if the index is out of bounds.
	*/
	void setNumber(int index, T value);

	/*
	Accessor: Returns the value at the given index. Throws an exception if the
    index is out of bounds.
	*/
	T getNumber(int index) const;

	/*
	Statistical functions: compute min, max, and average
	dynamically by scanning the array.
	*/
	T getMin() const;
	T getMax() const;
	double getAvg() const;

	//Print function: displays all values in the array.
	void print() const;

	//Accessor for size: returns the number of elements in the array.
	int getSize() const { return size; }
};
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

	data = new T[size]{};

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
	std::cout << "Destructor called for object at memory " << this << ". Memory released.\n";
}
/*
Copy constructor
Creates a deep copy of another NumberArray by allocating new memory and copying each element.
*/
template <typename T>
NumberArray<T>::NumberArray(const NumberArray<T>& other)
	: size(other.size),
	data(nullptr)
{
	data = new T[size];
	for (int i = 0; i < size; i++)
		data[i] = other.data[i];
}
/*
Assignment operator
Handles self-assignment, releases old memory, allocates new memory, and copies data from the other NumberArray.
*/
template <typename T>
NumberArray<T>& NumberArray<T>::operator=(const NumberArray<T>& other)
{
	if (this == &other)
	{
		return *this;
	}
	//Release existing memory
	delete[] data;
	//Allocate new memory and copy data
	size = other.size;
	data = new T[size];
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
template <typename T>
void NumberArray<T>::setNumber(int index, T value)
{
	if (index < 0 || index >= size)
	{
		throw std::out_of_range("Index is out of bounds.");
	}
	data[index] = value;
}
/*
Accessor: getNumber
Returns the value stored at the given index. If the index is
invalid, throws an exception.
*/
template <typename T>
T NumberArray<T>::getNumber(int index) const
{
	if (index < 0 || index >= size)
	{
		throw std::out_of_range("Index is out of bounds.");
	}
	return data[index];

}
/*
getMin
Scans the array and returns the smallest value. Because the
constructor initializes all elements to 0.0, the array will always
contain valid numeric data.
*/
template <typename T>
T NumberArray<T>::getMin() const
{
	T min = data[0];

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
template <typename T>
T NumberArray<T>::getMax() const
{
	T max = data[0];

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
template <typename T>
double NumberArray<T>::getAvg() const
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
template <typename T>
void NumberArray<T>::print() const
{
	for (int i = 0; i < size; i++)
		std::cout << data[i] << " ";

	std::cout << std::endl;
}
#endif


