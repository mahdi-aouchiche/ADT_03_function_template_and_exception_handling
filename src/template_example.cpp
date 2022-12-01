#include "../header/template_example.hpp"

template<typename T>
unsigned min_index(const vector<T> &vals, unsigned index) {

  int min_index = index ;     // min_index holds the index of the min value 
  T min_value ;               // min_value holds the value at index

  // throw an out of range exception
  if( ( vals.size() < 1 ) || ( index >= vals.size() ) ) {
    throw out_of_range("out of range exception occured");
  }  

  min_value   = vals.at(index);  // min_value holds the value at index1  

  // go throught the vector starting at index1 + 1  
  for ( unsigned i = index + 1 ; i < vals.size() ; ++i ) {

    if ( vals.at(i) < min_value ) {
      min_value = vals.at(i) ;      // update min value 
      min_index = i ;               // update the min_index to the new element 
    }
  }
  
  return min_index; 
}

template <typename T>
void selection_sort(vector<T> &vals) {

  // sort only if the vector has elements to sort
  if( vals.size() > 0 ) {
    
    unsigned min_element;   // holds the index of the min value 
    T temp;                 // holds the value to swap 
  
    // go through the vector from 0 to the element before last
    // the last element of the vector would be the largest at the end.
    for ( unsigned i = 0; i < vals.size() - 1 ; ++i ) {
      min_element = min_index( vals, i );   // find index of min value
      temp = vals.at(i);                    // save the value at index i
      vals.at(i) = vals.at(min_element);    // move the min value to index i 
      vals.at(min_element) = temp;          // move the value at index i to the min_index
    }
  }
}

template<typename T>
T getElement(vector<T> vals, int index) {

  // throw an out of range exception
  if( ( vals.size() < 1 ) || ( (unsigned) index >= vals.size() ) ) {
    throw out_of_range("out of range exception occured");
  }

  // return the element located at the index1 of the vals.
  return vals.at(index); 
}

vector<char> createVector(){
    int vecSize = rand() % 26;
    char c = 'a';
    vector<char> vals;
    for(int i = 0; i < vecSize; i++)
    {
        vals.push_back(c);
        c++;
    }
    return vals;
}