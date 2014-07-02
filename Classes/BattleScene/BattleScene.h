#include "cocos2d.h"
#include "MapLayer.h"
#include "SnowMapLayer.h"
#include "CharacterLayer.h"
#include "GameSetting.h"

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
	static Scene* createScene(GameSetting::Map map);
	CREATE_FUNC(BattleScene);
};

