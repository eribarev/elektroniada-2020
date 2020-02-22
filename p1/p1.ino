const int pinMap[]={11, 10, 9, 8, 7, 6, 5}, pinDecPoint=4, pinBtnPlus=3, pinBtnMinus=2;

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
int currDigit=0;

void displayDigit(int d)
{
  for (int i=0; i<7; i++){
    digitalWrite(pinMap[i], digits[d][i]);
  }
}

void setup() {
  // put your setup code here, to run once:
  for (int i=0; i<7; i++) pinMode(pinMap[i], OUTPUT);
  pinMode(pinBtnPlus, INPUT_PULLUP);
  pinMode(pinBtnMinus, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  lastPlus=plus;
  lastMinus=minus;

  plus=!digitalRead(pinBtnPlus);
  minus=!digitalRead(pinBtnMinus);

  if (plus>lastPlus) currDigit++;
  if (minus>lastMinus) currDigit--;
  if (currDigit<0) currDigit=0;
  if (currDigit>9) currDigit=9;

  displayDigit(currDigit);
}
