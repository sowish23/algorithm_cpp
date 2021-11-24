#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Edge {
public:
    int node[2];
    int distance;
    Edge(int a, int b, int distance) {
        this->node[0] = a;
        this->node[1] = b;
        this->distance = distance;
    }
    bool operator<(const Edge &edge) const{
        return this->distance < edge.distance;
    }
};

int getParents(int set[], int x) {
    if(set[x] == x) return x;
    return set[x] = getParents(set, set[x]);
}

void unionParents(int set[], int a, int b) {
    a = getParents(set, a);
    b = getParents(set, b);
    if(a<b) set[b] = a;
    else set[a] = b;
}

int find(int set[], int a, int b) {
    a = getParents(set, a);
    b = getParents(set, b);
    if(a==b) return 1;
    else return 0;
}

int main(void) {
    int num;
    cin >> num;
    while(num--) {
        int node_num;
        cin >> node_num;
        int n = node_num;
        vector<Edge> graph;
        while(node_num--){
            int node, near_node_num;
            cin >> node >> near_node_num;
            while(near_node_num--) {
                int near_node, dist;
                cin >> near_node >> dist;
                graph.push_back(Edge(node, near_node, dist));
            }

        }
        sort(graph.begin(), graph.end());

        int set[n];
        for(int i=0; i<n; i++) {
            set[i] = i;
        }

        int sum=0;
        for(int i=0; i<graph.size(); i++) {
            if(!find(set, graph[i].node[0]-1, graph[i].node[1]-1)) {
                sum += graph[i].distance;
                unionParents(set, graph[i].node[0]-1, graph[i].node[1]-1);
            }
        }
        cout << sum <<endl;

    }

    
    return 0;
}
