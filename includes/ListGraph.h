#include "IGraph.h"

class ListGraph : public IGraph {
public:
    explicit ListGraph(size_t vertexCount);

    explicit ListGraph(const IGraph &other);

    ~ListGraph() override = default;

    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    std::vector<int> GetNextVertices(int vertex) const override;

    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    std::vector<std::vector<int>> adjacencytList;
};