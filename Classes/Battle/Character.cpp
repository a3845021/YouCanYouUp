#include "Character.h"

//��ͼƬ�Ĺ��캯��
Character::Character(GameSetting::Character character)
{
	who = character;
	std::string res =CharacterParameter::getResource(character);
	sprite = Sprite::create(res); 
	sprite->setScale(0.3f);
	body = PhysicsBody::createCircle(sprite->getContentSize().width *0.3/ 2);

	//��������ھ�����
	sprite->setPhysicsBody(body);
	//����λ��
   // sprite->setPosition(p);
    
	//���ø����shape�ĵ���
	body->getShape(0)->setRestitution(CharacterParameter::getRestitution(character));
	
	init();
	
}
//û��ͼƬ�Ĺ��캯��
Character::Character(){
	sprite = Sprite::create();
	body = PhysicsBody::createCircle(40);
	sprite->setPhysicsBody(body);
   // sprite->setPosition(p);

}

void Character::init()
{
	//���������������ʼ���������������ͬ
	max_health = CharacterParameter::getMaxHealth(who);
	health = max_health;
	//��������
	body->setMass(CharacterParameter::getMass(who));
}

Sprite* Character::getSprite(){
	return sprite;
}

PhysicsBody* Character::getBody(){
	return body;
}

Character::~Character(void)
{
	
}


void Character::applyImpulse(Vec2 vec){
	//body->applyForce(vec);
	
	//vec.x*=200;
	//vec.y*=200;
	vec*= body->getMass()/2;
	body->applyImpulse(vec);
}

Vec2 Character::getPosition(){
	return body->getPosition();
	//return this->getSprite()->getPhysicsBody()->getPosition();
}

void Character::setPosition(Vec2 pos){
	sprite->setPosition(pos);
}


/*
Vec2 Character::getLastForce(){
	return this->lastForce;
}

void Character::setLastForce(Vec2 newForce){
	lastForce= newForce;
}*/