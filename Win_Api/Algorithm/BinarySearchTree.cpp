#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
#include<stack>
#include<queue>
#include<algorithm>

#include "BST.h"
using namespace std;

#pragma region 이진 탐색트리
/*
	이진 탐색과 연결리스트의 장점을 둘다 잡기위한 자료구조
	입력할때 루트부터 시작해서 비교하는 노드보다 작다면 왼쪽 크다면 오른쪽으로 보낸다.
	제일 작은 값은 왼쪽으로 쭉간 노드의 값
	제일 큰 값은 오른쪽으로 쭉 간 노드의 값
	중앙값은 루트노드이다.

	
	이진 탐색트리 
	-삽입 :log(n)
	-key 탐색 : log(n)
	- 삭제 : log(n)
	
	
	자가균형 이진 탐색트리 : 깊이를 스스로 조절하는 트리.
	- 레드 블랙 트리(map)
	- B-트리 => DB에 쓰임
	- AVL

			이진 탐색트리 vs 해쉬 테이블
			Node(key,Data) : pair(key,data)
			key로 정렬	   : 해쉬 값으로 정렬. => index
탐색시간 : log(n)		   : 체이닝이 없을시 상수
삽입시간 : log(n)		   : 체이닝이 없을 시 상수
삭제시간 : log(n)		   : 체이닝이 없을 시 상수

이진 탐색트리를 쓰는 이유
1. 데이터를 많이 쓴다.(데이터 파편화가 되어있으면 해쉬테이블을 쓰기 힘들 수 있다)
2. 해쉬테이블은 해쉬함수의 성능이 떨어질 경우 체이닝이 발생되어 성능이 떨어짐

서버의 데이터베이스에서는 둘다쓴다.






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
	cout << "최소" << endl;
	tree.PrintNode(tree.Min(tree.root));
	cout << "최대" << endl;
	tree.PrintNode(tree.Max(tree.root));
	cout << "75 찾기" << endl;
	tree.PrintNode(tree.Search(tree.root,75));
	cout << "최대 값의 이전값 찾기" << endl;
	tree.PrintNode(tree.Previous(tree.Max(tree.root)));
	cout << "최소 값의 이전값 찾기" << endl;
	tree.PrintNode(tree.Previous(tree.Min(tree.root)));
	cout << "최대 값의 이후값 찾기" << endl;
	tree.PrintNode(tree.Next(tree.Max(tree.root)));
	cout << "최소 값의 이후값 찾기" << endl;
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