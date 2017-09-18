#include <iostream>
using namespace std;

class Planet {
	public:
		string name;
		int radius;
		float gravity;
		Planet() {
			name = "";
			radius = 0;
			gravity = 0;
		}
		Planet(string n, int r, float g) {
			name = n;
			radius = r;
			gravity = g;
		}
		void habitability() {
			cout << "I am a planet full of life." << endl;
		}
		string getName() {
			return name;
		}
		int getRadius() {
			return radius;
		}
		float getGravity() {
			return gravity;
		}
		
		void setName(string na) {
			name = na;
		}
		void setRadius(int rad) {
			if (rad < 0) {
				radius = 0;
			}
			else {
				radius = rad;
			}
		}
		void setGravity(float grav) {
			if (grav < 0) {
				gravity = 0;
			}
			else {
				gravity = grav;
			}
		}
};