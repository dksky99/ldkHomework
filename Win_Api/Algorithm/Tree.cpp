#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

#pragma region Ʈ��
/*
	
	Ʈ�� 
	1. ������ ������ ��Ÿ���� �ڷᱸ��(�θ��� �ڽİ���
	2. Ʈ���� �߶� Ʈ���� (����Ʈ�� ����)
		-> Ʈ���� ����� �Ӽ��� ���´�.


	���� :  
	1. ����Ʈ�� : �θ� �ִ� 2���� �ڽ��� ���� Ʈ��
	2. ��ȭ����Ʈ�� : 
	3. ���� ����Ʈ�� : 
	4. �� Ʈ�� : (�켱���� ť)
	5. (�ڰ�����) ����Ž��Ʈ�� Map�ڷ���, �����Ʈ��

	

*/

#pragma endregion

struct Node
{
	string data;
	vector<Node*> children;
};


Node* CreateTree()
{
	Node* root = new Node();
	root->data = "������";


	Node* programming = new Node();
	root->children.push_back(programming);
	{
		Node* node1 = new Node();
		node1->data = "Ŭ���̾�Ʈ";
		programming->children.push_back(node1);


		Node* node2 = new Node();
		node2->data = "����";
		programming->children.push_back(node2);


		Node* node3 = new Node();
		node3->data = "����";
		programming->children.push_back(node3);

	}

	Node* art = new Node();
	root->children.push_back(art);
	{
		Node* node1 = new Node();
		node1->data = "���";
		art->children.push_back(node1);


		Node* node2 = new Node();
		node2->data = "��";
		art->children.push_back(node2);


		Node* node3 = new Node();
		node3->data = "��ȭ";
		art->children.push_back(node3);

	}

	Node* planing = new Node();
	root->children.push_back(planing);
	{
		Node* node1 = new Node();
		node1->data = "������";
		planing->children.push_back(node1);


		Node* node2 = new Node();
		node2->data = "���丮";
		planing->children.push_back(node2);


		Node* node3 = new Node();
		node3->data = "����";
		planing->children.push_back(node3);

	}


	PrintTree(root);
	return root;
}



void PrintTree(Node* node,int depth=0)
{

	//Ʈ���� ���� ��ȸ :  �θ�- ���� �ڽĵ� - ������ �ڽĵ�
	//Ʈ���� ���� ��ȸ :  ���� �ڽ�- �θ� - ������ �ڽĵ�
	//Ʈ���� ���� ��ȸ :  ���� �ڽ�-  ������ �ڽĵ�- �θ�

	//Ʈ���� ���� ��ȸ
	//��� ���� ���ڴ�.

	for (int i = 0;i < depth;i++)
	{
		cout << "-";
	}

	//���� ��ȸ
	//cout << node->data << endl;
	for (auto child : node->children)
	{
		PrintTree(child,depth+1);
	}
	//���� ��ȸ
	cout << node->data << endl;
}


int main()
{

	

	return 0;
}