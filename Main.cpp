/*
 * Code Written By Mahmoud Abdelmoneum on 6/13/2021
 * Code Written To Be A Grapher Application That Adjacency Tables
 * This project is NOT complete yet (it has just been started and is not functional in any capacity yet) 
 */
#include <iostream>
#include <vector>
#include <cstring>
#include "Node.h"
using namespace std;

//add edge
//delete vertex
//print graph

int main(){

	while(true){
		char input[100];
		cout<<"Input VERTEX to add a vertex to the graph, EDGE to add an edge to the graph, PRINT to print to print the graph, DELETE to delete a vertex from the graph, and QUIT to exit."<<endl;
		cin.getline(input, sizeof(input));
		for(int j = 0; j<sizeof(input); j++){
			input[j] = toupper(input[j]);
		}
		if(strcmp(input, "Vertex") == 0){
		   char* val = new char();
		   cout<<"Enter the value of the vertex that you would like to add"<<endl;
		   cin.getline(val, sizeof(val));
		}
		else if(strcmp(input, "EDGE") == 0){
		   char* first = new char();
		   char* second = new char();
		   cout<<"What is the value of the first vertex?"<<endl;
		   cin.getline(first, sizeof(first));
		   cout<<"What is the value of the second vertex?"<<endl;
		   cin.getline(second, sizeof(second));
		   int weight;
		   cout<<"What is the desired weight of this edge?"<<endl;
		   cin>>weight;
		   cin.ignore();
		   //add();
		}
		else if(strcmp(input, "PRINT") == 0){
		  //print();
		}
		else if(strcmp(input , "DELETE") == 0){
		  char* val = new char();
		  cout<<"What is the value you want to delete?"<<endl;
		  cin.getline(val, sizeof(val));
		  //remove();
		}
		else if(strcmp(input, "QUIT") == 0){
			return;
		}
	}
	return 0;
}

//add edge
//remove vertex
//print graph 
