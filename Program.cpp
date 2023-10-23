#include <iostream>
#include <format>
#include <string>
#include <regex>
#include <optional>
#include <functional>
#include <ranges>
#include <unordered_map>
#include <map>

using namespace std;

struct OBBBox
{
	// 행렬
	// 회전축
	// 중심
};

class Collider
{
	// ID
	// 게임오브젝트 포인터
	// OBBBox
	// Collision Handler
};

union COLLIDER_ID
{
	struct {
		int left;
		int right;
	};
	unsigned long long ID;
};

struct CollisionInfo
{
	bool bPrevCollision;
	bool bNowCollision;
	// 축 행렬
	
	// 콜라이더 쉐어드 A
	// 콜라이더 쉐어드 B
};

// 1. 충돌 테이블 돌면서 충돌검사 스레드에 넣음
// 2. map을 돌면서 충돌 처리함

class CollisionMgr
{
	unordered_map<unsigned long long, CollisionInfo> m_mapCol;

public:
	void CheckCollisionGroup()
	{
		// 현재 씬 이중 포문 돌면서 try emplace하고 충돌 스레드로 보냄
		// 혹시 죽은거 있으면 컨테이너에서 빼냄
	}
	void ResultOfCollison()
	{
		// 맵 돌면서 충돌의 결과를 처리함.
	}
};