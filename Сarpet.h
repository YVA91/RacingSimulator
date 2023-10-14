#pragma once
#include "Air.h"
class Carpet :
    public Air
{
public:
    Carpet(int adistance);

    double start_race() override;
};




