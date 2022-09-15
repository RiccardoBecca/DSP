#include"graph_generator.h"

Node::Node(unint _value)
    : value(_value) {}

DAG::DAG(int size)
{
    noNodes = size;

    nodes.resize(noNodes);
    int i, j;

    initializeNodes(0, noNodes-1);
    for(i = 0; i < noNodes-1; i++)
    {
        for(j = i+1; j < noNodes; j++)
        {
            if(isPowerOf2(i ^ j))
            {
                nodes[i]->neighbors.push_back(nodes[j]);
                nodes[j]->neighbourTo.push_back(nodes[i]);
            }
        }
    }
}
void DAG::initializeNodes(int min, int max)
{
    if(max == min)
        nodes[max] = new Node(max);
    else
    {
        int s = (max + min)/2;
        initializeNodes(min, s);
        initializeNodes(s+1, max);
    }
}
int DAG::isPowerOf2(unsigned int value)
{
    return ((value != 0) && !(value & (value - 1)));
}
int DAG::getMaxNaighbourTo(int index)
{
    if(index > 0 && index <= (noNodes-1))
    {
        int size = nodes[index]->neighbourTo.size();
        return nodes[index]->neighbourTo[size-1]->value;
    }
    return -1;
}
int DAG::getMinNeighbor(int index)
{
    if(index >= 0 && index < (noNodes-1))
        return nodes[index]->neighbors[0]->value;
    return -1;
}
int DAG::numberOfPathsLengthK(int K)
{
    if(K <= 0)
        return 0;
    long int paths = 0;
    for(int i = 0; i < nodes.size(); i++)
    {
        paths += recursion(*nodes[i], K - 1);
    }
    return (paths % 100003);
}
int DAG::recursion(Node& node, int K)
{
    if( K <= 0 )
        return node.neighbors.size();
    else
    {
        long int paths = 0;
        for(int i = 0; i < node.neighbors.size(); i++)
        {
            paths += recursion(*node.neighbors[i], K - 1);
        }
        return paths;
    }
}
void DAG::print()
{
    for(int i = 0; i < nodes.size(); i++)
    {
        cout << "Node: " << nodes[i]->value << "\tNeighbors: ";
        for(int j = 0; j < nodes[i]->neighbors.size(); j++)
        {
            cout << nodes[i]->neighbors[j]->value << " ";
        }
        cout << endl;
    }
}

void DAG::print2()
{
    cout << "Graph g(" << nodes.size() << ");" << endl;
    for(int i = 0; i < nodes.size(); i++)
    {
        for(int j = 0; j < nodes[i]->neighbors.size(); j++)
        {
            int random_integer = rand()%11;
            //cout << nodes[i]->neighbors[j]->value << " ";
            cout << "g.AddAdjItem(" << nodes[i]->value << ", " << nodes[i]->neighbors[j]->value << ", " << random_integer << ");" << endl;
        }
    }
}


void DAG::InsertGraph(Graph *g){
    for(int i = 0; i < nodes.size(); i++)
    {
        for(int j = 0; j < nodes[i]->neighbors.size(); j++)
        {
            int random_integer = rand()%10 +1;
            g->AddAdjItem(nodes[i]->value, nodes[i]->neighbors[j]->value, random_integer);
        }
    }

}


Graph ProduceGraph(int e){
    
    Graph g(e);
    DAG graf(e);
    Graph* ptr =&g;
    graf.InsertGraph(ptr);
    //graf.print();
    
    return g;
}

