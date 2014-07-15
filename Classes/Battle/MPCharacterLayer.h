#include "cocos2d.h"
#include "Character.h"
#include "network/WebSocket.h"
#include "CharacterLayer.h"

class MPCharacterLayer : public CharacterLayer, public cocos2d::network::WebSocket::Delegate
{
private:

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
	~MPCharacterLayer();
	CREATE_FUNC(MPCharacterLayer);

	void setHero(GameSetting::Character hero);
	void setEnemy(GameSetting::Character enemy);

	// for virtual function in websocket delegate
	virtual void onOpen(cocos2d::network::WebSocket* ws);
	virtual void onMessage(cocos2d::network::WebSocket* ws, const cocos2d::network::WebSocket::Data& data);
	virtual void onClose(cocos2d::network::WebSocket* ws);
	virtual void onError(cocos2d::network::WebSocket* ws, const cocos2d::network::WebSocket::ErrorCode& error);

	// the websocket io client
	cocos2d::network::WebSocket* _wsiClient;

	std::string enemyKey;

	void initBattleScene(int tag);
};