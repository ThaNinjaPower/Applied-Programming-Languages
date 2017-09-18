#include <iostream>
#include "project2.h"
using namespace std;

int main() {
	Planet earth("Earth", 6371, 9.8);
	cout << "Name: " + earth.getName() << endl;
	cout << "Radius = " + to_string(earth.getRadius()) << endl;
	cout << "Gravity = " + to_string(earth.getGravity()) << endl;
	
	cout << "\nChanges" << endl;
	
	earth.setName("Mars");
	earth.setRadius(3390);
	earth.setGravity(3.8);
	
	cout << "New Name: " + earth.getName() << endl;
	cout << "New Radius = " + to_string(earth.getRadius()) << endl;
	cout << "New Gravity = " + to_string(earth.getGravity()) << endl;
	
	return 0;
};