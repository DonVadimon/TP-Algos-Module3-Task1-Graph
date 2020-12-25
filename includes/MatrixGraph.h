#include "IGraph.h"

#include <iostream>

class MatrixGraph : public IGraph {
public:
    explicit MatrixGraph(size_t vertexCount);

    explicit MatrixGraph(const IGraph &other);

    ~MatrixGraph() override = default;

    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    std::vector<int> GetNextVertices(int vertex) const override;

    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    std::vector<std::vector<int>> adjacencytMatrix;
};