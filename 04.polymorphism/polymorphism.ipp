#pragma once

#include <iostream>
#include <string>

using i32 = std::int32_t;
using u32 = std::uint32_t;

class Bird {
protected:
	const std::string name;
	std::string type;
public:
	static i32 counter;
public:
	virtual ~Bird() {--counter;}
	Bird(const std::string & name): name{name} {
		this->type = __FUNCTION__;
		++counter;
	}
	virtual void actions() = 0;
	virtual void report() final {std::cout << name << " is a " << type << '\n';}
};
i32 Bird::counter{0};

class BlackBird: virtual public Bird {
public:
	~BlackBird() override {}
	BlackBird(const std::string & name): Bird{name} {this->type = __FUNCTION__;}
	void actions() override {this->report(); this->flagBlackWings(); std::cout << '\n';}
	virtual void flagBlackWings() {std::cout << name << " flags its black wings.\n";}
};

class Swan: virtual public Bird {
public:
	~Swan() override {}
	Swan(const std::string & name): Bird{name} {this->type = __FUNCTION__;}
	void actions() override {this->report(); this->swim(); std::cout << '\n';}
	virtual void swim() {std::cout << name << " is swimming.\n";}
};

class BlackSwan: public BlackBird, public Swan {
public:
	~BlackSwan() override {}
	BlackSwan(const std::string & name)
	:
		Bird{name},
		BlackBird{name},
		Swan{name}
	{
		this->type = __FUNCTION__;
	}
	void actions() override {
		this->report();
		this->flagBlackWings();
		this->swim();
		std::cout << '\n';
	}
};
