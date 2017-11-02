//
// Created by cirq on 17-10-30.
//

#include <vector>
#include "gesture_db.h"
#include "gesture_reconstruct.h"

using namespace std;

gesture_db db;

gesture_reconstruct::gesture_reconstruct() = default;

gesture_reconstruct::gesture_reconstruct(int aid){
    this->acts_id = aid;
    db.load_acts(this->acts_id, this->ga);
}

gesture_acts &gesture_reconstruct::get_acts(){
    return this->ga;
}

void gesture_reconstruct::reconstruct(){
    db.load_datarows(this->ga);
    const vector<datarow> &vec = this->ga.get_vec();
    for(auto ptr = vec.begin(), e = vec.end(); ptr != e; ++ptr){
        cout << *ptr << endl;
    }
}
