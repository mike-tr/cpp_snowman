#include "snowman.hpp"
#include <array>
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

const int NUM_PARTS = 8;
const int INDEX_OFFSET = -1;
const int NUM_LEVELS = 4;
const int BASE10 = 10;

const int max_bound = 99999999;
const int min_bound = 10000000;

// All the bases for the snowman, as had might have to lines we seperate it into 2 sets, those with exatra space,
// and those without an extra space.

array<string, 4> phats_full = {" _===_\n", "  ___\n .....\n", "   _\n  /_\\\n", "  ___\n (_*_)\n"};
array<string, 4> phats = {"_===_\n", " ___\n .....\n", "  _\n /_\\\n", " ___\n(_*_)\n"};

array<string, 4> pnose = {",", ".", "_", " "};

array<string, 4> peye = {".", "o", "O", "-"};

array<string, 4> pleft_arm_up = {" ", "\\", " ", ""};
array<string, 4> pleft_arm_down = {"<", " ", "/", ""};

array<string, 4> pright_arm_up = {"", "/", "", ""};
array<string, 4> pright_arm_down = {">", "", "\\", ""};

array<string, 4> ptorso = {" : ", "] [", "> <", "   "};

array<string, 4> pbase = {" : ", "\" \"", "___", "   "};

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

/**
 * add each level of the snowman.
 * level 0 : hat
 * level 1 : face
 * level 2 : torso
 * level 3 : base
 * 
 * *output : is the return output. ( its getting changed each itteration )
 **/
void add_body_part(const array<int, NUM_PARTS> parts, int level, bool frontspace, string *output) {
    if (level == 0) {
        // add hat
        *output += frontspace ? phats_full.at(parts[hat]) : phats.at(parts[hat]);
    } else if (level == 1) {
        // add face level
        *output += pleft_arm_up.at(parts[left_arm]);                                                         // add left arm
        *output += "(" + peye.at(parts[left_eye]) + pnose.at(parts[nose]) + peye.at(parts[right_eye]) + ")"; // add body
        *output += pright_arm_up.at(parts[right_arm]) + "\n";                                                // add right arm
    } else if (level == 2) {
        // add torso level
        *output += pleft_arm_down.at(parts[left_arm]);
        *output += "(" + ptorso.at(parts[torso]) + ")";
        *output += pright_arm_down.at(parts[right_arm]) + "\n";
    } else if (level == 3) {
        // add base level
        if (frontspace) {
            *output += " ";
        }
        *output += "(" + pbase.at(parts[base]) + ")";
    }
}

namespace ariel {
string snowman(int input) {
    // check if input too long or too short.
    if (input < min_bound || input > max_bound) {
        throw invalid_argument{"Invalid code \'" + to_string(input) + "\'"};
    }
    // create an array that will hold the part indecies.
    array<int, NUM_PARTS> parts{};
    int input_copy = input;
    // get the number for each part, throw error if number part is invalid.
    for (int i = NUM_PARTS - 1; i >= 0; i--) {
        int id = input_copy % BASE10;
        if (id == 0 || id > 4) {
            throw invalid_argument{"Invalid code \'" + to_string(input) + "\'"};
        }
        parts.at(i) = id + INDEX_OFFSET;
        input_copy /= BASE10;
    }

    // save if we need or dont need a space at the beggining of the snowman on each row.
    // a.k.a if there is a hand or no hand.
    bool spaces = parts[parts_id::left_arm] != 4 + INDEX_OFFSET;

    string s_output;
    for (int i = 0; i < NUM_LEVELS; i++) {
        add_body_part(parts, i, spaces, &s_output);
    }
    return s_output;
}
} // namespace ariel
