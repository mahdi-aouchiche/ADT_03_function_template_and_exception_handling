#include "selection_sort_test_harness.cpp"

int main(){
  
  // test vectors of type int, double, string
  vector<int> integers = { 20, -10, 5, 9, 15, -55, 25, 90, 0, 1};
  vector<double> doubles = {20.5, -30.5, 5, 9.0, 15.5, -5.9, 25, 90.1, 0, 1.1};
  vector<string> strings = {"ab" , "A", "cd", "ac", "z", "abc", "aa", "a", "zzz", "b"};
  vector<int> empty = {} ;     // used to check execptions for an empty vector 

  // test min_index() 
  {
    cout << endl << "Test min_index() function:" << endl;

    unsigned index1; 
    cout << " - Enter an index between 0 to 9: ";
    cin >> index1; 

    try {  
      // output results 
      cout << " - min_index of integers is " << min_index( integers, index1 ) << endl;
      cout << " - min_index of doubles is "  << min_index( doubles, index1 )  << endl;
      cout << " - min_index of integers is " << min_index( strings, index1 )  << endl;
      // cout << " - min_index of integers is " << min_index( empty, index1 )  << endl;
    }
    catch ( out_of_range &excpt) {
      // Prints the error message passed by throw statement and a newline 
      cout << excpt.what() << endl;
    }
    // end test min_index1() 
    cout << "End of testing min_index() function." << endl;  
  }
    
  // test selection_sort() 
  {
    cout << endl << "Test selection_sort() function:" << endl;
    cout << " - Method 1: using std::cout to check for valid output" << endl;

    // call the selection_sort() function on the vectors 
    selection_sort( integers );
    selection_sort( doubles );
    selection_sort( strings ); 
    selection_sort( empty);     // used to check the function for an empty vector
 
    // for loop to display the vectors using selection_sort
    cout << " -- integers: " ;
    for ( unsigned i = 0; i < integers.size(); ++i ) {
      cout << integers.at(i) << ", ";
    }
    cout << endl;

    cout << " -- doubles: ";
    for ( unsigned i = 0; i < doubles.size(); ++i ) {
      cout << doubles.at(i) << ", ";
    }
    cout << endl;

    cout << " -- strings: ";
    for ( unsigned i = 0; i < strings.size(); ++i ) {
      cout << strings.at(i) << ", ";
    }
    cout << endl;

    cout << " -- empty vector: ";
    for ( unsigned i = 0; i < empty.size(); ++i ) {
      cout << empty.at(i) << ", ";
    }
    cout << endl;

    cout << endl << " - Method 2: using a test harness" << endl;
    if(testPassed()) {
      cout << " -- Selection_sort() function harness tests passed for integers." << endl;
    }

    // end test selection_sort() 
    cout << "End of testing selection_sort() function." << endl; 
  }

  // test getElement()
  {
    cout << endl << "Test getElement() function:" << endl;
    srand(time(0));
    vector<char> vals = createVector();
    char curChar;
    int index;
    int numOfRuns = 5;
  
    while(--numOfRuns >= 0){
      cout << " - Enter an index number: ";
      cin >> index;

      try {
        curChar = getElement(vals,index);
        cout << "   Element located at index " << index << " is: " << curChar << endl;
      }
      catch ( out_of_range &excpt) {
        // Prints the error message passed by throw statement and a newline 
        cout << excpt.what() << endl;
      }
    }

    // end test getElement() 
    cout << "End of testing getElement() function." << endl; 
  }
  
  return 0;
}
