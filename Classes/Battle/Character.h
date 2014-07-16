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

	// �������˭��
	GameSetting::Character who;
	//��ɫ����
	//float mass;
	int maxHealth;


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

	//���Ľ�ɫ����
	bool useHealth(int v);
	//�ظ���ɫ����
	void recovery(int v);
	//���ص�ǰ����ֵ
	int getHealth();

	int getMaxHealth(){return maxHealth;}

	void init();
};

