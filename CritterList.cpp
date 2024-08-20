#include "CritterList.h"
#include "Critter.h"

CritterList* CritterList::ptrInstance = nullptr;

CritterList::CritterList()
{
	head = NULL;
	tail = NULL;
}

void CritterList::privInsertNode(Critter* c)
{
	CritterNode* n = new CritterNode;
	n->critter = c;

	if (head == NULL) {
		head = n;
		n->prev = NULL;
	}
	else {
		tail->next = n;
		n->prev = tail;
	}

	tail = n;
	n->next = NULL;
}

void CritterList::privRemoveNode(Critter* c)
{
	CritterNode* n = head;
	while (n != NULL) {
		if (n->critter == c) {
			if (n->prev != NULL) n->prev->next = n->next;
			if (n->next != NULL) n->next->prev = n->prev;
			if (head == n) head = n->next;
			if (tail == n) tail = n->prev;
			delete n;
			return;
		}
		n = n->next;
	}
}

void CritterList::privClear()
{
	CritterNode* n = tail;
	if (n == NULL) return;
	if (n->prev == NULL) {
		n->critter->MarkForDestroy(); 
		return;
	}
	while (n != head) {
		n = n->prev;
		n->next->critter->MarkForDestroy();
	}
	n->critter->MarkForDestroy();
	head = NULL;
	tail = NULL;
}

bool CritterList::privCentiAlive()
{
	CritterNode* n = head;
	while (n != NULL) {
		if (n->critter->getType() == Critter::Types::Centipede) return true;
		n = n->next;
	}
	return false;
}

bool CritterList::privScorpionAlive()
{
	CritterNode* n = head;
	while (n != NULL) {
		if (n->critter->getType() == Critter::Types::Scorpion) return true;
		n = n->next;
	}
	return false;
}

bool CritterList::privSpiderAlive()
{
	CritterNode* n = head;
	while (n != NULL) {
		if (n->critter->getType() == Critter::Types::Spider) return true;
		n = n->next;
	}
	return false;
}

void CritterList::Terminate()
{
	CritterList::clear();
	delete ptrInstance;
	ptrInstance = nullptr;
}