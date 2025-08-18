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

	string line;
	getline(file, line);

	while (getline(file, line))
	{
		if (!line.empty())
		{
			Lead lead = parseCSV(line, repName);
			leads.insert(lead);
		}
	}
	file.close();
	std::cout << "CSV file read successfully." << std::endl;
	return leads;
}

void CSV::writeCSV(const std::string& filename, const MySet<Lead>& leads)
{
	std::ofstream file(filename);
	if (!file.is_open())
	{
		std::cerr << "COuldn't open file." << filename << std::endl;
		return;
	}

	file << "Name,Email,Phone,Company,Rep" << std::endl;

	for (int i = 0; i < leads.length(); i++)
	{
		file << leads.getElement(i).toCSV() << std::endl;
	}

	file.close();
	std::cout << "CSV file written to: " << filename << std::endl;
}