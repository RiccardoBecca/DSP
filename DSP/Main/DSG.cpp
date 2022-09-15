#include"DSG.h"
#include<string>
#include<fstream>

#define INF INT_MAX
#define MAX_DISTANCE 1000

using namespace std;

void Graph::DFSTree(){
    string visited[this->GetGraphV()];
    for(int j=0; j< this->GetGraphV(); j++){
        visited[j]="white";
    }
    for(int v=0; v<this->GetGraphV(); v++){
        if(visited[v]=="white"){
            DFS(v, visited);
        }
    }
}

void Graph::DFS(int v, string *visited){
    visited[v] = "gray";
    list<AdjEdgeItem>::iterator it;
    for (it = adj[v].begin(); it != adj[v].end(); ++it){
        if (visited[it->GetAdj()]=="white"){
            DFS(it->GetAdj(), visited);
        }
    }
    visited[v] = "black";
    order.push_back(v);

}

void Graph::PrintOrder(){
    for(int t=0; t<order.size(); t++){
        cout << order[this->GetGraphV() - t -1] << '\t';
    }
    cout << endl;
}

void Graph::InitializeSingleSource(int s){
    for(int v=0; v<this->GetGraphV(); v++){
        distance[v]=MAX_DISTANCE;
        predecessor[v]=INT_MAX;
    }
    distance[s]=0;
}

void Graph::Relax(int u, int v, int w){
    if(distance[v]>(distance[u]+w)){
        distance[v]=distance[u]+w;
        predecessor[v]=u;
    }
}

void Graph::DagShortestPath(int s){
    DFSTree();
    //this->PrintOrder(); uncomment if ypu want to see the order
    InitializeSingleSource(s);
    for(int t=0; t<order.size(); t++){
        int u = order[this->GetGraphV() - t -1];
        list<AdjEdgeItem>::iterator it;
        for (it = adj[u].begin(); it != adj[u].end(); ++it){
            Relax(u, it->GetAdj(), it->GetEdgeWeight());
        }
    }
}

void Graph::PrintShortestPath(){
    cout << "=== PREDECESSOR ===" << endl;
    for(int v=0; v<this->GetGraphV(); v++){
        if(predecessor[v]==INT_MAX) cout << "Node: " << v << "; predecessor: ---" << endl;
        else cout << "Node: " << v << "; predecessor: " << predecessor[v] << endl;
        
    }
    
    cout << endl << "==== DISTANCE =====" << endl;
    for(int v=0; v<this->GetGraphV(); v++){
        if(distance[v]== MAX_DISTANCE) cout << "Node: " << v << "; distance: ---" <<  endl;
        else cout << "Node: " << v << "; distance: " << distance[v] << endl;
    }
    cout << endl;
}

void Graph::PrintGraph(){
    for(int v=0; v<this->GetGraphV(); v++){
        cout << "Node: " << v << " Neighbors: ";
        list<AdjEdgeItem>::iterator it;
        for (it = adj[v].begin(); it != adj[v].end(); ++it){
            cout << it->GetAdj() << " (" << it->GetEdgeWeight() << "); ";
        }
        cout << endl;
    }
}

void Graph::PrintPathTo(int v){
    if(distance[v]==MAX_DISTANCE){
        cout << endl << "There is not a path from source " << this->GetSource() << " to vertex " << v << endl << endl;
    }
    else{
        cout << "Distance from the source: " << distance[v] << endl;
        bool flag = false;
        cout << "Path: " << v ;
        while(flag == false){
            int u = predecessor[v];
            if(u==this->GetSource()){ //change 0 in source
                flag = true;
            }
            v=u;
            cout <<" <- " << u;
        }
        cout << endl << endl;
    }
}

int Graph::GetNumberOfEdge(){
    int e=0;
    for(int v=0; v<this->GetGraphV(); v++){
        list<AdjEdgeItem>::iterator it;
        for (it = adj[v].begin(); it != adj[v].end(); ++it){
            e=e+1;
        }
    }
    return e;
}

Graph GetGraphFromFile(string name){
    ifstream myfile;
    myfile.open(name);
    int u,v,w,s;
    myfile >> s;
    Graph g(s);
    while(true){
        myfile >> u >> v >> w;
        if( myfile.eof() ) break;
        g.AddAdjItem(u, v, w);
    }
    return g;
}

void PrintError(){
    cout << endl << "BE CAREFUL: ./main.exe name_of_file" << endl;
    cout << "This programme requires the file's name from which you want to upload the graph" << endl;
    cout << "In the first row of name_of_file there must be the graph's number of nodes. All the others line are in the form" << endl;
    cout << "u v w" << endl;
    cout << "Where u and v represent the connection edge (u,c) with w weight" << endl << endl;
}
