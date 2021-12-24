#include "cMap.h"
#include "cConsole.h"

cMap::cMap() : width(100), height(27)
{
	int f = 0, e = width - 1;
	for (int i = 1; i < width; i++)
	{
		map[0][i] = map[4][i] = map[8][i] = map[12][i] = map[16][i] = map[24][i] = char(196);
		if (i < width - 1)
		{
			map[1][i] = ' '; map[2][i] = ' '; map[3][i] = ' '; map[5][i] = ' '; map[6][i] = ' ';
			map[7][i] = ' '; map[9][i] = ' '; map[10][i] = ' '; map[11][i] = ' ';
			map[13][i] = ' '; map[14][i] = ' '; map[15][i] = ' '; map[17][i] = ' '; map[18][i] = ' ';
			map[19][i] = ' '; map[20][i] = ' '; map[21][i] = ' '; map[22][i] = ' '; map[23][i] = ' ';
		}

	}
	map[0][0] = char(218);
	map[0][width - 1] = char(191);
	for (int i = 1; i < 27; i++)
	{
		map[i][f] = char(179);
		map[i][e] = char(179);
	}
	map[4][0] = char(195); map[8][0] = char(195); map[12][0] = char(195);
	map[16][0] = char(195); map[20][0] = char(179); map[24][0] = char(192);
	map[4][e] = char(180); map[8][e] = char(180); map[12][e] = char(180);
	map[16][e] = char(180); map[20][e] = char(180); map[24][e] = char(217);
}

void cMap::resetMap() {
	cout << "This is resetMap" << endl;
	int f = 0, e = width - 1;
	for (int i = 1; i < width; i++)
	{
		map[0][i] = map[4][i] = map[8][i] = map[12][i] = map[16][i] = map[24][i] = char(196);
		if (i < width - 1)
		{
			map[1][i] = ' '; map[2][i] = ' '; map[3][i] = ' '; map[5][i] = ' '; map[6][i] = ' ';
			map[7][i] = ' '; map[9][i] = ' '; map[10][i] = ' '; map[11][i] = ' ';
			map[13][i] = ' '; map[14][i] = ' '; map[15][i] = ' '; map[17][i] = ' '; map[18][i] = ' ';
			map[19][i] = ' '; map[20][i] = ' '; map[21][i] = ' '; map[22][i] = ' '; map[23][i] = ' ';
		}

	}
	map[0][0] = char(218);
	map[0][width - 1] = char(191);
	for (int i = 1; i < 26; i++)
	{
		map[i][f] = char(179);
		map[i][e] = char(179);
	}
	map[4][0] = char(195); map[8][0] = char(195); map[12][0] = char(195);
	map[16][0] = char(195); map[20][0] = char(179); map[24][0] = char(192);
	map[4][e] = char(180); map[8][e] = char(180); map[12][e] = char(180);
	map[16][e] = char(180); map[20][e] = char(180); map[24][e] = char(217);
}
void cMap::printBorder()
{
	clrscr();
	gotoXY(0, 0);
	for (int i = 0; i < height - 2; i++) {
		//cout << "  ";
		for (int j = 0; j < width; j++) {
			cout << map[i][j];
		}
		cout << endl;
	}
	gotoXY(115, 1); cout << "Road Crossing Game";
}
void cMap::printMap()
{
	int color = rand() % 7 + 9;
	TextColor(color);
	clrscr();
	gotoXY(0, 0);
	for (int i = 0; i < height - 2; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			cout << map[i][j];
		}
		cout << endl;
	}
	gotoXY(120, 1); cout << "<Crossing Road Game>";
	gotoXY(120, 3); cout << "LV. " << level.getLevel() << endl;
	gotoXY(120, 5); cout << "CONTROL MANUAL" << endl;
	gotoXY(120, 6); cout << "[ W ]: UP" << endl;
	gotoXY(120, 7); cout << "[ S ]: DOWN" << endl;
	gotoXY(120, 8); cout << "[ A ]: LEFT" << endl;
	gotoXY(120, 9); cout << "[ D ]: RIGHT" << endl;
	gotoXY(120, 11); cout << "COMMANDS" << endl;
	gotoXY(120, 12); cout << "[ L ]: Save game" << endl;
	gotoXY(120, 13); cout << "[ T ]: Load game" << endl;
	gotoXY(120, 14); cout << "[ P ]: Pause game/Menu" << endl;
	int x = 1;
	int i = 28;
	gotoXY(x, i++);
	TextColor(12);
	cout << "     ______                                         |oo|                            ______     /  |                                     /  |    ";
	gotoXY(x, i++);
	cout << "   $$$$$$  |  ______    ______     ______   ______  |oo|   _______    ______       /$$$$$$    _$$ |_     ______    ______    ______    _$$ |_   ";
	gotoXY(x, i++);
	cout << "  $$ |  $$/  /         /          /       |/        __    /          /             $$  __$$  / $$   |   /         /         /         / $$   |  ";
	gotoXY(x, i++);
	cout << "  $$ |      /$$$$$$  |/$$$$$$  |/$$$$$$$//$$$$$$$/  $$ | $$$$$$$  |/$$$$$$  |      $$        $$$$$$/   /$$$$$$ | /$$$$$$   /$$$$$$  | $$$$$$/   ";
	gotoXY(x, i++);
	cout << "  $$ |   __ $$ |  $$/ $$ |  $$ |$$       $$         $$ | $$ |  $$ |$$ |  $$ |       $$$$$$     $$ | __ $$ |  $$/ $$    $$  $$    $$ |   $$ | __ ";
	gotoXY(x, i++);
	cout << "  $$ |__/  |$$ |      $$ |__$$ | $$$$$$  |$$$$$$  | $$ | $$ |  $$ |$$ |__$$ |          __$$|   $$ |/  |$$ |      $$$$$$$$/ $$$$$$$$/    $$ |/  |";
	gotoXY(x, i++);
	cout << "  $$    $$/ $$ |      $$    $$/  _____$$/ _____$$/  $$ | $$ |  $$ |$$    $$ |      $$| _ $$/   $$  $$/ $$ |      $$        $$       |   $$  $$/ ";
	gotoXY(x, i++);
	cout << "   $$$$$$/  $$/        $$$$$$/  $$$$$$$/ $$$$$$$/   $$/  $$/   $$/  $$$$$$$ |       $$$$$$/    $$$$/   $$/        $$$$$$$/  $$$$$$$/     $$$$/  ";
	gotoXY(x, i++);
	cout << "                                                                         $$ |                                                                 ";
	gotoXY(x, i++);
	cout << "                                                                  $$     $$/                                                                  ";
	gotoXY(x, i++);
	cout << "                                                                    $$$$$$/                                                                   ";
	drawPlayer();
}

void cMap::hitMap() {
	//resetMap();
	vector <animal_vehical*> enemyList = rowsData.listEnemy(); //enemyList = 0 
	for (int i = 0; i < (int)enemyList.size(); ++i) {
		//drawEnemies(enemyList[i]);
		if (people.Impact(enemyList[i]->getPos(), enemyList[i]->getWidth() - 3, enemyList[i]->getHeight())) {
			if (!constantVar::isMute) enemyList[i]->sound();
			people.killPlayer();
			//randomNextState();
			deleteOldPlayer();
			drawPlayer();
			Sleep(300);
			clrscr();
			printMap();
			deleteOldPlayer();
			bombEffect();
			return;
		}
	}
	//drawPlayer();
}

int cMap::draw(cPosition pos, char ** shape, int w, int h) {
	int X = pos.getX();
	int Y = pos.getY();
	if (Y + w <= 0) return 0;
	if (Y > width) return 0;
	for (int i = 0; i < h; ++i) {
		for (int j = max(1, Y); j <= min(width, Y + w - 1); ++j) {
			gotoXY(Y + j, X + i);
			cout << shape[i][j - max(1, Y)];
		}
	}
	return 1;
}

void cMap::drawEnemies(animal_vehical* enemy) { // deleted
	int status = draw(enemy->getPos(), enemy->array2(), enemy->getWidth(), enemy->getHeight());
	if (status == 0) {
		enemy->goOutMap();
	}
	if (status == -1) {
		people.killPlayer();
	}
}

void cMap::drawPlayer() {
	int status = draw(people.getPos(), people.array2(), people.getWidth(), people.getHeight());
	if (status == -1) {
		people.killPlayer();
	}
}

void cMap::deleteOldPlayer() {
	draw(people.getPos(), people.emptyShape(), people.getWidth(), people.getHeight());
}


void cMap::initializeNewState() {
	people.~cPeople();
	new(&people) cPeople();
	rowsData.~cRows();
	new(&rowsData) cRows();
	int padding[10];
	for (int i = 1; i < 5; ++i) {
		padding[i] = 0;
		int speed = rand() % (level.getMinSpeed() - level.getMaxSpeed()) + level.getMaxSpeed();
		bool direction = rand() % 5;
		bool redLight = rand() % 5;
		rowsData.pushRow(new cOneRow(speed, direction, redLight, (i * 2)));
	}
	animal_vehical* newEnemy;
	cPosition pos;
	int tryCount = 10;
	while (tryCount--) {
		int rRow = (rand() % 9) + 1;
		padding[rRow] += (rand() % 20) + 9;
		pos = cPosition((rRow * 2), padding[rRow]);
		newEnemy = level.randNewEnemy(pos);
		if (!newEnemy) break;
		if (!rowsData.pushEnemy(rRow, newEnemy)) {
			level.decNEnemy(1);
			delete newEnemy;
		};
	}
	Sleep(300);
	rowsData.moveToNextState(2);
}

void cMap::randomNextState() {
	srand(time(NULL));
	//int t = rand(); // this will be get from global clock
	animal_vehical* newEnemy;
	cPosition pos;
	int tryCount = 10000;
	while (tryCount--) {
		int rRow = (rand() % 4) + 1;
		pos = cPosition((rRow * 5) + 1, 4);
		newEnemy = level.randNewEnemy(pos);
		if (!newEnemy) break;
		if (!rowsData.pushEnemy(rRow, newEnemy)) {
			level.decNEnemy(4);
			delete newEnemy;
		};
	}
	++t;
	int tmp = rowsData.moveToNextState(t);
	level.decNEnemy(tmp);
	hitMap();
}

void cMap::redrawMap() {
	printMap();
	int tmp = rowsData.moveToNextState(t);
	level.decNEnemy(tmp);
	hitMap();
}

void cMap::updatePosPlayer(char moving) {
	deleteOldPlayer();
	if (moving == 'a' || moving == 'A') people.Left();
	else if (moving == 'w' || moving == 'W') people.Up();
	else if (moving == 'd' || moving == 'D') people.Right();
	else if (moving == 's' || moving == 'S') people.Down();
	else return;
}

bool cMap::isEnd()
{
	return people.checkIsDead();
}
bool cMap::isWin()
{
	if (people.getX() == 2) {
		if (!constantVar::isMute)PlaySound(TEXT("CompleteStage.wav"), NULL, SND_ASYNC);
		return true;
	}
	return false;
}

void cMap::bombEffect()
{
	const int baseX = 10, baseY = 10;
	gotoXY(baseX, baseY);
	cout << R"(                                               ____                       )" << "\n";
	gotoXY(baseX, baseY + 1);
	cout << R"(                                           __,-~~/~    `---.                  )" << "\n";
	gotoXY(baseX, baseY + 2);
	cout << R"(                                         _/_,---(      ,    )                 )" << "\n";
	gotoXY(baseX, baseY + 3);
	cout << R"(                                     __ /        <    /   )  \___             )" << "\n";
	gotoXY(baseX, baseY + 4);
	cout << R"(                      - ------===;;;'====------------------===;;;===----- -  -)" << "\n";
	gotoXY(baseX, baseY + 5);
	cout << R"(                                      \/  ~"~"~"~"~"~\~"~)~" / )" << "\n";
	gotoXY(baseX, baseY + 6);
	cout << R"(                                        (_ (   \  (     >    \)               )" << "\n";
	gotoXY(baseX, baseY + 7);
	cout << R"(                                         \_( _ <         >_>'                 )" << "\n";
	gotoXY(baseX, baseY + 8);
	cout << R"(                                            ~ `-i' ::>|--"                    )" << "\n";
	gotoXY(baseX, baseY + 9);
	cout << R"(                                                I;|.|.|                       )" << "\n";
	gotoXY(baseX, baseY + 10);
	cout << R"(                                               <|i::|i|`.                     )" << "\n";
	gotoXY(baseX, baseY + 11);
	cout << R"(                                              (` ^'"`-' ")                    )";
}

void cMap::nextLevel() {
	level.nextLevel();
}

void cMap::printInt(int x, ofstream& outfile) {
	outfile.write((char*)&x, sizeof(int));
}

int cMap::readInt(ifstream& infile) {
	int x;
	infile.read((char*)&x, sizeof(int));
	return x;
}

void cMap::saveGame(string file)
{
	ofstream outfile("./data/" + file + ".bin", ios::out | ios::binary);
	printInt(level.getLevel(), outfile);
	printInt(people.getX(), outfile);
	printInt(people.getY(), outfile);

	vector <cOneRow*> rows(rowsData.listRow());
	for (int i = 0; i < 5; ++i) {
		printInt(rows[i]->getCurrentRow(), outfile);
		printInt((int)rows[i]->getDirection(), outfile);
		printInt(rows[i]->getSpeed(), outfile);
		printInt((int)rows[i]->getRedLight(), outfile);

		vector <animal_vehical*> enemy(rows[i]->getEnemy());
		printInt((int)enemy.size(), outfile);

		for (int j = 0; j < (int)enemy.size(); ++j) {
			printInt(enemy[j]->getX(), outfile);
			printInt(enemy[j]->getY(), outfile);
			printInt(enemy[j]->getType(), outfile);
		}
	}
	outfile.close();
}

bool cMap::loadGame(string file) {
	ifstream infile("./data/" + file, ios::in | ios::binary);
	if (!infile.is_open()) {
		return false;
	}
	int lv = readInt(infile);
	level.~cLevel();
	new(&level) cLevel(lv, 0);
	int playerX, playerY;
	playerX = readInt(infile);
	playerY = readInt(infile);
	people.~cPeople();
	new(&people) cPeople(cPosition(playerX, playerY));

	int nEnemy = 0;

	rowsData.~cRows();
	new(&rowsData) cRows();

	for (int i = 0; i < 5; ++i) {
		int currentRow, direction, speed, redLight;
		currentRow = readInt(infile);
		direction = readInt(infile);
		speed = readInt(infile);
		redLight = readInt(infile);

		rowsData.pushRow(new cOneRow(speed, direction, redLight, currentRow));
		
		int enemySize = readInt(infile);
		nEnemy += enemySize;
		
		for (int j = 0; j < enemySize; ++j) {
			int eX, eY, eType;
			eX = readInt(infile);
			eY = readInt(infile);
			eType = readInt(infile);
			rowsData.pushEnemy(i, level.getNewEnemy(cPosition(eX, eY), eType));
		}
	}
	infile.close();
	return true;
}

void cMap::printCongrats()
{
	clrscr();
	printMap();	
	deleteOldPlayer();
	if (!constantVar::isMute)PlaySound(TEXT("CompleteStage.wav"), NULL, SND_ASYNC);
	gotoXY(120, 2); cout << "*         *         * * *      *  " << endl;
	gotoXY(120, 3); cout << " *       * *       *  * * *    *  " << endl;
	gotoXY(120, 4); cout << "  *     *   *     *   * *  *   *  " << endl;
	gotoXY(120, 5); cout << "   *   *     *   *    * *   *  *  " << endl;
	gotoXY(120, 6); cout << "    * *       * *     * *    * *  " << endl;
	gotoXY(120, 7); cout << "     *         *      * *     **  " << endl;
	gotoXY(130, 8); cout << "Exit ?" << endl;
	const char *choice[2] = { "<YES>", "<OF COURSE>" };
	int pos = 0, x = 130, y = 10;
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
			return ;
		}
	}
}

bool cMap::printLevelUp() {
	if (level.getLevel() == 5)
	{
		printCongrats();
		return false;
	}
	else {
		clrscr();
		printMap();
		deleteOldPlayer();
		gotoXY(120, 15); cout << "Continue ?" << endl;
		const char *choice[2] = { "<YES>", "<NO>" };
		int pos = 0, x = 120, y = 17;
		TextColor(7);

		while (1) {
			TextColor(7);
			for (int i = 0; i < 2; i++) 
			{
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
}

