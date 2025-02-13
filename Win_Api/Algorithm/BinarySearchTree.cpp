#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
#include<stack>
#include<queue>
#include<algorithm>

#include "BST.h"
using namespace std;

#pragma region ���� Ž��Ʈ��
/*
	���� Ž���� ���Ḯ��Ʈ�� ������ �Ѵ� ������� �ڷᱸ��
	�Է��Ҷ� ��Ʈ���� �����ؼ� ���ϴ� ��庸�� �۴ٸ� ���� ũ�ٸ� ���������� ������.
	���� ���� ���� �������� �߰� ����� ��
	���� ū ���� ���������� �� �� ����� ��
	�߾Ӱ��� ��Ʈ����̴�.

	
	���� Ž��Ʈ�� 
	-���� :log(n)
	-key Ž�� : log(n)
	- ���� : log(n)
	
	
	�ڰ����� ���� Ž��Ʈ�� : ���̸� ������ �����ϴ� Ʈ��.
	- ���� �� Ʈ��(map)
	- B-Ʈ�� => DB�� ����
	- AVL

			���� Ž��Ʈ�� vs �ؽ� ���̺�
			Node(key,Data) : pair(key,data)
			key�� ����	   : �ؽ� ������ ����. => index
Ž���ð� : log(n)		   : ü�̴��� ������ ���
���Խð� : log(n)		   : ü�̴��� ���� �� ���
�����ð� : log(n)		   : ü�̴��� ���� �� ���

���� Ž��Ʈ���� ���� ����
1. �����͸� ���� ����.(������ ����ȭ�� �Ǿ������� �ؽ����̺��� ���� ���� �� �ִ�)
2. �ؽ����̺��� �ؽ��Լ��� ������ ������ ��� ü�̴��� �߻��Ǿ� ������ ������

������ �����ͺ��̽������� �Ѵپ���.






*/

#pragma endregion

class Player
{
public:
	bool operator==(const Player& other)
	{
		return other.atk == atk && other.hp == hp;
	}
	bool operator<(const Player& other)
	{
		return other.atk < atk ;
	}

	int hp;
	int atk;
};


int main(void)
{

	BinarySearchTree tree;
	tree.Insert(100);
	tree.Insert(50);
	tree.Insert(25);
	tree.Insert(75);
	tree.Insert(150);
	tree.Insert(110);
	tree.Insert(200);
	tree.Insert(99);

	tree.PrintTree(tree.root);
	cout << "======================" << endl;
	cout << "�ּ�" << endl;
	tree.PrintNode(tree.Min(tree.root));
	cout << "�ִ�" << endl;
	tree.PrintNode(tree.Max(tree.root));
	cout << "75 ã��" << endl;
	tree.PrintNode(tree.Search(tree.root,75));
	cout << "�ִ� ���� ������ ã��" << endl;
	tree.PrintNode(tree.Previous(tree.Max(tree.root)));
	cout << "�ּ� ���� ������ ã��" << endl;
	tree.PrintNode(tree.Previous(tree.Min(tree.root)));
	cout << "�ִ� ���� ���İ� ã��" << endl;
	tree.PrintNode(tree.Next(tree.Max(tree.root)));
	cout << "�ּ� ���� ���İ� ã��" << endl;
	tree.PrintNode(tree.Next(tree.Min(tree.root)));


	map<string, int> m;
	cout << m["Hanill"] << endl;
	if(m.count("Hanil1")==0)
		m["Hanil1"] = 1;
	auto iter = m.insert(make_pair<string, int>("Hanil2", 2));


	for (auto p : m)
	{
		cout << p.first << " ... " << p.second << endl;
	}

	cout << m["Hanil5"] << endl;



	return 0;

}