#include "Calc.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

void Display::add(Digit digit){
  switch(digit){
    case ZERO: std::cout << 0; break;
    case ONE: std::cout << 1; break;
    case TWO: std::cout << 2; break;
    case THERE: std::cout << 3; break;
    case FOUR: std::cout << 4; break;
    case FIVE: std::cout << 5; break;
    case SIX: std::cout << 6; break;
    case SEVEN: std::cout << 7; break;
    case EIGHT: std::cout << 8; break;
    case NINE: std::cout << 9; break;


    default:
        std::cout << 'E';
  }
}

void Display::clearAll(){
    std::cout << std::endl;
    //operand count não precisa ser zerado <?>
}

void Display::clear(){
    if(this->Cpu?this->Cpu->operation == NULL){
        this->Cpu->countOperand1--;
    }
    else if(this->Cpu?this->Cpu->operation != NULL){
        this->Cpu->countOperand2--;
    }
}

void Display:reset(){
    free(this->Cpu->Operand1);
    free(this->Cpu->Operand2);
    this->Cpu->countOperand1 = 0;
    this->Cpu->countOperand2 = 0;
}

void Cpu::receiveDigit(Digit digit){
  int num;
  switch (expression){
    case ZERO: num = 0;
    break;
    case ONE: num = 1;
    break;  
    case TWO: num = 2;
    break;
    case THREE: num = 3;
    break;
    case FOUR: num = 4;
    break;
    case FIVE: num = 5;
    break;
    case SIX: num = 6;
    break;
    case SEVEN: num = 7;
    break;
    case EIGHT: num = 8;
    break;
    case NINE: num = 9;
    break;

  default:
    break;
  }
    // Armazenar no operando apropriado
    if(this->operation == NULL){
        this->operand1[this->countOperand1] = digit;
        this->countOperand1++;
    }
    else if(this->operation != NULL){
        this->operand2[this->countOperand2] = digit;
        this->countOperand2++;
    }

    // Mostrar o dígito na tela
    this->Display?this->display->add(digit):void();
}

void Cpu::receiveOperand(Operand operand){

}

void Cpu::sum()

void Cpu::receiveControl(Control control){
    switch (Control control)
    {
    case CLEAR:this->Display?this->display->clear(); break;
    case CLEAR_ALL:this->Display?this->display->clearAll(); break;
    case RESET:this->Display?this->display->reset()

    
    default:
        break;
    }
}

void Display::receiveDigit(Digit digit){
    add(digit):void();
}


void Keyboard::addKey(Key* ){
  
}
void Keyboard::receiveDigit(Digit digit){
  // 
  this->cpu?this->cpu->receiveDigit(digit):void();
};
void Keyboard::receiveOperation(Operation operation){
  this->cpu?this->cpu->receiveOperation(operation):void();
};
void Keyboard::receiveControl(Control control){
  this->cpu?this->cpu->receiveControl(control):void();
};

void Key::setKeyboard(Keyboard* keyboard){
  this->keyboard = keyboard;
}

KeyDigit::KeyDigit(Digit d):digit(d){}

void KeyDigit::press(){
  this->keyboard->receiveDigit(this->digit);
}

KeyOperation::KeyOperation(Operation o):operation(o){}

void KeyOperation::press(){
  this->keyboard->receiveOperation(this->operation);
}

KeyControl::KeyControl(Control c):control(c){}

void KeyControl::press(){
  this->keyboard->receiveControl(this->control);
}