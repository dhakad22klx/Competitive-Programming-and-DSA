Role of Access Specifiers in Encapsulation
Access specifiers facilitate Data Hiding in C++ programs by restricting access to the class member functions and data members.
There are three types of access specifiers in C++:

Private: Private access specifier means that the member function or
 data member can only be accessed by other member functions of the same class.
 
Protected: A protected access specifier means that the member function or 
data member can be accessed by other member functions of the same class or by derived classes.

Public: Public access specifier means that the member function or data member can be accessed by any code. 
By default, all data members and member functions of a class are made private by the compiler.


//static in c++ gfg

Static functions in a class: Just like the static data members or static variables inside the class, static member functions also do not depend on the object of the class. We are allowed to invoke a static member function using the object and the ‘.’ operator but it is recommended to invoke the static members using the class name and the scope resolution operator. Static member functions are allowed to access only the static data members or other static member functions, they can not access the non-static data members or member functions of the class. 
