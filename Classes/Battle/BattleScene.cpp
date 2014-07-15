#include "BattleScene.h"

USING_NS_CC;

Scene* BattleScene::createScene(bool online, GameSetting::Character hero, GameSetting::Map map, GameSetting::Character enemy, int initNum, std::string &enemyKey){
	//�������� 
	auto scene = Scene::createWithPhysics();
	//����������
	auto mapLayer = BattleScene::selectMap(map);
	//������ɫ��
	CharacterLayer *characterLayer;
	if(online)
	{
		characterLayer = MPCharacterLayer::create();
		((MPCharacterLayer*)characterLayer)->enemyKey = enemyKey;
	}
	else
	{
		characterLayer = SPCharacterLayer::create();
	}
		
	characterLayer->setHero(hero);
	characterLayer->setEnemy(enemy);

	if(online)
	{
		((MPCharacterLayer*)characterLayer)->initBattleScene(initNum);
	}

	//������ӵ�������
	scene->addChild(mapLayer);
	scene->addChild(characterLayer);

	//���������������ɼ�
	scene->getPhysicsWorld()->setDebugDrawMask(true);
	//������������������ͱ���
	scene->getPhysicsWorld()->setGravity(Vec2(0,-300));
	scene->getPhysicsWorld()->setSpeed(1.5f);

	return scene;
}

bool BattleScene::init(){
	return true;
}

Layer* BattleScene::selectMap(GameSetting::Map map){
	if(map==GameSetting::Map::FOREST){
		return ForestMapLayer::create();
	}
	if(map==GameSetting::Map::SNOW){
		return SnowMapLayer::create();
	}
	return nullptr;
}
