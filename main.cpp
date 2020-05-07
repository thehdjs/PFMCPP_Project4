/*
 Project 4 - Part 1 / 9
 video: Chapter 2 Part 7
 Returning Values tasks 

 Create a branch named Part1

 Purpose:  This project will take you through the process of writing a class that wraps a numeric type, beginning with writing simple member functions and ending with a fully templated class with lots of functionality. 
 
 1) write 3 UDTs named FloatType, DoubleType, IntType.
 
 2) give each UDT the following member functions:
        add( lhs, rhs );
        subtract( lhs, rhs );
        multiply( lhs, rhs );
        divide( lhs, rhs );
 3) implement the appropriate action in the member function. 
         a) Be aware that floating point division by 0 is legal, but integer division by 0 will crash your program.  
         b) Handle this possible input when you write your divide() functions.
         c) you should warn the user if they're doing floating-point-division-by-zero but not prevent the division from happening
         d) you should warn AND prevent the division from happening if it is an integer-division-by-zero.
 
 4) make them return the correct primitive type. e.g. if you're implementing the FloatType::add function, your implementation would start like this:
        float FloatType::add( float lhs, float rhs )
 
 5) declare a few instances of each class in main() and call the member functions with the appropriate arguments.
        FloatType ft;
        auto result = ft.add(3.2f, 23.f );
 
 6) print out those results using std::cout:
        std::cout "result of ft.add(): " << result << std::endl;
 
 7) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
Make a pull request after you make your first commit and pin the pull request link to our DM thread.

send me a DM to check your pull request

 Wait for my code review.
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
        if(rhs == 0.f) // gave me warning when writing 0 without .f saif it was unsafe to use == or =! with floats. Don't see how 0.f makes it better
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
        else return lhs / rhs;
    }
};

int main()
{
    FloatType floaty;
    auto result = floaty.divide(5.6f, 0);
    std::cout << "result of floaty.divide(): " << result << "\n";

    FloatType floater;
    result = floater.subtract(77.5648f, 10000);
    std::cout << "result of floater.substract(): " << result << "\n";

    DoubleType doubly;
    result = doubly.add(48956.684364684, 365345347.68463648);
    std::cout << "result of doubly.add(): " << result << "\n";

    DoubleType doubler;
    result = doubler.multiply(384345346346841.686846434, 3484239339439.64536836);
    std::cout << "result of doubler.multiply(): " << result << "\n";

    IntType inty;
    result = inty.divide(5, 0);
    std::cout << "result of inty.divide(): " << result << "\n";
    
    IntType inter;
    result = inter.add(756, 566);
    std::cout << "result of inter.add(): " << result << "\n";
    
    std::cout << "good to go!" << std::endl;
}
