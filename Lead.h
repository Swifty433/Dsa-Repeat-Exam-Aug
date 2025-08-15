#pragma once
#include "headers.h"

class Lead {
private:
	std::string name;
	std::string email;
	int phoneNumber;
	std::string companyName;
	std::string repName;

public:
	Lead();
	Lead(const std::string& name, const std::string& email, int phoneNumber, const std::string& companyName, const std::string& repName);
	~Lead();

	//Getters
	string getName() const;
	string getEmail() const;
	int getPhoneNumber() const;
	string getCompanyName() const;
	string getRepName() const;

	//Setters
	void setName(const string& name);
	void setEmail(const string& email);
	void setPhoneNumber(int phoneNumber);
	void setCompanyName(const string& companyName);
	void setRepName(const string& repName);
	
	//Operator overloads
	bool operator==(const Lead& other) const;
	bool operator!=(const Lead& other) const;
	bool operator<(const Lead& other) const;
	bool operator>(const Lead& other) const;
	bool operator<=(const Lead& other) const;
	bool operator>=(const Lead& other) const;

	// Utility methods
	std::string toString() const;
	std::string toCSV() const;
};
