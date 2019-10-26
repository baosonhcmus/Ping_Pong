
#ifndef PONG_PLAYER_H
#define PONG_PLAYER_H
#include <iostream>
using namespace std;
class Player
{
private:
	int x, y;
	//Vị trí ban đầu của Player.
	int originalX, originalY;
public:
	Player(int posX, int posY);
	void Reset() { x = originalX; y = originalY; }
	int getX() { return x; }
	int getY() { return y; }
	void moveUp() { y--; }
	void moveDown() { y++; }
	~Player();
};
#endif