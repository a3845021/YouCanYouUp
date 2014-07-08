#include "BattleScene.h"

USING_NS_CC;

Scene* BattleScene::createScene(GameSetting::Map map, GameSetting::Character hero, std::vector<GameSetting::Character> enemy){
	//��������
	auto scene = Scene::createWithPhysics();
	//����������
	//auto mapLayer = MapLayer::create();
	auto mapLayer = BattleScene::selectMap(map);
	//������ɫ��
	auto characterLayer = CharacterLayer::create();
	characterLayer->setHero(hero);
	characterLayer->setEnemy(enemy);
	//characterLayer->setCharacter(character);
	//����UI��
	//auto uiLayer = UILayer::create();

	//������ӵ�������
	scene->addChild(mapLayer);
	scene->addChild(characterLayer);

	//mapLayer->ready = true;
	characterLayer->ready = true;

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
