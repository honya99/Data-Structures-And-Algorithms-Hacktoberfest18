#include "my.h"
#define MAX_VERTICES 26
void breadthFirstSearch(Vertex* vertices[])
{
	Queue vertexQueue;
	Vertex* topVertex;
	Edge* nextEdge;
	vertexQueue.size = 0;

	printf("Breadth-First Search:\t");

	int i;
	for (i = 0; i < MAX_VERTICES; i++)
	{
		if (vertices[i]->letter == '?')
		{
			printf("%c", vertices[0]->letter);
			queueInsert(&vertexQueue, vertices[0]);
			break;
		}
		vertices[i]->isVisited = false;
	}
	while (vertexQueue.size != 0)
	{
		topVertex = queuePeekFront(&vertexQueue);
		nextEdge = topVertex->edges;

		while (nextEdge != NULL)
		{
			if (!nextEdge->connectingVertex->isVisited)
			{
				nextEdge->connectingVertex->isVisited = true;
				queueInsert(&vertexQueue, nextEdge->connectingVertex);
				printf("%c", nextEdge->connectingVertex->letter);
			}
			nextEdge = nextEdge->nextEdge;
		}
		queueGetFront(&vertexQueue);
	}
	printf("\n");
}
	
