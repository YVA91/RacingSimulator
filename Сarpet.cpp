#include "Ñarpet.h"

Carpet::Carpet(int adistance) : Air(adistance) {
    this->speed = 10;
    this->distance = adistance;
}

double Carpet::start_race() {
    double time;
    if (distance < 5000) {
        time = (distance * 0.97) / speed;
    }
    else if (distance < 10000) {
        time = (distance * 0.9) / speed;
    }
    else if (distance >= 10000) {
        time = (distance * 0.95) / speed;
    }
    else {
        time = distance / speed;
    }
    return time;
}