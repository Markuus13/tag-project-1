#include <string>
#include <vector>

class Vertex {
private:
    std::string registration;
    std::string name;
    std::vector<Vertex> adjVertices;

public:
    Vertex();
    Vertex(std::string registration, std::string name);

    std::string getRegistration();
    void setRegistration(int registration);
    std::string getName();
    void setName(std::string name);
    std::vector<Vertex> getAdjVertices();
    void addAdjacencyVertex(Vertex vertex);
    int getDegree() const;
};
