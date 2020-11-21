/*
问题：带权有向图G=(V, E), 顶点集V被划分k(k > 2)为个不相交的子集，其中V_1和V_k分别只有一个顶点s（源）和一个顶点t（汇），所有的边(u,v)的始点和终点都在相邻的两个子集V_i和V_i+1中, 且边(u,v)有一个正权重，记为w(u,v).求解从源s到汇t的权重之和最小的路径。

输入：包含多组测试数据。每组测试数据第一行输入正整数k(k < 100), 表示不相交子集的数目。第二行包含k个正整数n_i(1 <= i <= k), 分别表示每一个顶点集V_i(1 <= i <= k)中顶点的数目（不超过100）。紧接着k-1行记录相邻顶点集合间边的权重。其第i(1 <= i < k)行包含n_i * n_i+1个数，表示顶点集V_i和V_i+1之间的边的权重（-1表示没有边相连），权重矩阵按行排列，也就是V_i中第p（1 <= p < ni)个顶点和Vj中第q(1 <= q < n_i)个顶点之间的权重对应行第(p-1)*n_j+q和位置的值。最后一行输入-1，表示输入结束。

输出：每组测试数据的结果输出占一行，输出其最小的权重值。

样例输入：
5
1 4 3 3 1
9 7 3 2
4 2 1 2 7 -1 -1 -1 11 -1 11 8
6 5 -1 4 3 -1 -1 5 6
4 2 5 
-1
*/ 

#include <iostream> 
#include <vector>

#define MaxState 101

using namespace std;
int minRoad[MaxState][MaxState];

void multiStageGraph(int stageNum, int* numPerStage) {
    int i, q, p, weight, temp;
    memset(minRoad, 0x3f, sizeof(minRoad));           //初始化为一个充分大的数0x3f
 
    for (p = 0; p < numPerStage[0]; ++p) {
        minRoad[0][p] = 0;
    }
 
    for (i = 0; i < stageNum - 1; ++i)                //按段计算，终止与汇顶点的前一段
    {
        for (q = 0; q < numPerStage[i]; ++q)          //遍历第i段顶点
        {
            for (p = 0; p < numPerStage[i + 1]; ++p)  //遍历第i+1段顶点
            {
                scanf("%d", &weight);                 //读取边(q,p)的权重w(q,p)
                if (weight != -1)                     //存在边(q,p)
                {
                    temp = minRoad[i][q] + weight;
                    if (temp < minRoad[i+1][p])       //发现s到o的更短路径
                    {
                        minRoad[i+1][p] = temp;
                    }
                }
            }
        }
    }
    printf("%d\n", minRoad[stageNum-1][0]);
}

int main() {
    int i, k, ni[MaxState];
    int k;
    cin >> k;
    vector<int> stage(k, 0);
    for (int i = 0; i < k; ++i) {
	cin >> n[i];
	getMinPath(k, n);
    }
    while(scanf("%d", &k), k != -1) {
        for(i = 0; i < k; ++i) {
            scanf("%d", &ni[i]);
        }
        multiStageGraph(k, ni);
    }
    return 0;
}
 

