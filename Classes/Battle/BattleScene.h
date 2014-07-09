#pragma once

#include "cocos2d.h"
#include "ForestMapLayer.h"
#include "SnowMapLayer.h"
#include "CharacterLayer.h"
#include "GameSetting.h"
#include "HUDLayer.h"

class BattleScene : public cocos2d::Scene
{
private:
	//UI�����
	//Layer* UILayer;
	//���γ�����
	//Layer* mapLayer;
	//��ɫ��
	//Layer* characterLayer;
	//��ʼ��
	virtual bool init();

	static Layer* selectMap(GameSetting::Map map); 

public:
	//��������
	static Scene* createScene(GameSetting::Map map, GameSetting::Character hero, std::vector<GameSetting::Character> enemy);
	CREATE_FUNC(BattleScene);
};

