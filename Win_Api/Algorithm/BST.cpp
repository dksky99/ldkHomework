#include "BST.h"

BinarySearchTree::BinarySearchTree()
{
}

BinarySearchTree::~BinarySearchTree()
{
}

void BinarySearchTree::Insert(int key)
{
	Node* newNode = new Node(key);

	if (root == nullptr)
	{
		root = newNode;
		return;
	}

	Node* node = root;
	Node* parent = nullptr;
	while (true)
	{
		//���ڸ��� ã��������.
		if (node == nullptr)
			break;
		//��尡 �ִٸ� �� �ڸ��� ������ �� �����Ƿ� �θ�� �ΰ� ���� �ڽ����γ�������.
		parent = node;
		if (key < node->key)
		{
			node = node->leftChild;
		}
		else
		{

			node = node->rightChild;
		}
	}
	newNode->parent = parent;

	//�θ��尡 ���ο� ����� ������ �˰���.
	if (key < parent->key)
	{
		parent->leftChild = newNode;
	}
	else
	{
		parent->rightChild = newNode;

	}


}

//��� ȣ��. DFS�� ����ѵ�
void BinarySearchTree::PrintTree(Node* node)
{
	if (node == nullptr)
	{
		return;
	}

	// ���� ��ȸ : �θ� - ���� �ڽĵ� - �������ڽĵ� : ���� ���� ������ ���. ���ĵȴ���.
	// ���� ��ȸ : ���� �ڽĵ� - �θ� -  �������ڽĵ� : 
	// ���� ��ȸ : ���� �ڽĵ� - �������ڽĵ� -�θ� : 



	cout << node->key << endl;
	PrintTree(node->leftChild);
	PrintTree(node->rightChild);

}

void BinarySearchTree::PrintNode(Node* node)
{
	if (node == nullptr)
	{
		cout << "���� ���" << endl;
		return;
	}
	cout << node->key << endl;
}

Node* BinarySearchTree::Search(Node* node, int key)
{
	Node* temp = node;

	while (temp != nullptr)
	{
		if (temp->key == key)
			break;

		if (temp->key > key)
		{
			temp = temp->leftChild;
		}
		else
		{

			temp = temp->rightChild;
		}
	}



	return temp;
}

Node* BinarySearchTree::Min(Node* node)
{
	Node* prev = nullptr;
	while (node != nullptr)
	{
		prev = node;
		node = node->leftChild;
	}

	return prev;
}

Node* BinarySearchTree::Max(Node* node)
{
	Node* prev = nullptr;
	while (node != nullptr)
	{
		prev = node;
		node = node->rightChild;
	}

	return prev;
}

//���� ��. ���� �ڽ��� �ִٸ�. �������� ��ĭ ���ٰ� ���������� �� ���鳪�ð�?
// ���� �ڽ��� ���ٸ� �θ��� �����ʰ��� �ڽ��̶�� �θ� ������..
// �θ��� ���ʰ��� �ڽ��̶�� ��� �θ�� �ö󰡴� �θ��� �������ڽ��� �θ��� �θ��� Ȯ��.
//���̻� �θ� ������ nullptr;
Node* BinarySearchTree::Previous(Node* node)
{
	Node* temp = node;
	Node* prev = nullptr;
	temp = temp->leftChild;
	//���� �ڽ��� �������. 
	//prev�� �θ� temp�� �ڽ�
	if (temp != nullptr)
	{
		return(Max(temp));
	}

	

	return temp;
}

//
Node* BinarySearchTree::Next(Node* node)
{
	Node* temp = node;
	Node* prev = nullptr;
	temp = temp->rightChild;
	//������ �ڽ��� �������. 
	//prev�� �θ� temp�� �ڽ�
	if (temp != nullptr)
	{
		return(Min(temp));
	}



	return temp;
}

//����� ����.  
void BinarySearchTree::Delete(Node* node)
{
	if (node == nullptr)
		return;

	if (node->leftChild == nullptr)
	{
		Replace(node, node->rightChild);
	}
	else if (node->rightChild == nullptr)
	{
		Replace(node, node->leftChild);

	}
	else
	{
		//�ڽ��� �������� ã�Ƽ� �����ϰ� 
		//���� ���� �ִ� ��忡 �ٽ� Delete�� �ؼ� �� �ڽ��� �ϳ��� ����ִ� �ڸ��� 
		
		
		Node* prev = Previous(node);

		node->data = prev->data;
		node->key = prev->key;
		Delete(prev);

	}

}

void BinarySearchTree::Replace(Node* node1, Node* node2)
{
	if (node1->parent == nullptr)
	{
		root = node2;
	}
	//���ʿ� �޷�����
	else if (node1 == node1->parent->leftChild)
	{
		node1->parent->leftChild = node2;

	}
	//�����ʿ� �޷�����
	else
	{
		node1->parent->rightChild = node2;
	}

	//
	if (node2  != nullptr)
	{
		node2->parent = node1->parent;
	}


	delete node1;


}







