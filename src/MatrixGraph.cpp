#include "MatrixGraph.h"
#include <cassert>

MatrixGraph::MatrixGraph(const size_t vertexCount) :
        adjacencytMatrix(vertexCount) {
    for (auto &row : adjacencytMatrix) {
        row.resize(vertexCount, 0);
    }
}

MatrixGraph::MatrixGraph(const IGraph &other) {
    size_t verticesCount = other.VerticesCount();
    adjacencytMatrix.resize(verticesCount);
    for (int i = 0; i < verticesCount; ++i) {
        adjacencytMatrix[i].resize(verticesCount, 0);
        for (int j : other.GetNextVertices(i)) {
            adjacencytMatrix[i][j]++;
        }
    }
}

void MatrixGraph::AddEdge(int from, int to) {
    assert(from >= 0 && from < adjacencytMatrix.size());
    assert(to >= 0 && to < adjacencytMatrix.size());
    adjacencytMatrix[from][to]++;
}

int MatrixGraph::VerticesCount() const {
    return adjacencytMatrix.size();
}

std::vector<int> MatrixGraph::GetNextVertices(int vertex) const {
    assert(vertex >=0 && vertex < adjacencytMatrix.size());
    std::vector<int> nextVertices;
    for (int to = 0; to < adjacencytMatrix[vertex].size(); ++to) {
        if (adjacencytMatrix[vertex][to] != 0)
            nextVertices.push_back(to);
    }
    return nextVertices;
}

std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const {
    assert(vertex >= 0 && vertex < adjacencytMatrix.size());
    std::vector<int> prevVertices;
    for (int i = 0; i < adjacencytMatrix.size(); ++i) {
        if (adjacencytMatrix[i][vertex] != 0)
            prevVertices.push_back(i);
    }
    return prevVertices;
}
