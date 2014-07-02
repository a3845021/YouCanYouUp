#pragma once
#include "cocos2d.h"
USING_NS_CC;

class Character
{
private:
	//��ɫ�ľ���
	Sprite* sprite;
	//��ɫ���������
	PhysicsBody* body;
	//��ɫ����
	int health;

	//��ɫ�ϴ�����
	//Vec2 lastForce;

	//��ɫ����
	//float mass;
	int max_health;

public:
	Character(const std::string &filename,Point p);
	Character(Point p);
	~Character(void);
	//���ؽ�ɫ�ľ���ָ��
	Sprite* getSprite();
	//���ؽ�ɫ�ĸ���ָ��
	PhysicsBody* getBody();
	//���������һ���ٶ�
	void applyImpulse(Vec2 vec);
	//���ؽ�ɫλ��
	Vec2 getPosition();

	/*
	//���ý�ɫ�ϴ�����
	void setLastForce(Vec2 newForce);
	//���ؽ�ɫ�ϴ�����
	Vec2 getLastForce();
	*/
};

