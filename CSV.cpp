#include "CSV.h"

Lead CSV::parseCSV(const std::string& line, const std::string& repName) const
{
	std::string name, email, companyName;
	std::string phoneNumber;
	std::stringstream ss(line);

	//CSV parsing logic
	std::getline(ss, name, ',');
	std::getline(ss, email, ',');
	std::getline(ss, phoneNumber, ',');
	std::getline(ss, companyName, ',');

	return Lead(name, email, phoneNumber, companyName, repName);
}

MySet<Lead> CSV::readCSV(const std::string& filename, const std::string& repName)
{
	MySet<Lead> leads;
	std::ifstream file(filename);

	if(!file.is_open())
	{
		std::cout << ("Couldnt open the file: " + filename);
		return leads;
	}
}