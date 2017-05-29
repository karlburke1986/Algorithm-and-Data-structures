//x00115288
//Karl Burke

#include <iostream>
#define nodes 8
using namespace std;

void dijkstraSingleNode(int[nodes][nodes], int, int);
void dijkstraEveryNode(int[nodes][nodes], int);
int minDistance(int distance[], bool included[]);
char positionToLetter(int);
void printShortest(int[], int);


int main()
{
	int graph[nodes][nodes] = {
			  //A  B  C  D  E  F  G  H
		/*A */ {0, 6, 0, 8, 4, 0, 0, 0},
		/*B */ {6, 0, 6, 0, 2, 4, 0, 1},
		/*C */ {0, 6, 0, 0, 0, 0, 3, 0},
		/*D */ {8, 0, 0, 0, 0, 0, 7, 0},
		/*E */ {4, 2, 0, 0, 0, 0, 0, 0},
		/*F */ {0, 4, 0, 0, 0, 0, 5, 3},
		/*G */ {0, 0, 3, 7, 0, 5, 0, 0},
		/*H */ {0, 1, 0, 0, 0, 3, 0, 0} };	

	
	dijkstraEveryNode(graph, 0);
	
	dijkstraSingleNode(graph, 0, 3);

	dijkstraSingleNode(graph, 2, 4);

	dijkstraSingleNode(graph, 1, 6);

	system("PAUSE");

	return 0;
}

/***************************************************************************************

*    Usage: Modified
*    Title: Greedy Algorithms | Set 7 (Dijkstra's shortest path algorithm)
*    Author: N/A
*    Date: 5/05/2017
*    Code version: N/A
*    Availability: http://www.geeksforgeeks.org/greedy-algorithms-set-6-dijkstras-shortest-path-algorithm/
*
***************************************************************************************/


void dijkstraEveryNode(int graph[nodes][nodes], int start)
{
	int distance[nodes];

	bool included[nodes];

	for (int i = 0; i < nodes; i++)
	{
		distance[i] = INT_MAX;
		included[i] = false;
	}

	distance[start] = 0;

	for (int count = 0; count < nodes - 1; count++)
	{
		int u = minDistance(distance, included);
		included[u] = true;

		for (int v = 0; v < nodes; v++)
		{
			if (!included[v] && graph[u][v] && distance[u] != INT_MAX && distance[u]
				+ graph[u][v] < distance[v])
			{
				distance[v] = distance[u] + graph[u][v];
			}
		}
	}

	printShortest(distance, start);
}

/***************************************************************************************

*    Usage: Modified
*    Title: Greedy Algorithms | Set 7 (Dijkstra's shortest path algorithm)
*    Author: N/A
*    Date: 5/05/2017
*    Code version: N/A
*    Availability: http://www.geeksforgeeks.org/greedy-algorithms-set-6-dijkstras-shortest-path-algorithm/
*
***************************************************************************************/

void dijkstraSingleNode(int graph[nodes][nodes], int start, int finish)
{
	int distance[nodes];

	bool included[nodes];

	for (int i = 0; i < nodes; i++)
	{
		distance[i] = INT_MAX;
		included[i] = false;
	}

	distance[start] = 0;

	for (int count = 0; count < nodes - 1; count++)
	{
		int u = minDistance(distance, included);
		included[u] = true;

		for (int v = 0; v < nodes; v++)
		{
			if (!included[v] && graph[u][v] && distance[u] != INT_MAX && distance[u]
				+graph[u][v] < distance[v])
			{
				distance[v] = distance[u] + graph[u][v];
			}
		}
	}

	cout << "The shorest path from " << positionToLetter(start) << " to " << positionToLetter(finish)
		<< " is " << distance[finish] << endl;
}

/***************************************************************************************

*    Usage: Modified
*    Title: Greedy Algorithms | Set 7 (Dijkstra's shortest path algorithm)
*    Author: N/A
*    Date: 5/05/2017
*    Code version: N/A
*    Availability: http://www.geeksforgeeks.org/greedy-algorithms-set-6-dijkstras-shortest-path-algorithm/
*
***************************************************************************************/

int minDistance(int distance[], bool included[])
{
	int min = INT_MAX, min_index;

	for (int i = 0; i < nodes; i++)
	{
		if (included[i] == false && distance[i] <= min)
		{
			min = distance[i], min_index = i;
		}
	}

	return min_index;
}

char positionToLetter(int value)
{
	if (value >= 0 && value <= 7)
	{
		char letters[8] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };

		return letters[value];
	}
	return 'z';
}

/***************************************************************************************

*    Usage: Used
*    Title: Greedy Algorithms | Set 7 (Dijkstra's shortest path algorithm)
*    Author: N/A
*    Date: 5/05/2017
*    Code version: N/A
*    Availability: http://www.geeksforgeeks.org/greedy-algorithms-set-6-dijkstras-shortest-path-algorithm/
*
***************************************************************************************/

void printShortest(int distance[], int start)
{
	printf("Vertex   Distance from Source\n");
	for (int i = 0; i < 8; i++)
	{
		cout << positionToLetter(i) << " shortest path " << distance[i] << endl;
	}
		
}
