**Dijkstra : Find shortest path to objective. Search through all possible paths. :(**

1. Start all nodes with weight= infinity, except the starting node(S).

2. Iterate through all adjacents nodes of starting node, putting on a priority queue, based on their weights ('current distance from S').

3. Repeat process with first node(i.e. shortest path so far) on the priority queue.

4. When updating values of weights' nodes on priority queue:

-> dist[adj] uses current value + weight from current('u') to adj('v').

-> reorganize priority queue

->set predecessor[v] = u

5. If a path is reachable, the total weight is cost[objective node] and actual path is 0, i where predecessor[i] == 0, and so on, until the last node.

**Ex: from 0 to 5**

![Graph](https://github.com/hglps/algorithms/blob/master/graph.png)

|      | 0 | 1 | 2 | 3 | 4 | 5 |
|------|---|---|---|---|---|---|
| pred | ~ | 4 | 0 | 2 | 2 | 3 |

path is 0->2->3->5

![Example](https://github.com/hglps/algorithms/blob/master/dijkstra.png)


