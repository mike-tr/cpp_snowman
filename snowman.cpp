#include "snowman.hpp"
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

const int NUM_PARTS = 8;
const int INDEX_OFFSET = -1;
const int NUM_LEVELS = 4;

const int max_bound = 99999999;
const int min_bound = 10000000;

// All the bases for the snowman, as had might have to lines we seperate it into 2 sets, those with exatra space,
// and those without an extra space.
string phats_full[4] = {" _===_\n", "  ___\n .....\n", "   _\n  /_\\\n", "  ___\n (_*_)\n"};
string phats[4] = {"_===_\n", " ___\n .....\n", "  _\n /_\\\n", " ___\n(_*_)\n"};

string pnose[4] = {",", ".", "_", " "};

string peye[4] = {".", "o", "O", "-"};

string pleft_arm_up[4] = {" ", "\\", " ", ""};
string pleft_arm_down[4] = {"<", " ", "/", ""};

string pright_arm_up[4] = {"", "/", "", ""};
string pright_arm_down[4] = {">", "", "\\", ""};

string ptorso[4] = {" : ", "] [", "> <", "   "};

string pbase[4] = {" : ", "\" \"", "___", "   "};

int get_id(int *num) {
    const int base = 10;
    int id = *num % base;
    if (id == 0 || id > 4) {
        throw invalid_argument{"Invalid code : \'" + to_string(id) + "\' all characters must be between 1-4, included."};
    }
    *num /= base;
    return id;
}

enum parts_id {
    base = 7,
    torso = 6,
    right_arm = 5,
    left_arm = 4,
    right_eye = 3,
    left_eye = 2,
    nose = 1,
    hat = 0,
};

// add the body part at each level!
void add_body_part(const int parts[], int level, bool frontspace, string *output) {
    if (level == 0) {
        // add hat
        *output += frontspace ? phats_full[parts[hat]] : phats[parts[hat]];
    } else if (level == 1) {
        // add face level
        *output += pleft_arm_up[parts[left_arm]];                                                   // add left arm
        *output += "(" + peye[parts[left_eye]] + pnose[parts[nose]] + peye[parts[right_eye]] + ")"; // add body
        *output += pright_arm_up[parts[right_arm]] + "\n";                                          // add right arm
    } else if (level == 2) {
        // add torso level
        *output += pleft_arm_down[parts[left_arm]];
        *output += "(" + ptorso[parts[torso]] + ")";
        *output += pright_arm_down[parts[right_arm]] + "\n";
    } else if (level == 3) {
        // add base level
        if (frontspace) {
            *output += " ";
        }
        *output += "(" + pbase[parts[base]] + ")";
    }
}

namespace ariel {
string snowman(int input) {
    if (input < min_bound || input > max_bound) {
        throw logic_error{"Invalid code: \'" + to_string(input) + "\'"};
    }
    int parts[NUM_PARTS] = {0};
    for (int i = 0; i < NUM_PARTS; i++) {
        parts[NUM_PARTS - i - 1] = get_id(&input) + INDEX_OFFSET;
    }

    bool spaces = parts[parts_id::left_arm] != 4 + INDEX_OFFSET;

    string s_output;
    for (int i = 0; i < NUM_LEVELS; i++) {
        add_body_part(parts, i, spaces, &s_output);
    }
    return s_output;
}
} // namespace ariel
