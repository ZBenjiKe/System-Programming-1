#include <stdio.h>
#include <limits.h>
#include "my_mat.h"

#define V 10

void printMatrix(int matrix[V][V]){
    for(int i=0; i<V;i++){
        for(int j=0; j<V;j++){
            if(matrix[i][j] == INT_MAX){
                printf("- ");
            } else {
                printf("%d ", matrix[i][j]);
            }
        }
        printf("\n");
    }
}

void createMatrix(int matrix[V][V]){
	int x;
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			scanf("%d", &x);
			matrix[i][j] = x;
		}
	}
}

int shortestPath(int a, int b, int matrix[V][V]){
		
	// create distance matrix
	int dis[V][V];
	
	// change all non-exsisting edges to be infinity
	for(int i = 0; i < V; i++){
		for (int j = 0; j < V; j++){
			if((i != j) && (matrix[i][j] == 0)){
				dis[i][j] = INT_MAX;
			} else {
				dis[i][j] = matrix[i][j];
			}
		}
	}
	
	// update distance from node i to node j:
	// if there is an edge from i to j, and it has a smaller value than going from i to j through k (assuming that exsists as well)
	// keep that value; otherwise, update the value in dis[i][j] to be the route through k.
	for(int k = 0; k < V; k++){
		for(int i = 0; i < V; i++){
			for(int j = 0; j < V; j++){
				if((dis[i][k] != INT_MAX) && (dis[k][j] != INT_MAX) &&
				(dis[i][j] > dis[i][k] + dis[k][j])){
	    				dis[i][j] = dis[i][k] + dis[k][j];
    			}
			}
		}
	}
	return (((dis[a][b] == INT_MAX) || (dis[a][b] == 0)) ? -1 : dis[a][b]);
}

void isConnected(int a, int b, int matrix[V][V]){
	int dist = shortestPath(a, b, matrix);
	if(dist != -1){
		printf("True");
	} else {
		printf("False");
	}
}


int main() {
    
    int matrix[V][V] = {{ 0, 3, 1, 0, 0, 2, 0, 0, 0, 0},
						{ 3, 0, 1, 0, 0, 0, 0, 0, 0, 0},
						{ 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
						{ 0, 0, 0, 0, 0, 0, 0, 5, 0, 0},
						{ 0, 0, 0, 0, 0, 0, 0, 4, 1, 1},
						{ 2, 0, 0, 0, 0, 0, 2, 0, 0, 0},
						{ 0, 0, 0, 0, 0, 2, 0, 0, 0, 0},
						{ 0, 0, 0, 5, 4, 0, 0, 0, 0, 2},
						{ 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
						{ 0, 0, 0, 0, 1, 0, 0, 2, 0, 0}};
	
    printf("%d", shortestPath(1, 1, matrix));

    return 0;
}
