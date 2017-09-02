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

Vertex* Graph::findByRegistration(string registration) {
    for (size_t i = 0; i < vertices.size(); i++) {
        if (vertices[i].getRegistration() == registration) {
            return &vertices[i];
        }
    }
    return new Vertex();
}

void Graph::formatedPrint() {
    for (Vertex vertex: this->vertices) {
      cout << "Nome: " << vertex.getName() << "|";
      cout << "Matrícula: " << vertex.getRegistration() << "|";
      cout << "Amigos: ";

      vector<Vertex> foo = vertex.getAdjVertices();

      for (Vertex friendVertex : foo) {
        cout << friendVertex.getName() << " ~ ";
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

                Vertex* oneVertex = this->findByRegistration(registration);
                // cout << oneVertex->getName() << endl;
                for(string friendRegistration: vectorFriendRegs) {
                    // cout << oneVertex.getName() << " -> ";
                    Vertex* friendVertex = this->findByRegistration(friendRegistration);
                    // cout << friendVertex.getName() << endl;
                    oneVertex->addAdjacencyVertex(*friendVertex);
                }
        }

    } else {
        cout << "Unable to open file.";
    }
    myfile.close();
}
