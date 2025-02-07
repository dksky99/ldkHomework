#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

#pragma region 트리
/*
	
	트리 
	1. 계층적 구조를 나타내는 자료구조(부모의 자식관계
	2. 트리는 잘라도 트리다 (서브트리 존재)
		-> 트리는 재귀적 속성을 갖는다.


	종류 :  
	1. 이진트리 : 부모가 최대 2개의 자식을 갖는 트리
	2. 포화이진트리 : 
	3. 완전 이진트리 : 
	4. 힙 트리 : (우선순위 큐)
	5. (자가균형) 이진탐색트리 Map자료형, 레드블랙트리

	

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
	root->data = "개발팀";


	Node* programming = new Node();
	root->children.push_back(programming);
	{
		Node* node1 = new Node();
		node1->data = "클라이언트";
		programming->children.push_back(node1);


		Node* node2 = new Node();
		node2->data = "서버";
		programming->children.push_back(node2);


		Node* node3 = new Node();
		node3->data = "엔진";
		programming->children.push_back(node3);

	}

	Node* art = new Node();
	root->children.push_back(art);
	{
		Node* node1 = new Node();
		node1->data = "배경";
		art->children.push_back(node1);


		Node* node2 = new Node();
		node2->data = "모델";
		art->children.push_back(node2);


		Node* node3 = new Node();
		node3->data = "원화";
		art->children.push_back(node3);

	}

	Node* planing = new Node();
	root->children.push_back(planing);
	{
		Node* node1 = new Node();
		node1->data = "컨텐츠";
		planing->children.push_back(node1);


		Node* node2 = new Node();
		node2->data = "스토리";
		planing->children.push_back(node2);


		Node* node3 = new Node();
		node3->data = "레벨";
		planing->children.push_back(node3);

	}


	PrintTree(root);
	return root;
}



void PrintTree(Node* node,int depth=0)
{

	//트리의 전위 순회 :  부모- 왼쪽 자식들 - 오른쪽 자식들
	//트리의 중위 순회 :  왼쪽 자식- 부모 - 오른쪽 자식들
	//트리의 후위 순회 :  왼쪽 자식-  오른쪽 자식들- 부모

	//트리의 중위 순회
	//가운데 부터 보겠다.

	for (int i = 0;i < depth;i++)
	{
		cout << "-";
	}

	//전위 순회
	//cout << node->data << endl;
	for (auto child : node->children)
	{
		PrintTree(child,depth+1);
	}
	//후위 순회
	cout << node->data << endl;
}


int main()
{

	

	return 0;
}