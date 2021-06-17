#include <iostream>
#include <cstring>
#include "Node.h"


Node::Node(Node* newNext, char* newLabel, int newWeight){
    next = newNext;
    label = new char[strlen(newLabel)];
    strcpy(label, newLabel);
    weight = newWeight;
}

Node::~Node(){ //destructor to delete the labels (for removing vertices)
    delete[] label;
    label = NULL;
}

Node* Node::getNext(){ //getter
    return next;
}
void Node::setNext(Node* newNext){ //setter
    next = newNext;

}

char* Node::getLabel(){ //getter
    return label;
}
void Node::setLabel(char* newLabel){ //setter -> empties label from what it was before and puts in new contents
    delete[] label;
    label = new char[strlen(newLabel)];
    strcpy(label, newLabel);
}

int Node::getWeight(){ //getter
    return weight;
}
void Node::setWeight(int newWeight){ //setter! 
    weight = newWeight;
}
