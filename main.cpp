/*
 Project 4 - Part 2 / 9
 Video: Chapter 3 Part 6

 Create a branch named Part2

New/This/Pointers/References conclusion

    Build/Run often with this task to make sure you're not breaking the code with each step.
    I recommend committing after you get each step working so you can revert to a working version easily if needed.
 
 0) in the blank space below, declare/define an empty struct named 'A' on a single Line. 
     on the lines below it, write a struct named 'HeapA' that correctly shows how to own an instance of 'A' 
         on the heap without leaking, without using smart pointers. 
 */
struct A {};

struct HeapA
{
    HeapA() : ptrToaA(new A() ) {}
    ~HeapA()
    {
        delete ptrToaA;
    }
    A* ptrToaA = nullptr;
};
  /*
 1) Edit your 3 structs so that they own a heap-allocated primitive type without using smart pointers named 'value'
         IntType should own a heap-allocated int, for example.
 
 2) give it a constructor that takes the appropriate primitive
    this argument will initialize the owned primitive's value.
         i.e. if you're owning an int on the heap, your ctor argument will initialize that heap-allocated int's value.
 
 3) modify those add/subtract/divide/multiply member functions from chapter 2 on it
         a) make them modify the owned numeric type
         b) set them up so they can be chained together.
             i.e.
             DoubleType dt(3.5);
             dt.add(3.0).multiply(-2.5).divide(7.2); //an example of chaining
 
 4) write add/subtract/divide/multiply member functions for each type that take your 3 UDTs
        These are in addition to your member functions that take primitives
        for example, IntType::divide(const DoubleType& dt);
        These functions should return the result of calling the function that takes the primitive.
     
 5) Don't let your heap-allocated owned type leak!
 
 6) replace your main() with the main() below.
    It has some intentional mistakes that you need to fix to match the expected output
    i.e. don't forget to dereference your pointers to get the value they hold.

 7) click the [run] button.  Clear up any errors or warnings as best you can.
 */

#include <iostream>


/*
your program should generate the following output.  

18 warnings generated.
FloatType add result=4
FloatType subtract result=2
FloatType multiply result=4
FloatType divide result=0.25

DoubleType add result=4
DoubleType subtract result=2
DoubleType multiply result=4
DoubleType divide result=0.8

IntType add result=4
IntType subtract result=2
IntType multiply result=4
IntType divide result=1

Chain calculation = 590
New value of ft = (ft + 3.0f) * 1.5f / 5.0f = 0.975
---------------------

Initial value of dt: 0.8
Initial value of it: 590
Use of function concatenation (mixed type arguments) 
New value of dt = (dt * it) / 5.0f + ft = 95.375
---------------------

Intercept division by 0 
New value of it = it / 0 = error: integer division by zero is an error and will crash the program!
590
New value of ft = ft / 0 = warning: floating point division by zero!
inf
New value of dt = dt / 0 = warning: floating point division by zero!
inf
---------------------

good to go!



Use a service like https://www.diffchecker.com/diff to compare your output. 
you will have 3 conversion warnings at the top of your output.  
you'll learn to solve them in the next project part.

*/




#include <iostream>

struct FloatType;
struct IntType;
struct DoubleType;
struct FloatType
{   
    using T = FloatType;
    using U = float;
    
    FloatType(U u) : value( new U(u) ) { } 
    ~FloatType() { delete value; }

    T& add(U rhs)       { *value += rhs; return *this; }
    T& add(const FloatType& ft) { return add(*ft.value); }
    T& add(const IntType& ft);
    T& add(const DoubleType& ft);

    T& subtract(U rhs)  { *value -= rhs; return *this; }
    T& subtract(const FloatType& ft) { return subtract(*ft.value); }
    T& subtract(const IntType& ft);
    T& subtract(const DoubleType& ft);

    T& multiply(U rhs)  { *value *= rhs; return *this; }
    T& multiply(const FloatType& ft) { return multiply(*ft.value); }
    T& multiply(const IntType& ft);
    T& multiply(const DoubleType& ft);

    T& divide(U rhs)    
    { 
        if( rhs == 0.f )
            std::cout << "warning, floating point division by zero\n";
        *value /= rhs; 
        return *this; 
    }
    T& divide(const FloatType& ft) { return divide(*ft.value); }
    T& divide(const IntType& ft);
    T& divide(const DoubleType& ft);

    U* value = nullptr;
};

struct DoubleType
{   
    using T = DoubleType;
    using U = double;

    DoubleType(U u) : value( new U(u) ) { } 
    ~DoubleType() { delete value; }

    T& add(U rhs)       { *value += rhs; return *this; }
    T& add(const FloatType& ft) { return add(*ft.value); }
    T& add(const IntType& ft);
    T& add(const DoubleType& ft) { return add(*ft.value); }

    T& subtract(U rhs)  { *value -= rhs; return *this; }
    T& subtract(const FloatType& ft) { return subtract(*ft.value); }
    T& subtract(const IntType& ft);
    T& subtract(const DoubleType& ft) { return subtract(*ft.value); }

    T& multiply(U rhs)  { *value *= rhs; return *this; }
    T& multiply(const FloatType& ft) { return multiply(*ft.value); }
    T& multiply(const IntType& ft);
    T& multiply(const DoubleType& ft) { return multiply(*ft.value); }

    T& divide(U rhs)    
    { 
        if( rhs == 0.0 )
            std::cout << "warning, floating point division by zero\n";
        *value /= rhs; 
        return *this; 
    }
    T& divide(const FloatType& ft) { return divide(*ft.value); }
    T& divide(const IntType& ft);
    T& divide(const DoubleType& ft) { return divide(*ft.value); }

    U* value = nullptr;
};

struct IntType
{   
    using T = IntType;
    using U = int;

    IntType(U u) : value( new U(u) ) { } 
    ~IntType() { delete value; }

    T& add(U rhs)       { *value += rhs; return *this; }
    T& add(const FloatType& ft) { return add(*ft.value); }
    T& add(const IntType& ft) { return add(*ft.value); }
    T& add(const DoubleType& ft) { return add(*ft.value); }

    T& subtract(U rhs)  { *value -= rhs; return *this; }
    T& subtract(const FloatType& ft) { return subtract(*ft.value); }
    T& subtract(const IntType& ft) { return subtract(*ft.value); }
    T& subtract(const DoubleType& ft) { return subtract(*ft.value); }

    T& multiply(U rhs)  { *value *= rhs; return *this; }
    T& multiply(const FloatType& ft) { return multiply(*ft.value); }
    T& multiply(const IntType& ft) { return multiply(*ft.value); }
    T& multiply(const DoubleType& ft) { return multiply(*ft.value); }

    T& divide(U rhs)    
    { 
        if( rhs == 0 )
        {
            std::cout << "error, integer division by zero will crash program\n";
        }
        else
        {
            *value /= rhs; 
        }
        return *this; 
    }
    T& divide(const FloatType& ft) { return divide(*ft.value); }
    T& divide(const IntType& ft) { return divide(*ft.value); }
    T& divide(const DoubleType& ft) { return divide(*ft.value); }

    U* value = nullptr;
};

FloatType& FloatType::add(const IntType& ft) { return add(*ft.value); }
FloatType& FloatType::add(const DoubleType& ft) { return add(*ft.value); }

FloatType& FloatType::subtract(const IntType& ft) { return subtract(*ft.value); }
FloatType& FloatType::subtract(const DoubleType& ft) { return subtract(*ft.value); }

FloatType& FloatType::multiply(const IntType& ft) { return multiply(*ft.value); }
FloatType& FloatType::multiply(const DoubleType& ft) { return multiply(*ft.value); }

FloatType& FloatType::divide(const IntType& ft) { return divide(*ft.value); }
FloatType& FloatType::divide(const DoubleType& ft) { return divide(*ft.value); }

DoubleType& DoubleType::add(const IntType& ft) { return add(*ft.value); }
DoubleType& DoubleType::subtract(const IntType& ft) { return subtract(*ft.value); }
DoubleType& DoubleType::multiply(const IntType& ft) { return multiply(*ft.value); }
DoubleType& DoubleType::divide(const IntType& ft) { return divide(*ft.value); }
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{   
    //testing instruction 0
    HeapA heapA; 

    //assign heap primitives
    FloatType ft ( 2.0f );
    DoubleType dt ( 2 );
    IntType it ( 2 ) ;

    std::cout << "FloatType add result=" << *ft.add( 2.0f ).value << std::endl;
    std::cout << "FloatType subtract result=" << *ft.subtract( 2.0f ).value << std::endl;
    std::cout << "FloatType multiply result=" << *ft.multiply( 2.0f ).value << std::endl;
    std::cout << "FloatType divide result=" << *ft.divide( 16.0f).value << std::endl << std::endl;

    std::cout << "DoubleType add result=" << *dt.add(2.0).value << std::endl;
    std::cout << "DoubleType subtract result=" << *dt.subtract(2.0).value << std::endl;
    std::cout << "DoubleType multiply result=" << *dt.multiply(2.0).value << std::endl;
    std::cout << "DoubleType divide result=" << *dt.divide(5.f).value << std::endl << std::endl;

    std::cout << "IntType add result=" << *it.add(2).value << std::endl;
    std::cout << "IntType subtract result=" << *it.subtract(2).value << std::endl;
    std::cout << "IntType multiply result=" << *it.multiply(2).value << std::endl;
    std::cout << "IntType divide result=" << *it.divide(3).value << std::endl << std::endl;
    std::cout << "Chain calculation = " << *(it.multiply(1000).divide(2).subtract(10).add(100)).value << std::endl;

        // FloatType object instanciation and method tests
    // --------
    std::cout << "New value of ft = (ft + 3.0f) * 1.5f / 5.0f = " << *ft.add( 3.0f ).multiply(1.5f).divide(5.0f).value << std::endl;
       
    std::cout << "---------------------\n" << std::endl; 
    
    // DoubleType/IntType object instanciation and method tests
    // --------
    std::cout << "Initial value of dt: " << *dt.value << std::endl;
    std::cout << "Initial value of it: " << *it.value << std::endl;
    // --------
    std::cout << "Use of function concatenation (mixed type arguments) " << std::endl;
    std::cout << "New value of dt = (dt * it) / 5.0f + ft = " << *(dt.multiply(it).divide(5.0f).add(ft).value) << std::endl;

    std::cout << "---------------------\n" << std::endl; 
    
    // Intercept division by 0
    // --------
    std::cout << "Intercept division by 0 " << std::endl;
    std::cout << "New value of it = it / 0 = " << *it.divide(0).value << std::endl;
    std::cout << "New value of ft = ft / 0 = " << *ft.divide(0).value << std::endl;
    std::cout << "New value of dt = dt / 0 = " << *dt.divide(0).value << std::endl;

    std::cout << "---------------------\n" << std::endl; 

    std::cout << "good to go!\n";

    return 0;
}


