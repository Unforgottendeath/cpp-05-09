#pragma once

#include <iostream>
#include <string>

class Base;

Base* generate(void);

void identify(Base* p);

void identify(Base& p);