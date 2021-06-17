/*
  Code Written By Mahmoud Abdelmoneum On 6/16/2021
  Code Written To Be A Graph Creator Program That Takes Vertex and Edge Inputs To Make a weighted Graph
  Program can also print out adjacency table for the graph, as well as remove Vertices and Edges
  Program was initially intended to have a portion that utilizes Djikistra's algorithm to find the shortest point between two vertices,
  But after multiple failures, and some exhaustion as a result of finals, I gave up on these efforts
  What caused me to be so late with this project, however, were some issues with adding weights and deleting weights
  I ended up resolving these issues using some additional learning and understanding from:
  geeksforgeeks.org/add-remove-edge-in-adjacency-list-representation-of-a-graph/
  This was for adjacency lists, but it helped me better understand how to deal with the edges!
 */

#include <iostream>
#include <cstring>
#include <vector>
#include <iterator>
#include <math.h>
#include "Node.h"

using namespace std;

//function declarations
void getInput(char* in);
void addVertex(vector<Node*> &nodeList, char* in);
void addEdge(vector<Node*> &nodeList, char* in);
void removeVertex(vector<Node*> &nodeList, char* in);
void removeEdge(vector<Node*> &nodeList, char* in);
void print(vector<Node*> &nodeList);
void removeList(Node* &head);
void removeNode(char* in, Node* &head);
int nodeLength(Node* head);

int main(){
    //Holds input found from getInput() function --> I don't use this in main, but it is an easier method than what I use in main for use in later functions 
    char inArray[999];
    char* in = &inArray[0];
    //Holds list of vertices
    vector<Node*> nodeList;
    bool isUsing = true; //while user doesn't want to quit


    //simple while loop to used below for quit function
    while(isUsing == true){
        
	char input[100];

	cout << "Enter ADDV to add a vertex, ADDE to add an edge, DELETEV to delete a vertex, REMOVEEDGE to delete an edge, PRINT to print an adjacency table for the graph, and QUIT to exit" << endl;

	//store input
	cin.getline(input, sizeof(input));
	for(int i = 0; i<sizeof(input); i++) {
	    input[i] = toupper(input[i]);
	  }
	
        //adding a vertex
        if(strcmp(input, "ADDV") == 0){
            addVertex(nodeList, input);
        }
        //adding an edge
        else if(strcmp(input, "ADDE") == 0){
            addEdge(nodeList, input);
        }
        //deleting a vertex
        else if(strcmp(input, "DELETEV") == 0){
            removeVertex(nodeList, input);
        }
        //remove an edge
        else if(strcmp(input, "REMOVEEDGE") == 0){
            removeEdge(nodeList, input);
        }
        //print adjacency tree
        else if(strcmp(input, "PRINT") == 0){
            print(nodeList);
        }
	      
        //quit the program
        else if(strcmp(input, "QUIT") == 0){
	  isUsing = false;
        }

    }
    return 0;
}

//Get input takes user input and stores it into char* in, with some minimal input checking
void getInput(char* in){
    while(true){
        cin.getline(in,999);
        if(strcmp(in, "") != 0){
            break;
        }
        cout << "No input detected. Please enter something..." << endl;
    }
}


//Pushes back a new node into the list of vertices
void addVertex(vector<Node*> &nodeList, char* in){
    cout << "Please enter the value for the vertex you would like to add: ";
    getInput(in);
    //vertex pushed into LL
    nodeList.push_back(new Node(NULL, in, -1));
    cout << "\"" << in << "\" has successfully been added to the graph!" << endl;
}

//Prints adjacency list
void print(vector<Node*>& nodeList){
    vector<Node*>::iterator it;
    if(it == nodeList.end()){ //base case --> iterator at end, graph is empty
        cout << "The graph is empty!" << endl;
    }
    for(it = nodeList.begin(); it != nodeList.end(); it++){ //go thru vertices and print each out
        Node* curr = (*it)->getNext();
        if(curr == NULL){
            cout << "For node \"" << (*it)->getLabel() << "\", there are no adjacent nodes." << endl;
        }else{
            //just traverse LL and print out each vertex
            cout << "For node \"" << (*it)->getLabel() << "\", the adjacent nodes are: ";
            while(curr!=NULL){
                cout << curr->getLabel() << " ";
                curr = curr->getNext();
            }
            cout << endl;
        }
    }
}

// given two input vertices, add an adjacent edge in between
void addEdge(vector<Node*> &nodeList, char* in){
    char firstNodeLabel[999];
    char secondNodeLabel[999];
    int weight = 0;
    //Asks user for two labels
    cout << "Please enter the value for the first vertex you would like to add an edge to: ";
    getInput(in);
    strcpy(firstNodeLabel, in);
    cout << "Please enter the value for the second vertex: ";
    getInput(in);
    strcpy(secondNodeLabel, in);
    cout << "Please enter the weight that you would like the edge to have: ";
    while(true){
        getInput(in);
        int inLen = strlen(in);
        bool alldig = true;
        //Check input
        for(int a = 0; a < inLen; ++a){
            if(!isdigit(in[a])){
                alldig = false;
                break;
            }
        }
        if(alldig){
            break;
        }
        cout << "Please enter an integer weight" << endl;
    }
    weight = atoi(in);
    //check nodes
    vector<Node*>::iterator it;
    vector<Node*>::iterator firstNodeSpot; //store vertex 1 location
    bool firstFound = false;
    bool secondFound = false;
    for(it = nodeList.begin(); it != nodeList.end(); ++it){ //continue if first vertex exists
            if(strcmp((*it)->getLabel(),firstNodeLabel) == 0){
                firstFound = true;
            firstNodeSpot = it;
        }else if(strcmp((*it)->getLabel(),secondNodeLabel) == 0){
            secondFound = true;
        }
    }
    //all da stuff for if user puts in something wrong
    if(firstFound == false){
        if(secondFound == false){
            cout << "The node first and second \"" << firstNodeLabel << "\" and \"" << secondNodeLabel << "\" were not found...therefore an edge was not added." << endl;
            return;
        }
        cout << "The first node \"" << firstNodeLabel << "\" was not found...therefore an edge was not added." << endl;
    }else if(secondFound == false){
        cout << "The second node \"" << secondNodeLabel << "\" was not found... therefore and edge was not added." << endl;
    }else{
        Node* curr = (*firstNodeSpot);
        while(true){
	  if(strcmp(curr->getLabel(), secondNodeLabel) == 0){ //already existing node 
                cout << "The edge between \"" << firstNodeLabel << "\" and \"" << secondNodeLabel << "\" already exists! Therefore, an edge was not added." << endl;
                return;
            }
            if(curr->getNext()!=NULL){
                curr = curr->getNext();
            }else{
                break;
            }
        }
        curr->setNext(new Node(NULL, secondNodeLabel, weight));
        cout << "An edge with weight \"" << weight << "\" was successfully added between \"" << firstNodeLabel << "\" and \"" << secondNodeLabel << "\"!" << endl;
        return;
    }
}

//delete vertex given a vertex input
void removeVertex(vector<Node*> &nodeList, char* in){
    //First ask user for vertex to be deleted.
    cout << "Please enter a label for the vertex to be deleted." << endl;
    getInput(in);
    int deletedNodes = 0; //used to tell user later if nodes were deleted or not
    int deletedConnections = 0;
    //go through the vertices
    vector<Node*>::iterator it;
    for(it = nodeList.begin(); it!=nodeList.end(); ){
      if(strcmp((*it)->getLabel(), in) == 0){ //vertex found
	removeList((*it)); //delete LL
	it = nodeList.erase(it);
	deletedNodes++;
      }else{ //delete connects the old vertice that was deleted had
	int befLength = nodeLength((*it));
	removeNode(in, (*it));
	deletedConnections += (befLength - nodeLength((*it)));
	++it;
      }
    }
    //telling user if nodes are or aren't deleted is good for debugging. Adjacency table can be used too, but this is more immediate
    if(deletedNodes == 0){
        cout << "The vertex with the given label \"" << in << "\" was not found, so there were no changes to the graph." << endl;
    }else{
        cout << "The vertex \"" << in << "\" was deleted along with " << deletedConnections << " connections!" << endl;
    }
}


//Given two adjacent nodes with an edge in between, deletes edge
void removeEdge(vector<Node*> &nodeList, char* in){
    char firstNodeLabel[999];
    char secondNodeLabel[999];
    //Asks for vertices between which edge should be deleted
    cout << "Please enter the value for the first vertex: ";
    getInput(in);
    strcpy(firstNodeLabel, in);
    cout << "Please enter the value for the second vertex: ";
    getInput(in);
    strcpy(secondNodeLabel, in);
    vector<Node*>::iterator it;
    for(it = nodeList.begin(); it!=nodeList.end(); ++it){ //iterate through vertices
      if(strcmp((*it)->getLabel(), firstNodeLabel) == 0){ //vertex fiybd
            int befLength = nodeLength((*it));
            removeNode(secondNodeLabel, (*it));
            if(befLength == nodeLength((*it))){
                cout << "The second node \"" << secondNodeLabel << "\" does not exist, and as a result; no edge was deleted" << endl;
            }else{
                cout << "The edge between \"" << firstNodeLabel << "\" and \"" << secondNodeLabel << "\" was successfully deleted!" << endl;
            }
            return;
        }
    }
    cout << "The first node \"" << firstNodeLabel << "\" does not exist! Edge cannot be deletes :(" << endl;
}

//Deletes whole LL: Used to remove edges/vertices
void removeList(Node* &head){
    while(head!=NULL){
      //basic LL traversal and deletion
      Node* tempChild = head->getNext();
      head->setNext(NULL);
      delete head;
      head = tempChild;
    }
}

//removes particular node in LL, used more for removing vertices
void removeNode(char* in, Node* &head){
    Node** past = &head;
    Node** current = &head;
    //traversal and deletion of individual node
    while((*current)!=NULL){ 
      if(strcmp((*current)->getLabel(), in) == 0){ //if match is found, standard deletion procedure for a LL node
            Node* tempChild = (*current)->getNext();
            (*current)->setNext(NULL);
            delete (*current);
            (*current) = NULL;
            (*past)->setNext(tempChild);
        } else{
            past = current;
            Node* temp = (*current)->getNext();
            current = &temp;
        }
    }
}

//Gives total LL length using counter variable and traversal
int nodeLength(Node* head){
    int length = 0;
    while(head!=NULL){
        ++length;
        head=head->getNext();
    }
    return length;
}


/* 
At 12:53 a.m on June 17th 2021, I came to the conclusion that I would no longer try use Djikstra's algorithm to make a function finding the shortest path between two vertices
I tried, but, I have given up :,,(
This is my last project of DS so hopefully everything else is correct though :)
*/
