#include "Graphics_and_Manger.h"
// hàm thay đổi kích cỡ của khung cmd.
void FixConsoleWindow() {
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}
//Ẩn con trỏ.
void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}

// hàm tô màu.
void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}

// Hàm xóa màn hình.
void XoaManHinh()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}
void Draw_color(char str, int color)
{
	textcolor(color);
	cout << str;
	textcolor(7);
}
Graphics_and_Manger::Graphics_and_Manger(int w, int h)
{
	srand(time(NULL));
	quit = false;
	up1 = 'w'; up2 = 72;
	down1 = 's'; down2 = 80;
	score1 = score2 = 0;
	width = w; height = h;
	ball = new Ball(w / 2, h / 2);//Vị trí ban đầu của Ball.
	player1 = new Player(1, h / 2 - 3);//Vị trí ban đầu của Player1.
	player2 = new Player(w - 2, h / 2 - 3);//Vị trí ban đầu của Player2.
}
Graphics_and_Manger::~Graphics_and_Manger()
{
	delete ball, player1, player2;
}
void Graphics_and_Manger::ScoreUp(Player * player)
{
	if (player == player1)
		score1++;
	else if (player == player2)
		score2++;

	ball->Reset();
	player1->Reset();
	player2->Reset();
}
void Graphics_and_Manger::Draw()
{
	XoaManHinh();
	Sleep(ball->getSpeed());
	for (int i = 0; i < width + 2; i++)
		Draw_color(' ', 56);
	cout << endl;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width+5; j++)
		{
			int ballx = ball->getX();
			int bally = ball->getY();
			int player1x = player1->getX();
			int player2x = player2->getX();
			int player1y = player1->getY();
			int player2y = player2->getY();

			if (j == 0)
				Draw_color(' ', 56);

			if (ballx == j && bally == i)
				Draw_color('O', 13);
			else if (player1x == j && player1y == i)
				Draw_color(' ', 108);
			else if (player1x == j && player1y + 1 == i)
				Draw_color(' ', 108);
			else if (player1x == j && player1y + 2 == i)
				Draw_color(' ', 108);
			else if (player1x == j && player1y + 3 == i)
				Draw_color(' ', 108);
			else if (player2x == j && player2y == i)
				Draw_color(' ', 120);
			else if (player2x == j && player2y + 1 == i)
				Draw_color(' ', 120);
			else if (player2x == j && player2y + 2 == i)
				Draw_color(' ', 120);
			else if (player2x == j && player2y + 3 == i)
				Draw_color(' ', 120);
			else
				cout << " ";
			if (j == width + 2 && i == height - 7) { 
				textcolor(108);
				cout << "Score_Player1";
				textcolor(7);
				cout<<" "<< score1; 
			}
			if (j == width + 2 && i == height - 5) {
				textcolor(120);
				cout << "Score_Player2";
				textcolor(7);
				cout << " "<< score2;
				
			}
			if (j == width + 2 && i == height - 3) {
				textcolor(1);
				cout << "Press Q to Quit";
				textcolor(7);
			}
			if (j == width + 2 && i == height-2) {
				textcolor(2);
				cout << "Press P to Pause";
				textcolor(7);
			}
			if (j == width + 2 && i == height - 1) {
				textcolor(3);
				cout << "Press R to Resume";
				textcolor(7);
			}
			if (j == width - 1)
				Draw_color(' ', 56);
		}
		cout << endl;
	}

	for (int i = 0; i < width + 2; i++)
		Draw_color(' ', 56);
	cout << endl;

}
void Graphics_and_Manger::Input()//
{
	ball->Move();

	int ballx = ball->getX();
	int bally = ball->getY();
	int player1x = player1->getX();
	int player2x = player2->getX();
	int player1y = player1->getY();
	int player2y = player2->getY();

	if (_kbhit())
	{
		char current = _getch();
		if (current == up1)
			if (player1y > 0)
				player1->moveUp();
		if (current == up2)
			if (player2y > 0)
				player2->moveUp();
		if (current == down1)
			if (player1y + 4 < height)
				player1->moveDown();
		if (current == down2)
			if (player2y + 4 < height)
				player2->moveDown();
		if (ball->getDirection() == STOP)
			ball->randomDirection();
		if (current == 'p') {
			char p;
			do {
				if (_kbhit())
				{
					p = _getch();
				}
			} while (p != 'R' && p != 'r');
		}
		if (current == 'q')
			quit = true;
	}
}
void Graphics_and_Manger::AI() //Cho Player2 chạy theo tọa độ của ball.
{ 
	int ballx = ball->getX();
	int bally = ball->getY();
	int player2x = player2->getX();
	int player2y = player2->getY();
	if (bally > player2y) {
		player2->moveDown();
	}
	else if (bally < player2y)
		player2->moveUp();
}
void Graphics_and_Manger::Logic()
{
	int ballx = ball->getX();
	int bally = ball->getY();
	int player1x = player1->getX();
	int player2x = player2->getX();
	int player1y = player1->getY();
	int player2y = player2->getY();

	//chạm Player1 bên trái.
	for (int i = 0; i < 4; i++)
		if (ballx == player1x + 1)
			if (bally == player1y + i) {
				ball->changeDirection((S_rule)((rand() % 3) + 4));//Ball chạy theo 3 hướng 4,5,6.
				ball->changeSpeed();
			}
	//chạm Player2 bên phải.
	for (int i = 0; i < 4; i++)
		if (ballx == player2x - 1)
			if (bally == player2y + i) {
				ball->changeDirection((S_rule)((rand() % 3) + 1));//Ball chạy theo 3 hướng 1,2,3.
				ball->changeSpeed();
			}
	//chạm tường dưới.
	if (bally == height - 1)
		ball->changeDirection(ball->getDirection() == DOWNRIGHT ? UPRIGHT : UPLEFT);//Ball chạy theo hướng 5 nếu trước khi chạm là hướng 6 ngược lại thì hướng 2.
	//chạm tường trên
	if (bally == 0)
		ball->changeDirection(ball->getDirection() == UPRIGHT ? DOWNRIGHT : DOWNLEFT);//Ball chạy theo hướng 6 nếu trước khi chạm là hướng 5 ngược lại thì hướng 3.
	//chạm tường phải
	if (ballx == width - 1)
		ScoreUp(player1);
	//chạm tường trái
	if (ballx == 0)
		ScoreUp(player2);
}
void Graphics_and_Manger::Run()
{
	while (!quit)
	{
		ShowCur(0);
		Draw();
		Input();
		Logic();
	}
}
void Graphics_and_Manger::RunAI()
{
	while (!quit)
	{
		ShowCur(0);
		Draw();
		Input();
		AI();
		Logic();
	}
}

