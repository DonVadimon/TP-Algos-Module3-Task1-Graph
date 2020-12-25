#include "ListGraph.h"
#include <cassert>

ListGraph::ListGraph(const size_t vertexCount) :
        adjacencytList(vertexCount) {}

ListGraph::ListGraph(const IGraph &other) {
    adjacencytList.resize(other.VerticesCount());
    for (int from = 0; from < adjacencytList.size(); ++from) {
        adjacencytList[from] = other.GetNextVertices(from);
    }
}

void ListGraph::AddEdge(int from, int to) {
    assert(from >= 0 && from < adjacencytList.size());
    assert(to >= 0 && from < adjacencytList.size());
    adjacencytList[from].push_back(to);
}

int ListGraph::VerticesCount() const {
    return adjacencytList.size();
}

std::vector<int> ListGraph::GetNextVertices(int vertex) const {
    assert(vertex >= 0 && vertex < adjacencytList.size());
    return adjacencytList[vertex];
}

std::vector<int> ListGraph::GetPrevVertices(int vertex) const {
    assert(vertex >= 0 && vertex < adjacencytList.size());
    std::vector<int> prevVertices;
    for (int from = 0; from < adjacencytList.size(); ++from) {
        for (int i = 0; i < adjacencytList[from].size(); ++i) {
            if (adjacencytList[from][i] == vertex)
                prevVertices.push_back(from);
        }
    }
    return prevVertices;
}

