#include "tutorials/week3/dictionary_library.h"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>

// TODO(tutors): Discuss how the use of istream instead of ifstream improves ease of testing.
// istream is the base class of a lot of stream classes, using it ensures that your code is compatible
// those classes. This is important for testing as now we can pass in a pre-constructed istringstream here.
// e.g. you don't have to prompt user input during testing and just use pre-defined strings.
std::vector<std::string> ToWordList(std::istream& input) {
  std::vector<std::string> word_list;

  //std::istringstream input_stream{input};
  std::copy(std::istream_iterator<std::string>(input),
            std::istream_iterator<std::string>(),
            std::back_inserter(word_list));

  return word_list;
}

// We only ever pass std::cin and std::cout to input and output respectively.
// TODO(tutors): Discuss why we don't just use std::cin and std::cout with respect to testing.
void PrintValidWords(const std::vector<std::string>& valid_words,
                     std::istream& input,
                     std::ostream& output) {
  std::copy_if(std::istream_iterator<std::string>(input),
               std::istream_iterator<std::string>(),
               std::ostream_iterator<std::string>(output, " "),
               [&valid_words](const std::string& split_string){
                 return std::find(valid_words.begin(), valid_words.end(), split_string) != valid_words.end();
               });
}
