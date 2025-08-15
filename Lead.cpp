#include "Lead.h"

//Default constructor
Lead::Lead() : name(""), email(""), phoneNumber(0), companyName(""), repName("") {}

//COnstructor with parameters
Lead::Lead(const std::string& name, const std::string& email, int phoneNumber, const std::string& companyName, const std::string& repName)
	: name(name), email(email), phoneNumber(phoneNumber), companyName(companyName), repName(repName) {}

//Destructor
Lead::~Lead() {}

//Getteres
std::string Lead::getName() const { return name; }
std::string Lead::getEmail() const { return email; }
int Lead::getPhoneNumber() const { return phoneNumber; }
std::string Lead::getCompanyName() const { return companyName; }
std::string Lead::getRepName() const { return repName; }

//Setters
void Lead::setName(const std::string& name) { this->name = name; }
void Lead::setEmail(const std::string& email) { this->email = email; }
void Lead::setPhoneNumber(int phoneNumber) { this->phoneNumber = phoneNumber; }
void Lead::setCompanyName(const std::string& companyName) { this->companyName = companyName; }
void Lead::setRepName(const std::string& repName) { this->repName = repName; }

// Operator overloads
bool Lead::operator == (const Lead& other) const
{
	return this->phoneNumber == other.phoneNumber;
}

bool Lead::operator!= (const Lead& other) const
{
	return !(*this == other);
}

bool Lead::operator< (const Lead& other) const
{
	return this->phoneNumber < other.phoneNumber;
}

bool Lead::operator> (const Lead& other) const
{
	return this->phoneNumber > other.phoneNumber;
}

bool Lead::operator<= (const Lead& other) const
{
	return *this < other || *this == other;
}

bool Lead::operator>= (const Lead& other) const
{
	return *this > other || *this == other;
}

//utiliy mMethods
std::string Lead::toString() const
{
	return "Name: " + name + ", Email: " + email + ", Phone: " + std::to_string(phoneNumber) + ", Company: " + companyName + ", Rep: " + repName;
}

std::string Lead::toCSV() const
{
	return name + "," + email + "," + std::to_string(phoneNumber) + "," + companyName + "," + repName;
}
