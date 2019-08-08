using namespace std;
struct Edge
{
    int src;
    int dest;
    int weight;
    
    Edge(int s, int d, int w)
    {
        src = s;
        dest = d;
        weight =w;
    }
};

class Graph{
public:
    int V;
    int E;
    vector<Edge> edge;
    
    int index =0;
public:
    Graph(int V, int E)
    {
        this->V = V;
        this->E = E;
    }
    
    int getNoOfEdges(){
        return E;
    }
    static bool comp(Edge e1, Edge e2)
    {
        return e1.weight < e2.weight;
    }
   void AddEdge(int s, int d, int w)
    {
        edge.push_back(Edge(s,d,w));
    }
    void Sort()
    {
        std::sort(edge.begin(), edge.end(), comp);
    }

    
    vector<Edge>& GetEdgeList()
    {
        return edge;
    }
};

class UnionFind{
public:
    int Find(int set[], int s)
    {
        if(set[s] == -1)
            return s;
        return Find(set, set[s]);
    }
    
    void Union(int set[], int s, int d)
    {
        int x = Find(set, s);
        
        set[x] = d;
    }
    
    
};

void Kruskal(Graph *g)
{
    g->Sort();
    
    vector<Edge> el = g->GetEdgeList();
    
    int arr[g->getNoOfEdges()];
    memset(arr, -1, sizeof(int) * g->getNoOfEdges());
    
    UnionFind uf;
    for(auto e : el)
    {
        int x = uf.Find(arr, e.src);
        int y = uf.Find(arr, e.dest);
        
        if(x != y)
        {
            uf.Union(arr, e.src, e.dest);
            cout<<e.src<<"-->"<<e.dest<<"\n";
        }
    }
    
}

int main()
{
    Graph* graph = new Graph(4, 5);
    
    graph->AddEdge(0, 0, 10);

    
    // add edge 0-2
    graph->AddEdge(0, 2, 16);

    
    // add edge 0-3
    graph->AddEdge(0, 3, 15);

    
    // add edge 1-3
    graph->AddEdge(1, 3, 15);

    
    // add edge 2-3
   graph->AddEdge(2, 3, 4);
    
    Kruskal(graph);
}
