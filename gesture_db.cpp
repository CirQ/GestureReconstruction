//
// Created by cirq on 17-10-15.
//

#include "gesture_db.h"

const char *gesture_db::db_name = DB_NAME;

gesture_db::gesture_db(){
    int rc = sqlite3_open(db_name, &db);
    if(rc != SQLITE_OK){
        cerr << "[ERROR] cannot open database: \n" << sqlite3_errmsg(db) << endl;
        sqlite3_close(db);
        exit(EXIT_FAILURE);
    }
    stmt = (sqlite3_stmt*)nullptr;
    cout << "[SUCCESS] database opened" << endl;
}

gesture_db::~gesture_db(){
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    cout << "[SUCCESS] database closed" << endl;
}

void gesture_db::load_acts(int id, gesture_acts &ga){
    string sql = "SELECT user.uid, user.age, user.male, user.right_hand, acts.action_id "
                 "FROM ((SELECT * FROM acts WHERE id=?) AS acts) JOIN user ON acts.uid=user.uid;";
    int rc = sqlite3_prepare_v2(db, sql.c_str(), (int)sql.size(), &stmt, nullptr);
    if(rc == SQLITE_OK){
        sqlite3_bind_int(stmt, 1, id);
        if(sqlite3_step(stmt) == SQLITE_ROW){
            auto uid = (char*)sqlite3_column_text(stmt, 0);
            int age = sqlite3_column_int(stmt, 1);
            int male = sqlite3_column_int(stmt, 2);
            int right_hand = sqlite3_column_int(stmt, 3);
            int gid = sqlite3_column_int(stmt, 4);
            ga = gesture_acts(id, uid, age, male, right_hand, gid);
            cout << "[SUCCESS] successfully load acts data with user information" << endl;
        }
    } else{
        cerr << "[ERROR] statement error when loading acts:\n" << sqlite3_errmsg(db) << endl;
    }
    sqlite3_finalize(stmt);
}

void gesture_db::load_datarows(gesture_acts &ga){
    string sql = "SELECT acc_x, acc_y, acc_z, gyr_x, gyr_y, gyr_z, timestamp "
                 "FROM datarow WHERE acts_id=?;";
    int rc = sqlite3_prepare_v2(db, sql.c_str(), (int)sql.size(), &stmt, nullptr);
    if(rc == SQLITE_OK){
        sqlite3_bind_int(stmt, 1, ga.get_id());
        auto vec = ga.get_vec();
        while(sqlite3_step(stmt) == SQLITE_ROW) {
            double d1 = sqlite3_column_double(stmt, 0);
            double d2 = sqlite3_column_double(stmt, 1);
            double d3 = sqlite3_column_double(stmt, 2);
            double d4 = sqlite3_column_double(stmt, 3);
            double d5 = sqlite3_column_double(stmt, 4);
            double d6 = sqlite3_column_double(stmt, 5);
            int timestamp = sqlite3_column_int(stmt, 6);
            datarow dr(d1, d2, d3, d4, d5, d6, timestamp);
            vec.push_back(dr);
        }
        cout << "[SUCCESS] successfully load " << vec.size() << " datarows" << endl;
    } else{
        cerr << "[ERROR] statement error when loading datarows:\n" << sqlite3_errmsg(db) << endl;
    }
    sqlite3_finalize(stmt);
}