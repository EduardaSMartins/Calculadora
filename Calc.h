enum Digit {ZERO, ONE, TWO, THERE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};
enum Operation {ADDITION, SUBTRACTION, DIVISION, MULTIPLICATION, SQUARE_ROOT, PERCENTAGE};
enum Control {CLEAR, CLEAR_ALL, RESET, DECIMAL_SEPARATOR, MEMORY_READ_CLEAR, MEMORY_ADDITION, MEMORY_SUBTRACTION, EQUAL};
enum Signal {POSITIVE, NEGATIVE};

class Display: public Receiver{
  public:
    virtual void add(Digit ) = 0;
    virtual void setDecimalSeparator() = 0;
    virtual void setSignal(Signal ) = 0;
    virtual void setError() = 0;
    virtual void clear() = 0;
    virtual void clearAll() = 0;
};

class Receiver{
  public:
    virtual void receiveDigit(Digit ) = 0;
    virtual void receiveOperation(Operation ) = 0;
    virtual void receiveControl(Control ) = 0;

};
class Cpu: public Receiver{
    Display* display;
    int countOperand1 = 0;
    int countOperand2 = 0;
    Digit operand1[8], operand2[8];
    Operation* operation = NULL;

  public:
    void setDisplay(Display* );

    void receiveDigit(Digit ) = 0;
    void receiveOperation(Operation ) = 0;
    void receiveControl(Control ) = 0;

};


class Keyboard: public Receiver{
    Cpu* cpu;
    public:
      void setCpu(Cpu* );

      virtual void addKey(Key* ) = 0;

      void receiveDigit(Digit ) = 0;
      void receiveOperation(Operation ) = 0;
      void receiveControl(Control ) = 0;
};


class Calculator{
  public:
    virtual void setDisplay(Display* ) = 0;
    virtual void setCpu(Cpu* ) = 0;
    virtual void setKeyboard(Keyboard* ) = 0;
};

class CalcOne: public Calculator{ //EXEMPLO DE DECLARAÇÃO DO QUE ESTÁ NO MAIN
  
};

class Key{
   protected:
     Receiver* receiver;
   public:
      void setReceiver(Receiver* );

      virtual void press() = 0;
};

class KeyDigit: public Key{
     Digit digit;
   public:
      KeyDigit(Digit );
      void press();
};

class KeyOperation: public Key{
     Operation operation;
   public:
      KeyOperation(Operation );
      void press();
};

class KeyControl: public Key{
     Control control;
   public:
      KeyControl(Control );
      void press();
};

class KeySignal: public Key{
    Signal signal;
    public:
      KeySignal(Signal );
      void press();
};