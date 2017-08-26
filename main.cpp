#include <iostream>
#include <fstream>

using namespace std;

void create_graph_using_file(string filename) {
  ifstream myfile;

  myfile.open(filename);

  if (myfile.is_open()) {
    string name;
    string registration;
    string friend_registrations;

    while ( getline(myfile, name, '|')
              && getline(myfile, registration, '|')
              && getline(myfile, friend_registrations) ) {
      cout << "Nome: " << name << endl;
      cout << "Matrícula: " << registration << endl;
      cout << "Matrícula dos amigos: " << friend_registrations << endl;
      cout << "---------------------------------------------------------" << endl;
    }
    myfile.close();
  } else {
    cout << "Unable to open file.";
  }
}

int main() {
  create_graph_using_file("example.txt");
  return 0;
}
