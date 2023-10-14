#include "Eagle.h"

Eagle::Eagle(int adistance) : Air(adistance) {
    this->speed = 8;
    this->distance = adistance;
}

double Eagle::start_race() {
    return (distance * 0.94) / speed;
}