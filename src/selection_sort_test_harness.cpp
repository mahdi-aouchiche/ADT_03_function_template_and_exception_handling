#include <cstdlib>
#include <iostream>
#include <ctime>
#include <vector>
#include <sstream>
#include <algorithm>
#include "template_example.cpp"

using namespace std;

string int2str(int n) {
   ostringstream ssout;
   ssout << n;
   return ssout.str();
}

int genRandInt(int low, int high) {
	return low + rand() % (high - low + 1);
}

bool testPassed() {
   srand(time(0));
   ostringstream ssout;
   string actual, expected;
   int randValue;
   vector<int> values;
   vector<int> expectedValues;
   int numValues;
   
   selection_sort(values);
   //ssout << values;
   for (unsigned i = 0; i < values.size(); ++i) {
       ssout << values.at(i);
       if(i != values.size()-1)
       	   ssout<< " ";
   }
   actual = ssout.str();
   if (actual != expected) {
      cout << "selection_sort did not work when called on an empty vector of integers." << endl;
      cout << "Expected: " << expected << endl;
      cout << "Actual: " << actual << endl;
      return false;
   }
   
   randValue = genRandInt(-20, -10);
   values.push_back(randValue);
   expectedValues.push_back(randValue);
   selection_sort(values);
   expected = int2str(randValue);
   ssout.str("");
   //ssout << values;
   for (unsigned i = 0; i < values.size(); ++i) {
       ssout << values.at(i);
       if(i != values.size()-1)
       	   ssout<< " ";
   }
   actual = ssout.str();
   if (actual != expected) {
      cout << "selection_sort did not work when called on a vector with a single integer." << endl;
      cout << "Expected: " << expected << endl;
      cout << "Actual: " << actual << endl;
      return false;
   }
   
   randValue = genRandInt(-9, -1);
   values.push_back(randValue);
   expectedValues.push_back(randValue);
   selection_sort(values);
   expected = int2str(expectedValues.at(0)) + " " + int2str(expectedValues.at(1));
   ssout.str("");
   //ssout << values;
   for (unsigned i = 0; i < values.size(); ++i) {
       ssout << values.at(i);
       if(i != values.size()-1)
       	   ssout<< " ";
   }
   actual = ssout.str();
   if (actual != expected) {
      cout << "selection_sort did not work when called on a vector with 2 integers." << endl;
      cout << "Expected: " << expected << endl;
      cout << "Actual: " << actual << endl;
      return false;
   }
   
   numValues = genRandInt(10, 20);
   
   for (int n = 0; n < numValues; ++n) {
      randValue = genRandInt(-10, 20);
      values.push_back(randValue);
      expectedValues.push_back(randValue);
   }
   selection_sort(values);
   sort(expectedValues.begin(), expectedValues.end());
   expected = int2str(expectedValues.at(0));
   for (unsigned i = 1; i < expectedValues.size(); ++i) {
      expected = expected + " " + int2str(expectedValues.at(i));
   }
   ssout.str("");
   //ssout << values;
   for (unsigned i = 0; i < values.size(); ++i) {
       ssout << values.at(i);
       if(i != values.size()-1)
       	   ssout<< " ";
   }
   actual = ssout.str();
   if (actual != expected) {
      cout << "selection_sort did not work when called on a vector with more than 2 integers." << endl;
      cout << "Expected: " << expected << endl;
      cout << "Actual: " << actual << endl;
      return false;
   }
   
   return true;
}