/**
 * Demo program for snowman exercise.
 * 
 * Author: Erel Segal-Halevi
 * Since : 2021-02
 */

#include "snowman.hpp"

#include <iostream>
#include <stdexcept>
using namespace std;

int main() {

    int k = 10;
    cin >> k;

    int arr[k];
    for (int i = 0; i < k; i++) {
        arr[i] = i;
        cout << arr[i] << endl;
    }
    cout << ariel::snowman(11114411) << endl; /* Should print:
_===_
(.,.)
( : )
( : )
	*/
    cout << ariel::snowman(33232124) << endl; /* Should print:
	
   _
  /_\
\(o_O)
 (] [)>
 (   )
	*/

    cout << ariel::snowman(44444432) << endl;
    try {
        cout << ariel::snowman(5) << endl; // Exception - not a valid code
    } catch (exception &ex) {
        cout << "   caught exception: " << ex.what() << endl; // should print "Invalid code '5'"
    }
}
