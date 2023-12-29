//Inheritance 

The capability of a class to derive properties and characteristics from another class is called Inheritance.
Inheritance is one of the most important features of Object-Oriented Programming. 

Inheritance is a feature or a process in which, new classes are created from the existing classes.
The new class created is called “derived class” or “child class” and the existing class is known as the “base class” or “parent class”.
The derived class now is said to be inherited from the base class.



Derived Classes: A Derived class is defined as the class derived from the base class.
Syntax: 

class  <derived_class_name> : <access-specifier> <base_class_name>
{
        //body
}

class      — keyword to create a new class
derived_class_name   — name of the new class, which will inherit the base class
access-specifier  — either of private, public or protected. If neither is specified, PRIVATE is taken as default
base-class-name  — name of the base class

Note: A derived class doesn’t inherit access to private data members.
However, it does inherit a full parent object, which contains any private members which that class declares.


1.When a base class is privately inherited by the derived class,
public members of the base class becomes the private members of the derived class 
and therefore,the public members of the base class can only be accessed by the member functions of the derived class. 
They are inaccessible to the objects of the derived class.

2. On the other hand, when the base class is publicly inherited by the derived class, 
public members of the base class also become the public members of the derived class. 
Therefore, the public members of the base class are accessible by the 
objects of the derived class as well as by the member functions of the derived class.



 
