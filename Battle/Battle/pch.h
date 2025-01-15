#pragma once
/*
	미리 컴파일된 헤더
	1. pch.h와 pch.cpp만들기
	2. pch.cpp에 속성-> c/c++-> 미리 컴파일된 헤더 -> 모든구성/모든 플랫폼
	3. 미리 컴파일된 헤더 '만들기'
	4. 미리 컴파일된 헤더 pch.h

	5.프로젝트 속성-> c/c++-> 미리 컴파일된 헤더 -> 모든구성/모든 플랫폼
	6. 미리 컴파일된 헤더 '사용'
	7. 미리 컴파일된 헤더 pch.h

	-../pch.h=> 포함 디렉토리 : 미리 컴파일된 헤더의 주소를 스크립트가 위치한 폴더에따라 다른 주소를 적어야하는게 싫다면.
	1. 프로젝트 속성
	2. VC++ 디렉토리 -> 포함 디렉토리 편집
	3. $(ProjectDir) -> 확인


*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <functional>
using namespace std;

bool CheckEnemysAlive(vector<Creature*>& enemys);
