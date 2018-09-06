#include "emp_5.h"

#include <iostream>
#include <string>
using std::string;

abstr_emp::abstr_emp()
{
    fname = "none";
    lname = "none";
    job = "none";
}

abstr_emp::~abstr_emp() {}

void abstr_emp::ShowAll() const
{
    std::cout << "firstname: " << fname << std::endl;
    std::cout << "lastname: " << lname << std::endl;
    std::cout << "job: " << job << std::endl;
}

void abstr_emp::SetAll()
{
    std::cout << "Enter firstname: ";
    std::getline(std::cin, fname);
    std::cout << "Enter lastname: ";
    std::getline(std::cin, lname);
    std::cout << "Enter job: ";
    std::getline(std::cin, job);
}

// friend functions
std::ostream & operator<<(std::ostream & os, const abstr_emp & e)
{
    os << e.lname << " " << e.fname << ", " << e.job;
    return os;
}


void employee::ShowAll() const
{
    abstr_emp::ShowAll();
}

void employee::SetAll()
{
    abstr_emp::SetAll();
}

void manager::ShowAll() const
{
    abstr_emp::ShowAll();
    std::cout << "Inchargeof: " << inchargeof << std::endl;
}

void manager::SetAll()
{
    abstr_emp::SetAll();
    std::cout << "Enter inchargeof: ";
    std::cin >> inchargeof;
    std::cin.get();
}

void fink::ShowAll() const
{
    abstr_emp::ShowAll();
    std::cout << "Reportsto: " << reportsto << std::endl;
}

void fink::SetAll()
{
    abstr_emp::SetAll();
    std::cout << "Enter reportsto: ";
    std::getline(std::cin, reportsto);
}

void highfink::ShowAll() const
{
    abstr_emp::ShowAll();
    std::cout << "Inchargeof: " << manager::InChargeOf() << std::endl;
    std::cout << "Reportsto: " << fink::ReportsTo() << std::endl;
}

void highfink::SetAll()
{
    abstr_emp::SetAll();
    std::cout << "Enter reportsto: ";
    std::getline(std::cin, fink::ReportsTo());
    std::cout << "Enter Inchargeof: ";
    std::cin >> manager::InChargeOf();
    std::cin.get();
}
