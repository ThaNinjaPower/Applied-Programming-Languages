#ifndef PROJECT4_HXX
#define PROJECT4_HXX

class Stack {
private:
	class Element {
	public:
		int value;
		Element * next;
		
		Element() {
			int value = 0;
			Element * next = NULL;
		}
	};
	
	Element * headElement;
	Element * currentElement;
	Element * temporaryElement;

public:
	Stack();
	
	void pushElement(int insVal);
	void pushTenElements(int val1, int val2, int val3, int val4, int val5, int val6, int val7, int val8, int val9, int val10);
	void popElement();
	void traverseStack();
	void reverseStack();
	void reverseStackWithPrint();
};

#endif