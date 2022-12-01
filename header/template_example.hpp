#ifndef __TEMPLATE_EXAMPLE_HPP
#define __TEMPLATE_EXAMPLE_HPP

#include <iostream>
#include <stdexcept>
#include <vector>
#include <ctime>
using namespace std;

/* Passes in an index1 of type int and a vector of type T 
 * (T could be string, double or int).
 * The function returns the index1 of the min value
 * starting from "index1" to the end of the "vector".
*/
template<typename T>
unsigned min_index(const vector<T> &vals, unsigned index);

/* Passes in a vector of type T and sorts them
 * based on the selection sort method.
 * This function should utilize the min_index function
 * to find the index of the min value
 * in the unsorted portion of the vector.
*/
template <typename T>
void selection_sort(vector<T> &vals);

/* Passes in a vector of type T (T could be string, double or int)
 * and an index of type int.
 * The function returns the element located at the index of the vals.
 * You should write up a try catch block in main function
 * so that when the index is out of the range of the vector,
 * the "std::outofrange" exception will be caught
 * by the catch (const std::outofrange& excpt).
 * Once the exception is caught,
 * it should output "out of range exception occured"
 * followed by a new line.
*/
template<typename T>
T getElement(vector<T> vals, int index);

vector<char> createVector();

#endif  //__TEMPLATE_EXAMPLE_HPP