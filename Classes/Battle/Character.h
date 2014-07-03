#pragma once
#include "cocos2d.h"
#include "CharacterParameter.h"
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

	// �������˭��
	GameSetting::Character who;

public:
	Character(GameSetting::Character character);
	Character();
	~Character(void);
	//���ؽ�ɫ�ľ���ָ��
	Sprite* getSprite();
	//���ؽ�ɫ�ĸ���ָ��
	PhysicsBody* getBody();
	//���������һ���ٶ�
	void applyImpulse(Vec2 vec);
	//���ؽ�ɫλ��
	Vec2 getPosition();

	//���ý�ɫλ��
	void setPosition(Vec2 pos);

	void init();
};

