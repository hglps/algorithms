#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <queue>
#include <functional>
#include <utility>

#define MAX_SIZE 100
#define inf 1e9 //search for better reference of 'infinity'
typedef std::string string;
typedef std::pair<int,int> pairINT;

struct increasingPQ {
    constexpr bool operator()(
        std::pair<int,int> const& a,
        std::pair<int,int> const& b)
        const noexcept
    {
        return a.second > b.second;
    }
};

class adj_list{
    public:
        int item;
        int w;
        adj_list *next;
        adj_list(int item, int weight){
            this->item = item;
            this->w = weight;
            this->next = NULL;
        }
};

class graph{
    public:
        adj_list *vertices[MAX_SIZE];
        short visited[MAX_SIZE];
        graph(int n){
            for(int i=0; i< n; i++){
                this->vertices[i] = NULL;
                this->visited[i] = 0;
            }
        }
        
        void add_edge(int item1, int item2, int weight, int directed);
        void display_nodes(int n);
        int dijkstra(int source, int target, int n);
        void showPathDijkstra(int pred[], int target);
};

void graph::add_edge(int item1, int item2, int weight, int directed){
    adj_list *vex = new adj_list(item2, weight);
    if(this->vertices[item1] == NULL)
        this->vertices[item1] = vex;
    else{
        adj_list *aux1 = this->vertices[item1];
        while(aux1->next != NULL)
            aux1 = aux1->next;
        aux1->next = vex;
    }

    if(!directed){
        adj_list *vex2 = new adj_list(item1, weight);
    if(this->vertices[item2] == NULL)
        this->vertices[item2] = vex2;
        else{
            adj_list *aux2 = this->vertices[item2];
            while(aux2->next != NULL)
                aux2 = aux2->next;
            aux2->next = vex2;
        }
    }
}

void graph::showPathDijkstra(int pred[], int target)
{
    std::vector<int> predecessors;
    predecessors.push_back(target);
    for(int i= target; i != 0; i= pred[i]){
        predecessors.push_back(pred[i]);
    }
    std::cout << "Final path= ";
    for(int i=predecessors.size()-1; i>= 0; i--)
    {
        std::cout << predecessors[i];
        if(i != 0) std::cout << " - ";
    }
    std::cout << std::endl;
}

int graph::dijkstra(int source, int target, int n){
    int cost[MAX_SIZE];
    for(int i=0; i<n; i++)
        cost[i] = inf;
    std::priority_queue<pairINT, std::vector<pairINT> , increasingPQ > pqueue;
    int pred[MAX_SIZE];
    pred[0] = -1;
    cost[source] = 0;
    pqueue.push({source, 0});
    
    while(!pqueue.empty()){
        int u = pqueue.top().first;
        
        pqueue.pop();
        
        adj_list *auxU = this->vertices[u];
        while(auxU != NULL){

            int v = auxU->item;
            int weightUV = auxU->w;
            if(cost[u] + weightUV < cost[v]){
                cost[v] = cost[u] + weightUV;
                pqueue.push({v, cost[v]});
                pred[v] = u;
            }
            auxU = auxU->next;
        }

    }

    showPathDijkstra(pred, target);

    return cost[target];
}

void graph::display_nodes(int n){
    // n vertices
    for(int i=0; i< n; i++){
        if(this->vertices[i] != NULL){
            adj_list *aux = this->vertices[i];
            std::cout << i << " -> ";
            while(aux != NULL){
                std::cout << aux->item << " -> ";
                aux = aux->next;
            }
            std::cout << std::endl;
        }
    }
}




int main(int argc, const char** argv) {

    int m, n, u, v, w;
    std::cout << "Enter n vertices and m paths:\n";
    std::cin >> n >> m;

    graph *gp = new graph(n);


    std::cout <<"Enter " << m << " paths and weight:\n";
    for(int i=0; i<m; i++){
        std::cin >> u >> v >> w;
        gp->add_edge(u, v, w, true); // false : undirected

    }
    // gp->display_nodes(n);
    int dist = gp->dijkstra(0,n-1,n);
    std::cout << "Nearest path has total weight: " << dist << std::endl;

    return 0;
}

// 6 9
// 0 1 9
// 0 2 8
// 2 1 2
// 1 3 4
// 1 4 4
// 2 5 3
// 2 4 5
// 3 5 5
// 4 5 6
