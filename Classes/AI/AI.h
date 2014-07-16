#include "Battle/Character.h"
#include "Battle/BodyInfo.h"
#include <vector>
#include "ManagerInfo.h"
#include <list>

#ifndef AI_DEFINE
#define AI_DEFINE

class StateNode{

private:

protected:
	ManagerInfo * info;
	Character * enemy;

		//�жϾ���enemy����box��ͨ������жϷ���
	Vec2 getCloseVec(Vec2 now);

	int leftup(Vec2 * v);


public:

	StateNode(ManagerInfo * info, Character * enemy) :info(info), enemy(enemy){}

	//��������״̬ʱ��ȡ�Ĳ���
	virtual void enter()=0;

	//�����ڸ�״̬ʱ�Ķ���
	virtual void action()=0;

	//�����뿪��״̬ʱ��ȡ�Ĳ���
	virtual void exit()=0;

	virtual StateNode* changeState()=0;
};

//�����ؽڵ�
class DefendStateNode: public StateNode{

public:

	DefendStateNode(ManagerInfo * info, Character * enemy):StateNode(info,enemy){}

	void enter();
	void action();
	void exit();
	StateNode* changeState();
};

//�������ڵ�
class AttackStateNode: public StateNode{
public:
	AttackStateNode(ManagerInfo * info, Character * enemy):StateNode(info,enemy){}
	void enter();
	void action();
	void exit();
	StateNode* changeState();
};

//���ò��Խڵ�
class StrategyStateNode: public StateNode{
public:
	StrategyStateNode(ManagerInfo * info, Character * enemy):StateNode(info,enemy){}
	void enter();
	void action();
	void exit();
	StateNode* changeState();
};


class AI{
protected:
	ManagerInfo * info;
	std::vector<StateNode*> states;
	bool ready;	//�ж���Ϣ�Ƿ��ȡ


	const static int NUM=10;
	const static int posNum=10;  //��¼λ�õ�����
	std::list<Vec2> eList[NUM];   //�洢enemy��ǰ���λ��
	std::list<Vec2> hList[NUM];    //�洢heroǰ���λ��
	int eListSize[NUM];      //�洢eList�ĳ���
	int hListSize[NUM];   //�洢hList�ĳ���

public:

	const static int delta = 20;

	AI(ManagerInfo * info) : info(info), ready(false)
	{
		for(int i=0;i<NUM;i++)
		{
			eListSize[i]=0;
			hListSize[i]=0;
		}
	}

	void init();

	//�ı�����enemy��state
	void changeState();

	//ÿ��enemy��Ҫִ�ж���
	void actions();

	void addState(Character* enemy){
		states.push_back(new DefendStateNode(info,enemy));
	}

	void setReady(bool ready){
		this->ready=ready;
	}
};

#endif