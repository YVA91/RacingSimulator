#include "Broomstick.h"

Broomstick::Broomstick(int adistance) : Air(adistance) {
    this->speed = 20;
    this->distance = adistance;
}

double Broomstick::start_race() {
    return (distance * (1 + ((static_cast<int>(distance) % 1000) / 100))) / speed;
};