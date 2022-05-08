/**
 * @file math_operation.cpp
 * @author abdelrahman elsayed
 * @brief 
 * @version 0.1
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "tinyexpr.h"
#include<exception>
/**
 * @brief Construct a new math operation object
 * 
 */
math_operation::math_operation()
{

}

/**
 * @brief substitute by x value in expression anf get result or 
 * throw exception in case of invaild expression
 * 
 * @param exp math expression in string form
 * @param x_value  value of x to substitute in math expression
 * @return double - result
 * 
 */
double math_operation::vaildate_input_get_result(std::string exp,double x_value){

    char expression[exp.length() + 1];

    strcpy(expression, exp.c_str());

    double r=0;
    double x;

    te_variable vars[] = {{"x", &x}};

    /* This will compile the expression and check for errors. */
    int err_position;
    te_expr *n = te_compile(expression, vars, 1, &err_position);

    if (n) {
        /* The variables can be changed here, and eval can be called as many
         * times as you like. This is fairly efficient because the parsing has
         * already been done. */
        x = x_value;
        r = te_eval(n);

        te_free(n);
    } else {
        /* error  */
        throw Invaild_Expression();
    }
    return r;
}
