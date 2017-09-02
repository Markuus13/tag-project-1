#include <bits/stdc++.h>
using namespace std;

class Vertex {
private:
    string registration;
    string name;
    vector<Vertex> adjVertices;

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
     vector<Vertex> getAdjVertices() {
         return this->adjVertices;
     }
     void addAdjacencyVertex(Vertex vertex) {
         this->adjVertices.push_back(vertex);
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
    Vertex findByRegistration(string registration) {
        for (Vertex vertex: this->vertices) {
            if(vertex.getRegistration() == registration) {
                return vertex;
            }
        }
        return Vertex("9999999999", "LEOZIN DA MASSA");
    }

    void formatedPrint() {
        cout << "endereco bugado " << &this->vertices << endl;
        for (Vertex vertex: this->vertices) {
          cout << "Nome: " << vertex.getName() << "|";
          cout << "Matrícula: " << vertex.getRegistration() << "|";
          cout << "Amigos: ";
          for (Vertex friend_vertex :vertex.getAdjVertices()) {
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


Graph createGraphFromFile() {
    Graph graph;
    ifstream myfile;
    myfile.open("amigos.txt");
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
        vector<Vertex> all = graph.getVertices();
        cout << "Endereco ok:" << &all << endl;
        for(Vertex v: all) {
          vector<string> current = friends_cache[i];
                for (string friend_registration: current) {
                    Vertex friend_vertex = graph.findByRegistration(friend_registration);
                    v.addAdjacencyVertex(friend_vertex);
                }
                cout << "Nome: " << v.getName() << "|";
                cout << "Matrícula: " << v.getRegistration() << "|";
                cout << "Amigos: ";
                i++;
                vector<Vertex> oi =  v.getAdjVertices();
                for(Vertex k: oi) {
                  cout << k.getRegistration() << " ";
                }
                cout << endl;
        }
        cout << &graph;
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
