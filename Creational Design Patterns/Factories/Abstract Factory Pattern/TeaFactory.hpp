#pragma once
#include <memory>
#include "HotDrink.hpp"
#include "HotDrinkFactory.hpp"

struct HotDrink;

struct TeaFactory : HotDrinkFactory
{
	unique_ptr<HotDrink> make() const override {
		return make_unique<Tea>();
	}
};
