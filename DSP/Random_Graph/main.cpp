#include"DSG.h"
#include"graph_generator.h"

using namespace std;

int main(){
    
    cout << endl;
    cout << "===============================" << endl;
    cout << "==     DAG-SORTEST-PATH      ==" << endl;
    cout << "==     Riccardo Beccaria     ==" << endl;
    cout << "==     SDA September 2022    ==" << endl;
    cout << "===============================" << endl << endl;
    
    cout << "This algorithm generates a random Directed Acyclic Graph (DAG) and calculate the shortest path from a source s" << endl;
    
    int e,s,v;
    cout << "Tell me number of Vertex for the Random DAG: " << endl;
    cin >> e;
    
    Graph g = ProduceGraph(e);
    cout << endl << "So There it is the Random DAG generated. The notation is:"<< endl;
    cout << "Node v: u (w(v,u)): ..." << '\t' << "where u is v neighbour and w(u,v) is the weight of the edge (v,u)." << endl << endl;
    g.PrintGraph();
    cout << endl << "Tell the source's node number: " << endl;
    cin >> s;
    g.SetSource(s);
    g.DagShortestPath(s);
    
    cout << endl << "Shortest Path is given in term of Predecessor and Distance of every node from its predecessor"<< endl;
    cout << "If for a vertex u, its predecessor and its distance from predecessor is '---' means no path from source to u exists" << endl << endl;
    g.PrintShortestPath();
    
    cout << endl << "Tell me the vertex v of which you wanna print distance and shortest path from source s" << endl;
    cin >> v;
    
    g.PrintPathTo(v);
     
    return 0;
}


