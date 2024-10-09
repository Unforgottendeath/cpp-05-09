#pragma once

#include <iostream>
#include <string>
#include <cstdlib>

class Base;

Base* generate(void);

void identify(Base* p);

void identify(Base& p);