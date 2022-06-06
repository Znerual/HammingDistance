#include "HammingDistance.h"

using namespace std;

string int_to_str(int input) {
    /*
    Converts an integer to its 4er base string representation
    */
    if (input == 0) {
        return string(SEQUENCE_LENGTH, '0');
    }

    string number = string();
    int rest = input;
    int digits = 0;
    while (rest != 0) {
        number.append(to_string(rest % 4));
        rest /= 4;
        digits += 1;
    }

    reverse(number.begin(), number.end());
    int pad_amount = SEQUENCE_LENGTH - digits;
    if (pad_amount > 1) {
        string pad = string(pad_amount, '0');
        return pad + number;
    }

    return number;
}

int get_tetra_hamming_distance(string& aa, string& bb) {
    int distance = 0;

    for (auto i = 0; i < aa.size(); i++) {
        if (aa[i] != bb[i]) {
            distance += 1;
        }
    }

    return distance;
}