#include <string>
namespace {

// return is an rvalue
// rvalue can be categorized further into prvalue or xvalue depending on the context
std::string getEmptyString() {
  return {};
}

}

int main() {
  // in this context the return value of getEmptyString() is a prvalue
  std::string empty_string = getEmptyString();

  // in this context, the return value of getEmptyString() is subject to temporary materialization
  // and is therefore treated as a std::string&& (xvalue)
  // for a method to be called, an object is required, a prvalue has no result object, that is why
  // temporary materialization is required
  const int empty_string_size = getEmptyString().size();

  // both empty_string and empty_string_size are glvalues or lvalues to be specific

  // here the move constructor, std::string::string(std::string&& from) is called
  // `from` is a glvalue that is an xvalue (moved from empty_string)
  std::string empty_string_2 { std::move(empty_string) };
}