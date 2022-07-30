class Solution{
public:
    bool isPossible(int node, bool graph[101][101], int n, int clr, int color[]){
        for(int i=0; i<n; i++){
            //if node is adjacent with i and adj node's(i's) color 
            //is same as the color that we are try on node, return false
            if(i != node && graph[i][node] == 1 && color[i] == clr){
                return false;
            }
        }
        return true;
    }
    bool solve(int node, bool graph[101][101], int n, int m, int color[]){
        if(node == n){
            return true;
        }
        //try every color from 1 to m on curr node
        for(int clr=1; clr<=m; clr++){
            if(isPossible(node, graph, n, clr, color)){
                color[node] = clr;
                if(solve(node+1, graph, n, m, color)) return true;
                color[node] = 0;
            }
        }
        return false;
    }
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        int color[n] = {0};
        return solve(0, graph, n, m, color);
    }
};
