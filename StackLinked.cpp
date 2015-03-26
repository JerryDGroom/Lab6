//--------------------------------------------------------------------
//
//  Laboratory 6                                       StackLinked.cpp
//
//
//
//--------------------------------------------------------------------

#ifndef STACKLINKED_CPP
#define STACKLINKED_CPP

#include <iostream>

#include "StackLinked.h"

//--------------------------------------------------------------------

template <typename DataType>
StackLinked<DataType>::StackNode::StackNode(const DataType& newDataItem,
					  StackLinked<DataType>::StackNode* nextPtr)

// Creates a stack node containing item newDataItem and next pointer
// nextPtr.
{
    dataItem = newDataItem;
    next = nextPtr;
}

//--------------------------------------------------------------------

template <typename DataType>
StackLinked<DataType>::StackLinked(int maxNumber)

// Creates an empty stack. The parameter maxNumber is provided for
// compatability with the array implementation and is ignored.
{
    // ADD YOUR CODE HERE
// Creates an empty stack.

    top = NULL;
}

//--------------------------------------------------------------------

template <typename DataType>
StackLinked<DataType>::StackLinked(const StackLinked& other)

// Copy constructor for linked stack

: top( 0 )
{
    (void) operator=(other);	// Use operator=, ignore return value
}

//--------------------------------------------------------------------

template <typename DataType>
StackLinked<DataType>& StackLinked<DataType>::operator=(const StackLinked& other)

// Overloaded assignment operator for the StackLinked class.
// Because this function returns a StackLinked object reference,
// it allows chained assignment (e.g., stack1 = stack2 = stack3).

{
    // Self-assignment protection
    if( this != &other ) return *this;

    clear();				// Clear existing nodes
    if( ! other.isEmpty() ) {
        // Copy first node
        top = new StackNode(other.top->dataItem, 0);
        StackNode *otherTemp = other.top->next;
        StackNode *thisTemp=0, *thisPrevious=top;

        // Copy rest of nodes
        while( otherTemp != 0 )
        {
            thisTemp = new StackNode(otherTemp->dataItem, 0);
            // ADD YOUR CODE HERE (uncomment and complete the following 3 lines)
            thisPrevious->next = other->top;
            thisPrevious = top;
            otherTemp = thisPrevious;
        }
    }

    return *this;
}

//--------------------------------------------------------------------

template <typename DataType>
StackLinked<DataType>::~StackLinked()

// Destructor. Frees the memory used by a stack.

{
    clear();
}

//--------------------------------------------------------------------

template <typename DataType>
void StackLinked<DataType>::push(const DataType& newDataItem) throw (logic_error)

// Inserts newDataItem onto the top of a stack.

{
    if (isFull()) {
	// Not likely with linked implementation
	throw logic_error("push() while stack full");
    }else{
        //StackNode* newStack = new StackNode;
        StackNode* newNode = new StackNode(newDataItem,top);
        newNode->dataItem = newDataItem;
        newNode->next = top;
        top = newNode;


    }
}

//--------------------------------------------------------------------

template <typename DataType>
DataType StackLinked<DataType>::pop() throw (logic_error)

// Removes the topmost item from a stack and returns it.

{
    if (isEmpty()) {
	throw logic_error("pop() while stack empty");
    }else{
        StackNode* tempTop = top->next;
        StackNode* tempNode = top;
        top = tempTop;
        return tempNode->dataItem;
        delete tempNode;
    }

    // ADD YOUR CODE HERE
}

//--------------------------------------------------------------------

template <typename DataType>
void StackLinked<DataType>::clear()

// Removes all the data items from a stack.

{
    // ADD YOUR CODE HERE
while(top != NULL){
    delete top;
    top = NULL;
}
}


//--------------------------------------------------------------------

template <typename DataType>
bool StackLinked<DataType>::isEmpty() const

// Returns true if a stack is empty. Otherwise, returns false.

{
    if(top == NULL){
       //return top == 0;
       return true;
    }else{
        return false;
    }

}

//--------------------------------------------------------------------

// ADD YOUR CODE HERE (need to implement the function you added to the .h file)
//      NOTE: the function has just one line

template <typename DataType>
bool StackLinked<DataType>::isFull() const

// Returns true if a stack is empty. Otherwise, returns false.

{
       return false;
    }







//--------------------------------------------------------------------

template <typename DataType>
void StackLinked<DataType>::showStructure() const

// Linked list implementation. Outputs the data elements in a stack.
// If the stack is empty, outputs "Empty stack". This operation is
// intended for testing and debugging purposes only.

{
    if( isEmpty() )
    {
	cout << "Empty stack" << endl;
    }
    else
    {
        cout << "Top\t";
	for (StackNode* temp = top; temp != 0; temp = temp->next) {
	    if( temp == top ) {
		cout << '[' << temp->dataItem << "]\t";
	    }
	    else {
		cout << temp->dataItem << "\t";
	    }
	}
        cout << "Bottom" << endl;
    }
}

#endif		//#ifndef STACKLINKED_CPP
