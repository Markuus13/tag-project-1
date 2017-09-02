#include <bits/stdc++.h>
#include "Vertex.h"
#include "Graph.h"

using namespace std;

int main() {
    Graph studentsGraph;

    studentsGraph.createVertices("amigos.txt");
    studentsGraph.createAdjVertices("amigos.txt");
    studentsGraph.formatedPrint();

    return 0;
}
