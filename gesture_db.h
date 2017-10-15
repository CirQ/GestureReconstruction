//
// Created by cirq on 17-10-15.
//

#ifndef GESTURERECONSTRUCTION_GESTURE_SQLITE3_H
#define GESTURERECONSTRUCTION_GESTURE_SQLITE3_H

#include <iostream>
#include <sqlite3.h>

#define DB_NAME "GESTURE.db"

class gesture_db{
private:
    static const char *db_name;
    sqlite3 *db;
    char *errMsg;

public:
    gesture_db();
    ~gesture_db();
};

#endif //GESTURERECONSTRUCTION_GESTURE_SQLITE3_H
