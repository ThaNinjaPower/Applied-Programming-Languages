#include <iostream>
#include "project4.hxx"

using namespace std;

Stack::Stack() {
	headElement = NULL;
	currentElement = NULL;
	temporaryElement = NULL;
}

void Stack::pushElement(int pushVal) {
	Element * pushElement = new Element;
	pushElement->next = NULL;
	pushElement->value = pushVal;
	
	// If head element points to another element, move currentElement to headElement
	if (headElement != NULL) {
		currentElement = headElement;
		
		// Check if at the end of the list
		while (currentElement->next != NULL) {
			currentElement = currentElement->next;
		}
		
		currentElement->next = pushElement;
	}
	
	// Otherwise, insertedNode is the headElement
	else {
		headElement = pushElement;
	}
	
	cout << "Element " << pushVal << " is pushed." << endl;
}

void Stack::pushTenElements(int val1, int val2, int val3, int val4, int val5, int val6, int val7, int val8, int val9, int val10) {
	int val[10] = {val1, val2, val3, val4, val5, val6, val7, val8, val9, val10};
	
	for (int i = 0; i < 10; i++) {
		pushElement(val[i]);
	}
}

void Stack::popElement() {
	// Point soon to be deleted element to null
	Element * delElement = NULL;
	temporaryElement = headElement;
	currentElement = headElement;
	
	// If stack is empty, say that it is.
	if (headElement == NULL) {
		cout << "Stack is empty." << endl;
		delete delElement;
		return;
	}
	
	// If headElement is the only element
	if (headElement != NULL && headElement->next == NULL) {
		delElement = headElement;
		headElement = NULL;
		cout << "Element " << delElement->value << " is popped. Stack is empty." << endl;
		delete delElement;
		return;
	}
	
	// While traversing the list and currentElement value
	while (currentElement != NULL && currentElement->next != NULL) {
		temporaryElement = currentElement;
		// Step to the next element
		currentElement = currentElement->next;
	}
	
	// DeleteNode is the current element
	delElement = currentElement;
	delElement->value = currentElement->value;
	
	// CurrentNode bypasses the deletedNode
	currentElement = currentElement->next;
	temporaryElement->next = currentElement;
	
	cout << "Element " << delElement->value << " is popped." << endl;
	
	delete delElement;
}

void Stack::traverseStack() {
	
	cout << "Stack: ";
	
	// While traversing the list, print the element's value
	if (headElement != NULL) {
		reverseStack();
		for (currentElement = headElement; currentElement != NULL; currentElement = currentElement->next) {
			cout << currentElement->value << " ";
		}
		reverseStack();
	}
	
	cout << endl;

}

void Stack::reverseStack() {
	Element * previousElement = NULL;
	currentElement = headElement;
	temporaryElement = NULL;
	
	while (currentElement != NULL) {
		// Temporary element points to the element after current
		temporaryElement = currentElement->next;
		// Element after current element will be the previous element
		currentElement->next = previousElement;
		// The previous element becomes the current element
		previousElement = currentElement;
		// The current element becomes the temporary element
		currentElement = temporaryElement;
	}
	headElement = previousElement;
}

void Stack::reverseStackWithPrint() {
	reverseStack();
	cout << "Stack is reversed." << endl;
}

int main() {
	Stack myElement;
	
	// Demonstrate addition of ten nodes
	 myElement.pushTenElements(2,6,8,1,7,10,9,3,4,5);
	// Demonstrate traversion of the list
	myElement.traverseStack();
	
	for (int i = 0; i < 3; i++) {
		myElement.popElement();
		myElement.traverseStack();
	}
	
	for (int i = 0; i < 7; i++) {
		myElement.popElement();
		myElement.traverseStack();
	}
	
	return 0;
};