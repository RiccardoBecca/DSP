#include"DSG.h"
//#include"graph_generator.h"

using namespace std;

int main(int argc, char *argv[]){
    
    if(argc!=2){
        PrintError();
        return 1;
    }
    
    cout << endl;
    cout << "===============================" << endl;
    cout << "==     DAG-SORTEST-PATH      ==" << endl;
    cout << "==     Riccardo Beccaria     ==" << endl;
    cout << "==     SDA September 2022    ==" << endl;
    cout << "===============================" << endl << endl;
    
    cout << "This algorithm generates a Directed Acyclic Graph (DAG) from the file input.dat and calculate the shortest path from a source s" << endl;
    cout << "Here you are the graph loaded from input.dat" << endl << endl;

    int s,v;
    Graph g = GetGraphFromFile(argv[1]);
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


