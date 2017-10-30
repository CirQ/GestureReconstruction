#include "gesture_db.h"

using namespace std;

int main(){
    gesture_db d = gesture_db();
    gesture_acts a;

    d.load_acts(387, a);
    d.load_datarows(a);

    cout << a.get_vec().data() << endl;

    return 0;
}