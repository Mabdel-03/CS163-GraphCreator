#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class Node{
	public:

		Node(char*, int, Node*);
		char* getVal();
		int getWeight();
		Node* getSecond();
		void addEdge(int, Node*);
		~Node();
  
	private:
		int weight;
		vector<Node*> edges;
		Node* second;
		char* val;	
};
