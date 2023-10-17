#include "Broomstick.h"

Broomstick::Broomstick(int adistance) : Air(adistance) {
    this->speed = 20;
    this->distance = adistance;
}

double Broomstick::start_race() {
    int ratio = distance / 1000;
    return distance * (1-(ratio/100.0)) / speed;
};