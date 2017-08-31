// g++ -std=c++11 -Wall -pedantic Vertex.cpp -o vertex-main

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

class Vertex {
  private:
    string registration;
    string name;
    vector<Vertex> adjacencyVertices;

  public:
    Vertex() {}

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
    //   cout << vertex.getName() << endl;
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

    Vertex find_by_registration(string registration) {
      for (Vertex vertex: this->vertices) {
        if(vertex.getRegistration() == registration) {
          return vertex;
        }
      }
      return Vertex("9999999999", "LEOZIN DA MASSA");
    }

    void formated_print() {
      for (Vertex vertex: this->vertices) {
        cout << "Nome: " << vertex.getName() << "|";
        cout << "Matrícula: " << vertex.getRegistration() << "|";
        cout << "Amigos: ";
        for (Vertex friend_vertex :vertex.getAdjacencyVertices()) {
          cout << friend_vertex.getName() << " ";
        }
        cout << endl;
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

  return internal;;
}

Graph create_graph_from_file() {
    Graph graph;
    ifstream myfile;
    myfile.open("teste.txt");
    vector<vector<string>> friends_cache;

    if (myfile.is_open()) {
        string name;
        string registration;
        string friend_registrations;

        while ( getline(myfile, name, '|')
                  && getline(myfile, registration, '|')
                  && getline(myfile, friend_registrations) ) {
            Vertex student(registration, name);
            graph.addVertex(student);

            vector<string> friend_registrations_vector = split(friend_registrations, ',');
            friends_cache.push_back(friend_registrations_vector);
        }

        int i = 0;
        for (vector<string> row_friend: friends_cache) {
            for (string friend_registration: row_friend) {
                Vertex friend_vertex = graph.find_by_registration(friend_registration);
                graph.getVertices()[i].addAdjacencyVertex(friend_vertex);
            }
            i++;
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
