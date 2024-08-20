#ifndef _CritterList
#define _CritterList

#include "Game Components\TEAL\CommonElements.h"
#include "Critter.h"

struct CritterNode {
	Critter* critter;
	CritterNode* prev;
	CritterNode* next;
};

class CritterList
{
private:
	static CritterList* ptrInstance;

	CritterList();
	CritterList(const CritterList&) = delete;
	CritterList& operator=(const CritterList&) = delete;
	~CritterList() = default;

	static CritterList& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new CritterList();
		return *ptrInstance;
	};

	void privInsertNode(Critter* c);
	void privRemoveNode(Critter* c);
	void privClear();

	bool privCentiAlive();
	bool privScorpionAlive();
	bool privSpiderAlive();

	CritterNode* head;
	CritterNode* tail;

public:
	static void insertNode(Critter* c) { Instance().privInsertNode(c); };
	static void removeNode(Critter* c) { Instance().privRemoveNode(c); };
	static void clear() { Instance().privClear(); };

	static bool centiAlive() { return Instance().privCentiAlive(); };
	static bool scorpionAlive() { return Instance().privScorpionAlive(); };
	static bool spiderAlive() { return Instance().privSpiderAlive(); };

	static void Terminate();
};

#endif _CritterList