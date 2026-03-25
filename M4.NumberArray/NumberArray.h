#ifndef NUMBERARRAY_H
#define NUMBERARRAY_H

#include <iostream>
using namespace std;

class NumberArray

{
private:
	int     size; //Number of elements in the array
	double* data; //Pointer to dynamically allocated array

	//Static default size used by the constructor
	static const int MAX_SIZE = 100;

public:
	/*
	Constructor: allocates memory and initializes all elements
	to 0.0. If an invalid size is provided, MAX_SIZE is used.
	*/
	NumberArray(int size = MAX_SIZE);

	/*
	Destructor: releases allocated memory and prints a message
	confirming that the destructor executed.
	*/
	~NumberArray();

	/*
	Mutator: stores a value at the given index only if the index
	is within bounds. Invalid index are ignored.
	*/
	void setNumber(int index, double value);

	/*
	Accessor: retrieves the value at the given index. If the
	index is invalid, a static default value (0.0) is returned.
	*/
	double getNumber(int index) const;

	/*
	Statistical functions: compute min, max, and average
	dynamically by scanning the array.
	*/
	double getMin() const;
	double getMax() const;
	double getAvg() const;

	//Print function: displays all values in the array.
	void print() const;

	//Accessor for size: returns the number of elements in the array.
	int getSize() const { return size; }
};

#endif


