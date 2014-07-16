#ifndef _CHARACTERLAYER_H_
#define _CHARACTERLAYER_H_

#include "cocos2d.h"
#include "Character.h"
#include "Health.h"
#include <vector>

class CharacterLayer : public cocos2d::Layer
{

protected:

	//������������ʼ����ֹ��
	Point posBegan,posEnded;

	//�ٿؽ�ɫ
	Character* hero;

	int hero_lives;

	//�ж�ʤ��
	virtual void CheckResult() = 0;
	//��ɫ����
	virtual void Rebirth(Character* cha) = 0;

	//������ʼ�¼�
	virtual bool onTouchBegan(Touch *pTouch, Event *pEvent) = 0;
	//������ֹ�¼�
	virtual void onTouchEnded(Touch *touch, Event *unused_event) = 0;

	Health* heroHealth;
	void sendHealth(Object* obj){
	/*
	Health* health = (Health*)obj;
	health->health = getHeroHealth();*/
};
	int getHeroHealth(){return hero->getHealth();};

public:

	//schedule���ú���
	virtual void scheduleCallBack(float fDelta){ CheckResult(); };

	virtual void setHero(GameSetting::Character hero){};
	virtual void setEnemy(std::vector<GameSetting::Character> enemy){};

};

#endif
