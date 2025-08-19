#include "CSV.h"

Lead CSV::parseCSV(const std::string& line, const std::string& repName) const
{
	// Format is: Name,Email,Phone,Company.
	std::string name, email, companyName, phoneNumber;
	std::stringstream ss(line);

	//CSV parsing logic
	std::getline(ss, name, ',');
	std::getline(ss, email, ',');
	std::getline(ss, phoneNumber, ',');
	std::getline(ss, companyName, ',');

	//return a Lead object
	return Lead(name, email, phoneNumber, companyName, repName);
}

//Read from CSV method
MySet<Lead> CSV::readCSV(const std::string& filename, const std::string& repName)
{
	MySet<Lead> leads;
	// Open the file
	std::ifstream file(filename);

	//checking if file is open
	if(!file.is_open())
	{
		std::cout << ("Couldnt open the file: " + filename);
		return leads;
	}

	std::string line;
	getline(file, line);

	// Check if the first line is the header
	while (getline(file, line))
	{
		// Skip empty lines
		if (!line.empty())
		{
			//create a Lead object from the line
			Lead lead = parseCSV(line, repName);
			leads.insert(lead);
		}
	}
	//close the file
	file.close();
	std::cout << "CSV file read successfully." << std::endl;
	//return the set of leads
	return leads;
}

// Write to CSV method
void CSV::writeCSV(const std::string& filename, const MySet<Lead>& leads)
{
	// Open the file for writing
	std::ofstream file(filename);
	if (!file.is_open())
	{
		std::cerr << "COuldn't open file." << filename << std::endl;
		return;
	}

	// Write the header
	file << "Name,Email,Phone,Company,Rep" << std::endl;

	// Write each lead to the file
	for (int i = 0; i < leads.length(); i++)
	{
		file << leads.getElement(i).toCSV() << std::endl;
	}

	// Close the file
	file.close();
	std::cout << "CSV file written to: " << filename << std::endl;
}