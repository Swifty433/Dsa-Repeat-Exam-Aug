#pragma once
#include "headers.h"

class Lead {
private:
	std::string name;
	std::string email;
	std::string phoneNumber;
	std::string companyName;
	std::string repName;

public:
	Lead();
	Lead(const std::string& name, const std::string& email, const std::string& phoneNumber, const std::string& companyName, const std::string& repName);
	~Lead();

	//Getters
	std::string getName() const;
	std::string getEmail() const;
	std::string getPhoneNumber() const;
	std::string getCompanyName() const;
	std::string getRepName() const;

	//Setters
	void setName(const std::string& name);
	void setEmail(const std::string& email);
	void setPhoneNumber(const std::string& phoneNumber);
	void setCompanyName(const std::string& companyName);
	void setRepName(const std::string& repName);
	
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
