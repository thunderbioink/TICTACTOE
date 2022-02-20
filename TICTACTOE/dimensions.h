#ifndef DIMENSIONS_H
#define DIMENSIONS_H
#include <cstdio>
#include <iostream>
#include <string>
#include <iomanip>

namespace TicTacToe {
	class dimensionsGUI {
	
	
		bool is_num(const std::string& s);

		//CREATE PRIVATE variables:
	private:
		std::string** g;
		size_t size;
	
	//Call private variables into public mehtod:

	public:
		dimensionsGUI(int dimensionsGUI_size = 3);
		std::string get_item(int pos) const;
		std::string get_item(int row, int col) const;
		void print();
		size_t get_size() const { return size; }
		bool X_win();
		bool O_win();
		bool X_insert(int pos);
		bool X_insert(int row, int col);
		bool O_insert(int pos);
		bool O_insert(int row, int col);
	};
	std::ostream& operator << (std::ostream& out, const dimensionsGUI& g);
}
#endif