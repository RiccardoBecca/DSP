#include <math.h>
#include "DSG.h"
typedef unsigned int unint;
using namespace std;

class Node
{
    friend class DAG;
private:
    unint value;
    vector<Node* > neighbourTo;
    vector<Node* > neighbors;
public:
    Node(unint );
};

class DAG
{
private:
    int noNodes;
    vector<Node* > nodes;
public:
    DAG(int );
    void initializeNodes(int ,int );
    int isPowerOf2(unsigned int );
    int getMaxNaighbourTo(int );
    int getMinNeighbor(int );
    int numberOfPathsLengthK(int );
    int recursion(Node& , int );
    void print();
    void print2();
    void InsertGraph(Graph *g);
};

Graph ProduceGraph(int e);
