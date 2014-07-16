#include "SignupScene.h"
#include "LoginScene.h"
#include "CCSGUIReader.h"

USING_NS_CC;
using namespace cocostudio;
using namespace ui;
using namespace network;

bool SignupScene::init()
{
	if(!Scene::init()){
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	Widget *pNode = (Widget*)(GUIReader::getInstance()->widgetFromJsonFile("OnlineUI4.ExportJson"));
	this->addChild(pNode);
	Button *return_ = (Button*)(ui::Helper::seekWidgetByName(pNode, "return"));
	return_->addTouchEventListener(CC_CALLBACK_2(SignupScene::returnEvent, this));
	Button *login = (Button*)(ui::Helper::seekWidgetByName(pNode, "login"));
	login->addTouchEventListener(CC_CALLBACK_2(SignupScene::loginEvent, this));
	
	Button *signup = (Button*)(ui::Helper::seekWidgetByName(pNode, "register"));
	signup->addTouchEventListener(CC_CALLBACK_2(SignupScene::signupEvent, this));
	// �ҵ����������
	username = (TextField*)(ui::Helper::seekWidgetByName(pNode, "username"));
	password = (TextField*)(ui::Helper::seekWidgetByName(pNode, "code"));
	return true;
}

void SignupScene::returnEvent(Ref *pSender, Widget::TouchEventType type)
{
	switch(type){
	case Widget::TouchEventType::ENDED:
		Director::getInstance()->popScene();
		break;
	}	
}

void SignupScene::loginEvent(Ref *pSender, Widget::TouchEventType type)
{
	switch(type){
	case Widget::TouchEventType::ENDED:
		Scene *login = LoginScene::create();
		TransitionScene *transition = TransitionFade::create(1, login);
		Director::getInstance()->pushScene(transition);
		break;
	}	
}

void SignupScene::signupEvent(Ref *pSender, Widget::TouchEventType type)
{
	switch(type){
	case Widget::TouchEventType::ENDED:
		std::string username_s = username->getStringValue();
		std::string password_s = password->getStringValue();
		CCLOG("GET-Signup");
		HttpRequest* request = new HttpRequest();  
		std::string url = "http://whydemo.sinaapp.com/whyuser/sign_up/"+username_s+"/"+password_s;
		request->setUrl(url.c_str());  
		request->setRequestType(HttpRequest::Type::GET);  
		request->setResponseCallback(this, httpresponse_selector(SignupScene::onHttpRequestCompleted));    
		request->setTag("GET-Signup");  
		HttpClient::getInstance()->send(request);  
		request->release();
		break;
	}
}

void SignupScene::onHttpRequestCompleted(HttpClient *sender, HttpResponse *response) 
{
	if(!response || !response->isSucceed())
		return;

    std::vector<char>* buffer = response->getResponseData();  
    char res = (*buffer)[0];
	// ע��ɹ�
	if(res == '1')
	{
		// ת����¼����
		Scene *login = LoginScene::create(); 
		TransitionScene *transition = TransitionFade::create(0.5, login);
		Director::getInstance()->pushScene(transition);
	}
	// ע��ʧ�ܡ�������������
	else
	{
		username->setText("");
		password->setText("");
	}
}