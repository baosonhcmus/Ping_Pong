#include "Menu.h"



Menu::Menu()
{
}
void Menu::StartGame() {
	Ping_Pong_asciiart();
	wprintf(
		L"\n\n\n\t\t --------------------------------\n"
		L"\t\t|            MENU               |\n"
		L"\t\t|                               |\n"
		L"\t\t|                               |\n"
		L"\t\t|     N to New Game             |\n"
		L"\t\t|     A to Play with AI         |\n"
		L"\t\t|     E to Exit                 |\n"
		L"\t\t|                               |\n"
		L"\t\t --------------------------------\n"
	);
	char key = _getch();
	if (key == 'n') {
		system("cls");
		Graphics_and_Manger pong(80, 20);
		FixConsoleWindow();
		pong.Run();
	}
	else if (key == 'a'){
		system("cls");
		Graphics_and_Manger pong(80, 20);
		FixConsoleWindow();
		pong.RunAI();
	}
	else if (key == 'e') {
		exit(0);
	}
}

void Menu::Ping_Pong_asciiart() {
		textcolor(12);
		wprintf(

			L" ________  ___  ________   ________          ________  ________  ________   ________      \n"
			L"|\\   __  \\|\\  \\|\\   ___  \\|\\   ____\\        |\\   __  \\|\\   __  \\|\\   ___  \\|\\   ____\\     \n"
			L"\\ \\  \\|\\  \\ \\  \\ \\  \\\\ \\  \\ \\  \\___|        \\ \\  \\|\\  \\ \\  \\|\\  \\ \\  \\\\ \\  \\ \\  \\___|     \n"
			L" \\ \\   ____\\ \\  \\ \\  \\\\ \\  \\ \\  \\  ___       \\ \\   ____\\ \\  \\\\\\  \\ \\  \\\\ \\  \\ \\  \\  ___   \n"
			L"  \\ \\  \\___|\\ \\  \\ \\  \\\\ \\  \\ \\  \\|\\  \\       \\ \\  \\___|\\ \\  \\\\\\  \\ \\  \\\\ \\  \\ \\  \\|\\  \\  \n"
			L"   \\ \\__\\    \\ \\__\\ \\__\\\\ \\__\\ \\_______\\       \\ \\__\\    \\ \\_______\\ \\__\\\\ \\__\\ \\_______\\ \n"
			L"    \\|__|     \\|__|\\|__| \\|__|\\|_______|        \\|__|     \\|_______|\\|__| \\|__|\\|_______| \n"
		);
}

Menu::~Menu()
{
}
