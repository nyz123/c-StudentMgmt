#include <stdio.h>
#define MAX_VERTEX_NUM 10;

typedef struct {
	int arcs[10][10];//弧权重 
	int vexnum,arcnum;
}Graph;//无向图定义 

typedef struct {
	int adjvex;
	int lowcost;//最近距离 
}closedge[10];

int mininum(closedge a,int num){//MIN
	int i,k;
	int min;
	
	for(i=0;i<num;i++){
		if(a[i].lowcost!=0){
			min=a[i].lowcost;
			k=i;
			break;
		}
	}
	for(i=0;i<num;i++){
		if(a[i].lowcost!=0&&a[i].lowcost<min){
			min=a[i].lowcost;
			k=i;
		}	
	}	
	printf("the next min arc is:%d\n",min); 
	return k;
}
void Prim(Graph G,int u){
	//用普利姆算法从第u个顶点出发构造网G的最小生成树T，输出T的各条边。
	//记录从顶点集u到v-u的代价最小的边的辅助数组定义
	closedge close;
	int i,j,k,m;
	for(j=0;j<G.vexnum;j++){
		if(j!=u){
			close[j].adjvex=u;
			close[j].lowcost=G.arcs[u][j];
		}	
	}
	close[u].adjvex=u;
	close[u].lowcost=0;

	printf("***************************************\n");


	for(i=1;i<G.vexnum;i++){
		k=mininum(close,G.vexnum);//求出最小的权重 
	
		m=close[k].adjvex;
		printf("the arc is:(%d,%d) weight=%d\n",m,k,G.arcs[m][k]);//输出边
	
		close[k].lowcost=0;	
		for(j=0;j<G.vexnum;j++){
			if(G.arcs[k][j]<close[j].lowcost){
				close[j].adjvex=k;
				close[j].lowcost=G.arcs[k][j];
			}
		}
	}
		printf("***************************************\n");
}
int main()
{
	Graph G;
	int i,j,m,n,adj,vexnum,arcnum;
	printf("\n\n***********谢冬丽的prime程序**********\n",vexnum-1);
	printf("please input vexnum:");
	scanf("%d",&vexnum);
	printf("please input arcnum:");
	scanf("%d",&arcnum);
	printf("\n\n***********[vertex from 0-%d]**********\n",vexnum-1);
	G.vexnum=vexnum;
	G.arcnum=arcnum;
	//初始化图
	for(i=0;i<G.vexnum;i++){
	for(j=0;j<G.vexnum;j++)
		G.arcs[i][j]=100;
	}
	for(i=0;i<arcnum;i++){
		printf("please input arc and adj(i j adj):\n");
		scanf("%d",&m);	scanf("%d",&n);	scanf("%d",&adj);
		getchar();
		if(m>=G.vexnum||n>=G.vexnum)
			printf("ERROR!");
		else {
			G.arcs[m][n]=adj;
			G.arcs[n][m]=adj;
		}
	} 
	printf("***************************************\n");
	printf("the graph matrix is:\n");
	for(i=0;i<G.vexnum;i++){
	 	for(j=0;j<G.vexnum;j++){
	 		printf("*%4d  ",G.arcs[i][j]);
		 } 
		 printf("\n");
 	} 
 	Prim(G,1);
	return 0;
}
