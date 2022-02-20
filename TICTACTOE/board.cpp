#include "DIMENSIONS.h"
#include <stdlib.h>
namespace TicTacToe {
	dimensionsGUI::dimensionsGUI(int board_size) {
		size = board_size;
		//SIZE OF BOARD 
		g = new std::string * [board_size];
		for (int i = 0; i < board_size; ++i)
			g[i] = new std::string[board_size];

		for (int i = 0; i < board_size; ++i) {
			for (int j = 0; j < board_size; ++j) {
				std::string k = std::to_string(((i * board_size) + j));
				g[i][j] = k;
			}
		}
	}
	bool dimensionsGUI::is_num(const std::string& s) {
		std::string::const_iterator it = s.begin();
		while (it != s.end() && std::isdigit(*it)) ++it;
		return !s.empty() && it == s.end();
	}
	//POSITION OF x/o
	std::string dimensionsGUI::get_item(int pos) const {
		int row = pos / size;
		int col = pos % size;
		return g[row][col];
	}
	//ROWS AND COLUMNS
	std::string dimensionsGUI::get_item(int row, int col) const {
		return g[row][col];
	}

	void dimensionsGUI::print() {
		for (int i = 0; i < get_size(); ++i) {
			for (int j = 0; j < get_size(); ++j) {
				std::cout << g[i][j];
			}
		}
	}
	//WINNING LOGIC FOR LOOPS:
	bool dimensionsGUI::X_win() {
		//Horizontal
		for (int i = 0; i < size; ++i) {
			for (int j = 0; j < size; ++j) {
				if (g[i][j] != "X")
					break;
				if (j == (size - 1))
					return true;
			}
		}

		//Vertical 
		for (int i = 0; i < size; ++i)
			for (int j = 0; j < size; ++j) {
				if (g[j][i] != "X")
					break;
				if (j == (size - 1))
					return true;
			}

		//Top Left to Bottom Right Diagonal
		for (int i = 0; i < size; ++i) {
			if (g[i][i] != "X")
				break;
			if (i == (size - 1))
				return true;
		}

		//Top Right to Bottom Left Diagonal 
		for (int i = 0; i < size; ++i) {
			if (g[(size - 1) - i][i] != "X")
				break;
			if (i == (size - 1))
				return true;
		}

		return false;
	}

	bool dimensionsGUI::O_win() {
		//Horizontal
		for (int i = 0; i < size; ++i) {
			for (int j = 0; j < size; ++j) {
				if (g[i][j] != "O")
					break;
				if (j == (size - 1))
					return true;
			}
		}

		//Vertical
		for (int i = 0; i < size; ++i)
			for (int j = 0; j < size; ++j) {
				if (g[j][i] != "O")
					break;
				if (j == (size - 1))
					return true;
			}

		//Top Left to Bottom Right Diagonal
		for (int i = 0; i < size; ++i) {
			if (g[i][i] != "O")
				break;
			if (i == (size - 1))
				return true;
		}

		//Top Right to Bottom Left Diagonal
		for (int i = 0; i < size; ++i) {
			if (g[(size - 1) - i][i] != "O")
				break;
			if (i == (size - 1))
				return true;
		}

		return false;
	}

	bool dimensionsGUI::X_insert(int pos) {
		int row = pos / size;
		int col = pos % size;
		if (is_num(g[row][col])) {
			g[row][col] = "X";
			return true;
		}
		return false;
	}

	bool dimensionsGUI::X_insert(int row, int col) {
		if (is_num(g[row][col])) {
			g[row][col] = "X";
			return true;
		}
		return false;
	}

	bool dimensionsGUI::O_insert(int pos) {
		int row = pos / size;
		int col = pos % size;
		if (is_num(g[row][col])) {
			g[row][col] = "O";
			return true;
		}
		return false;
	}

	bool dimensionsGUI::O_insert(int row, int col) {
		if (is_num(g[row][col])) {
			g[row][col] = "X";
			return true;
		}
		return false;
	}
	//DRAW THE g BOARD WITH ASCCII FORMAT
	std::ostream& operator << (std::ostream& out, const dimensionsGUI& g) {
		for (int i = 0; i < g.get_size(); ++i) {
			out << std::endl;
			for (int j = 0; j < g.get_size(); ++j) {
				out << "+---";
			}
			out << "+" << std::endl << "|";

			for (int j = 0; j < g.get_size(); ++j) {
				std::string item = g.get_item(i, j);
				int len = item.length();
				if (len <= 1)
					out << std::setw(2) << item << std::setw(2) << "|";
				else if (len == 2)
					out << std::setw(1) << item << std::setw(2) << "|";
				else if (len == 3)
					out << std::setw(0) << item << std::setw(1) << "|";
			}
		}

		out << std::endl;
		for (int j = 0; j < g.get_size(); ++j) {
			out << "+---";
		}
		out << "+";

		out << std::endl;
		return out;
	}
}