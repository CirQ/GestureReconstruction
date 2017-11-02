//
// Created by cirq on 17-10-16.
//

#ifndef GESTURERECONSTRUCTION_GESTURE_ACTS_H
#define GESTURERECONSTRUCTION_GESTURE_ACTS_H

#include <iostream>
#include <vector>
#include <map>

class datarow{
    friend std::ostream &operator<<(std::ostream&, const datarow&);
public:
    double acc_x, acc_y, acc_z;
    double gyr_x, gyr_y, gyr_z;
    long long timestamp;
    datarow(double, double, double, double, double, double, long long);
};

class gesture_acts{
    friend std::ostream &operator<<(std::ostream&, const gesture_acts&);
private:
    static std::map<int, std::string> gname_map;
    int id;
    std::string uid;
    int age;
    bool gender;    // true for male and false for female
    bool hand;      // true for right and false for left
    int gid;
    std::vector<datarow> vec_dr;

public:
    gesture_acts();
    void set(int, char*, int, int, int, int);
    int get_id();
    std::vector<datarow> &get_vec();
};

#endif //GESTURERECONSTRUCTION_GESTURE_ACTS_H
