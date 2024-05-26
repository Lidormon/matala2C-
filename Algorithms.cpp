/*
lidor mondel
207478256
lidormon20@gmail.com
*/


#include "Algorithms.hpp"
#include <vector>
#include <climits>
#include <queue> 


using namespace ariel;

//2
// algoritm that find if the graph is scc

bool Algorithms::isConnected(Graph& graph) {

    vector<bool> vertex_vis(graph.size(), false);
    DFS(graph, 0, vertex_vis);

    for (bool vis : vertex_vis) {
        if (!vis){
            return false;//not connected
        }
    }

    graph.transposeGraph();
    fill(vertex_vis.begin(), vertex_vis.end(), false); 
    DFS(graph, 0, vertex_vis);
    graph.transposeGraph();

    for (bool vis : vertex_vis) {
        if (!vis){
            return false; //not connected
        }
    }

    return true;
}


string Algorithms::shortestPath(const Graph& graph, const unsigned int start, const unsigned int end) {

    const unsigned int num_vertes = graph.size();

    if(start >= num_vertes || end >= num_vertes) { // start and end represent the count of vertex in path so far
        throw invalid_argument("Invalid values:Not in the range of the matrix .");
    }

    vector<int> distance(num_vertes, INT_MAX); // all the vertex intilized to infinti
    distance[start] = 0; // the start vertex intilized to zero
    vector<int> pred(num_vertes, -1); // π(pi)


  // belman-ford (relax)
  
    for (unsigned int i = 0; i < num_vertes; i++) { // in belman-ford we do relax n-1 times
        for (unsigned int j = 0; j < num_vertes; j++) {
            for (unsigned int k = 0; k < num_vertes; k++) {

                if(graph.getEdge(j,k) != 0) { // if have edge beteen j to k

                   
                    if (distance[j] != INT_MAX && distance[j] + graph.getEdge(j,k) < distance[k]) {
                        distance[k] = distance[j] + graph.getEdge(j,k);
                        pred[k] = static_cast<int>(j); // static_cast<int> convert j from unsigned to int. j is the pred of k
                    }
                }
            }
        }
    }

     
     
   
    // detact negative cycle
   
    for (unsigned int j = 0; j < num_vertes; j++) {
        for (unsigned int k = 0; k < num_vertes; k++) {
            if(graph.getEdge(j,k) != 0) {  // if have edge beteen j to k
                if (distance[j] != INT_MAX && distance[j] + graph.getEdge(j,k) < distance[k]) {
                    return "Negative Cycle.No shortest path.";
                }
            }
        }
    }


    // built the shortest path accordind to pred

    if (distance[static_cast<unsigned int>(end)] == INT_MAX) {  // If the distance to the end vertex is still INT_MAX, it means there is no path from start to end, so return "-1".
        return "-1";
    }

    string path = to_string(end);

//Otherwise, build the path string by following the pred vector from end back to start.
    for (unsigned int num_vertex = end; num_vertex != start; num_vertex = static_cast<unsigned int>(pred[num_vertex])) { // ???
        path.insert(0, "->");
        path.insert(0, to_string(pred[num_vertex]));
    }

    return path;
}



string Algorithms::isContainsCycle(const Graph& graph) {

    const unsigned int num_vertex = graph.size(); // number of all vertex in the graph
    vector<bool> vis(num_vertex, false); // array of all vectexs i visit
    vector<unsigned int> pred_vec(num_vertex, INT_MAX);// array of pred vertex (pi)
    string ans_path = "";
    for (unsigned int i = 0; i < num_vertex; i++) {
        if (!vis[i]) { // if i not visit in this vertex yet
            if (dfs_for_cycle(i, INT_MAX, graph, vis, pred_vec, ans_path)) { // if have cycle in the graph

              unsigned int temp = 0;
                 for (const char ch : ans_path) { // if i see > in the string of the path
                     if (ch == '>') {
                          temp++; // temp is the number of vertex in the path
                    }
                }

                if (temp >= 2) {
                    return ans_path; // return the cycle
                }

                else {
                    ans_path = "";
                    fill(vis.begin(), vis.end(), false); // fill is built-in function (and so the functions begin() and end()) that fill all the vis vector from the begin to the end in false
                }
            }
        }
    }

    // No cycle found
    return "0"; //(return string)
}




//function that do a DFS traversal to detect if have cycles in an undirected graph.

bool Algorithms::dfs_for_cycle(const unsigned int node, unsigned int parentNode, const Graph& graph, vector<bool>& vis, vector<unsigned int>& parent, string& ans_path) {
    vis[node] = true; // i visit this current node
    parent[node] = parentNode;

    for (const unsigned int nextNode : graph.get_voisin(node)) { // i visit in all the neighbors (nextNode) of node 

        if (!vis[nextNode]) { // if i not visit this neighbor yet  
            if (dfs_for_cycle(nextNode, node, graph, vis, parent, ans_path)) {
                return true ;
            }
        }

        else if (nextNode != parentNode) { // if the neighbor is not the parent
            // print the cycle
            unsigned int temp_no = node;
            ans_path = "The cycle is: " + to_string(nextNode); 

            while (temp_no != INT_MAX && temp_no != nextNode) {  // ????
                ans_path += "->" + std::to_string(temp_no); 
                temp_no = parent[temp_no];
            }

            ans_path += "->" + to_string(nextNode); 
            return true;
        }
    }

    return false;
}




bool Algorithms::help_bipartite(size_t start, const vector<vector<int>> &graph, vector<size_t> &colors, vector<vector<size_t>> &sets)
{
    queue<size_t> q;
    q.push(start); // the start is the only node in the queue meanwhile
    colors[start] = 0;

    while (!q.empty())
    {
        size_t node = q.front(); // node is start now
        q.pop(); // remove node from queue

        for (size_t neighbor = 0; neighbor < graph[node].size(); ++neighbor) // advance all the neighbors of the current node
        {
            if (graph[node][neighbor] != 0)// if have edge between node to neighbor
            {
                if (colors[neighbor] == INF)// the neighbor steel not paint
                {
                    colors[neighbor] = 1 - colors[node]; // paint the neighbor in the oposite color(0 or 1)
                    q.push(neighbor); // push neighbor to queue
                }
                else if (colors[neighbor] == colors[node]) //  the neighbor have same color like node
                {
                    return false;
                }
            }
        }
    }

// built the bipartite graph

    vector<size_t> set1;
    vector<size_t> set2;

    for (size_t i = 0; i < colors.size(); i++)
    {
        if (colors[i] == 0)
        {
            set1.push_back(i);
        }
        else
        {
            set2.push_back(i);
        }
    }
    // sets is all the graph that we get is as parameter from the function
    sets.push_back(set1);
    sets.push_back(set2);

    return true;
}



bool Algorithms::isBipartite(const Graph& g) {
    const vector<vector<int>> &graph = g.getGraph();
    size_t num_vertex = g.size();
    vector<vector<size_t>> sets;
    vector<size_t> colors(num_vertex, INF); 

    for (size_t i = 0; i < num_vertex; ++i)
    {
        if (colors[i] == INF) //if i not paint yet
        {                                                       
            if (!help_bipartite(i, graph, colors, sets)) 
            {
                cout << "Graph is not Bipartite" << endl;
                return false;
            }
        }
    }
  // if we arrive to hear so have Bipartite graph
  cout << "Graph is Bipartite .The sets are::" << endl;
    for (size_t i = 0; i < sets.size(); i++) // we orgenized the graph(sets) to be Bipartite in help_bipartite function (lines 210-231)
    {
        cout << "Group " << (i % 2) + 1 << ": "; // 0 or 1
        for (size_t vertex : sets[i]) // print the Bipartite graph
        {
            cout << vertex << " ";
        }
        cout << endl;
    }

    return true; 


}

string Algorithms::negativeCycle(const Graph& graph) {

    const unsigned int num_vertes = graph.size(); 
    for(unsigned int i = 0; i < num_vertes; i++) {
        if(shortestPath(graph, i, i) == "Negative Cycle.No shortest path.") { // in cycle the start vertex and the end vertex are same
            return "Contains negative cycle";
        }
    }

    
    return "Not contains negative cycle";
}

void Algorithms::DFS(const Graph& graph, unsigned int vis, vector<bool>& node_vis) {
    node_vis[vis] = true; // we visit in vertex vis

    vector<unsigned int> voisin=graph.get_voisin(vis); // give me all the neighbors of vis
    for (unsigned int i : voisin) { // for each neighbor of vis

    
        if (!node_vis[i]) { // if we not visit this neighbor yet

            DFS(graph, i, node_vis); // go to the neighbor of the neighbor recorsive
        }
    }
}


