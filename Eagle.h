#pragma once
#include "Air.h"
class Eagle :
    public Air
{
public:
    Eagle(int adistance);

    double start_race() override;
};

