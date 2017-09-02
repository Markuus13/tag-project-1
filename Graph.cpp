#include "Vertex.h"
#include "Graph.h"

using namespace std;

vector<Vertex> Graph::getVertices() {
    return this->vertices;
}

void Graph::addVertex(Vertex vertex) {
    this->vertices.push_back(vertex);
}

Vertex Graph::findByRegistration(string registration) {
    for (Vertex vertex: this->vertices) {
        if(vertex.getRegistration() == registration) {
            return vertex;
        }
    }
    return Vertex();
}

void Graph::formatedPrint() {
    for (Vertex vertex: this->vertices) {
      cout << "Nome: " << vertex.getName() << "|";
      cout << "Matrícula: " << vertex.getRegistration() << "|";
      cout << "Amigos: ";

      vector<Vertex> foo = vertex.getAdjVertices();

      for (Vertex friend_vertex : foo) {
        cout << friend_vertex.getName() << " ";
      }
      cout << endl;
    }
}
