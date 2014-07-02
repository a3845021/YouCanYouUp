#pragma once
#include "cocos2d.h"
#include "Character.h"
#include "EnemyAI.h"
#include <vector>

class CharacterLayer : public cocos2d::Layer
{
private:
	//������������ʼ����ֹ��
	Point posBegan,posEnded;
	//�ٿؽ�ɫ
	Character* hero;
	//���ֽ�ɫ
	//Character enemy[3];
	std::vector<Character> enemy;
	EnemyAI* enemyAI;
	
	//schedule���ú���
	void scheduleCallBack(float fDelta);
	//�ж�ʤ��
	void CheckResult();
	//��ɫ����
	void Rebirth(Character* cha,Point birthPoint);

	//������ʼ�¼�
	virtual bool onTouchBegan(Touch *pTouch, Event *pEvent);
	//������ֹ�¼�
	virtual void onTouchEnded(Touch *touch, Event *unused_event);

public:
	virtual bool init();  
	~CharacterLayer();
	CREATE_FUNC(CharacterLayer);

	void setHero(GameSetting::Character hero);
	void setEnemy(std::vector<GameSetting::Character> enemy);
};

