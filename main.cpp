#include "Calc.h"
#include <stdlib.h>
#include <stdio.h>

int main(){

    Calculator* c1 = new CalcOne();
    Cpu* cpu1 = new CpuOne();
    Display* c1 = new DisOne();
    Keyboard* k1 = new KeyOne();

    KeyDigit key0(ZERO), key1(ONE), key2(TWO), key3(THERE), key4(FOUR), key5(FIVE), key6(SIX), key7(SEVEN), key8(EIGHT), key9(NINE);
    KeyOperation keyAdd(ADDITION);
    KeyControl keyEqual(EQUAL);

    k1.addKey(&key0);
    k1.addKey(&key1);
    k1.addKey(&key2);
    k1.addKey(&key3);
    k1.addKey(&key4);
    k1.addKey(&key5);
    k1.addKey(&key6);
    k1.addKey(&key7);
    k1.addKey(&key8);
    k1.addKey(&key9);
    
    key1.press();
    key1.press();
    key1.press();
    key0.press();
    keyadd.press();
    key1.press();
    keyEqual.press()

    return 1;
}