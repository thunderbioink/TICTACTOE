#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "dimensions.h"
//#include <chrono>
//#include <thread>

using namespace std;
int main() {

	int dimensionsGUI_size;
	bool X_turn = true;

	cout << "==================================" << endl;
	cout << "==================================" << endl;
	cout << "==================================" << endl;
	cout << "==================================" << endl;

	cout << "             WELCOME\n                TO\n          TIC -TAC - TOE\n\n\n" << endl;
	cout << "==================================" << endl;
	cout << "==================================" << endl;
	cout << "==================================" << endl;
	cout << "==================================" << endl;

	cout << "Enter board size (i.e. 3): ";
	cin >> dimensionsGUI_size;
	//CALL TICTACTOE 
	TicTacToe::dimensionsGUI g(dimensionsGUI_size);
	
	//WHILE LOOP RUN GAME ---see pygame examples -- != python but reference:
	while (!g.X_win() && !g.O_win()) {
		cout << string(100, '\n');
		cout << g;
		//INSERT X
		if (X_turn) {
			bool inserted = false;
			while (!inserted) {
				int pos;
				cout << "X, enter position number:\n ";
				cin >> pos;
				inserted = g.X_insert(pos);
				X_turn = false;
			}
		}
		//INSERT O
		else {
			bool inserted = false;
			while (!inserted) {
				int pos;
				cout << "O, enter position number:\n ";
				cin >> pos;
				inserted = g.O_insert(pos);
				X_turn = true;
			}
		}
		cout << g;

		//VICTORY MESSAGES:
		if (g.X_win()) {
			cout << "  *    .  *       .             *\n				*\n				*. * .       . *\n				. *\n				.     . * *\n				.                .        .\n				. * **\n				.\n				* . *" << endl;
			cout << "                                                                                X  WON!" << endl;
			cout << "  *    .  *       .             *\n				*\n				*. * .       . *\n				. *\n				.     . * *\n				.                .        .\n				. * **\n				.\n				* . *" << endl;
			//std::chrono::milliseconds dura(2000);
			//std::this_thread::sleep_for(dura);
		}
		else {
			cout << "  *    .  *       .             *\n				*\n				*. * .       . *\n				. *\n				.     . * *\n				.                .        .\n				. * **\n				.\n				* . *" << endl;
			cout << "                                                                                O  WON!" << endl;
			cout << "  *    .  *       .             *\n				*\n				*. * .       . *\n				. *\n				.     . * *\n				.                .        .\n				. * **\n				.\n				* . *" << endl;
			//std::chrono::milliseconds dura(2000);
			//std::this_thread::sleep_for(dura);
		}
	}
	return EXIT_SUCCESS;
}



///RESOURCES:
///
/// https://codereview.stackexchange.com/questions/268345/tic-tac-toe-in-c-with-classes
/// http://www.cplusplus.com/forum/beginner/143523/
/// https://www.youtube.com/watch?v=KrH1qNVYKO0
/// https://www.simplilearn.com/tutorials/cpp-tutorial/game-in-cpp?source=sl_frs_nav_playlist_video_clicked
/// https://gist.github.com/ajnarayan/718d7fea9692f8442c20
/// 

