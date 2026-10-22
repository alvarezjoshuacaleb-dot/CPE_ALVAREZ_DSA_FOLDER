//Alvarez, Joshua Caleb P.
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stack>

template <typename T>
struct Edge{
    size_t src;
    size_t dest;
    T weight;

    bool operator<(const Edge<T>& e) const{
        return weight < e.weight;
    }

    bool operator>(const Edge<T>& e) cons{
        return weight > e.weight;
    }
};

template <typename T>
class Graph;

template <typename T>
std::ostream& operator<<(std::ostream& os, const Graph<T>& G){
    for (size_t i = 1; i <= G.vertices(); i++){
        os << i << ":\t";

        std::vector<Edge<T>> edges = G.outgoing_edges(i);

        for (const auto& e : edges){
            os << "{" << e.dest << ": " << e.weight << "}, ";
        }

        os << std::endl;
    }

    return os;
}

template <typename T>
class Graph{
public:
    // Create graph
    Graph(size_t N) : V(N){
    }

    // Return vertices
    size_t vertices() const{
        return V;
    }

    // Return edges
    const std::vector<Edge<T>>& edges() const{
        return edge_list;
    }

    // Add an edge
    void add_edge(const Edge<T>& e){
        if (e.src >= 1 && e.src <= V &&
            e.dest >= 1 && e.dest <= V){
            edge_list.push_back(e);
        }
    }

    // Get outgoing edges
    std::vector<Edge<T>> outgoing_edges(size_t v) const{
        std::vector<Edge<T>> edges_from_v;

        for (const auto& e : edge_list){
            if (e.src == v){
                edges_from_v.push_back(e);
            }
        }

        return edges_from_v;
    }

private:
    size_t V;
    std::vector<Edge<T>> edge_list;
};

// DFS algorithm
template <typename T>
std::vector<size_t> depth_first_search(
    const Graph<T>& G, size_t start){
    std::stack<size_t> stack;
    std::vector<size_t> visit_order;
    std::set<size_t> visited;

    stack.push(start);

    while (!stack.empty()){
        size_t current_vertex = stack.top();
        stack.pop();

        if (visited.find(current_vertex) == visited.end()){
            visited.insert(current_vertex);
            visit_order.push_back(current_vertex);
            std::vector<Edge<T>> edges =
                G.outgoing_edges(current_vertex);

            for (const auto& e : edges){
                if (visited.find(e.dest) == visited.end()){
                    stack.push(e.dest);
                }
            }
        }
    }

    return visit_order;
}

// Create reference graph
template <typename T>
Graph<T> create_reference_graph(){
    Graph<T> G(9);

    std::map<unsigned, std::vector<std::pair<size_t, T>>> edges;

    edges[1] = {{2, 0}, {5, 0}};
    edges[2] = {{1, 0}, {5, 0}, {4, 0}};
    edges[3] = {{4, 0}, {7, 0}};
    edges[4] = {{2, 0}, {3, 0}, {5, 0}, {6, 0}, {8, 0}};
    edges[5] = {{1, 0}, {2, 0}, {4, 0}, {8, 0}};
    edges[6] = {{4, 0}, {7, 0}, {8, 0}};
    edges[7] = {{3, 0}, {6, 0}};
    edges[8] = {{4, 0}, {5, 0}, {6, 0}};

    for (const auto& i : edges){
        for (const auto& j : i.second){
            G.add_edge(Edge<T>{i.first, j.first, j.second});
        }
    }

    return G;
}

int main(){
    typedef unsigned T;

    Graph<T> G = create_reference_graph<T>();
    std::cout << G << std::endl;
    std::cout << "DFS Order of vertices:" << std::endl;
    std::vector<size_t> dfs_visit_order =
        depth_first_search(G, 1);

    for (size_t v : dfs_visit_order){
        std::cout << v << std::endl;
    }

    return 0;
}