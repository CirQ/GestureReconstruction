//
// Created by cirq on 17-10-16.
//

#include "gesture_acts.h"

datarow::datarow(double d1, double d2, double d3, double d4, double d5, double d6, int t){
    acc_x = d1, acc_y = d2, acc_z = d3;
    gyr_x = d4, gyr_y = d5, gyr_z = d6;
    timestamp = t;
}

map<int, string> gesture_acts::gname_map = {
    { 0, "number 0" }, { 1, "number 1" }, { 2, "number 2" }, { 3, "number 3" },
    { 4, "number 4" }, { 5, "number 5" }, { 6, "number 6" }, { 7, "number 7" },
    { 8, "number 8" }, { 9, "number 9" }, { 10, "character a" }, { 11, "character b" },
    { 12, "character c" }, { 13, "character d" }, { 14, "character e" }, { 15, "character f" },
    { 16, "character g" }, { 17, "character h" }, { 18, "character i" }, { 19, "character j" },
    { 20, "character k" }, { 21, "character l" }, { 22, "character m" }, { 23, "character n" },
    { 24, "character o" }, { 25, "character p" }, { 26, "character q" }, { 27, "character r" },
    { 28, "character s" }, { 29, "character t" }, { 30, "character u" }, { 31, "character v" },
    { 32, "character w" }, { 33, "character x" }, { 34, "character y" }, { 35, "character z" },
    { 36, "to right" }, { 37, "to left" }, { 38, "up" }, { 39, "down" },
    { 40, "right angle" }, { 41, "left angle" }, { 42, "up angle" }, { 43, "down angle" },
    { 44, "clockwise" }, { 45, "counter-clockwise" }
};

ostream &operator<<(ostream &os, const gesture_acts &ga){
    os << "Gesture [" << ga.gname_map.at(ga.gid);
    os << "] acts_id:" << ga.id << " user_id:" << ga.uid << " age:" << ga.age;
    os << " gender:" << (ga.gender ? "male" : "female");
    os << " hand:" << (ga.hand ? "right" : "left");
    os << " vector_size:" << ga.vec_dr.size();
    return os;
}

gesture_acts::gesture_acts(int id, char *uid, int age, int gender, int hand, int gid){
    this->id = id;
    this->uid = uid;
    this->age = age;
    this->gender = gender == 1;
    this->hand = hand == 1;
    this->gid = gid;
}

int gesture_acts::get_id(){
    return id;
}

vector<datarow> gesture_acts::get_vec(){
    return vec_dr;
}

