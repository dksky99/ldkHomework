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
		//빈자리를 찾을때까지.
		if (node == nullptr)
			break;
		//노드가 있다면 이 자리는 차지할 수 없으므로 부모로 두고 다음 자식으로내려가봄.
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

	//부모노드가 새로운 노드의 정보를 알게함.
	if (key < parent->key)
	{
		parent->leftChild = newNode;
	}
	else
	{
		parent->rightChild = newNode;

	}


}

//재귀 호출. DFS와 비슷한듯
void BinarySearchTree::PrintTree(Node* node)
{
	if (node == nullptr)
	{
		return;
	}

	// 전위 순회 : 부모 - 왼쪽 자식들 - 오른쪽자식들 : 제일 작은 값부터 출력. 정렬된느낌.
	// 중위 순회 : 왼쪽 자식들 - 부모 -  오른쪽자식들 : 
	// 후위 순회 : 왼쪽 자식들 - 오른쪽자식들 -부모 : 



	cout << node->key << endl;
	PrintTree(node->leftChild);
	PrintTree(node->rightChild);

}

void BinarySearchTree::PrintNode(Node* node)
{
	if (node == nullptr)
	{
		cout << "없는 노드" << endl;
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

//이전 값. 만약 자식이 있다면. 왼쪽으로 한칸 값다가 오른쪽으로 쭉 가면나올것?
// 만약 자식이 없다면 부모의 오른쪽값이 자신이라면 부모가 이전값..
// 부모의 왼쪽값이 자신이라면 계속 부모로 올라가다 부모의 오른쪽자식이 부모라면 부모라고 확인.
//더이상 부모가 없으면 nullptr;
Node* BinarySearchTree::Previous(Node* node)
{
	Node* temp = node;
	Node* prev = nullptr;
	temp = temp->leftChild;
	//왼쪽 자식이 있을경우. 
	//prev는 부모 temp는 자식
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
	//오른쪽 자식이 있을경우. 
	//prev는 부모 temp는 자식
	if (temp != nullptr)
	{
		return(Min(temp));
	}



	return temp;
}

//노드의 삭제.  
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
		//자신의 이전값을 찾아서 복사하고 
		//이전 값이 있던 노드에 다시 Delete를 해서 양 자식중 하나라도 비어있는 자리가 
		
		
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
	//왼쪽에 달렸을떄
	else if (node1 == node1->parent->leftChild)
	{
		node1->parent->leftChild = node2;

	}
	//오른쪽에 달렸을떄
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







