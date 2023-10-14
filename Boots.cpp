#include "Boots.h"


 Boots::Boots(int adistance) : Ground(adistance) {
    this->speed = 6;
    this->time = 60;
    this->relax[0] = 10;
    this->relax[1] = 5;
    this->distance = adistance;
}