#pragma once

class Node;

class Edge {
public:
	Edge* nextEdge;
	Node* data;

	Edge() {
		this->nextEdge = nullptr;
		this->data = nullptr;
	}
	Edge(Edge* E) {
		this->nextEdge = E;
		this->data = nullptr;
	}
	Edge(Node* N) {
		this->nextEdge = nullptr;
		this->data = N;
	}
	Edge(Edge* E, Node* N) {
		this->nextEdge = E;
		this->data = N;
	}
};

class EdgeQueueElement {
public:
	Edge* element;
	EdgeQueueElement* nextElement;
	EdgeQueueElement* prevElement;

	EdgeQueueElement() {
		this->element = nullptr;
		this->nextElement = nullptr;
		this->prevElement = nullptr;
	}
};

class EdgeQueue {
public:
	EdgeQueueElement* start;
	EdgeQueueElement* end;

	EdgeQueue() {
		this->start = nullptr;
		this->end = nullptr;
	}

	void push(Edge* element) {
		EdgeQueueElement* eqe = new EdgeQueueElement();
		if (!this->end) {
			this->end = eqe;
		}
		eqe->element = element;
		eqe->nextElement = start;
		eqe->nextElement->prevElement = eqe;
		start = eqe;
	}

	EdgeQueueElement* pop() {
		EdgeQueueElement* element = this->end;
		element->prevElement->nextElement = nullptr;
		this->end = element->prevElement;
		element->prevElement = nullptr;

		return element;
	}
};