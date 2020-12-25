#include "IGraph.h"

#include <set>

class SetGraph : public IGraph {
public:
    explicit SetGraph(size_t vertexCount);

    explicit SetGraph(const IGraph &other);

    ~SetGraph() override = default;

    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    std::vector<int> GetNextVertices(int vertex) const override;

    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    std::vector<std::set<int>> adjacencytList;
};