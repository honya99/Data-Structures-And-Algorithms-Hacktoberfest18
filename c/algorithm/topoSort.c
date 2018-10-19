#include "my.h"
#define MAX_VERTICES 26

void topoSort(Vertex* vertices[])
{
	char sortedVertices[MAX_VERTICES];
	int i;
	for (i = 0; i < MAX_VERTICES; i++)
	{
		sortedVertices[i] = '?';
	}

	printf("Topological Sort:\t");
	while (vertices[0]->edges != NULL)
	{
		for (i = 0; i < MAX_VERTICES; i++)
		{
			if (vertices[i]->letter == '?')
			{
				break;
			}
			if (vertices[i]->edges == NULL)
			{
				bool alreadyCounted = false;
				int j;
				for (j = 0; j < MAX_VERTICES; j++)
				{
					if (sortedVertices[j] == '?')
					{
						break;
					}
					if (sortedVertices[j] == vertices[i]->letter)
					{
						alreadyCounted = true;
						break;
					}
				}
				if (alreadyCounted)
				{
					continue;
				}
				for (j = 0; j < MAX_VERTICES; j++)
				{
					if (sortedVertices[j] == '?')
					{
						sortedVertices[j] = vertices[i]->letter;
						break;
					}
				}
				for (j = 0; j < MAX_VERTICES; j++)
				{
					if (vertices[j]->letter == '?')
					{
						break;
					}
					Edge** checkEdge = &(vertices[j]->edges);

					while ((*checkEdge) != NULL)
					{
						if ((*checkEdge)->connectingVertex->letter == vertices[i]->letter)
						{
							if ((*checkEdge)->nextEdge == NULL)
							{
								*checkEdge = NULL;
							}
							else
							{
								*checkEdge = (*checkEdge)->nextEdge;
							}
							break;
						}
						checkEdge = &((*checkEdge)->nextEdge);
					}
				}
			}
		}
	}
	for (i = 0; i < MAX_VERTICES; i++)
	{
		if (sortedVertices[i] == '?')
		{
			sortedVertices[i] = vertices[0]->letter;
			printf("%c", sortedVertices[i]);
			break;
		}
		printf("%c", sortedVertices[i]);
	}
	printf("\n");
}
