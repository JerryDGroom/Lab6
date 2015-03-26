/*
*******************************************************************

LAB 6 Group
StackLinked
Jerry Groom & Christian Uwimana
3/5/15

*******************************************************************
*/
#ifndef STACKARRAY_H
#define STACKARRAY_H

#include <stdexcept>
#include <iostream>

using namespace std;

#include "Stack.h"

// ADD YOUR CODE HERE (uncomment and complete the 2nd line below)
template <typename DataType>
class StackLinked : public Stack<DataType> {
public:

StackLinked(int maxNumber = Stack<DataType>::MAX_STACK_SIZE);
StackLinked(const StackLinked& other);
StackLinked& operator=(const StackLinked& other);
~StackLinked();

void push(const DataType& newDataItem) throw (logic_error);
DataType pop() throw (logic_error);

void clear();

bool isEmpty() const;
bool isFull() const;




void showStructure() const;

private:

class StackNode
{
public:
    StackNode(const DataType& nodeData, StackNode* nextPtr);

    DataType dataItem;
    StackNode* next;
};

StackNode* top;
};

#endif		//#ifndef STACKARRAY_H

