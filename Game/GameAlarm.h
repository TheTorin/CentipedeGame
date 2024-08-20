#ifndef _GameAlarm
#define _GameAlarm

#include "Game Components\TEAL\CommonElements.h"

class GameAlarm : public GameObject
{
public:
	GameAlarm();
	GameAlarm(const GameAlarm&) = delete;
	GameAlarm& operator=(const GameAlarm&) = delete;
	~GameAlarm();

	void Init();

	virtual void Update();

	virtual void Alarm0();
	virtual void Alarm1();
	virtual void Alarm2();
	virtual void Alarm3();

	void playerRespawn();
	void spiderRespawn(float time);
	void scorpionRespawn(float time);
	void fleaBegin();

private:
};

#endif _GameAlarm
