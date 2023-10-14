#include "Ground.h"


  double Ground::start_race() {
        double travel_time = distance / speed;
        double count_relax = travel_time / time;

        if (count_relax >= 1) {
            if (relax[1] > 0) {
                travel_time += relax[0];
                count_relax--;
            }
            else {
                travel_time += relax[0] * count_relax;
            }
        } if (count_relax >= 1 && relax[1] != 0) {
            if (relax[2] > 0) {
                travel_time += relax[1];
                count_relax--;
            }
            else {
                travel_time += relax[1] * count_relax;
            }
        } if (count_relax >= 1 && relax[2] != 0) {
            travel_time += relax[2] * count_relax;
        }
        return travel_time;

    }


