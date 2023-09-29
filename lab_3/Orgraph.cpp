#include <iostream>
#include <vector>
#include<set>
#include <unordered_map>

using namespace std;

const int INF = 1e10;

class Graph {
private:
    unordered_map<int, vector<pair<int, int>>> graph;

public:
    void AddTop(int top) {
        if (graph.find(top) == graph.end()) {
            graph[top] = vector<pair<int, int>>();
        }
        else {
            cout << "Такая вершина уже существует!" << endl;
        }
    }

    void AddEdge(int from, int to, int weight) {
        if (graph.find(from) != graph.end() && graph.find(to) != graph.end()) {
            graph[from].push_back(make_pair(to, weight));
        }
        else {
            cout << "Одной(или двух вершин) из указанных не существует" << endl;
        }
    }

    void Dijkstra(int source) {
        unordered_map<int, int> distance;
        set<pair<int, int>> s;

        for (auto p : graph) {
            int vertex = p.first;
            distance[vertex] = INF;
        }

        distance[source] = 0;
        s.insert({ 0, source });

        while (!s.empty()) {
            int current_vertex = s.begin()->second;
            s.erase(s.begin());

            for (auto& edge : graph[current_vertex]) {
                int neighbor = edge.first;
                int weight = edge.second;

                if (distance[current_vertex] + weight < distance[neighbor]) {
                    s.erase({ distance[neighbor], neighbor });
                    distance[neighbor] = distance[current_vertex] + weight;
                    s.insert({ distance[neighbor], neighbor });
                }
            }
        }

        cout << "Кратчайшие пути к вершинам от вершины " << source << ":" << endl;
        for (auto& p : distance) {
            cout << "Вершина " << p.first << ": ";
            if (p.second == INF) {
                cout << "INF" << endl;
            }
            else {
                cout << p.second << endl;
            }
        }
    }


};

int main() {
    setlocale(LC_ALL, "rus");
    Graph graph;

    graph.AddTop(1);
    graph.AddTop(2);
    graph.AddTop(3);
    graph.AddTop(4);
    graph.AddTop(5);
    graph.AddTop(6);


    graph.AddEdge(1, 2, 28);
    graph.AddEdge(1, 3, 21);
    graph.AddEdge(1, 5, 12);
    graph.AddEdge(1, 4, 59);
    graph.AddEdge(1, 6, 27);

    graph.AddEdge(2, 1, 7);
    graph.AddEdge(2, 3, 24);
    graph.AddEdge(2, 6, 9);
    graph.AddEdge(2, 5, 21);

    graph.AddEdge(3, 1, 9);
    graph.AddEdge(3, 2, 32);
    graph.AddEdge(3, 5, 11);
    graph.AddEdge(3, 4, 13);

    graph.AddEdge(4, 1, 8);
    graph.AddEdge(4, 3, 5);
    graph.AddEdge(4, 5, 16);

    graph.AddEdge(5, 1, 14);
    graph.AddEdge(5, 2, 13);
    graph.AddEdge(5, 3, 15);
    graph.AddEdge(5, 4, 10);
    graph.AddEdge(5, 6, 22);

    graph.AddEdge(6, 1, 15);
    graph.AddEdge(6, 2, 18);
    graph.AddEdge(6, 5, 6);
    
    int vert;
    cout << "От какой вершины ищем кратчайшие пути? ";
    cin >> vert;
    graph.Dijkstra(vert);

    return 0;
}
