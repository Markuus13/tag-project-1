#include <bits/stdc++.h>
#include "Vertex.h"
#include "Graph.h"

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

Graph createGraphFromFile() {
    Graph graph;
    ifstream myfile;
    myfile.open("amigos.txt");
    vector<vector<string>> friends_cache;

    if (myfile.is_open()) {
        // Vertices with name and registration created and added to the graph
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

        // Adjacency Vertices created and added to vertices of graph
        int i = 0;
        vector<Vertex> graphVertices = graph.getVertices();
        for(Vertex vertex: graphVertices) {
          vector<string> currentFriend = friends_cache[i];

          for (string friendRegistration: currentFriend) {
              Vertex friendVertex = graph.findByRegistration(friendRegistration);
              vertex.addAdjacencyVertex(friendVertex);
          }

          cout << "Nome: " << vertex.getName() << "|";
          cout << "Matrícula: " << vertex.getRegistration() << "|";
          cout << "Amigos: ";
          i++;

          vector<Vertex> oi =  vertex.getAdjVertices();
          for(Vertex k: oi) {
            cout << k.getRegistration() << " ";
          }
          cout << endl;
        }

        myfile.close();
    } else {
        cout << "Unable to open file.";
    }
    return graph;
}

int main() {
    Graph studentsGraph = createGraphFromFile();
    studentsGraph.formatedPrint();

    return 0;
}
