#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

std::pair<int, int> GetMidpointIndices(int size) {
  const auto midpoint_a = ((size + 1) / 2) - 1;
  const auto midpoint_b = midpoint_a + (size % 2 == 0);
  // this constructs a std::pair<int, int>
  // the compiler can deduce the return type since it is already mentioned in the prototype
  return { midpoint_a, midpoint_b };
}

int FindMedianMark(const std::vector<int>& marks) {
  const auto midpoints = GetMidpointIndices(marks.size());
  // vector is not ordered, so we should not assume that data is sorted
  std::vector<int> temp_marks = marks;
  std::sort(temp_marks.begin(), temp_marks.end());
  return (temp_marks[midpoints.first] + temp_marks[midpoints.second]) / 2;
}

int main() {
  std::vector<int> studentMarks;

  studentMarks.push_back(82);
  studentMarks.push_back(63);
  studentMarks.push_back(74);
  studentMarks.push_back(69);
  studentMarks.push_back(67);

  std::cout << "Median: " << FindMedianMark(studentMarks) << "\n";
}