#include "Vertex.h"
#include "Graph.h"

int main() {
    Graph studentsGraph;

    studentsGraph.createVertices("doc/amigos_tag20172.txt");
    studentsGraph.createAdjVertices("doc/amigos_tag20172.txt");
    studentsGraph.sortDesc();
    studentsGraph.printRegistrations();

    return 0;
}
