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

    void printEdges(listNode * head) {
        listNode * current = head;
        while(current != NULL) {
            cout << " -> " << current -> dest;
            current = current -> next;
        }
        cout << endl;
    }

    void printGraph() {
        vertexNode * current = head;
        while(current != NULL) {
            cout << "V: " << current -> vertex;
            printEdges(current -> listHead);
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

    vertexNode * findVertex(int v) {
        vertexNode * current = head;

        if(current == NULL) return NULL;

        while(current -> vertex != v) {
            if(current -> next == NULL) {
                return NULL;
            } else {
                current = current -> next;
            }
        }
        return current;
    }

    listNode * newListNode(int vertex) {
        listNode * newNode = new listNode;
        newNode -> dest = vertex;
        newNode -> next = NULL;
        return newNode;
    }

    void addNewEdge(int startV, int endV) {
        listNode * newNode = newListNode(endV);
        vertexNode * originVertex = findVertex(startV);
        newNode -> next = originVertex -> listHead;
        originVertex -> listHead = newNode;

        newNode = newListNode(startV);
        originVertex = findVertex(endV);
        newNode -> next = originVertex -> listHead;
        originVertex -> listHead = newNode;
    }

    int countListNodes(listNode * head) {
        listNode * current = head;
        int nodes = 0;
        while(current != NULL) {
            nodes++;
            current = current -> next;
        }
        return nodes;
    }
};

int main(int argc, char const *argv[]) {

    Graph G;
    G.addNewVertex(1);
    G.addNewVertex(2);
    G.addNewVertex(3);
    G.addNewVertex(4);
    G.addNewVertex(5);
    G.addNewEdge(1, 2);
    G.addNewEdge(1, 3);
    G.addNewEdge(2, 4);
    G.addNewEdge(3, 4);
    G.addNewEdge(4, 5);

    vertexNode * v = G.findVertex(3);
    int total = G.countListNodes(v -> listHead);
    cout << total << endl;
    return 0;
}
