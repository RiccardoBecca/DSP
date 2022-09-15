#include"DSG.h"
#include"graph_generator.h"
#include <fstream>
#include <chrono>
#include <ctime>

using namespace std;

int main(int argc, char *argv[]){
    int t=atoi(argv[1]);
    int s=0;
    ofstream myfile;
    myfile.open("data.txt", ios_base::app);
    int arr[1] = {t};
    for(int e=0; e<1; e++){
        cout << "Initializing Graph with " << arr[e] << " nodes"<<endl;
        Graph g(arr[e]);
        for(int i=1; i< arr[e]; i++){
            for(int j=i+1;j<arr[e];j++){
                g.AddAdjItem(i, j, 1);
            }
        }
        int edge = g.GetNumberOfEdge();
        g.SetSource(s);
        
        auto start = chrono::system_clock::now();
        g.DagShortestPath(s);
        auto end = chrono::system_clock::now();
        chrono::duration<double> elapsed_seconds = end-start;
        time_t end_time = std::chrono::system_clock::to_time_t(end);


        cout << "finished computation at " << ctime(&end_time)
                  << "elapsed time: " << elapsed_seconds.count() << "s"
                  << endl << endl;
        myfile << arr[e] << " " << edge << " " << e+edge << " " << elapsed_seconds.count() << endl;
    }
    myfile.close();
    return 0;
}


