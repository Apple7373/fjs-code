#include <bits/stdc++.h>

using namespace std;
#define MaxVertexNum 100
typedef struct ArcNode{
    int adjvex;
    struct ArcNode* nextarc;
}ArcNode;

typedef struct VNode{
    ArcNode *firstarc;
}VNode, AdjList[MaxVertexNum];

int main()
{
    AdjList list;
    int a[100];
}