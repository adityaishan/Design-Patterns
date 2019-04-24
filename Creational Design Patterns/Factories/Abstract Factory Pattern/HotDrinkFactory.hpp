#pragma once
#include "HotDrink.hpp"

struct HotDrinkFactory //Abstract Factory
{
	virtual unique_ptr<HotDrink> make() const = 0;
};

