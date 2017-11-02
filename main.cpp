#include "src/gesture_reconstruct.h"

using namespace std;

int main(){
    gesture_reconstruct gr(299);

    cout << gr.get_acts() << endl;

    gr.reconstruct();

    cout << gr.get_acts() << endl;

    return 0;
}