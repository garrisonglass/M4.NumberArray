//NumberArray.h : This file contains the declaration of the NumberArray class.

#ifndef NUMBERARRAY_H
#define NUMBERARRAY_H




class NumberArray

{
private:
	int     size; //Number of elements in the array
	double* data; //Pointer to dynamically allocated array

	

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
	NumberArray(const NumberArray& other);

	/*
	Assignment operator (Rule of three): assigns one NumberArray to another, ensuring proper memory management
	*/
	NumberArray& operator=(const NumberArray& other);

	/*
	Mutator: stores a value at the given index only if the index
	is within bounds. Throws an exception if the index is out of bounds.
	*/
	void setNumber(int index, double value);

	/*
	Accessor: Returns the value at the given index. Throws an exception if the
    index is out of bounds.
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


