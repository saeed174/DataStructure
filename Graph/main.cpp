#include <iostream>
#include <queue>
#include <stack>
using namespace std;

#define inf INT_MAX

void BFS(int i , int arr[7][7]) // As tree level_order
{
    queue<int> q;
    vector<int> visited(7,0);
    cout << i << " ";
    visited[i] = 1;
    q.push(i);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int v = 1 ; v <= 6 ; v++)
        {
            if(arr[u][v] == 1 && visited[v] == 0)
            {
                cout << v << " ";
                visited[v] = 1;
                q.push(v);
            }
        }
    }
    cout << "\n";
}

vector<int> D_visited(7,0);
void DFS(int i , int arr[7][7]) // As trees pre_order
{
    int u = i;
    if(D_visited[u] == 0)
    {
        cout << u << " ";
        D_visited[u] = 1;
        for(int v = 1 ; v <= 6 ; v++)
        {
            if(arr[u][v] == 1 && D_visited[v] == 0)
            {
                DFS(v,arr);
            }
        }
    }
}


void prims(int arr[8][8])
{
    int mn = inf;
    int u = 0;
    int v = 0;

    for(int i = 1 ; i < 8 ; i++)
    {
        for(int j = 1 ; j < 8 ; j++)
        {
            if(arr[i][j] < mn)
            {
                mn = arr[i][j];
                u = i; v = j;
            }
        }
    }

    int spanning[2][8-2] = {};
    int near[8] = {inf,inf,inf,inf,inf,inf,inf,inf};

    spanning[0][0] = u ;  spanning[1][0] = v;
    near[u] = 0; near[v] = 0;

    for(int i = 1 ; i < 8 ; i++)
    {
        if(near[i] != 0)
        {
            if(arr[i][u] < arr[i][v])
                near[i] = u;
            else
                near[i] = v;
        }
    }

    for(int i = 1 ; i < 8-2 ; i++)
    {
        int mini = inf;
        int k = 0;
        for(int j = 1 ; j < 8 ; j++)
        {
            if(near[j] != 0 && arr[j][near[j]] < mini)
            {
                mini = arr[j][near[j]];
                k = j;
            }
        }

        spanning[0][i] = k ; spanning[1][i] = near[k];
        near[k] = 0;

        for(int j = 1 ; j < 8 ; j++)
        {
            if(near[j] != 0 && arr[j][k] < arr[j][near[j]])
                near[j] = k;
        }
    }

    cout << "The minimal cost spanning tree is : \n";
    for(int i = 0 ; i < 6 ; i++)
    {
        cout << "(" << spanning[0][i] << "," << spanning[1][i] << ")" << "\n";
    }
}

int find_parent(int u , int arr[])
{
    int x = u;
    while (arr[x] > 0)
    {
        x = arr[x];
    }
    return x;
}

void unioon(int u , int v , int arr[])
{
    if(arr[u] < arr[v])
    {
        arr[u] = arr[u]+arr[v];
        arr[v] = u;
    }
    else
    {
        arr[v] = arr[u]+arr[v];
        arr[u] = v;
    }
}

void krukals(int arr[3][9])
{
    int set[8] = {-1,-1,-1,-1,-1,-1,-1,-1};
    int include[9] = {0};
    int spanning[2][6] = {0};

    int i = 0 , k = 0 , u = 0 , v = 0;

    while(i < 6)
    {
        int mn = inf;
        for(int j = 0 ; j < 9 ; j++)
        {
            if(include[j] == 0 && arr[2][j] < mn)
            {
                mn = arr[2][j];
                k = j; u = arr[0][j] ; v = arr[1][j];
            }
        }

        if(find_parent(u,set) != find_parent(v,set))
        {
            spanning[0][i] = u ; spanning[1][i] = v;
            i++; 
            unioon(find_parent(u,set),find_parent(v,set),set);
        }
        include[k] = 1;
    }

    cout << "The minimal cost spanning tree is : \n";
    for(int i = 0 ; i < 6 ; i++)
    {
        cout << "(" << spanning[0][i] << "," << spanning[1][i] << ")" << "\n";
    }
}

int main()
{
    
    static int adjacency_matrix[7][7] = {
        {0,0,0,0,0,0,0},
        {0,0,1,1,0,0,0},
        {0,1,0,0,1,0,0},
        {0,1,0,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0},
    };

    // for(int i = 1 ; i <= 6 ; i++)
    // {
    //     cout << "Enter all adjacent of vertices " << i << " and end with -1 value : \n";
    //     int add;
    //     cin >> add;
    //     while(add != -1)
    //     {
    //         adjacency_matrix[i][add] = 1;
    //         cin >> add;
    //     }
    // }

    BFS(3,adjacency_matrix);
    DFS(4,adjacency_matrix);
    cout << "\n";

// ==================================================

    int cost_adjacency_matrix[8][8] = {
        {inf,inf,inf,inf,inf,inf,inf,inf},
        {inf,inf,25,inf,inf,inf,5,inf},
        {inf,25,inf,12,inf,inf,inf,10},
        {inf,inf,12,inf,8,inf,inf,inf},
        {inf,inf,inf,8,inf,16,inf,14},
        {inf,inf,inf,inf,16,inf,20,18},
        {inf,inf,inf,inf,inf,20,inf,inf},
        {inf,inf,10,inf,14,18,inf,inf}
    };

    prims(cost_adjacency_matrix);

// ==================================================

    int edges[3][9] = {
        {1,1,2,2,3,4,4,5,5},
        {2,6,3,7,4,5,7,6,7},
        {25,5,12,10,8,16,14,20,18}
    };

    krukals(edges);

    return 0;
}