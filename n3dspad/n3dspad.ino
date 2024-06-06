#include <BleGamepad.h>
#include <Arduino.h>

// ボタンのピン番号の定義
const int pinA = 32;
const int pinB = 33;
const int pinX = 25;
const int pinY = 26;
const int pinL = 27;
const int pinR = 14;
const int pinZL = 12;
const int pinZR = 13;
const int pinDpadUp = 19;
const int pinDpadDown = 18;
const int pinDpadLeft = 5;
const int pinDpadRight = 17;
const int pinCirclePadX = 35; // アナログ入力
const int pinCirclePadY = 34; // アナログ入力
const int pinCstickX = 39; // アナログ入力
const int pinCstickY = 36; // アナログ入力
const int pinStart = 21;
const int pinSelect = 22;
const int pinHome = 23;
const int pinPower = 4;

BleGamepad bleGamepad("N3DSPad", "Maker", 100);

void setup() {
  Serial.begin(115200);
  bleGamepad.begin();

  // デジタル入力ピンの設定
  pinMode(pinA, INPUT_PULLUP);
  pinMode(pinB, INPUT_PULLUP);
  pinMode(pinX, INPUT_PULLUP);
  pinMode(pinY, INPUT_PULLUP);
  pinMode(pinL, INPUT_PULLUP);
  pinMode(pinR, INPUT_PULLUP);
  pinMode(pinZL, INPUT_PULLUP);
  pinMode(pinZR, INPUT_PULLUP);
  pinMode(pinDpadUp, INPUT_PULLUP);
  pinMode(pinDpadDown, INPUT_PULLUP);
  pinMode(pinDpadLeft, INPUT_PULLUP);
  pinMode(pinDpadRight, INPUT_PULLUP);
  pinMode(pinStart, INPUT_PULLUP);
  pinMode(pinSelect, INPUT_PULLUP);
  pinMode(pinHome, INPUT_PULLUP);
  pinMode(pinPower, INPUT_PULLUP);

  // アナログ入力ピンの設定
  analogReadResolution(12); // 12ビット解像度でのアナログ読み取りを設定
}

void loop() {
  if (bleGamepad.isConnected()) {
    // ボタンの状態を読み取り
    if (digitalRead(pinA) == LOW) bleGamepad.press(BUTTON_1);
    else bleGamepad.release(BUTTON_1);

    if (digitalRead(pinB) == LOW) bleGamepad.press(BUTTON_2);
    else bleGamepad.release(BUTTON_2);

    if (digitalRead(pinX) == LOW) bleGamepad.press(BUTTON_3);
    else bleGamepad.release(BUTTON_3);

    if (digitalRead(pinY) == LOW) bleGamepad.press(BUTTON_4);
    else bleGamepad.release(BUTTON_4);

    if (digitalRead(pinL) == LOW) bleGamepad.press(BUTTON_5);
    else bleGamepad.release(BUTTON_5);

    if (digitalRead(pinR) == LOW) bleGamepad.press(BUTTON_6);
    else bleGamepad.release(BUTTON_6);

    if (digitalRead(pinZL) == LOW) bleGamepad.press(BUTTON_7);
    else bleGamepad.release(BUTTON_7);

    if (digitalRead(pinZR) == LOW) bleGamepad.press(BUTTON_8);
    else bleGamepad.release(BUTTON_8);

    if (digitalRead(pinStart) == LOW) bleGamepad.press(BUTTON_9);
    else bleGamepad.release(BUTTON_9);

    if (digitalRead(pinSelect) == LOW) bleGamepad.press(BUTTON_10);
    else bleGamepad.release(BUTTON_10);

    if (digitalRead(pinHome) == LOW) bleGamepad.press(BUTTON_11);
    else bleGamepad.release(BUTTON_11);

    if (digitalRead(pinPower) == LOW) bleGamepad.press(BUTTON_12);
    else bleGamepad.release(BUTTON_12);

    // D-padの状態を読み取り
    int16_t dpadX = 0;
    int16_t dpadY = 0;

    if (digitalRead(pinDpadUp) == LOW) dpadY = -1;
    if (digitalRead(pinDpadDown) == LOW) dpadY = 1;
    if (digitalRead(pinDpadLeft) == LOW) dpadX = -1;
    if (digitalRead(pinDpadRight) == LOW) dpadX = 1;

    bleGamepad.setAxes(0, 0, 0, 0, dpadX, dpadY);

    // アナログスティックの状態を読み取り
    int16_t circlePadX = analogRead(pinCirclePadX) - 2048;
    int16_t circlePadY = analogRead(pinCirclePadY) - 2048;
    int16_t cstickX = analogRead(pinCstickX) - 2048;
    int16_t cstickY = analogRead(pinCstickY) - 2048;

    bleGamepad.setLeftThumb(circlePadX, circlePadY);
    bleGamepad.setRightThumb(cstickX, cstickY);

    // データの送信
    bleGamepad.sendReport();
  }
  delay(10);
}
