#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include "Ball.h"
#include "Player.h"
using namespace std;

// Hàm thay đổi kích cỡ của khung cmd.
void FixConsoleWindow();
// Hàm tô màu.
void textcolor(int x);
//Ẩn con trỏ.
void ShowCur(bool CursorVisibility);
//// Hàm xóa màn hình.
void XoaManHinh();
void Draw_color(char str, int color);
class Graphics_and_Manger
{
private:
	int width, height;
	int score1, score2;
	char up1, down1, up2, down2;
	bool quit;
	Ball * ball;
	Player *player1;
	Player *player2;
public:
	Graphics_and_Manger(int w, int h);
	~Graphics_and_Manger();
	void ScoreUp(Player * player);
	void Draw();
	void Input();
	void Logic();
	void Run();
	void AI();
	void RunAI();
};
