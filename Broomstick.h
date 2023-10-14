#pragma once
#include "Air.h"
class Broomstick :
    public Air
{
public:
    Broomstick(int adistance);

    double start_race() override;
};

