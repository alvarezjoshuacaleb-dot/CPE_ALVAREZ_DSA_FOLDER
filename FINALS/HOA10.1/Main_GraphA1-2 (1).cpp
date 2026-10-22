#include <iostream>

class Graph
{
private:
    int vertices;
    int edges[10][10];

public:
    // Constructor
    Graph(int v)
    {
        vertices = v;

        // initialize all edges to 0
        for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < vertices; j++)
            {
                edges[i][j] = 0;
            }
        }
    }

    // Add an edge between two vertices
    void addEdge(int start, int end)
    {
        edges[start][end] = 1;
        edges[end][start] = 1;
    }

    // Display the graph vertices
    void displayVertices()
    {
        std::cout << "Graph vertices: ";

        for (int i = 0; i < vertices; i++)
        {
            std::cout << i << " ";
        }

        std::cout << std::endl;
    }

    // Display the edges
    void displayEdges()
    {
        std::cout << "Graph edges:" << std::endl;

        for (int i = 0; i < vertices; i++)
        {
            for (int j = i + 1; j < vertices; j++)
            {
                if (edges[i][j] == 1)
                {
                    std::cout << i << " - " << j << std::endl;
                }
            }
        }
    }
};

int main()
{
    // Create a graph with 5 vertices
    Graph graph(5);

    // Add edges
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);

    // Display graph vertices
    graph.displayVertices();

    // Display graph edges
    graph.displayEdges();

    return 0;
}