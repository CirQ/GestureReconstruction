//
// Created by cirq on 17-10-30.
//

#ifndef GESTURERECONSTRUCTION_GESTURE_RECONSTRUCT_H
#define GESTURERECONSTRUCTION_GESTURE_RECONSTRUCT_H

#include <vector>
#include "gesture_acts.h"
#include "gesture_db.h"

class gesture_reconstruct{
private:
    gesture_reconstruct();
    int acts_id;
    gesture_acts ga;

public:
    explicit gesture_reconstruct(int);
    gesture_acts &get_acts();
    void reconstruct(void (*func)(const std::vector<datarow>&));
};

#endif //GESTURERECONSTRUCTION_GESTURE_RECONSTRUCT_H
