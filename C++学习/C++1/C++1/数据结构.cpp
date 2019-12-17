/*#include<iostream>
using namespace std;


class Graph<T>(private val vertices : ArrayList<Vertex<T>> = ArrayList(),
	private val adjacencyList : ArrayList<EdgeList<T>> = ArrayList()) {
	fun createVertex(value: T) : Vertex<T>{
		val matchingVertices = vertices.filter { it.data == value }

		if (matchingVertices.isNotEmpty()) {
			return matchingVertices.last()
		}

		val vertex = Vertex(value, adjacencyList.size)
		vertices.add(vertex)
		adjacencyList.add(EdgeList(vertex))
		return vertex
	}

		fun addDirectedEdge(fromVertex: Vertex<T>, toVertex : Vertex<T>, weightValue : Double) {
			val edge = Edge(from = fromVertex,
				to = toVertex,
				weight = weightValue)

				fromVertex.addEdge(edge)
				val fromIndex = vertices.indexOf(fromVertex)
				adjacencyList[fromIndex].edges.add(edge)
		}

		fun addUnDirectedEdge(fromVertex: Vertex<T>, toVertex : Vertex<T>, weightValue : Double = 0.0) {
			addDirectedEdge(fromVertex, toVertex, weightValue)
				addDirectedEdge(toVertex, fromVertex, weightValue)

		}

		fun printAdjacencyList() {
			(0 until vertices.size)
				.filterNot{ adjacencyList[it].edges.isEmpty() }
				.forEach{ println("""${vertices[it].data} ->[${adjacencyList[it].edges.joinToString()}] """) }
		}
}*/

/*#include<iostream>
using namespace std;
class R {
public:
	R(int r1, int r2) : r1(r1), r2(r2) { }
	void print();
	void print() const;
private:
	int r1, r2;
};

void R::print() {
	cout << r1 << ":" << r2 << endl;
}
void R::print() const {
	cout << r1 << ";" << r2 << endl;
}
int main() {
	R a(5, 4);
	a.print(); //����void print()
	const R b(20, 52);
	b.print(); //����void print() const
	return 0;
}*/

/*#include <iostream>
using namespace std;
class A {
public:
	A(int i);
	void print();
private:
	const int a;
	static const int b; //��̬�����ݳ�Ա
};
const int A::b = 10;
A::A(int i) : a(i) { }
void A::print() {
	cout << a << ":" << b << endl;
}
int main() {
	//��������a��b������100��0��Ϊ��ֵ���ֱ���ù��캯����ͨ�����캯���ĳ�ʼ���б������ĳ����ݳ�Ա����ֵ
	A a1(100), a2(0);
	a1.print();
	a2.print();
	return 0;
}*/

/*#include <iostream>
#include <cmath>
using namespace std;
class Point { //Point�ඨ��
public: //�ⲿ�ӿ�
	Point(int x = 0, int y = 0)
		: x(x), y(y) { }
	int getX() { return x; }
	int getY() { return y; }
	friend float dist(const Point& p1, const
		Point& p2);
private: //˽�����ݳ�Ա
	int x, y;
};
float dist(const Point& p1, const Point& p2) {
	double x = p1.x - p2.x;
	double y = p1.y - p2.y;
	return static_cast<float>(sqrt(x * x + y *
		y));
}
int main() { //������
	const Point myp1(1, 1), myp2(4, 5);
	cout << "The distance is: ";
	cout << dist(myp1, myp2) << endl;
	return 0;
}*/

/*#include "Point.h"
#include <iostream>
using namespace std;
int main() {
	Point a(4, 5); //�������a���乹�캯����ʹcount��1
	cout << "Point A: " << a.getX() << ", " << a.getY();
	Point::showCount(); //����������
	Point b(a); //�������b���乹�캯����ʹcount��1
	cout << "Point B: " << b.getX() << ", " << b.getY();
	Point::showCount(); //����������
	return 0;
}*/