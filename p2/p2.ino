const int pinMap[]={11, 10, 9, 8, 7, 6, 5}, pinDecPoint=4, pinBtnMinus=2;

const bool digits[10][7]={
  {1, 1, 1, 1, 1, 1, 0},  //0
  {0, 1, 1, 0, 0, 0, 0},  //1
  {1, 1, 0, 1, 1, 0, 1},  //2
  {1, 1, 1, 1, 0, 0, 1},  //3
  {0, 1, 1, 0, 0, 1, 1},  //4
  {1, 0, 1, 1, 0, 1, 1},  //5
  {1, 0, 1, 1, 1, 1, 1},  //6
  {1, 1, 1, 0, 0, 0, 0},  //7
  {1, 1, 1, 1, 1, 1, 1},  //8
  {1, 1, 1, 1, 0, 1, 1}   //9
};
bool plus=false, minus=false, lastPlus, lastMinus;

void displayDigit(int d)
{
  for (int i=0; i<7; i++){
    digitalWrite(pinMap[i], digits[d][i]);
  }
}

void setup() {
  // put your setup code here, to run once:
  for (int i=0; i<7; i++) pinMode(pinMap[i], OUTPUT);
  pinMode(pinBtnMinus, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  lastMinus=minus;

  minus=!digitalRead(pinBtnMinus);

  if (minus>lastMinus) displayDigit(8);
  if (minus<lastMinus) displayDigit(random(1, 6));
}
