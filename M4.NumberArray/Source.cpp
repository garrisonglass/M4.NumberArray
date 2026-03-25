#include "NumberArray.h"


/*
 Constructor
 Allocates a dynamic array of the specified size. If the size
 is less than or equal to 0, it defaults to MAX_SIZE.
 Initializes all elements of the array to 0.0.
*/
NumberArray::NumberArray(int size)
{
	if (size <= 0)
		this->size = MAX_SIZE;
	else
		this->size = size;

	data = new double[this->size]();

	for (int i = 0; i < this->size; i++)
		data[i] = 0.0;
}

/*
Destructor
Releases the dynamically allocated array. A confirmation
message is printed so the test program can verify that the
estructor executed at the correct time.
*/
NumberArray::~NumberArray()
{
	delete[] data;
	cout << "Destructor called. Memory released.\n";
}

/*
Mutator: setNumber
Stores a value at the given index only if the index is
within valid bounds (0 <= index < size). Invalid indices are
ignored to protect the array from out-of-bounds writes.
*/
void NumberArray::setNumber(int index, double value)
{
	if (index >= 0 && index < size)
		data[index] = value;
}
/*
Accessor: getNumber
Returns the value stored at the given index. If the index is
invalid, a static default value (0.0) is returned instead.
This prevents the caller from ever accessing invalid memory.
*/
double NumberArray::getNumber(int index) const
{
	static const double D_FAULT = 0.0;

	if (index >= 0 && index < size)
		return data[index];
	else
		return D_FAULT;
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
// Displays all values in the array.
*/
void NumberArray::print() const
{
	for (int i = 0; i < size; i++)
		cout << data[i] << " ";

	cout << endl;
}

