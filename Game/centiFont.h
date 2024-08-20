#ifndef _CentiFont
#define _CentiFont

#include "SpriteSheet.h"

class CentiFont : public SpriteSheet
{
public:

	CentiFont();

	CentiFont(const CentiFont&) = delete;
	CentiFont& operator=(const CentiFont&) = delete;
	virtual ~CentiFont() = default;

	virtual int CharToIndex(char& c);
private:
};


#endif _CentiFont'
