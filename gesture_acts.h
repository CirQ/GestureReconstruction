//
// Created by cirq on 17-10-16.
//

#ifndef GESTURERECONSTRUCTION_GESTURE_ACTS_H
#define GESTURERECONSTRUCTION_GESTURE_ACTS_H

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class datarow{
public:
    double acc_x, acc_y, acc_z;
    double gyr_x, gyr_y, gyr_z;
    int timestamp;
    datarow(double, double, double, double, double, double, int);
};

class gesture_acts{
    friend ostream &operator<<(ostream&, const gesture_acts&);
private:
    static const map<int, string> gname_map;
    int id;
    string uid;
    int age;
    bool gender;    // true for male and false for female
    bool hand;      // true for right and false for left
    int gid;
    vector<datarow> vec_dr;

public:
    gesture_acts(int, char*, int, int, int, int);
    int get_id();
    vector<datarow> get_vec();
};

#endif //GESTURERECONSTRUCTION_GESTURE_ACTS_H
