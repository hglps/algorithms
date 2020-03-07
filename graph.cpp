#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <queue>

#define MAX_SIZE 100
#define inf 1e9 //search for better reference of 'infinity'
typedef std::string string;

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
        graph(){
            for(int i=0; i< MAX_SIZE; i++){
                this->vertices[i] = NULL;
                this->visited[i] = 0;
            }
        }
        
        void add_edge(int item1, int item2, int weight, int directed);
        void display_nodes();
        int dijkstra(int source, int target);
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

int graph::dijkstra(int source, int target){
    int cost[MAX_SIZE];
    for(int i=0; i<MAX_SIZE; i++)
        cost[i] = inf;
    std::priority_queue<std::pair<int, int>> pqueue;
    int pred[MAX_SIZE];
    cost[source] = 0;
    pqueue.push({source, 0});

    while(!pqueue.empty()){
        int u = pqueue.top().first;
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

        pqueue.pop();
    }

    //TODO: fix predecessors array :)

    return cost[target];
}

void graph::display_nodes(){
    for(int i=0; i< MAX_SIZE; i++){
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

    graph *gp = new graph();
    int n, u, v, w;
    std::cout << "Enter n of paths:\n";
    std::cin >> n;
    std::cout <<"Enter " << n << " paths and weight:\n";
    for(int i=0; i<n; i++){
        std::cin >> u >> v >> w;
        gp->add_edge(u, v, w, 0); // 0 : undirected

    }
    gp->display_nodes();
    int dist = gp->dijkstra(0,5);
    std::cout << "Nearest path has total weight: " << dist << std::endl;

    return 0;
}
