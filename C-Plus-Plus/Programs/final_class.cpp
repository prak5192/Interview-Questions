/*
A program with compilation error to demonstrate that Final class cannot 
   be inherited 
*/

/*
Explanation : Ever wondered how can you design a class in C++ which can’t 
be inherited. Java and C# programming languages have this feature built-in. 
You can use final keyword in java, sealed in C# to make a class non-extendable.

Below is a mechanism using which we can achieve the same behavior in C++. 
It makes use of private constructor, virtual inheritance and friend class.

In the following code, we make the Final class non-inheritable. When a 
class Derived tries to inherit from it, we get compilation error.

An extra class MakeFinal (whose default constructor is private) is used 
for our purpose. Constructor of Final can call private constructor of 
MakeFinal as Final is a friend of MakeFinal .

Note that MakeFinal is also a virtual base class. The reason for this is 
to call the constructor of MakeFinal through the constructor of Derived, 
not Final (The constructor of a virtual base class is not called by the 
class that inherits from it, instead the constructor is called by the 
constructor of the concrete class).

*/
#include<iostream>
using namespace std;

class Final;  // The class to be made final

class MakeFinal // used to make the Final class final
{
    private:
        MakeFinal() 
        { 
            cout << "MakFinal constructor" << endl; 
        }
        friend class Final;
};

class Final : virtual MakeFinal
{
    public:
        Final() 
        { 
            cout << "Final constructor" << endl; 
        }
};

class Derived : public Final // Compiler error
{
    public:
        Derived() 
        { 
            cout << "Derived constructor" << endl;
        }
};

int main(int argc, char *argv[])
{
    Derived d;
    return 0;
}
