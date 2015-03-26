//--------------------------------------------------------------------
//
//  Laboratory 6 (Programming Exercise 3)               delimiters.cpp
//
//  Jerry Groom
//  3/3/2015
//--------------------------------------------------------------------

#include <iostream>

#if LAB6_TEST1
#   include "StackLinked.cpp"
#else
#   include "StackArray.cpp"
#endif




//--------------------------------------------------------------------

bool delimitersOk ( const string &expression );




//--------------------------------------------------------------------

int main()
{
    string inputLine;            // Input line
    char   ch;                   // Holding pen for input chars

    cout << "This program checks for properly matched delimiters."
         << endl;

    while( cin )
    {
        cout << "Enter delimited expression (<EOF> to quit) : "
             << endl;

        // Read in one line
        inputLine = "";
        cin.get(ch);
        while( cin && ch != '\n' )
        {
            inputLine = inputLine + ch;
            cin.get(ch);
        }

        if( ! cin )              // Reached EOF: stop processing
            break;

        if ( delimitersOk (inputLine) )
            cout << "Valid" << endl;
        else
            cout << "Invalid" << endl;
    }

    return 0;
}




//--------------------------------------------------------------------
// delimitersOk: the function that students must implement for
//    Programming Exercise 3.
// Note: we used the term "braces" to describe '[' and ']'. It would
//    have been better to use the term "brackets". The program can be
//    easily modified to process any set of matching delimiters.
//--------------------------------------------------------------------

bool delimitersOk ( const string &expression )
{
#if LAB6_TEST1
    StackLinked<char> openDelims(20);
#else
    StackArray<char> openDelims(20);
#endif

    for ( int i=0 ; i < expression.length() ; i++ )
    {
        switch( expression[i] )
        {
            case '(':
            case '[':
                if ( openDelims.isFull() )
                {
                    cerr << "Stack is full. Cannot evaluate." << endl;
                    return false;
                }
                else
                    // ADD YOUR CODE HERE (only 1 line required)
                    openDelims.push(expression[i]) ;

                break;

            case ')':
            case ']':
                // Should have had matching delimiter on stack => error
                if ( openDelims.isEmpty() )
                    return false;
                else
                // Remove match from stack and check if it is valid
                {
                    // ADD YOUR CODE HERE (uncomment and complete the following line)
                    char delim = openDelims.pop();
                    if(( delim == '(' && expression[i] != ')' ) ||
                       ( delim == '[' && expression[i] != ']' ))
                    return false;
                }
                break;

            default:
                // Nothing -- only pay attention to parenthesis + braces
                break;
        }
    }

    if ( ! openDelims.isEmpty() )   // Nothing should be left on stack
        return false;
    else                            // No problems detected. Valid delimiters.
        return true;
}

/*
----------------------------------------------------------------------------------------

2.	Does it matter which class (StackArray or StackLinked) you use to implement
    this program?
    Add your answer to this question as a comment near the delimiters.cpp file.


    No it does not matter which one you use in the grand scheme of things. With this
    small program we are running there is no reason to worry about sizes being an issue
    with array based lists. Both classes end up with the same results, they simply
    store the information in a different method.

----------------------------------------------------------------------------------------
*/



