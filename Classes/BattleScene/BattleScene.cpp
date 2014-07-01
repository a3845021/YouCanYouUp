#include "BattleScene.h"

USING_NS_CC;

Scene* BattleScene::createScene(GameSetting::Map map){
	//��������
	auto scene = Scene::createWithPhysics();
	//����������
	//auto mapLayer = MapLayer::create();
	auto mapLayer = BattleScene::selectMap(map);
	//������ɫ��
	auto characterLayer = CharacterLayer::create();
	//����UI��
	//auto uiLayer = UILayer::create();

	//������ӵ�������
	scene->addChild(mapLayer);
	scene->addChild(characterLayer);

	//���������������ɼ�
	scene->getPhysicsWorld()->setDebugDrawMask(true);
	//������������������ͱ���
	scene->getPhysicsWorld()->setGravity(Vec2(0,-150));
	scene->getPhysicsWorld()->setSpeed(1.f);


	return scene;
}

bool BattleScene::init(){

	return true;
}

Layer* BattleScene::selectMap(GameSetting::Map map){
	if(map==GameSetting::Map::DEFAULT){
		return MapLayer::create();
	}
	if(map==GameSetting::Map::SNOW){
		return SnowMapLayer::create();
	}
	return false;
}