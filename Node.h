class Node{
        public:
                //Constructor/destructor for my Node Class
                Node(Node* newNext, char* newLabel, int newWeight);
                ~Node();
                Node* getNext(); //getter!
                void setNext(Node* newNext); //setter
                char* getLabel(); //getter!
                void setLabel(char* newLabel); //setter
                int getWeight(); //getter!
                void setWeight(int newWeight); //setter 

        private:
                Node* next;
                char* label;
                int weight;
};

