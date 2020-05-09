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











 /*
 1) Edit your 3 structs so that they own a heap-allocated primitive type without using smart pointers  
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
     
 
 5) print out the results with some creative couts 
    i.e.
         FloatType ft(0.1f);
         IntType it(3);
         std::cout << "adding 3 and subtracting 'it' from 'ft' results in the following value: " << *ft.add(2.f).subtract( it ).value << std::endl;  //note the dereference of the `value` member of `ft`
 
 6) Don't let your heap-allocated owned type leak!
 
 7) click the [run] button.  Clear up any errors or warnings as best you can.
 
 */




#include <iostream>

struct FloatType
{
    float add(float lhs, float rhs)
    {
        return lhs + rhs;
    }

    float subtract(float lhs, float rhs)
    {
        return lhs - rhs;
    }

    float multiply(float lhs, float rhs)
    {
        return lhs * rhs;
    }

    float divide(float lhs, float rhs)
    {
        if(rhs == 0.f) 
            std::cout << "Attention: Dividing floats by 0!" << "\n";
        return lhs / rhs;
    }
};

struct DoubleType
{
    double add(double lhs, double rhs)
    {
        return lhs + rhs;
    }

    double subtract(double lhs, double rhs)
    {
        return lhs - rhs;
    }

    double multiply(double lhs, double rhs)
    {
        return lhs * rhs;
    }

    double divide(double lhs, double rhs)
    {
        if(rhs == 0.0) 
            std::cout << "Attention: Dividing doubles by 0!" << "\n";
        return lhs / rhs;
    }
};

struct IntType
{
    int add(int lhs, int rhs)
    {
        return lhs + rhs;
    }

    int subtract(int lhs, int rhs)
    {
        return lhs - rhs;
    }

    int multiply(int lhs, int rhs)
    {
        return lhs * rhs;
    }

    int divide(int lhs, int rhs)
    {
        if(rhs == 0) 
        {
            std::cout << "ERROR: Dividing ints by 0!" << "\n";
            return 0;
        }
        return lhs / rhs;
    }
};

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
    FloatType floaty;
    auto result = floaty.divide(5.6f, 0);
    std::cout << "result of floaty.divide(): " << result << "\n";

    FloatType floater;
    result = floater.subtract(77.5648f, 10000);
    std::cout << "result of floater.substract(): " << result << "\n";

    DoubleType doubly;
    auto result1 = doubly.add(48956.684364684, 365345347.68463648);
    std::cout << "result of doubly.add(): " << result1 << "\n";

    DoubleType doubler;
    result1 = doubler.multiply(384345346346841.686846434, 3484239339439.64536836);
    std::cout << "result of doubler.multiply(): " << result1 << "\n";
    
    DoubleType doublerer;
    result1 = doublerer.divide(384345346346841.686846434, 0.0);
    std::cout << "result of doublerer.divide(): " << result1 << "\n";

    IntType inty;
    auto result2 = inty.divide(5, 0);
    std::cout << "result of inty.divide(): " << result2 << "\n";
    
    IntType inter;
    result2 = inter.add(756, 566);
    std::cout << "result of inter.add(): " << result2 << "\n";
    
    std::cout << "good to go!" << std::endl;
}
