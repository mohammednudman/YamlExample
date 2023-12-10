## #include<fstream>

The #include <fstream> directive is used to include the C++ Standard Library header file that provides facilities for
performing input and output operations using file streams.
The name "fstream" is derived from "file stream," indicating that this header introduces classes for reading from and
writing to files.

- std::ifstream : This class represents an input file stream. You can use it to read data from files.

- std::ofstream : This class represents an output file stream. You can use it to write data to files.

- std::fstream : This class represents a file stream that can be used for both input and output operations. It combines
  the functionality of std::ifstream and std::ofstream.

## #include<ctime>

The #include<ctime> header provides functions for working with time and date. The name "ctime" is short for "C time."
Here are some key concepts and functions related to <ctime>:

- std::time_t : This is a type that represents time in C++. It is usually used to store the number of seconds elapsed
  since a specific point in time (usually the "epoch" – January 1, 1970).

- std::time() : This function returns the current time as a std::time_t value. It's like asking the clock for the
  current time.

## #include<iomanip>

The #include <iomanip> directive is used to include the C++ Standard Library header file that provides facilities for
manipulating the format of input and output in a C++ program.
The name "iomanip" is short for "input/output manipulation."
This header introduces several manipulators that allow you to control the formatting of data when it is input from or
output to streams, such as std::cout or std::cin.

- get_time() in you code

## explicit keyword

When a constructor is marked as explicit, it prevents the compiler from automatically using that constructor for
implicit conversions.
This can help prevent unexpected type conversions and improve the clarity of your code.

## datastream.fail()

Working with a std::istream (input stream), such as when reading from a file or the standard input, fail() is used to
check if an operation like reading data failed.
This could happen, for example, if you're expecting to read an integer, but the input contains non-numeric characters.

```cpp EmployeeBonusCalculator(const std::filesystem::path& csvFilePath, const std::string& yamlFilePath) : csvFilePath_(csvFilePath), yamlFilePath_(yamlFilePath) {}```

- Constructor Declaration: EmployeeBonusCalculator: This is the name of the class for which the constructor is defined.
- Parameters: (const std::filesystem::path& csvFilePath, const std::string& yamlFilePath): This part defines the
  parameters that the
  constructor takes. It has two parameters:
  const std::filesystem::path& csvFilePath: This parameter is a constant reference to an object of type std::
  filesystem::
  path. It is likely used to pass a file path represented by the C++ filesystem library.
  const std::string& yamlFilePath: This parameter is a constant reference to an object of type std::string. It is likely
  used to pass a file path represented by a standard string.

- Member Initialization List: csvFilePath_(csvFilePath), yamlFilePath_(yamlFilePath): This is the member initialization
  list that follows the
  colon (:) after the parameter list. It is used to initialize the member variables of the class.
  csvFilePath_(csvFilePath): This initializes the member variable csvFilePath_ with the value of the csvFilePath
  parameter.
  yamlFilePath_(yamlFilePath): This initializes the member variable yamlFilePath_ with the value of the yamlFilePath
  parameter.

- Constructor Body: {}: The curly braces represent the body of the constructor. In this case, it is empty, indicating
  that there are no
  additional actions to be performed in the constructor body.
  This constructor is likely part of a class (EmployeeBonusCalculator) designed to calculate bonuses for employees. The
  constructor takes file paths as parameters, likely pointing to a CSV file (csvFilePath) and a YAML file (
  yamlFilePath).
  The member variables csvFilePath_ and yamlFilePath_ are then initialized with the values passed to the constructor.

This pattern of initializing member variables in the constructor initialization list is a good practice, as it can lead
to more efficient code and is often considered better style, especially for members that are not simple primitives.

## Difference between push_back() and emplace_back()

### Construction:

- push_back requires a fully constructed object to be added to the container. It makes a copy (or move) of the provided
  object.
- emplace_back constructs the object directly in the container, eliminating the need for a separate copy or move
  operation.

### Arguments:

- push_back accepts an object of the container's value type.
- emplace_back accepts constructor arguments for the container's value type.

### Efficiency:

- emplace_back can be more efficient in some cases, as it avoids unnecessary copy or move operations by constructing the
  element directly in the container.

### Flexibility:

- emplace_back provides more flexibility when dealing with non-copyable or non-movable types, as it constructs the
  object in place without the need for copying or moving.

```c++
YAML::Node bonus_range_config = YAML::LoadFile(yamlFilePath_)["RangeAmountConfig"];
```

- YAML::Node: YAML::Node is a class provided by the YAML-CPP library. It represents a node in a YAML document. A YAML
  document is a hierarchical structure, and a YAML::Node can represent a scalar value, a sequence (array), or a
  mapping (dictionary).

- bonus_range_config: This is an instance of the YAML::Node class. It is being used to store the contents of a specific
  node in the YAML document.

- YAML::LoadFile(yamlFilePath_): This part loads the content of a YAML file into a YAML::Node. The YAML::LoadFile
  function reads the YAML file specified by yamlFilePath_ and parses it into a hierarchy of YAML::Node objects.

- ["RangeAmountConfig"]: This is an operator used to access a specific node within the loaded YAML data. In YAML, a node
  can be a scalar, a sequence, or a mapping.
  In this case, it is assuming that the root of the YAML document is a mapping, and it is accessing a specific key
  called "RangeAmountConfig" within that mapping.

```c++
std::time_t current_time = std::time(nullptr);
```

std::time_t current_time:
std::time_t is a data type that represents time, usually in seconds since the "epoch" (January 1, 1970).
current_time is a variable of type std::time_t that will store the current time.

std::time(nullptr):
std::time(nullptr) is a function that returns the current time as a std::time_t value.
The nullptr argument is used to get the current time without passing any additional information.

std::tm *current_date:
std::tm is a structure defined in the <ctime> header that holds the components of a calendar date and time.
current_date is a pointer to a std::tm structure that will store the components of the current local time and date.

std::localtime(&current_time):
std::localtime is a function that takes a std::time_t value (representing the time in seconds) and converts it to a

std::tm structure representing the local time and date.
The function returns a pointer to this std::tm structure.

Putting it all together, the code retrieves the current time as a std::time_t value using std::time(nullptr). Then, it
uses std::localtime to convert this std::time_t value into a std::tm structure, storing the components of the current
local time and date in the current_date variable.

### R(""") string literal

The string literal R"(C:\Users\Mohammed\CLionProjects\untitled\Employee.csv)" is an example of a Raw String Literal in
C++. Raw string literals were introduced in C++11 and are denoted by the R prefix followed by a pair of parentheses ( )
containing an optional delimiter. The delimiter is specified after the R, and the actual string content is placed
between the parentheses. In your example, there is no specified delimiter.

```c++
auto main() -> int
```

auto main() -> int
auto keyword:
The auto keyword is used to deduce the type of the variable or function return type from its initializer or body.

main():
This is the declaration of the main function, which serves as the entry point of a C++ program.

-> int:
The trailing return type syntax indicates the return type of the function. In this case, it explicitly states that the
main function returns an integer (int).

This syntax is functionally equivalent to the traditional int main() declaration. The use of trailing return type syntax
can be beneficial in more complex scenarios, especially when dealing with template functions or when the return type is
dependent on other template parameters.

```c++
 static auto
    calculateLoyaltyBonus(const std::tm &joining_date, const std::tm &current_date, const YAML::Node &bonus_ranges) -> int{}
```
The static keyword in this context is used to indicate that the calculateLoyaltyBonus function is a static member
function of a class. In C++, when a member function is declared as static, it means that the function belongs to the
class itself rather than to instances of the class. Static member functions can be called on the class itself, without
requiring an instance of the class