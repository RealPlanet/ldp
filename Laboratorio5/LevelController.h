#pragma once
#include "Controller.h"
#include "Shape.h"
class LevelController : Controller
{
private:
	Shape controlledShape;
public:
	void set_level(int newLevel) override;
	LevelController(Shape _S);
};

