#include "Vertex.h"
#include "Graph.h"
#include <fstream>
#include <sstream>

using namespace std;

vector<string> split(string str, char delimiter) {
    vector<string> internal;
    stringstream ss(str);
    string token;

    while(getline(ss, token, delimiter)) {
        internal.push_back(token);
    }
    return internal;
}

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
    myfile.close();
}

void Graph::createAdjVertices(string filename) {
    ifstream myfile;
    myfile.open(filename);

    if (myfile.is_open()) {
        string name;
        string registration;
        string friendRegistrations;

        while ( getline(myfile, name, '|')
                  && getline(myfile, registration, '|')
                  && getline(myfile, friendRegistrations) ) {

                vector<string> vectorFriendRegs = split(friendRegistrations, ',');

                for(string friendRegistration: vectorFriendRegs) {
                    Vertex oneVertex = this->findByRegistration(registration);
                    Vertex friendVertex = this->findByRegistration(friendRegistration);
                    oneVertex.addAdjacencyVertex(friendVertex);
                }
        }
    } else {
        cout << "Unable to open file.";
    }
    myfile.close();
}
