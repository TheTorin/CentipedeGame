#ifndef _Critter
#define _Critter

#include "Game Components\TEAL\CommonElements.h"

class Critter : public GameObject
{
public:
	Critter() = default;
	Critter(const Critter&) = delete;
	Critter& operator=(const Critter&) = delete;
	~Critter() = default;

	enum class Types { Centipede, Flea, Scorpion, Spider };

	virtual Types getType() = 0;
};

#endif _Critter
