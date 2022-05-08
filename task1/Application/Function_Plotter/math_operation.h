/**
 * @file math_operation.h
 * @author abdelrahman elsayed
 * @brief 
 * @version 0.1
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef MATH_OPERATION_H
#define MATH_OPERATION_H

#include<string>
#include<string.h>
/**
 * @brief class used to provide needed math functions
 * 
 */
class math_operation
{
public:
/**
 * @brief Construct a new math operation object
 * 
 */
    math_operation();
    /**
     * @brief substitute by x value in expression anf get result or 
     * throw exception in case of invaild expression
     * 
     * @param exp math expression in string form
     * @param x_value  value of x to substitute in math expression
     * @return double - result
     * 
     */
    static double vaildate_input_get_result(std::string exp,double x_value);
};

/**
 * @brief exception used in vaildate_input_get_result() function
 * 
 */
struct Invaild_Expression : public std::exception {
   const char * what () const throw () {
      return "Invaild math Expression";
   }
};
#endif // MATH_OPERATION_H
