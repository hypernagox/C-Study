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
	// ���
	// ȸ����
	// �߽�
};

class Collider
{
	// ID
	// ���ӿ�����Ʈ ������
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
	// �� ���
	
	// �ݶ��̴� ����� A
	// �ݶ��̴� ����� B
};

// 1. �浹 ���̺� ���鼭 �浹�˻� �����忡 ����
// 2. map�� ���鼭 �浹 ó����

class CollisionMgr
{
	unordered_map<unsigned long long, CollisionInfo> m_mapCol;

public:
	void CheckCollisionGroup()
	{
		// ���� �� ���� ���� ���鼭 try emplace�ϰ� �浹 ������� ����
		// Ȥ�� ������ ������ �����̳ʿ��� ����
	}
	void ResultOfCollison()
	{
		// �� ���鼭 �浹�� ����� ó����.
	}
};