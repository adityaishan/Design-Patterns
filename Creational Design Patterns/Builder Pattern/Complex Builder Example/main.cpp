#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <fstream>
#include <tuple>
#include <sstream>
#include <memory>

using namespace std;

#include "Person.hpp"
#include "PersonBuilder.hpp"
#include "PersonAddressBuilder.hpp"
#include "PersonJobBuilder.hpp"

int main()
{
	Person p = Person::create()
	           .lives().at("123 London Road").with_postcode("SW1 1GB").in("London")
	           .works().at("PragmaSoft").as_a("Consultant").earning(10e6);

	cout << p << "\n";
	getchar();
	return 0;
}
