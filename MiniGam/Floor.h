#include "Actor.h"
class AFloor : public AActor
{
public:
	AFloor();
	AFloor(int NewX, int NewY, char NewShape);
	virtual ~AFloor();
private:
	int X;
	int Y;
	char Shape;
	bool Collision;
};
