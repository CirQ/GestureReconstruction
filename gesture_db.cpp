//
// Created by cirq on 17-10-15.
//

#include "gesture_db.h"

const char *gesture_db::db_name = DB_NAME;

gesture_db::gesture_db(){
    int rc = sqlite3_open(db_name, &db);
    if(rc != SQLITE_OK){
        std::cerr << "[ERROR] cannot open database: \n" << sqlite3_errmsg(db) << std::endl;
        exit(EXIT_FAILURE);
    }
    std::cout << "[SUCCESS] database opened" << std::endl;
}

gesture_db::~gesture_db(){
    sqlite3_free(errMsg);
    sqlite3_close(db);
    std::cout << "[SUCCESS] database closed" << std::endl;
}