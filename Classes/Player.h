#include "cocos2d.h"
#define MAX_HP 3
#define MAX_SCORE 15

class Player:Sprite
{
    public:
        Player();
        void attach(Observer *observer);
        void detach(Observer *observer)
        void notify();
        virtual void setStatus(string s);
        virtual string getStatus();
    private:
        int HP = MAX_HP;
        bool isSpeedUp = false;
        bool isPoisoned = false;
        int score = 0;
        list<Observer* > m_observers;
	    string m_status;
}