#include "Ball.h"

Ball::Ball(int posX, int posY)
{
	//tọa độ ban đầu.
	originalX = posX;
	originalY = posY;
	x = posX; y = posY;
	direction = STOP;//Hướng của Ball.
	speed = 30;//tốc độ ban đầu.
}
void Ball::Reset()
{
	x = originalX; y = originalY;
	direction = STOP;
	speed = 30;
}
void Ball::changeDirection(S_rule d)
{
	direction = d;
}
void Ball::randomDirection()//random hướng di chuyển của ball khi reset.
{
	direction = (S_rule)((rand() % 6) + 1);
}
void Ball::Move()//Ball di chuyển.
{
	switch (direction)
	{
	case STOP:
		break;
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UPLEFT:
		x--; y--;
		break;
	case DOWNLEFT:
		x--; y++;
		break;
	case UPRIGHT:
		x++; y--;
		break;
	case DOWNRIGHT:
		x++; y++;
		break;
	default:
		break;
	}
}
