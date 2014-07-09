//#pragma once
#ifndef _CHARACTERLAYER_H_
#define _CHARACTERLAYER_H_

#include "cocos2d.h"
#include "Character.h"
#include "EnemyAI.h"
#include <vector>
#include "network/WebSocket.h"
#include "Health.h"


class CharacterLayer : public cocos2d::Layer/*, public cocos2d::network::WebSocket::Delegate*/
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

	Health* heroHealth;
	void sendHealth(Object* obj);
	int getHeroHealth();

public:
	
	virtual bool init();  
	~CharacterLayer();
	CREATE_FUNC(CharacterLayer);

	void setHero(GameSetting::Character hero);
	void setEnemy(std::vector<GameSetting::Character> enemy);


	// for virtual function in websocket delegate
	/*virtual void onOpen(cocos2d::network::WebSocket* ws);
	virtual void onMessage(cocos2d::network::WebSocket* ws, const cocos2d::network::WebSocket::Data& data);
	virtual void onClose(cocos2d::network::WebSocket* ws);
	virtual void onError(cocos2d::network::WebSocket* ws, const cocos2d::network::WebSocket::ErrorCode& error);*/

	// the websocket io client
	//cocos2d::network::WebSocket* _wsiClient;
};

#endif