#include "Camal.h"

Camal::Camal(int adistance) : Ground (adistance) {
    this->speed = 10;
    this->time = 30;
    this->relax[0] = 5;
    this->relax[1] = 8;
    this->distance = adistance;
}