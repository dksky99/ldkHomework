#pragma once

#include <iostream>

using namespace std;

struct Node
{

	Node() {}
	Node(int key) { this->key = key; }




	int data = 0;
	int key = -1;

	Node* leftChild = nullptr;
	Node* rightChild = nullptr;
	Node* parent = nullptr;
};


class BinarySearchTree
{
public:
	BinarySearchTree();
	~BinarySearchTree();

	void Insert(int key);

	void PrintTree(Node* node);

	void PrintNode(Node* node);

	Node* Search(Node* node, int key); //key값과 같은 값을 가진 노드 반환.
	Node* Min(Node* node);	//노드부터 시작하는 트리에서 가장 작은 값.
	Node* Max(Node* node); // 가장 큰값.

	//이건 외부에선 필요하지 않은 기능. 부모 이후는 살필필요가 없다. 다른 함수의 
	//구현을 편하게 하기 위한 용도.
	Node* Previous(Node* node); //매개 변수 node보다 한칸 더 작은 애.
	Node* Next(Node* node);

	void Delete(Node* node);

	void Replace(Node* node1, Node* node2);


	Node* root = nullptr;


private:



};