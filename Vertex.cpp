// ++ -std=c++11 -Wall -pedantic Vertex.cpp -o vertex-main

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

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

vector<string> split(string str, char delimiter) {
  vector<string> internal;
  stringstream ss(str); // Turn the string into a stream.
  string token;

  while(getline(ss, token, delimiter)) {
    internal.push_back(token);
  }

  return internal;
}

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
        vector<string> resultado = split(friend_registrations, ',');
        for (string s: resultado) {
          cout << s << endl;
        }
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
