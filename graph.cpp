#include<iostream>

using namespace std;
class EdgeNode{
    public:
    int edgeNum;
    int weight;
    EdgeNode* next;
    EdgeNode(int edgeNum, int weight) {
        this->edgeNum = edgeNum;
        this->weight = weight;
        this->next = nullptr;
    }
};

class Graph{
    EdgeNode*arr[5];
    public:
    Graph(){
        for(int i=0;i<5;i++){
            arr[i]=nullptr;
            }
            }
    void addEdge(char start, char end, int weight){
        int edgeNumberStart=start-'A';
        int edgeNumberEnd=end-'A';
        if(edgeNumberEnd>=5||edgeNumberEnd>=5){
            cout<<"Error: Edge number out of range"<<endl;
            return;
        }
        EdgeNode* newEdge=new EdgeNode(edgeNumberEnd, weight);
        if(arr[edgeNumberStart]==nullptr){
            arr[edgeNumberStart]=newEdge;
            }
            else{
                EdgeNode* current=arr[edgeNumberStart];
                while(current->next!=nullptr){
                    current=current->next;
                }
                current->next=newEdge;
            }
    }
    void displayGraph(){
        for(int i=0;i<5;i++){
            EdgeNode* current=arr[i];
            if(current!=nullptr){
            while(current!=nullptr){
                cout<<char(i+'A')<<"->"<<char(current->edgeNum+'A')<<"("<<current->weight<<")"<<endl;
                current=current->next;
            }
            }
            else{
                cout<<char(i+'A')<<"->"<<"Empty"<<endl;
            }
        }
    }

};


int main(){
    Graph g;
    g.addEdge('A','B',3);
    g.addEdge('A','C',2);
    g.addEdge('B','C',2);
    g.addEdge('B','D',1);
    g.addEdge('A','D',5);
    g.displayGraph();
    
}