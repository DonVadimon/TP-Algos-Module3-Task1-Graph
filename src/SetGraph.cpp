#include "SetGraph.h"
#include <cassert>

SetGraph::SetGraph(const size_t vertexCount) :
        adjacencytList(vertexCount) {}

SetGraph::SetGraph(const IGraph &other) {
    adjacencytList.resize(other.VerticesCount());
    for (int i = 0; i < adjacencytList.size(); ++i) {
        std::vector<int> otherNextVertices = other.GetNextVertices(i);
        for (int vertex : otherNextVertices) {
            adjacencytList[i].insert(vertex);
        }
    }
}

void SetGraph::AddEdge(int from, int to) {
    assert(from >= 0 && from < adjacencytList.size());
    assert(to >= 0 && to < adjacencytList.size());
    adjacencytList[from].insert(to);
}

int SetGraph::VerticesCount() const {
    return adjacencytList.size();
}

std::vector<int> SetGraph::GetNextVertices(int vertex) const {
    assert(vertex >= 0 && vertex < adjacencytList.size());
    std::vector<int> nextVertices;
    for (int cell : adjacencytList[vertex]) {
        nextVertices.push_back(cell);
    }
    return nextVertices;
}

std::vector<int> SetGraph::GetPrevVertices(int vertex) const {
    assert(vertex >= 0 && vertex < adjacencytList.size());
    std::vector<int> prevVertices;
    for (int from = 0; from < adjacencytList.size(); ++from) {
        if (adjacencytList[from].find(vertex) != adjacencytList[from].end()) {
            prevVertices.push_back(from);
        }
    }
    return prevVertices;
}
