#include <iostream>
#include "sudoku.h"



int main(void)
{
	std::cout << "Generera l�sning:" << std::endl;
	sudoku::generate_random_solution().print_to_console();
	std::cout << std::endl;

	std::cout << "Generera slumpm�ssig uppgift (75% l�st):" << std::endl;
	sudoku::generate_random_problem(0.75).print_to_console();
	std::cout << std::endl;

	std::cout << "Generera slumpm�ssig uppgift (50% l�st):" << std::endl;
	sudoku::generate_random_problem(0.50).print_to_console();
	std::cout << std::endl;

	std::cout << "Generera slumpm�ssig uppgift (25% l�st):" << std::endl;
	sudoku::generate_random_problem(0.25).print_to_console();
	std::cout << std::endl;
	return 0;
}