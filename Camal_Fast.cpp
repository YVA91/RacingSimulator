#include "Camal_Fast.h"

Camal_Fast::Camal_Fast(int adistance) : Ground(adistance) {
    this->speed = 40;
    this->time = 10;
    this->relax[0] = 5;
    this->relax[1] = 6.5;
    this->relax[2] = 8;
    this->distance = adistance;
}
