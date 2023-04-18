#include <iostream>
using namespace std;

struct Vertex
{
	int number;
	Vertex* next;
};
struct Edge
{
	int start, end;
};
class ListGraph
{
private:
	int num_nodes;

public:
	Vertex** head;
	ListGraph(Edge _edges[], int knot, int rib)
	{
		head = new Vertex * [knot]();
		this->num_nodes = knot;
		for (int i = 0; i < num_nodes; i++)
		{
			head[i] = nullptr;
		}
		for (unsigned i = 0; i < rib; i++)
		{
			int start = _edges[i].start;
			int end = _edges[i].end;
			Vertex* newNode = new Vertex;
			newNode->number = end;
			head[start] = newNode;
		}
	};
};
void printList(Vertex* ptr)
{
	while (ptr != nullptr)
	{
		cout << " -> " << ptr->number;
		ptr = ptr->next;
	}
	cout << endl;
}
int main()
{
    // массив ребер Graph согласно схеме выше
    Edge edges[] =
    {
        // пара {x, y} представляет ребро от `x` до `y`
        {0, 1}, {1, 2}, {2, 0}, {2, 1}, {3, 2}, {4, 5}, {5, 4}
    };

    // общее количество узлов в Graph (от 0 до 5)
    int N = 6;

    // вычисляем общее количество ребер
    int n = sizeof(edges) / sizeof(edges[0]);

    // построить Graph
    ListGraph graph(edges, n, N);

    // вывести представление списка смежности Graph
    for (int i = 0; i < N; i++)
    {
        // печатаем заданную вершину
        cout << i;

        // печатаем все его соседние вершины
        printList(graph.head[i]);
    }

    return 0;
}
// Структура данных для хранения узлов списка смежности
//struct Vertex
//{
//    int val;
//    Vertex* next;
//};
//
//// Структура данных для хранения ребра Graph
//struct Edge {
//    int src, dest;
//};
//
//class Graph
//{
//    // Функция выделения нового узла для списка смежности
//    Vertex* getAdjListNode(int dest, Vertex* head)
//    {
//        Vertex* newNode = new Vertex;
//        newNode->val = dest;
//
//        // указываем новый узел на текущую голову
//        newNode->next = head;
//
//        return newNode;
//    }
//
//    int N;    // общее количество узлов в Graph
//
//public:
//
//    // Массив указателей на Node для представления
//    // список смежности
//    Vertex** head;
//
//    // Конструктор
//    Graph(Edge edges[], int n, int N)
//    {
//        // выделить память
//        head = new Vertex * [N]();
//        this->N = N;
//
//        // инициализируем головной указатель для всех вершин
//        for (int i = 0; i < N; i++) {
//            head[i] = nullptr;
//        }
//
//        // добавляем ребра в ориентированный graph
//        for (unsigned i = 0; i < n; i++)
//        {
//            int src = edges[i].src;
//            int dest = edges[i].dest;
//
//            // вставляем в начало
//            Vertex* newNode = getAdjListNode(dest, head[src]);
//
//            // указываем головной указатель на новый узел
//            head[src] = newNode;
//
//            // раскомментируйте следующий код для неориентированного Graph
//
//            /*
//            newNode = getAdjListNode(src, head[dest]);
//
//            // изменяем указатель головы, чтобы он указывал на новый узел
//            head[dest] = newNode;
//            */
//        }
//    }
//
//    // Деструктор
//    ~Graph() {
//        for (int i = 0; i < N; i++) {
//            delete[] head[i];
//        }
//
//        delete[] head;
//    }
//};
//
//// Функция для печати всех соседних вершин данной вершины
//void printList(Vertex* ptr)
//{
//    while (ptr != nullptr)
//    {
//        cout << " -> " << ptr->val;
//        ptr = ptr->next;
//    }
//    cout << endl;
//}
//
//// Реализация Graph на C++ без использования STL
//int main()
//{
//    // массив ребер Graph согласно схеме выше
//    Edge edges[] =
//    {
//        // пара {x, y} представляет ребро от `x` до `y`
//        {0, 1}, {1, 2}, {2, 0}, {2, 1}, {3, 2}, {4, 5}, {5, 4}
//    };
//
//    // общее количество узлов в Graph (от 0 до 5)
//    int N = 6;
//
//    // вычисляем общее количество ребер
//    int n = sizeof(edges) / sizeof(edges[0]);
//
//    // построить Graph
//    Graph graph(edges, n, N);
//
//    // вывести представление списка смежности Graph
//    for (int i = 0; i < N; i++)
//    {
//        // печатаем заданную вершину
//        cout << i;
//
//        // печатаем все его соседние вершины
//        printList(graph.head[i]);
//    }
//
//    return 0;
//}