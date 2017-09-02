#include <iostream>
#include "Vertex.h"

using namespace std;

Vertex::Vertex() {}
Vertex::Vertex(string registration, string name) {
    this->registration = registration;
    this->name = name;
}

string Vertex::getRegistration() {
    return this->registration;
}

void Vertex::setRegistration(int registration) {
    this->registration = registration;
}

string Vertex::getName() {
    return this->name;
}

void Vertex::setName(string name) {
    this->name = name;
}

vector<Vertex> Vertex::getAdjVertices() {
    return this->adjVertices;
}

void Vertex::addAdjacencyVertex(Vertex vertex) {
    this->adjVertices.push_back(vertex);
}
