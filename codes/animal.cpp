#include "animal.h"
void animal::feed() {}
void animal::collect() {}
void animal::upgrade() {}
//_decOrInc:     0:decrease   1:increase
//_code: illustrates the code of each product
//_number: shows the number of each item to increase(buy) or decrease(sell).
void animal::transfer(bool _decOrInc, int _number) { //this function is definetely same in aviculture & livestock & sheepfold
    if (_decOrInc == 0) {
        if (number - _number >= 0) {
            number -= _number;
        }
    }
    if (_decOrInc == 1) {
        if ((number + _number) <= capasity) {
            number += _number;
        }
    }
}
int animal::getLvl() { return lvl; }
int animal::getCapasity() { return capasity; }
int animal::getNumber() { return number; }
int animal::getCondition() { return condition; }
void animal::check() {}
