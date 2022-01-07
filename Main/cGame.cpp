#include "cGame.h"

void cGame::gameSettings() 
{
	system("cls");
	const char *setting[3] = { "Mode", "Sound", "Menu" };
	const char * currentSettting[3] = { "HARD", "ON", "" };
	if (constantVar::isHard) {
		currentSettting[0] = "HARD";
	}
	else
	{
		currentSettting[0] = "EASY";
	}
	if (constantVar::isMute) {
		currentSettting[1] = "OFF";
	}
	else {
		currentSettting[1] = "ON ";
	}
	int pos1 = 0;
	const int y = 20;
	const int x = 25;
	int flag = 0;
	int color = rand() % 7 + 9;
	map.printBorder();
	bool currentKey = true;
	while (1) {
		if (currentKey) {
			color = rand() % 7 + 9;
			TextColor(color);
			drawTitle();
			for (int i = 0; i < 4 - 1; i++) {
				gotoXY(x, y + i);
				if (i == pos1) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				}
				else {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				}
				cout << setting[i] << " " << currentSettting[i];
			}
			currentKey = false;
		}
		while (1) {
			if (_kbhit()) {
				currentKey = true;
				//system("cls");
				
				char key = _getch();
				if (key == 'W' || key == 'w') {
					pos1--;
					pos1 = (pos1 + 3) % 3;
					break;
				}
				if (key == 'S' || key == 's') {
					pos1++;
					pos1 %= 3;
					break;
				}
				if (key == 13) {
					switch (pos1) {
					case 0: {
						//Game mode : easy || hard
						toggleHard();
						if (constantVar::isHard) {
							currentSettting[0] = "HARD";
							if (!constantVar::isMute) {
								PlaySound(TEXT("RING.wav"), NULL, SND_ASYNC);
								PlaySound(TEXT("PUBG.wav"), NULL, SND_ASYNC);
							}
						}
						else
						{
							currentSettting[0] = "EASY";
							if (!constantVar::isMute) {
								PlaySound(TEXT("RING.wav"), NULL, SND_ASYNC);
								PlaySound(TEXT("PUBG.wav"), NULL, SND_ASYNC);
							}
						}
						break;
					}
					case 1: {
						toggleMute();
						if (constantVar::isMute) {
							currentSettting[1] = "OFF";
							if (constantVar::isMute)PlaySound(NULL("PUBG.wav"), NULL, SND_APPLICATION);
						}
						else {
							currentSettting[1] = "ON ";
							PlaySound(TEXT("RING.wav"), NULL, SND_ASYNC);
							PlaySound(TEXT("PUBG.wav"), NULL, SND_ASYNC);
						}
						//flag = 1;
						break;
					}
					case 2: {
						system("cls");
						flag = 1;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
						return;
					}
					}
					break;
				}

			}
		}
		
	}
	return;
}

void cGame::menu() {

	const string choice[5] = { "New Game","Load Game","Settings","Instruction","Quit" };
	int pos = 0;
	int x = 120, y = 10;
	bool changeInput = true;
	drawTitle();
	while (true) {
		changeInput = true;
		map.printBorder();
		while (true) {
			if (changeInput) {
				for (int i = 0; i < 5; i++) {
					gotoXY(x, y + i);
					if (i == pos)
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
					}
					else
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					}
					cout << choice[i] << endl;
				}

				int color = rand() % 7 + 9;
				TextColor(color);
				TextColor(7);
			}
			changeInput = false;
			switch (inputKey()) {
				changeInput = true;
			case 'w':
				changeInput = true;
				pos--;
				pos = (pos + 5) % 5;
				break;
			case 's':
				changeInput = true;
				pos++;
				pos %= 5;
				break;
			case 13:
				switch (pos) {
				case 0:
					while (1) {
						loading();
						if (newGame()) {
							Sleep(1000);
							clrscr();
							map.printBorder();
							changeInput = true;
							break;// win-quit
							Sleep(1000);
						}
						else if (!continueMenu()) {
							if (isLoaded) {
								map.~cMap();
								new(&map) cMap;
							}
							Sleep(1000);
							clrscr();
							map.printBorder();
				
							changeInput = true;
							break;//lose-quit
						}
					}
					break;
				case 1: {
					Sleep(1000);
					if (loadGameMenu()) {
						while (1) {
							loading();
							if (newGame()) {
								Sleep(1000);
								clrscr();
								map.printBorder();
								changeInput = true;
								break;//win-quit
								Sleep(1000);
							}
							else if (!continueMenu()) {
								Sleep(1000);
								TextColor(7);
								clrscr();
								map.printBorder();								
								changeInput = true;
								break;//lose-quit
							}
						}
					}
					else 
					{
						changeInput = true;
						map.printBorder();
					}
				}break;
				case 2:
				{
					Sleep(500);
					gameSettings();
					changeInput = true;
					map.printBorder();
				}break;
				case 3:
				{
					system("cls");
					gotoXY(30, 12); cout << "How to play:";
					gotoXY(30, 16); cout << "[ W ]: UP" << endl;
					gotoXY(30, 17); cout << "[ S ]: DOWN" << endl;
					gotoXY(30, 18); cout << "[ A ]: LEFT" << endl;
					gotoXY(30, 19); cout << "[ D ]: RIGHT" << endl;
					gotoXY(30, 22); cout << "[ L ]: Save game" << endl;
					gotoXY(30, 23); cout << "[ T ]: Load game" << endl;
					gotoXY(30, 24); cout << "[ P ]: Pause game/Menu" << endl;
					gotoXY(30, 25); cout << "PRESS W or S to go back." << endl;
				}break;
				case 4:
					system("cls");
					return;
				}break;
				break;
			}
		}
	}
}

bool cGame::continueMenu() {
	clrscr();
	map.printMap();
	map.deleteOldPlayer();
	map.bombEffect();
	gotoXY(125, 1); cout << "                                             " << endl;
	gotoXY(125, 2); cout << "                                             " << endl;
	gotoXY(100, 3); cout << "*******     *     * *       *******  ******  " << endl;
	gotoXY(100, 4); cout << "*          * *    * *       *        *     * " << endl;
	gotoXY(100, 5); cout << "*******   * * *   * *       *******  *     * " << endl;
	gotoXY(100, 6); cout << "*        *     *  * *       *        *     * " << endl;
	gotoXY(100, 7); cout << "*       *       * * ******* *******  ******  " << endl;
	gotoXY(125, 8); cout << "                                             " << endl;
	gotoXY(125, 9); cout << "                                             " << endl;
	gotoXY(120, 9); cout << "Continue ?" << endl;
	gotoXY(125, 11); cout << "                                             " << endl;
	gotoXY(125, 12); cout << "                                             " << endl;
	gotoXY(125, 13); cout << "                                             " << endl;
	gotoXY(125, 14); cout << "                                             " << endl;
	gotoXY(125, 15); cout << "                                             " << endl;
	const char *choice[2] = { "<YES>", "<NO>" };
	int pos = 0, x = 120, y = 10;
	TextColor(7);

	while (1) {
		TextColor(7);
		for (int i = 0; i < 2; i++) {
			if (i == pos) {
				TextColor(227);
				gotoXY(x, y + i);
				cout << choice[i];
				TextColor(7);
			}
			else {
				gotoXY(x, y + i);
				cout << choice[i];
			}
		}

		switch (inputKey()) {
		case 'w':
			pos--;
			pos = abs(pos);
			pos %= 2;
			break;
		case 's':
			pos++;
			pos %= 2;
			break;
		case 13:
			return !pos;
		}
	}

}


bool cGame::newGame() { // start a new game, initialize cMap map
	
	char key;
	if (!isLoaded) {
		map.~cMap();
		new(&map) cMap();
	}
	isPausing = false;
	map.printMap();
	if(!isLoaded) map.initializeNewState();
	isLoaded = false;

	const string choice[3] = { "Save Game","Load Game","Quit" };
	int pos = 0;
	while (!map.isEnd()) {
		if (!isPausing) {
			map.randomNextState();
		}

		int x = 125, y = 22;
		if (isPausing) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			gotoXY(125, 19); cout << "PAUSE MENU" << endl;
			for (int i = 0; i < 3; i++) {
				gotoXY(x, y + i);
				if (i == pos)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				}
				else
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				}
				cout << choice[i] << endl;
			}
		}
			
		if (_kbhit())
		{
			key = _getch();
			if (key == 'l')
			{
				//Save
				// call saveGame of cGame to get name of file
				saveGameMenu();
			}
			if (key == 't')
			{
				togglePauseGame();
				loadGameMenu();
				loading();
				clrscr();
				map.redrawMap();
				togglePauseGame();
				isLoaded = false;
			}
			if (key == 'p')
			{
				togglePauseGame();
				pos = 0; // reset pause menu selection
				if (!isPausing) { // map.redrawMap();
					gotoXY(125, 19); cout << "                  " << endl;
					for (int i = 0; i < 3; i++) {
						gotoXY(x, y + i);
						cout << "                 " << endl;
					}
				}
			}
			if (key == 'a')
			{
				if (!isPausing) map.updatePosPlayer('a');
			}
			if (key == 'w')
			{
				if(!isPausing) map.updatePosPlayer('w');
				else {
					pos--;
					pos = (pos + 3) % 3;
				}

			}
			if (key == 's')
			{
				if (!isPausing) map.updatePosPlayer('s');
				else {
					pos++;
					pos %= 3;
				}
			}
			if (key == 'd')
			{
				if (!isPausing) map.updatePosPlayer('d');
			}
			if (isPausing && key == 13) {
				switch (pos) {
				case 0:
					saveGameMenu();
					break;
				case 1:
					loadGameMenu();
					loading();
					clrscr();
					map.redrawMap();
					togglePauseGame();
					isLoaded = false;
					break;
				case 2:
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					return true;
				}
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			map.drawPlayer();
			map.hitMap();
		}
		if (map.isWin()) {
			if (!constantVar::isMute)PlaySound(TEXT("CompleteStage.wav"), NULL, SND_ASYNC);
			if (map.printLevelUp()) {
				clrscr();
				map.nextLevel();
				map.printMap();
				map.deleteOldPlayer();
				map.initializeNewState();
				map.drawPlayer();
			}
			else return true;
		}
	}
	return false;
}

bool cGame::continueGame()
{
	char key;
	isPausing = false;
	map.printMap();
	map.initializeNewState();
	const string choice[3] = { "Save Game","Load Game","Quit" };
	int pos = 0;
	while (!map.isEnd()) {
		if (!isPausing) {
			map.randomNextState();
		}

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		gotoXY(125, 5); cout << "PAUSE MENU" << endl;
		int x = 125, y = 10;
		for (int i = 0; i < 3; i++) {
			gotoXY(x, y + i);
			if (isPausing && i == pos)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			}
			cout << choice[i] << endl;
		}

		if (_kbhit())
		{
			key = _getch();
			if (key == 'l')
			{
				//Save
				// call saveGame of cGame to get name of file
				togglePauseGame();
				saveGameMenu();
				togglePauseGame();
			}
			if (key == 't')
			{
				togglePauseGame();
				loadGameMenu();
				togglePauseGame();
			}
			if (key == 'p')
			{
				togglePauseGame();
				pos = 0; // reset pause menu selection
			}
			if (key == 'a')
			{
				if (!isPausing) map.updatePosPlayer('a');
			}
			if (key == 'w')
			{
				if (!isPausing) map.updatePosPlayer('w');
				else {
					pos--;
					pos = (pos + 3) % 3;
				}

			}
			if (key == 's')
			{
				if (!isPausing) map.updatePosPlayer('s');
				else {
					pos++;
					pos %= 3;
				}
			}
			if (key == 'd')
			{
				if (!isPausing) map.updatePosPlayer('d');
			}
			if (isPausing && key == 13) {
				switch (pos) {
				case 0:
					saveGameMenu();
					break;
				case 1:
					loadGameMenu();
					break;
				case 2:
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					return true;
				}
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			map.drawPlayer();
			map.hitMap();
		}
		if (map.isWin()) {
			if (map.printLevelUp()) {
				clrscr();
				map.nextLevel();
				map.printMap();
				map.deleteOldPlayer();
				map.initializeNewState();
				map.drawPlayer();
			}
			else return true;
		}
	}
	return false;
}


void cGame::loading()
{
	map.printMap();
	map.deleteOldPlayer();
	drawTitle();
	srand(NULL);
	int i = 7;
	int x = 20;
	gotoXY(x, i++);
	TextColor(10);
	gotoXY(40, 27);
	cout << "LOADING : ";
	int j, k;
	for (int i = 0; i < 100; i++) {
		gotoXY(49, 27);
		cout << i << " %";
		Sleep(10);
		gotoXY( i, 28);
		cout << char(219);
	}
}

vector<string> cGame::getAllFilename(const string& name)
{
		vector<string> v;
		string pattern(name);
		pattern.append("\\*");
		std::wstring stemp = std::wstring(pattern.begin(), pattern.end());
		LPCWSTR sw = stemp.c_str();
		WIN32_FIND_DATA data;					
		HANDLE hFind;
		if ((hFind = FindFirstFile(sw, &data)) != INVALID_HANDLE_VALUE) {
			do {
				wchar_t* txt = data.cFileName;
				wstring ws(txt);
				// your new String
				string str(ws.begin(), ws.end());
				if (str[0] == '.') continue;
				// Show String
				v.push_back(str);
			} while (FindNextFile(hFind, &data) != 0);
			FindClose(hFind);
		}
		return v;
}

bool cGame::loadGameMenu() { // get file of cMap map
	string filename;
	clrscr();
	vector <string> files = getAllFilename("data");
	if (files.size() == 0) {
		gotoXY(30, 15);
		cout << "No saved file to load !!!";
		Sleep(1000);
		return false;
	}
	int curPos = 0;
	clrscr();
	map.printBorder();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	gotoXY(15, 5); cout << "**      *******      ****     *******" << endl;
	gotoXY(15, 6); cout << "**     **     **    **  **    **     *" << endl;
	gotoXY(15, 7); cout << "**     **     **   ********   **      * **     ** ******** **    ** **    **" << endl;
	gotoXY(15, 8); cout << "****** **     **  **********  **     *  ** * * ** **       ** *  ** **    **" << endl;
	gotoXY(15, 9); cout << "******  *******  **        ** *******   **  *  ** *******  **  * ** **    **" << endl;
	gotoXY(15, 10); cout << "                                        **     ** **       **   *** **    **" << endl;
	gotoXY(15, 11); cout << "                                        **     ** ******** **    ** ********" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	gotoXY(30, 13); cout << "<Press ESC to escape...>";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	gotoXY(30, 15);
	

	for (int i = 0; i < (int)files.size(); ++i) {
		if (i == curPos) {
			gotoXY(26, 16 + i);
			cout << ">> ";
		}
		gotoXY(30, 16 + i);
		cout << files[i] << endl;
	}
	while (true) {
		if (_kbhit())
		{
			char key=_getch();
			if (key == 'w')
			{
				gotoXY(26, 16 + curPos);
				cout << "    " << files[curPos];
				curPos--;
				curPos = (curPos + files.size()) % files.size();
				gotoXY(26, 16 + curPos);
				cout << ">>  " << files[curPos];
			}
			if (key == 's')
			{
				gotoXY(26, 16 + curPos);
				cout << "    " << files[curPos];
				curPos++;
				curPos = (curPos + files.size()) % files.size();
				gotoXY(26, 16 + curPos);
				cout << ">>  " << files[curPos];
			}
			if (key == 13)
			{
				isLoaded = true;
				map.loadGame(files[curPos]);
				clrscr();
				//map.redrawMap();
				return true;
			}
			if (key == 27)
			{
				clrscr();
				//map.redrawMap();
				return false;
			}
		}
		Sleep(200);
	}
}

void cGame::saveGameMenu() { // get file of cMap ma
	string filename;
	clrscr();
	//map.printBorder();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	gotoXY(15, 5); cout << "*******       *   **      ** *******    **     ** ******** **    ** **    **  " << endl;
	gotoXY(15, 6); cout << " **          *  *  **    **  **         ** * * ** **       ** *  ** **    ** " << endl;
	gotoXY(15, 7); cout << "   **      *  ** *  **   **  *******    **  *  ** *******  **  * ** **    **  " << endl;
	gotoXY(15, 8); cout << "     **   *       *  ** **   **         **     ** **       **   *** **    **   " << endl;
	gotoXY(15, 9); cout << "******   *         *  **     *******    **     ** ******** **    ** ********  " << endl;                                  
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	gotoXY(15, 20);
	cout << "<Press ESC to escape>";
	map.deleteOldPlayer();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	gotoXY(15, 15);
	cout << "Input file name to save: ";
	//getline(cin, filename);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	char key;
	while ((key = _getch()) != 27 ) {
		switch (key) {
		case '\b':
			if (filename.size() != 0) {
				filename.pop_back();
				gotoXY(50, 15);
				cout << "                                                 ";
				gotoXY(50, 15);
				cout << filename;
			}
			break;
		case 13:
			map.saveGame(filename);
			break;
		default:
			filename.push_back(key);
			gotoXY(50, 15);
			cout << filename;
		}
		if (key == 13) break;
	}
	clrscr();
	map.redrawMap();
	//isPausing = false;
	//file = file + ".txt";
	//map.saveGame(filename);
}

void cGame::togglePauseGame() { // toggle status of isPausing
	isPausing = !isPausing;
};

void cGame::toggleMute()
 {
	constantVar::isMute = !constantVar::isMute;
}


void cGame::toggleHard()
{
	constantVar::isHard = !constantVar::isHard;
}