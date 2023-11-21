#include<iostream>
#include<ctime>
#include<set>
#include<vector>
using namespace std;

int maximum = INT16_MAX;

struct Vertex {
	int visited;
	int weight;
	vector <pair <int, int>> neighbors;
};

typedef vector<Vertex> Graph;

int Deikstra(Graph graph, int vertex) {
	int counter = 0;
	set <pair<int, int>> s;
	s.insert(make_pair(0, vertex));
	while (!s.empty()) {
		pair<int, int> p = *(s.begin());
		counter++;
		s.erase(s.begin());
		counter++;
		if (graph[p.second].visited == 1) {
			counter++;
			continue;
		}
		graph[p.second].visited = 1;
		counter++;
		graph[p.second].weight = p.first;
		counter++;
		for (auto i = graph[p.second].neighbors.begin(); i != graph[p.second].neighbors.end(); ++i)
			if (graph[i->first].visited == 0) {
				s.insert(make_pair(graph[p.second].weight + (i->second), i->first));
				counter += 2;
			}
	}
	return counter;
}
Graph rand(int size)
{
	Graph graph;
	graph.resize(size);
	for (int i = 0; i < size; ++i) {
		for (int j = i + 1; j < size; j++) {
			int q = rand() % 5;
			if (q)
			{
				graph[i].neighbors.push_back(make_pair(j, q));
				graph[j].neighbors.push_back(make_pair(i, q));
			}
		}
	}
	for (int i = 0; i < size; ++i)
	{
		graph[i].visited = 0;
		graph[i].weight = maximum;
	}
	return graph;
}

Graph max(int size)
{
	Graph graph;
	graph.resize(size);
	for (int i = 0; i < size; ++i) {
		for (int j = i + 1; j < size; j++) {
			graph[i].neighbors.push_back(make_pair(j, 5));
			graph[j].neighbors.push_back(make_pair(i, 5));
		}
	}
	for (int i = 0; i < size; ++i)
	{
		graph[i].visited = 0;
		graph[i].weight = maximum;
	}
	return graph;
}
Graph min(int size) {
	Graph graph;
	graph.resize(size);
	for (int i = 0; i < size; ++i) {
		graph[i].visited = 0;
		graph[i].weight = maximum;
	}
	return graph;
}

void main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "ru");
	cout << "size|	" << "|Среднее значение|	" << "|Max|		" << "|Min|		" << endl;
	cout << "-----------------------------------------------------" << endl;
	for (int size = 5; size <= 30; size++) {
		int average = 0;
		for (int i = 0; i < 1000; i++)
			average += Deikstra(rand(size), rand() % size);

		cout << size << "|	|" << float(average) / 1000 <<"|		|"<< Deikstra(max(size), 0) << "|		|" << Deikstra(min(size), 0) << "|" << endl;
	}
	system("pause>nul");
}
