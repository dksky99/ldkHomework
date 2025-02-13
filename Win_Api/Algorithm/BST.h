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

	Node* Search(Node* node, int key); //key���� ���� ���� ���� ��� ��ȯ.
	Node* Min(Node* node);	//������ �����ϴ� Ʈ������ ���� ���� ��.
	Node* Max(Node* node); // ���� ū��.

	//�̰� �ܺο��� �ʿ����� ���� ���. �θ� ���Ĵ� �����ʿ䰡 ����. �ٸ� �Լ��� 
	//������ ���ϰ� �ϱ� ���� �뵵.
	Node* Previous(Node* node); //�Ű� ���� node���� ��ĭ �� ���� ��.
	Node* Next(Node* node);

	void Delete(Node* node);

	void Replace(Node* node1, Node* node2);


	Node* root = nullptr;


private:



};