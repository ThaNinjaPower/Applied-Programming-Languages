#ifndef PROJECT3_HXX
#define PROJECT3_HXX

class HeadNode {
private:
	class Node {
		public:
		int value;
		Node * next;
		
		Node() {
			int value = 0;
			Node * next = NULL;
		}
	};
	
	Node * headNode;
	Node * currentNode;
	Node * temporaryNode;

public:
	HeadNode();
	
	void insertNode(int insVal);
	void insertTenNodes(int val1, int val2, int val3, int val4, int val5, int val6, int val7, int val8, int val9, int val10);
	void deleteNode(int delVal);
	void traverse();
	void reverseTraverse();
};
#endif