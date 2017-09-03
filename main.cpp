#include "Vertex.h"
#include "Graph.h"

using namespace std;


int main() {
    Graph studentsGraph;

    studentsGraph.createVertices("amigos_tag20172.txt");
    studentsGraph.createAdjVertices("amigos_tag20172.txt");
    studentsGraph.formatedPrint();

    return 0;
}
