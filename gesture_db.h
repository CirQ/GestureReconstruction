//
// Created by cirq on 17-10-15.
//

#ifndef GESTURERECONSTRUCTION_GESTURE_SQLITE3_H
#define GESTURERECONSTRUCTION_GESTURE_SQLITE3_H

#include <iostream>
#include <vector>
#include <sqlite3.h>
#include "gesture_acts.h"

#define DB_NAME "GESTURE.db"

class gesture_db{
private:
    static const char *db_name;
    sqlite3 *db;
    sqlite3_stmt *stmt;

public:
    gesture_db();
    ~gesture_db();
    void load_acts(int, gesture_acts&);
    void load_datarows(gesture_acts&);
};

#endif //GESTURERECONSTRUCTION_GESTURE_SQLITE3_H
