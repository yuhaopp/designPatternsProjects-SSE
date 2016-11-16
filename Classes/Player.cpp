#include "Player.h"
#include "cocos2d.h"

void attach(Observer *observer)
{
    m_observers.push_back(observer);
}

void detach(Observer *observer)
{
    m_observers.remove(observer);
}

void notify()
{
	list<Observer*>::iterator iter = m_observers.begin();
	for(;iter!=m_observers.end();iter++)
		(*iter)->Update();
}

virtual void setStatus(string s)
{
    m_status=s;
}

virtual string getStatus()
{
    return m_status;
}