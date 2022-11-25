/*
 * Author: Cole Flenniken
 * Assignment Title: Multiplication table
 * Assignment Description: Take user input and build a
 *    multiplication from it
 * Due Date: 3/18/22
 * Date Created: 3/18/22
 * Date Last Modified: 3/18/22
 */

#ifndef EQUATIONBUILDER_H_INCLUDED
#define EQUATIONBUILDER_H_INCLUDED


#include <string>

using namespace std;

//************************************************************
// description: Generates a string that is SizeOfEquation    *
//    characters long that computes mathematically or an     *
//    error message if the parameter is < 6                  *
// return: string                                            *
// precondition: an int exists                               *
// postcondition: returns the equation with specified size   *
//    or an error if the parameter was < 6                   *
//************************************************************

string EquationGenerator(int SizeOfEquation);


//************************************************************
// description: Takes a string with 0-9, +-*/ chars and will *
//    Convert the string to be a string where all of the     *
//    math has been done for */+- following order of         *
//    operations                                             *
//    ex. "55+77-3*2" becomes "126"                          *
// return: string                                            *
// precondition: A string exists with only 0-9, +-*/ values  *
//    No two or more operants are next to each other         *
// postcondition: returns the new string without +-*/        *
//    if division by 0 or division resulting in a decimal    *
//    is happens within the expression, "BADMATH" is returned*
//************************************************************


string Op1Evaluate(const string exp1eval);


//************************************************************
// description: finds the integer to the left of an          *
//    operator in a string                                   *
// return: void                                              *
// precondition: an int i exists                             *
// postcondition: i is unchanged. a is set to the index of   *
//    the leftmost digit in the integer. lSide is set to the *
//    integer to the left of the operator                    *
//************************************************************

void lSideFind();

//************************************************************
// description: finds the integer to the right of an         *
//    operator in a string                                   *
// return: void                                              *
// precondition: an int i exists                             *
// postcondition: i is unchanged. newIndex is set to the     *
//    index of the rightmost digit in the integer. rSide     *
//    is set to the integer to the right of the operator     *
//************************************************************

void rSideFine();

//************************************************************
// description: divides the integer to the left of the       *
//    operator by the integer to the right of the operator   *
// return: void                                              *
// precondition: values of lSide and rSide exist             *
// postcondition: i is unchanged. Answer is set to lSide     *
//    divided by rSide                                       *
//************************************************************

void evaluateDivision();


//************************************************************
// description: multiplies the integer to the left of the    *
//    operator by the integer to the right of the operator   *
// return: void                                              *
// precondition: values of lSide and rSide exist             *
// postcondition: i is unchanged. Answer is set to lSide     *
//    multiplied by rSide                                    *
//************************************************************

void evaluateMultiplication();

//************************************************************
// description: adds the integer to the left of the          *
//    operator with the integer to the right of the operator *
// return: void                                              *
// precondition: values of lSide and rSide exist             *
// postcondition: i is unchanged. Answer is set to lSide     *
//    added to rSide                                         *
//************************************************************

void evaluateAddition();

//************************************************************
// description: subtracts the integer to the left of the     *
//    operator by the integer to the right of the operator   *
// return: void                                              *
// precondition: values of lSide and rSide exist             *
// postcondition: i is unchanged. Answer is set to lSide     *
//    minus rSide                                            *
//************************************************************

void evaluateSubtraction();

//************************************************************
// description: finds the index where a * or / first occurs  *
//    if they do not exist it finds the index where + or -   *
//    if neither exist, i is set to evaluate.size()          *
// return: void                                              *
// precondition: a string evaluate exists                    *
// postcondition: evaluate is unchanged. i is set to the     *
//    correct index                                          *
//************************************************************

void checkForOperator();



#endif // EQUATIONBUILDER_H_INCLUDED
