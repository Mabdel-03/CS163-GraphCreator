#include <iostream>
#include <vector>
#include <cstring>
#include "Node.h"

using namespace std;

Node::Node(char* newVal, int newWeight, Node* newSecond) {
	val = new char[sizeof(newVal)];
	strcpy(val, newVal);
	weight = newWeight;
}

int Node:: getWeight(){
	return weight;
}

Node* Node:: getSecond(){
	return second;
}

char* Node:: getVal(){
	return val;
}

