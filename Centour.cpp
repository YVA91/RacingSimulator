#include "Centour.h"



Centour::Centour(int adistance) : Ground(adistance) {
    this->speed = 15;
    this->time = 8;
    this->relax[0] = 2;
    this->distance = adistance;
}
