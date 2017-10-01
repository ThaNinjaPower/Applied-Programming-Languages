#include <iostream>
#include "project3.hxx"

using namespace std;

HeadNode::HeadNode() {
	headNode = NULL;
	currentNode = NULL;
	temporaryNode = NULL;
}

void HeadNode::insertNode(int insVal) {
	Node * insNode = new Node;
	insNode->next = NULL;
	insNode->value = insVal;
	
	// If head node points to another node, move currentNode to headNode
	if (headNode != NULL) {
		currentNode = headNode;
		
		// Check if at the end of the list
		while (currentNode->next != NULL) {
			currentNode = currentNode->next;
		}
		
		currentNode->next = insNode;
	}
	
	// Otherwise, currentNode is the headNode
	else {
		headNode = insNode;
	}
	
	cout << "Node " + to_string(insVal) + " is inserted." << endl;
}

void HeadNode::insertTenNodes(int val1, int val2, int val3, int val4, int val5, int val6, int val7, int val8, int val9, int val10) {
	int val[10] = {val1, val2, val3, val4, val5, val6, val7, val8, val9, val10};
	
	for (int i = 0; i < 10; i++) {
		insertNode(val[i]);
	}
}

void HeadNode::deleteNode(int delVal) {
	// Point soon to be deleted node to null
	Node * delNode = NULL;
	temporaryNode = headNode;
	currentNode = headNode;
	
	// While traversing the list and currentNode value is not the deleted node value
	while (currentNode != NULL && currentNode->value != delVal) {
		temporaryNode = currentNode;
		// Step to the next node
		currentNode = currentNode->next;
	}
	
	// If the currentNode reaches the end without finding the value, print the following
	if (currentNode == NULL) {
		cout << "Node not found in the list." << endl << endl;
	}
	
	// If the currentNode finds the deleted value
	else {
		// DeleteNode is the current node
		delNode = currentNode;
		
		// CurrentNode bypasses 
		currentNode = currentNode->next;
		temporaryNode->next = currentNode;
		
		// If deleteNode is the headNode
		if (delNode == headNode) {
			headNode = headNode->next;
			temporaryNode = NULL;
		}
		cout << "Node " << to_string(delVal) << " is deleted." << endl;
	}
	
	delete delNode;
}

void HeadNode::traverse() {
	currentNode = headNode;
	cout << "List: ";
	
	// While traversing the list, print the node's value
	while (currentNode != NULL) {
		cout <<  to_string(currentNode->value) + " ";
		currentNode = currentNode->next;
	}
	
	cout << endl;
}

void HeadNode::reverseTraverse() {
	Node * previousNode = NULL;
	currentNode = headNode;
	temporaryNode = NULL;
	
	while (currentNode != NULL) {
		// Temporary node points to the node after current
		temporaryNode = currentNode->next;
		// Node after current node will be the previous node
		currentNode->next = previousNode;
		// The previous node becomes the current node
		previousNode = currentNode;
		// The current node becomes the temporary node
		currentNode = temporaryNode;
	}
	headNode = previousNode;
	cout << "List is reversed." << endl;
}

int main() {
	HeadNode myNode;
	
	// Demonstrate addition of ten nodes
	myNode.insertTenNodes(2,6,8,1,7,10,9,3,4,5);
	// Demonstrate traversion of the list
	myNode.traverse();
	
	// Demonstrate deletion of one node
	myNode.deleteNode(8);
	myNode.traverse();
	
	// Demonstrate reversal of list
	myNode.reverseTraverse();
	myNode.traverse();
	
	// Demonstrate addition of one node
	myNode.insertNode(8);
	myNode.traverse();
	
	return 0;
};