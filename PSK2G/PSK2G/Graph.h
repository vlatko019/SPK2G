#pragma once
#include "Edge.h"
#include "Node.h"

class Graph {
public:
	Node* start;

	Graph() {
		start = nullptr;
	}

	void insertNode(int n) {
		Node* a = new Node(n);
		a->nextNode = start;
		start = a;
	}

	Node* searchNode(Node* start, int data) {
		if (!start) return nullptr;
		if (start->key == data) return start;
		return searchNode(start->nextNode, data);
	}
	void addEdge(int a, int b) {
		Node *N, *M;
		N = searchNode(this->start, a);
		Edge *E = new Edge(N->adj, searchNode(this->start, b));
		N->adj = E;
	}
	int SearchPath(int a, int b) {
		Node* A = searchNode(start, a);
		if (!A->adj) return -1;
		Edge* E = A->adj;
		int i = 1;
		EdgeQueue Q;

		while (E) {
			if (E->data->key == b) return i;
			Q.push(E);
			E = E->nextEdge;
		}
		E = Q.pop()->element;
		i++;
	}
};