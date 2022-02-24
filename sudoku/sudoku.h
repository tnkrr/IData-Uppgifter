#pragma once
#include <array>



class sudoku
{
public:
	sudoku();

	void reset();

	void set_value(unsigned int row, unsigned int col, int value);
	int get_value(unsigned int row, unsigned int col) const;
	bool is_empty(unsigned int row, unsigned int col) const;

	static unsigned int get_row(size_t index);
	static unsigned int get_column(size_t index);
	static size_t get_index(unsigned int row, unsigned int col);
	static size_t get_random_number(size_t min, size_t max);

	bool is_solution() const;
	bool valid_change(unsigned int row, unsigned int col, int value) const;

	bool valid_row(unsigned int row) const;
	bool valid_column(unsigned int col) const;

	static sudoku generate_random_problem(float solved_percentage);
	static sudoku generate_random_solution();

	bool place_random_valid_value_recursively();

	void print_to_console() const;

private:
	std::array<int, 16> grid;
};