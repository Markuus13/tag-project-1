/**
*   Universidade de Brasília
*   Teoria e Aplicação de Grafos
*   2017/2
*
*   Leonardo de Almeida 150135491
*   Marcus Vinícius da Silva Borges 130032891
*/


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

    for (size_t i = P.size() - 1; i > 0 ; i--) {
        R.push_back(P[i]);
        bronKerbosch(R, verticesIntersec(P, P[i].getAdjVertices()), verticesIntersec(X, P[i].getAdjVertices()));
        X.push_back(P[i]);
        P.pop_back();
    }
    P.pop_back();
}

int main() {
    Graph studentsGraph;

    studentsGraph.createVertices("doc/amigos_tag20172.txt");
    studentsGraph.createAdjVertices("doc/amigos_tag20172.txt");
    studentsGraph.sortDesc();
    studentsGraph.printRegistrations();

    cout << "----------------------------------" << endl;

    vector<Vertex> p = studentsGraph.getVertices();
    vector<Vertex> r;
    vector<Vertex> x;

    bronKerbosch(r, p, x);

    return 0;
}
