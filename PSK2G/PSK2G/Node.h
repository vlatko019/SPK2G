#pragma once

class Edge;

class Node {
public:
	int key;
	Node* nextNode;
	Edge* adj;

	Node(int a) {
		this->key = a;
		this->adj = nullptr;
		this->nextNode = nullptr;
	}
};