#ifndef _MovementList
#define _MovementList

struct OffsetArray
{
	float Xoffset;
	float Yoffset;
	float Zoffset;

	OffsetArray(float x, float y, float z) : Xoffset(x), Yoffset(y), Zoffset(z) {};
};

class MovementList
{
public:
	static const OffsetArray OffsetsStraightRight[16];
	static const OffsetArray OffsetsTurnUpEndRight[16];
	static const OffsetArray OffsetsTurnDownEndRight[16];
	static const OffsetArray OffsetsStraightLeft[16];
	static const OffsetArray OffsetsTurnUpEndLeft[16];
	static const OffsetArray OffsetsTurnDownEndLeft[16];
	static const OffsetArray OffsetsNothing[16];
	static const OffsetArray OffsetsStraightDown[16];
};

#endif _MovementList