#pragma once

class Air
{
protected:
    int speed;
    double distance;

    Air(int) {

    };

public:
    virtual double start_race();
};