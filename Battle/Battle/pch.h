#pragma once
/*
	�̸� �����ϵ� ���
	1. pch.h�� pch.cpp�����
	2. pch.cpp�� �Ӽ�-> c/c++-> �̸� �����ϵ� ��� -> ��籸��/��� �÷���
	3. �̸� �����ϵ� ��� '�����'
	4. �̸� �����ϵ� ��� pch.h

	5.������Ʈ �Ӽ�-> c/c++-> �̸� �����ϵ� ��� -> ��籸��/��� �÷���
	6. �̸� �����ϵ� ��� '���'
	7. �̸� �����ϵ� ��� pch.h

	-../pch.h=> ���� ���丮 : �̸� �����ϵ� ����� �ּҸ� ��ũ��Ʈ�� ��ġ�� ���������� �ٸ� �ּҸ� ������ϴ°� �ȴٸ�.
	1. ������Ʈ �Ӽ�
	2. VC++ ���丮 -> ���� ���丮 ����
	3. $(ProjectDir) -> Ȯ��


*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <functional>
using namespace std;

bool CheckEnemysAlive(vector<Creature*>& enemys);
