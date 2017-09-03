#include <iostream>
#include "Vertex.h"

Vertex::Vertex() {}
Vertex::Vertex(std::string registration, std::string name) {
    this->registration = registration;
    this->name = name;
}

std::string Vertex::getRegistration() {
    return this->registration;
}

void Vertex::setRegistration(int registration) {
    this->registration = registration;
}

std::string Vertex::getName() {
    return this->name;
}

void Vertex::setName(std::string name) {
    this->name = name;
}

std::vector<Vertex> Vertex::getAdjVertices() {
    return this->adjVertices;
}

void Vertex::addAdjacencyVertex(Vertex vertex) {
    this->adjVertices.push_back(vertex);
}

int Vertex::getDegree() const {
    return this->adjVertices.size();
}
