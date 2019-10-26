#ifndef PONG_BALL_H
#define PONG_BALL_H
#include <iostream>
#include <time.h>
#include <conio.h>
using namespace std;
enum S_rule { STOP = 0, LEFT = 1, UPLEFT = 2, DOWNLEFT = 3, RIGHT = 4, UPRIGHT = 5, DOWNRIGHT = 6 };// các phương hướng di chuyển của Ball.
class Ball
{
private:
	int x, y;
	int originalX, originalY;
	S_rule direction;
	int speed;
public:
	Ball(int posX, int posY);
	void Reset();
	int getSpeed() { return speed; }
	void changeSpeed() {
		speed = speed-(speed/10);
	}
	void changeDirection(S_rule d);
	void randomDirection();
	inline int getX() { return x; }
	inline int getY() { return y; }
	inline S_rule getDirection() { return direction; }
	void Move();
};

#endif 