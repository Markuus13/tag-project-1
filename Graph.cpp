#include <iostream>
using namespace std;

struct listNode {
    int dest;
    listNode * next;
};
typedef struct listNode listNode;

struct vertexNode {
    int vertex;
    vertexNode * next;
    listNode * listHead;
};
typedef struct vertexNode vertexNode;

class Graph {
private:
    vertexNode * head;

public:
    Graph() {
        head = NULL;
    }

    void printGraph() {
        vertexNode * current = head;
        while(current != NULL) {
            cout << current -> vertex << endl;
            current = current -> next;
        }
    }

    vertexNode * newVertexNode(int value) {
        vertexNode * newNode = new vertexNode;
        newNode -> vertex = value;
        newNode -> next = NULL;
        newNode -> listHead = NULL;
        return newNode;
    }

    void addNewVertex(int value) {
        vertexNode * newNode = newVertexNode(value);
        newNode -> next = head;
        head = newNode;
    }

    // vertexNode * findVertex(int v) {
    //     vertexNode * currentNode = graphHead -> next;
    //
    //     if(currentNode == NULL) return NULL;
    //
    //     while(currentNode -> vertex != v) {
    //         if(currentNode -> next == NULL){
    //             return NULL;
    //         } else {
    //             currentNode = currentNode -> next;
    //         }
    //     }
    //     return currentNode;
    // }
    //
    // listNode * newListNode(int endV) {
    //     listNode * newNode = new listNode;
    //     newNode -> endVertex = endV;
    //     newNode -> next = NULL;
    //     return newNode;
    // }
    //
    // void addNewEdge(int startV, int endV) {
    //     listNode * newNode = newListNode(endV);
    //     vertexNode * originVertex = findVertex(startV);
    //     newNode -> next = originVertex -> listHead;
    //     originVertex -> listHead = newNode;
    //
    //     newNode = newListNode(startV);
    //     originVertex = findVertex(endV);
    //     newNode -> next = originVertex -> listHead;
    //     originVertex -> listHead = newNode;
    // }
};

int main(int argc, char const *argv[]) {

    Graph G;
    G.addNewVertex(1);
    G.addNewVertex(2);
    G.printGraph();
    return 0;
}
