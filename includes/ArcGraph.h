#include "IGraph.h"

class ArcGraph : public IGraph {
public:
    explicit ArcGraph(size_t _vertexCount);

    explicit ArcGraph(const IGraph &other);

    ~ArcGraph() override = default;

    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    std::vector<int> GetNextVertices(int vertex) const override;

    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    std::vector<std::pair<int, int>> arcList;
    size_t verticesCount;
};