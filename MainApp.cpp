#include "headers.h"
#include "CSV.h"
#include "Lead.h"
#include "MySet.h"

int main() {
	CSV processor;
	std::string file1, file2, rep1, rep2;

	//Getting file names
	std::cout << "Enter the first CSV file name: ";
	std::cin >> file1;
	std::cout << "Enter the second CSV file name: ";
	std::cin >> file2;

	//Getting rep names
	std::cout << "Enter the first rep name: ";
	std::cin >> rep1;
	std::cout << "Enter the second rep name: ";
	std::cin >> rep2;

	//Reading CSV files
	MySet<Lead> leads1 = processor.readCSV(file1, rep1);
	MySet<Lead> leads2 = processor.readCSV(file2, rep2);
}