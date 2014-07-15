#include "cocos2d.h"
#include "Character.h"
#include "EnemyAI.h"
#include <vector>
#include "CharacterLayer.h"

class SPCharacterLayer : public CharacterLayer
{
private:

	EnemyAI* enemyAI;
	
	//�ж�ʤ��
	void CheckResult();
	//��ɫ����
	void Rebirth(Character* cha);

	//������ʼ�¼�
	virtual bool onTouchBegan(Touch *pTouch, Event *pEvent);
	//������ֹ�¼�
	virtual void onTouchEnded(Touch *touch, Event *unused_event);

public:

	virtual bool init();  
	~SPCharacterLayer();
	CREATE_FUNC(SPCharacterLayer);

	void setHero(GameSetting::Character hero);
	void setEnemy(GameSetting::Character enemy);

};

