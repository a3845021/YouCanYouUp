#pragma once
#include "cocos2d.h"
#include "Character.h"

class CharacterLayer : public cocos2d::Layer
{

protected:

	//������������ʼ����ֹ��
	Point posBegan,posEnded;
	//�ٿؽ�ɫ
	Character* hero;
	Character* enemy;

	//�ж�ʤ��
	virtual void CheckResult() = 0;
	//��ɫ����
	virtual void Rebirth(Character* cha) = 0;

	//������ʼ�¼�
	virtual bool onTouchBegan(Touch *pTouch, Event *pEvent) = 0;
	//������ֹ�¼�
	virtual void onTouchEnded(Touch *touch, Event *unused_event) = 0;

public:

	//schedule���ú���
	virtual void scheduleCallBack(float fDelta){ CheckResult(); };

	virtual void setHero(GameSetting::Character hero){};
	virtual void setEnemy(GameSetting::Character enemy){};

};

