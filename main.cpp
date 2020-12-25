#include <iostream>


#include <queue>


#include "ListGraph.h"
#include "MatrixGraph.h"
#include "SetGraph.h"
#include "ArcGraph.h"

void BFS(const IGraph &graph, int vertex, void (*visit)(int)) {
    std::vector<bool> visited(graph.VerticesCount(), false);
    std::queue<int> bfsQueue;
    bfsQueue.push(vertex);
    visited[vertex] = true;

    while (!bfsQueue.empty()) {
        int current = bfsQueue.front();
        bfsQueue.pop();
        visit(current);
        std::vector<int> adjacentVertices = graph.GetNextVertices(current);
        for (int &adjacentVertex : adjacentVertices)
            if (!visited[adjacentVertex]) {
                bfsQueue.push(adjacentVertex);
                visited[adjacentVertex] = true;
            }
    }
}

void printVec(const std::vector<int> &vec) {
    for (int i : vec) {
        std::cout << i << ' ';
    }
    std::cout << '\n';
}

void printPrevVerticies(const IGraph &graph) {
    for (int i = 0; i < graph.VerticesCount(); ++i) {
        printVec(graph.GetPrevVertices(i));
    }
}

int main() {
    std::cout << "\n============== PROGRAM STARTS HERE ==============\n";

    ListGraph listGraph(5);
    listGraph.AddEdge(0, 1);
    listGraph.AddEdge(0, 3);
    listGraph.AddEdge(0, 4);
    listGraph.AddEdge(1, 4);
    listGraph.AddEdge(4, 2);

    std::cout << "\n============== BFS ==============\n";

    std::cout << "\nBFS listGraph:\n";

    BFS(listGraph, 0, [](int vertex) { std::cout << vertex << ", "; });

    std::cout << "\nBFS matrixGraph:\n";

    MatrixGraph matrixGraph(listGraph);

    BFS(matrixGraph, 0, [](int vertex) { std::cout << vertex << ", "; });

    std::cout << "\nBFS setGraph:\n";

    SetGraph setGraph(matrixGraph);

    BFS(setGraph, 0, [](int vertex) { std::cout << vertex << ", "; });

    std::cout << "\nBFS arcGraph:\n";

    ArcGraph arcGraph(setGraph);

    BFS(arcGraph, 0, [](int vertex) { std::cout << vertex << ", "; });

    std::cout << "\n============== PREV VERTICIES ==============\n";

    std::cout << "\nList Graph\n";

    printPrevVerticies(listGraph);

    std::cout << "\nList Graph\n";

    printPrevVerticies(matrixGraph);

    std::cout << "\nList Graph\n";

    printPrevVerticies(setGraph);

    std::cout << "\nList Graph\n";

    printPrevVerticies(arcGraph);

    return 0;
}