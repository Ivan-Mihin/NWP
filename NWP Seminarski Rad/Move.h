#pragma once
#include <string>

class Move
{
public:
	Move() {};
	~Move() {};

	int type;
	int value;
	std::string name;
};