#include <iostream>
#include <string>
#include <vector>

class Graph {
private:
    std::vector<Vertex> vertices;
public:
    std::vector<Vertex> getVertices();
    void addVertex(Vertex vertex);
    Vertex findByRegistration(std::string registration);
    void formatedPrint();
    void createVertices(std::string filename);
};
