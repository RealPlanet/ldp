#pragma once
#include "Controller.h"

class PrintController : Controller
{
public:
	void show() override;
	PrintController() : Controller() {}
};

