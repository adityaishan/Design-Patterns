#pragma once
#include <iostream>
#include <memory>
#include <string>	

using namespace std;

struct HotDrink
{
	virtual ~HotDrink() = default;
	virtual void prepare(int volume) = 0;
};

struct Tea : HotDrink
{
	void prepare(int volume) override {
		cout << "Prepare Tea of volume " << volume << "\n";
	}
};

struct Coffee : HotDrink
{
	void prepare(int volume) override {
		cout << "Prepare Coffee of volume " << volume << "\n";
	}
};
