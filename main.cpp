#include <iostream>         // March 2022
#include <vector>
using namespace std;

/**
 * Demonstrates creating a vector of integers
 * - populating the vector
 * - iterating over the elements
 * - accessing the elements
 */

// function prototypes
void print(vector<int> &);  // pass vector by reference

int main()
{
	vector<int> intVector;  // create vector of int

	intVector.push_back(1); // add element at end of vector
	intVector.push_back(2);

	for (int i = 3; i <= 10; i++)   // add 7 more elements
	{
		intVector.push_back(i);
	}

	cout << "Initial vector elements: ";
	print(intVector);   // pass the vector by reference

    // automatic (auto) type declaration based on return type of .begin()
	auto iter = intVector.begin();

    //	vector<int>::iterator iter = intVector.begin(); //

	for (iter = intVector.begin(); iter != intVector.end(); iter++)
	{
		cout << *iter << endl;  // dereference the iterator to access an element
	}

	iter = intVector.begin() + 2;    // position the iterator two places beyond the start position
	intVector.insert(iter, 11); // insert the value 11 at the current iterator position
	print(intVector);                // output to confirm what has happened

	iter = intVector.begin() + 2;   // re-position the iterator
	intVector.erase(iter);
	print(intVector);

    // access vector elements using array notation "[]"
    //
	for (int i = 0; i < intVector.size(); i++)
	{
		intVector[i] = intVector[i] * 2;
	}
	print(intVector);

    cout << "Element at index position 3 is = " << intVector.at(3) << endl;

    // using .at() will throw exception if array index is out of bounds.
    // array notation "[i]" will not indicate your error!!
    // uncomment the following line to see the exception thrown
    // cout << "Element at index position 13 is = " << intVector.at(13) << endl;
    cout << "Element at index position 13 is = " << intVector[13] << endl;
}

/**
 * Print out the elements in a vector of integer values.
 * @param intVector reference to a vector of numbers
 */
void print(vector<int> &intVector)
{
    for (int i = 0; i < intVector.size(); i++)
    {
        if (i != 0) {
            cout << ",";
        }
        cout << intVector.at(i);
    }
    cout << endl;
}
