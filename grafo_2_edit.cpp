#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <windows.h>
#define MAX 8

struct stgraph{
	int color = 0;
	int flag = 0;
	int size =0;
	int incid;
};

int mat = 0;
struct stgraph graph[MAX][MAX];
int maxgraph(stgraph[MAX][MAX]);

int main(){	
	int color=0;
	int grafmax=0;
	int colormax=0;
	int mat=0;
	
	printf("Matrix size X,Y:");
	scanf("%d",&mat);
	
	for(int i=0;i<mat;i++){	
		for(int j=0;j<mat;j++){
			printf("Incidence in node %i:%i: ", i+1, j+1);
			scanf("%i", &graph[i][j].incid);
			if(graph[i][j].incid>0){
				graph[i][0].size = (graph[i][0].size)+1;
			}
		}
	}
	
	system("cls");
	for(int i=0;i<mat;i++){
		printf("Incidences %i: ", i+1);
		for(int j=0;j<mat;j++){
			printf("%d ", graph[i][j].incid);
		}
		printf("\n");
	}	
	printf("\nBigger incidence - Line: %d\n\n", maxgraph(graph));
				
	for(int i=0;i<mat;i++){
		grafmax = maxgraph(graph);			
		
		for(int j=0;j<mat;j++){
			if((graph[grafmax][0].color==graph[j][0].color)&&(graph[grafmax][j].incid>0)){
				color++;				
			}
		}
		graph[grafmax][0].color = color;
			
		if(color > colormax){
			colormax=color;
		}
		color=0;
	}		
	printf("\nNumber of colors needed to fill this graph:%d\n\n", colormax);
}

int maxgraph(stgraph[MAX][MAX]){
	int max=0,i; 	
	for(i=0;i<MAX;i++){
		if(((graph[i][0].size)>max)&&(graph[i][0].flag==0)){
			max = i+1;
			graph[i][0].flag = 1;
		}
	}
	return max;
}
