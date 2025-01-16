#pragma region 솔루션과 프로젝트
/*
	sln : 솔루션(solution)
	- 편집기에서 서점과 비슷
	- 좀 포괄적인 역할.

	proj : 프로젝트(project)
	- 편집기에서 서점의 구역과 비슷
	
	ctrl c+ ctrl k : 주석처리

	함수의 선언부, 정의부

	void Hello(); //함수의 선언

	void Hello() //함수의 정의
	{

	}
	링커가 헤더와 c++파일로 분리된 파일을 합쳐줌. 여기서 문제가 나면 링커 오류가 난다.

	미리 컴파일된 헤더파일. : 미리 한번 해석해봣다.

	#pragma once : 한번 읽어봤으면 그냥 넘어가라.


*/
#pragma endregion
#include"pch.h"

#include "BattleManager.h"





int main()
{
	srand(time(NULL));

	BattleManager::Create();
	
	

	return 0;
}
