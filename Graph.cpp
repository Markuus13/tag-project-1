#include "Vertex.h"
#include "Graph.h"
#include <fstream>

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

void Graph::createVertices(string filename) {
    ifstream myfile;
    myfile.open(filename);

    if (myfile.is_open()) {
        string name;
        string registration;
        string friend_registrations;

        while ( getline(myfile, name, '|')
                  && getline(myfile, registration, '|')
                  && getline(myfile, friend_registrations) ) {
            Vertex student(registration, name);
            this->addVertex(student);
        }
    } else {
        cout << "Unable to open file.";
    }
}
