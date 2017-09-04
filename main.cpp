#include "Vertex.h"
#include "Graph.h"

using namespace std;

vector<vector<Vertex>> maximalCliques;

vector<Vertex> verticesIntersec(vector<Vertex> first, vector<Vertex> second) {
    vector<Vertex> intersec;
    for (Vertex a: first) {
        for (Vertex b: second) {
            if (a.getRegistration() == b.getRegistration())
                intersec.push_back(a);
        }
    }
    return intersec;
}

void bronKerbosch(vector<Vertex> R, vector<Vertex> P, vector<Vertex> X) {
    if (P.empty() && X.empty()) {
        maximalCliques.push_back(R);
        return;
    }

    for (Vertex v: P) {
        R.push_back(v);
        bronKerbosch(R, verticesIntersec(P, v.getAdjVertices()), verticesIntersec(X, v.getAdjVertices()));
        // P.erase(remove(P.begin(), P.end(), v), P.end());
        X.push_back(v);
    }
}

int main() {
    Graph studentsGraph;

    studentsGraph.createVertices("doc/amigos_tag20172.txt");
    studentsGraph.createAdjVertices("doc/amigos_tag20172.txt");
    studentsGraph.sortDesc();
    studentsGraph.printRegistrations();

    cout << "----------------------------------" << endl;

    // vector<Vertex> x = studentsGraph.getVertices();
    // vector<Vertex> v;
    // vector<Vertex> z;
    //
    // bronKerbosch(&v, &x, &z);

    return 0;
}
