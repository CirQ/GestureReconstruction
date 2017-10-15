#include <iostream>
#include <sqlite3.h>

using namespace std;

int main(){
    sqlite3 *db;

    int rc = sqlite3_open("GESTURE.db", &db);
    if(rc != SQLITE_OK) {
        cerr << "cannot open " << sqlite3_errmsg(db) << endl;
        sqlite3_close(db);
        exit(EXIT_FAILURE);
    }



    sqlite3_close(db);
    return 0;
}