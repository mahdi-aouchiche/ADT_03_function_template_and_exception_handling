#ifndef __UNIT_TEST_HPP__
#define __UNIT_TEST_HPP__

#include "gtest/gtest.h"
#include "../src/template_example.cpp"

// test vectors of type int, double, string. Check execption using empty vecor 
vector<int> integers     = { 8, 0, -10, -1, 3};
vector<double> doubles   = {0, -1.5, 10.9, 9.0, -9.0};
vector<string> strings   = {"ac" , "A", "c", "a", "ab"};
vector<int> empty_vector = {};  

// sorted vectors used to check verify selection_sort().
vector<int> sorted_integers   = {-10, -1, 0, 3, 8};
vector<double> sorted_doubles = {-9, -1.5, 0, 9, 10.9};
vector<string> sorted_strings = {"A", "a", "ab", "ac", "c"};

TEST(Function_Template, min_index_test) {   
    EXPECT_EQ(min_index(integers, 1), 2);
    EXPECT_EQ(min_index(doubles , 1), 4);
    EXPECT_EQ(min_index(strings , 1), 1);
    EXPECT_THROW(min_index(empty_vector, 10), out_of_range);
    EXPECT_THROW(min_index(integers, 10), out_of_range);  
}

TEST(Function_Template, selection_sort_integer_test) {  
    selection_sort(integers);
    for(unsigned i = 0; i < integers.size(); i++) {
        EXPECT_EQ(integers.at(i), sorted_integers.at(i));
    }  
}

TEST(Function_Template, selection_sort_double_test) {  
    selection_sort(doubles);
    for(unsigned i = 0; i < doubles.size(); i++) {
        EXPECT_EQ(doubles.at(i), sorted_doubles.at(i));
    }  
}

TEST(Function_Template, selection_sort_string_test) {  
    selection_sort(strings);
    for(unsigned i = 0; i < strings.size(); i++) {
        EXPECT_EQ(strings.at(i), sorted_strings.at(i));
    }  
}

TEST(Function_Template, selection_sort_empty_test) {  
    EXPECT_NO_THROW(selection_sort(empty_vector));
    EXPECT_THROW(empty_vector.at(0), out_of_range);
}

TEST(Function_Template, getElement_test) { 
    EXPECT_EQ(getElement(sorted_integers, 2), 0);
    EXPECT_EQ(getElement(sorted_doubles , 2), 0);
    EXPECT_EQ(getElement(sorted_strings , 2), "ab"); 
    
    EXPECT_THROW(getElement(sorted_strings, 10), out_of_range);
    EXPECT_THROW(getElement(empty_vector, 0), out_of_range);
}


#endif // __UNIT_TEST_HPP__