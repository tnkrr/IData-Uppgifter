#include <iostream>
#include "sudoku.h"



int main(void)
{
	std::cout << "Generera lösning:" << std::endl;
	sudoku::generate_random_solution().print_to_console();
	std::cout << std::endl;

	std::cout << "Generera slumpmässig uppgift (75% löst):" << std::endl;
	sudoku::generate_random_problem(0.75).print_to_console();
	std::cout << std::endl;

	std::cout << "Generera slumpmässig uppgift (50% löst):" << std::endl;
	sudoku::generate_random_problem(0.50).print_to_console();
	std::cout << std::endl;

	std::cout << "Generera slumpmässig uppgift (25% löst):" << std::endl;
	sudoku::generate_random_problem(0.25).print_to_console();
	std::cout << std::endl;
	return 0;
}