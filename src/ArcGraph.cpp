#include "ArcGraph.h"
#include <cassert>
#include <set>

ArcGraph::ArcGraph(size_t _vertexCount) {
    assert(_vertexCount >= 0);
    verticesCount = _vertexCount;
}

ArcGraph::ArcGraph(const IGraph &other) {
    verticesCount = other.VerticesCount();
    for (int from = 0; from < verticesCount; ++from) {
        std::vector<int> otherNextVertices = other.GetNextVertices(from);
        for (int to : otherNextVertices) {
            arcList.emplace_back(from, to);
        }
    }
}

void ArcGraph::AddEdge(int from, int to) {
    assert(from >= 0 && from < arcList.size());
    assert(to >= 0 && to < arcList.size());
    arcList.emplace_back(from, to);
}

int ArcGraph::VerticesCount() const {
    return verticesCount;
}

std::vector<int> ArcGraph::GetNextVertices(int vertex) const {
    assert(vertex >= 0 && vertex < arcList.size());
    std::vector<int> nextVertices;
    for (const auto &pair : arcList) {
        if (pair.first == vertex) {
            nextVertices.push_back(pair.second);
        }
    }
    return nextVertices;
}

std::vector<int> ArcGraph::GetPrevVertices(int vertex) const {
    assert(vertex >= 0 && vertex < arcList.size());
    std::vector<int> prevVertices;
    for (const auto &pair : arcList) {
        if (pair.second == vertex) {
            prevVertices.push_back(pair.first);
        }
    }
    return prevVertices;
}
