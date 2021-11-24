#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Edge {
public:
    int start;
    int end;
    int distance;
    Edge(int start, int end, int distance){
        this->start = start;
        this->end = end;
        this->distance = distance;
    }
    bool operator < (const Edge &edge) const {
        return this->distance > edge.distance;
    }
};

int main() {
    int num;
    cin >> num;
    while(num--) {
        vector<pair<int,int> > a[1001];
        bool c[1001] = {0};
        int node_num;
        cin >> node_num;
        int n = node_num;
        while(node_num--){
            int node, near_node_num;
            cin >> node >> near_node_num;
            while(near_node_num--) {
                int near_node, dist;
                cin >> near_node >> dist;
                a[node].push_back(make_pair(near_node,dist));
            }

        }
        c[1] = true;
        priority_queue<Edge> pq;
        for (int i=0; i<a[1].size(); i++) {
            pq.push(Edge(1, a[1][i].first, a[1][i].second));
        }
        int answer = 0;
        for (int i=0; i<n-1; i++) {
            Edge e = Edge(0,0,0);
            while (!pq.empty()) {
                e = pq.top();
                pq.pop();
                if (c[e.end] == false) {
                    break;
                }
            }
            c[e.end] = true;

            answer += e.distance;
            int x = e.end;
            for (int i=0; i<a[x].size(); i++) {
                pq.push(Edge(x, a[x][i].first, a[x][i].second));
            }
        }
        cout << answer << endl;
    }

    return 0;
}