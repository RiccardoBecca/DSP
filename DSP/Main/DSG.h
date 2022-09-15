#ifndef __FunzioneBase__
#define __FunzioneBase__

#include<iostream>
#include<list>
#include<vector>
#include<string>

using namespace std;

class AdjEdgeItem {
    private:
        int adj_vertex;
        int edge_weight;
    
    public:
        AdjEdgeItem(int a, int w) {
            adj_vertex = a;
            edge_weight = w;
        }
        int GetAdj() {return adj_vertex;}
        int GetEdgeWeight() {return edge_weight;}
};

class Graph {
    public:
        Graph(int V){
            number_of_V =V;
            adj = new list<AdjEdgeItem>[V];
            distance.resize(V);
            predecessor.resize(V);
            source=0;
        }
        int GetGraphV(){return number_of_V;}
        void AddAdjItem(int u, int v, int w){
            AdjEdgeItem item(v,w);
            adj[u].push_back(item);
        }
        void PrintGraph();
        void DFSTree();
        void DFS(int v, string *arr);
        void PrintOrder();
        void InitializeSingleSource(int s);
        void Relax(int u, int v, int w);
        void DagShortestPath(int s);
        void PrintShortestPath();
        void PrintPathTo(int v);
        void SetSource(int s){source = s;}
        int GetSource(){return source;}
        int GetNumberOfEdge();
    
    private:
        int number_of_V;
        list<AdjEdgeItem> *adj;
        vector<int> order;
        vector<int> predecessor;
        vector<int> distance;
        int source;
};

Graph GetGraphFromFile(string name);
void PrintError();



#endif
