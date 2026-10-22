#include <iostream>
#include <vector>
#include <set>
#include <queue>

template <typename T>
class Graph;

template <typename T>
struct Edge{
    size_t src;
    size_t dest;
    T weight;

    bool operator<(const Edge<T>& other) const{
        return weight < other.weight;
    }

    bool operator>(const Edge<T>& other) const{
        return weight > other.weight;
    }
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Graph<T>& G){
    for (size_t i = 1; i <= G.vertices(); ++i){
        os << i << ": ";

        for (auto e : G.outgoing_edges(i)){
            os << "(" << e.dest << ", " << e.weight << ") ";
        }

        os << std::endl;
    }

    return os;
}

template <typename T>
class Graph{
public:
    Graph(size_t N) : V(N){
    }

    size_t vertices() const{
        return V;
    }

    void add_edge(const Edge<T>& e){
        edge_list.push_back(e);
    }

    std::vector<Edge<T>> outgoing_edges(size_t v) const{
        std::vector<Edge<T>> result;

        for (auto e : edge_list){
            if (e.src == v){
                result.push_back(e);
            }
        }

        return result;
    }

private:
    size_t V;
    std::vector<Edge<T>> edge_list;
};

// Create reference graph
template <typename T>
Graph<T> create_reference_graph(){
    Graph<T> G(9);

    std::vector<Edge<T>> edges ={
        {1, 2, 2},{1, 5, 3},{2, 1, 2},
        {2, 5, 5},{2, 4, 1},{3, 4, 2},
        {3, 7, 3},{4, 2, 1},{4, 3, 2},
        {4, 5, 2},{4, 6, 4},{4, 8, 5},
        {5, 1, 3},{5, 2, 5},{5, 4, 2},
        {5, 8, 3},{6, 4, 4},{6, 7, 4},
        {6, 8, 1},{7, 3, 3},{7, 6, 4},
        {8, 4, 5},{8, 5, 3},{8, 6, 1}
    };

    for (auto e : edges){
        G.add_edge(e);
    }
    return G;
}

// Breadth-First Search
template <typename T>
auto breadth_first_search(const Graph<T>& G, size_t dest){
    std::queue<size_t> queue;
    std::vector<size_t> visit_order;
    std::set<size_t> visited;

    queue.push(1); // BFS always starts from vertex 1

    while (!queue.empty()){
        auto current_vertex = queue.front();
        queue.pop();

        if (visited.find(current_vertex) == visited.end()){
            visited.insert(current_vertex);
            visit_order.push_back(current_vertex);

            for (auto e : G.outgoing_edges(current_vertex)){
                queue.push(e.dest);
            }
        }
    }

    return visit_order;
}

// Test BFS
template <typename T>
void test_BFS(){
    auto G = create_reference_graph<T>();

    std::cout << G << std::endl;

    std::cout << "BFS Order of vertices: " << std::endl;

    auto bfs_visit_order = breadth_first_search(G, 1);

    for (auto v : bfs_visit_order){
        std::cout << v << std::endl;
    }
}

int main(){
    using T = unsigned;

    test_BFS<T>();

    return 0;
}