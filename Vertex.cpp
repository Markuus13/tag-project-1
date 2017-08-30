#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Vertex {
  private:
    string registration;
    string name;
    vector<Vertex> adjacencyVertices;

  public:
    Vertex(string registration, string name) {
      this->registration = registration;
      this->name = name;
    }

    string getRegistration() {
      return this->registration;
    }

    void setRegistration(int registration) {
      this->registration = registration;
    }

    string getName() {
      return this->name;
    }

    void setName(string name) {
      this->name = name;
    }

    vector<Vertex> getAdjacencyVertices() {
      return this->adjacencyVertices;
    }

    void addAdjacencyVertex(Vertex vertex) {
      this->adjacencyVertices.push_back(vertex);
    }
};

class Graph {
  private:
    vector<Vertex> vertices;
  public:
    vector<Vertex> getVertices() {
      return this->vertices;
    }

    void addVertex(Vertex vertex) {
      this->vertices.push_back(vertex);
    }

    void formated_print() {
      for (Vertex vertex: this->vertices) {
        cout << "Nome: " << vertex.getName() << " -> ";
        cout << "Matrícula: " << vertex.getRegistration() << endl;
      }
    }
};

Graph create_graph_from_file() {
  Graph graph;
  ifstream myfile;
  myfile.open("teste.txt");

  if (myfile.is_open()) {
    string name;
    string registration;
    string friend_registrations;

    while ( getline(myfile, name, '|')
              && getline(myfile, registration, '|')
              && getline(myfile, friend_registrations) ) {
        Vertex student(registration, name);
        graph.addVertex(student);
    }

    myfile.close();
  } else {
    cout << "Unable to open file.";
  }
  return graph;
}

int main() {
  Graph studentsGraph = create_graph_from_file();
  studentsGraph.formated_print();
}
