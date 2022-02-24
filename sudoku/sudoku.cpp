#include <iostream>
#include <random>
#include <chrono>
#include "sudoku.h"



sudoku::sudoku()
{
	reset();
}



void sudoku::reset()
{
	grid.fill(0);
}



void sudoku::set_value(unsigned int row, unsigned int col, int value)
{
	grid[get_index(row, col)] = value;
}

int sudoku::get_value(unsigned int row, unsigned int col) const
{
	return grid.at(get_index(row, col));
}



bool sudoku::is_empty(unsigned int row, unsigned int col) const
{
	return get_value(row, col) == 0;
}



unsigned int sudoku::get_row(size_t index)
{
	return (index % 16) / 4;
}

unsigned int sudoku::get_column(size_t index)
{
	return index % 4;
}

size_t sudoku::get_index(unsigned int row, unsigned int col)
{
	return col + row * 4;
}

size_t sudoku::get_random_number(size_t min, size_t max)
{
	static std::random_device r;
	static std::mt19937 generator(r());
	std::uniform_int_distribution<int> distribution(min, max - 1);
	return distribution(generator);
}



bool sudoku::is_solution() const
{
	// Kollar om alla rader och kolumner är giltiga
	for (size_t r = 0; r < 4; r++)
		if (!valid_row(r))
			return false;
	for (size_t c = 0; c < 4; c++)
		if (!valid_column(c))
			return false;
	return true;
}



bool sudoku::valid_change(unsigned int row, unsigned int col, int value) const
{
	// Om värdet redan finns i kolumnen eller raden retunera att det är en ogiltigt förändring
	for (size_t r = 0; r < 4; r++)
		if (get_value(r, col) == value)
			return false;
	for (size_t c = 0; c < 4; c++)
		if (get_value(row, c) == value)
			return false;
	return true;
}



bool sudoku::valid_row(unsigned int row) const
{
	int sum = 0;
	for (size_t c = 0; c < 4; c++)
		sum += get_value(row, c);
	return sum == 10; // 1 + 2 + 3 + 4 = 10
}

bool sudoku::valid_column(unsigned int col) const
{
	int sum = 0;
	for (size_t r = 0; r < 4; r++)
		sum += get_value(r, col);
	return sum == 10; // 1 + 2 + 3 + 4 = 10
}



sudoku sudoku::generate_random_problem(float solved_percentage)
{
	sudoku problem = generate_random_solution();
	size_t remove_value_count = 16 - (int)(solved_percentage * 16); // Antal värden att ta bort
	size_t index = get_random_number(0, 16);
	while (remove_value_count > 0)
	{
		if (problem.grid.at(index) != 0)
		{
			problem.grid[index] = 0;
			remove_value_count--;
			index += get_random_number(0, 16);
		}
		++index %= 16;
	}
	return problem;
}

sudoku sudoku::generate_random_solution()
{
	sudoku solution;
	while (!solution.is_solution())
	{
		solution.reset();
		solution.place_random_valid_value_recursively();
	}
	return solution;
}



// Genererar giltiga lösningar
bool sudoku::place_random_valid_value_recursively()
{
	size_t random_index = get_random_number(0, 16);
	size_t offset = 0; // Används om det redan finns ett värde på random_index
	while (offset < 16)
	{
		unsigned int row = get_row(random_index + offset);
		unsigned int col = get_column(random_index + offset);
		if (!is_empty(row, col))
		{
			offset++;
			continue;
		}
		int random_value = get_random_number(0, 4);
		for (size_t i = 0; i < 4; i++)
		{
			int value = ((random_value + i) % 4) + 1;
			if (valid_change(row, col, value))
			{
				set_value(row, col, value);
				if (place_random_valid_value_recursively()) // Leta vidare
					return true; // Hittat en lösning
				set_value(row, col, 0); // Hittade ingen lösning så återställer värdet
			}
		}
		return false; // Finns inget giltigt värde på den här plattsen (row, col)
	}
	return is_solution();
}



void sudoku::print_to_console() const
{
	for (size_t r = 0; r < 4; r++)
	{
		for (size_t c = 0; c < 4; c++)
		{
			if (is_empty(r, c))
				std::cout << "  ";
			else
				std::cout << get_value(r, c) << " ";
		}
		std::cout << std::endl;
	}
}