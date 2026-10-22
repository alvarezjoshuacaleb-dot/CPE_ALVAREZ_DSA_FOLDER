//Alvarez, Joshua Caleb P.
#include <iostream>

class Graph{
private:
    int matrix[5][5];

public:
    // Set matrix to 0
    Graph(){
        for (int i = 0; i < 5; i++){
            for (int j = 0; j < 5; j++)
            {
                matrix[i][j] = 0;
            }
        }
    }

    // Add undirected edge
    void addEdge(int start, int end){
        matrix[start][end] = 1;
        matrix[end][start] = 1;
    }

    // Add weighted edge
    void addWeightedEdge(int start, int end, int weight){
        matrix[start][end] = weight;
    }

    // Display matrix
    void displayMatrix(){
        std::cout << "    A B C D E" << std::endl;

        for (int i = 0; i < 5; i++){
            std::cout << char('A' + i) << "   ";

            for (int j = 0; j < 5; j++){
                std::cout << matrix[i][j] << " ";
            }

            std::cout << std::endl;
        }
    }
};

int main(){
    // Undirected graph
    Graph undirected;

    undirected.addEdge(0, 1); // A - B
    undirected.addEdge(0, 2); // A - C
    undirected.addEdge(0, 3); // A - D
    undirected.addEdge(1, 4); // B - E
    undirected.addEdge(2, 3); // C - D
    undirected.addEdge(3, 4); // D - E

    std::cout << "Undirected Graph Adjacency Matrix:" << std::endl;
    undirected.displayMatrix();

    std::cout << std::endl;

    // Weighted graph
    Graph weighted;

    weighted.addWeightedEdge(0, 1, 4); // A -> B
    weighted.addWeightedEdge(0, 2, 3); // A -> C
    weighted.addWeightedEdge(0, 4, 1); // A -> E
    weighted.addWeightedEdge(2, 3, 2); // C -> D
    weighted.addWeightedEdge(3, 1, 1); // D -> B
    weighted.addWeightedEdge(3, 4, 1); // D -> E
    weighted.addWeightedEdge(4, 0, 1); // E -> A

    std::cout << "Weighted Graph Adjacency Matrix:" << std::endl;
    weighted.displayMatrix();

    return 0;
}