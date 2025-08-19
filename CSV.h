#pragma once
#include "headers.h"
#include "Lead.h"
#include "MySet.h"

// Function to read CSV file and return a set of Leads
class CSV
{
public:
	// Reads a CSV file and returns a set of Leads
	MySet<Lead> readCSV(const std::string& filename, const std::string& repName);

	// Writes a set of Leads to a CSV file
	void writeCSV(const std::string& filename, const MySet<Lead>& leads);

	//helper
	Lead parseCSV(const std::string& line, const std::string& repName) const;
};