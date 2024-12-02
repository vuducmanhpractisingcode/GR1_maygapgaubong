// C++ code cải tiến
//
#define motorleft 32
#define motorright 33
#define motorfront 27
#define motorback 14
#define motorup 12
#define motordown 13

#define buttonleft 5
#define buttonright 18
#define buttonfront 21
#define buttonback 19
#define buttonup 4
#define buttondown 15

bool prevButtonState[] = {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH};
int buttonPins[] = {buttonleft, buttonright, buttonfront, buttonback, buttonup, buttondown};
int motorPins[] = {motorleft, motorright, motorfront, motorback, motorup, motordown};


//debug sut áp
const int ledPin = 2;

void setup()
{
  // Serial Monitor
  Serial.begin(115200);

  //set up signal pins
  for (int i = 0; i < 6; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }

  // Default the state of all motors
  for (int i = 0; i < 6; i++) {
    pinMode(motorPins[i], OUTPUT);
    digitalWrite(motorPins[i], LOW);
  }

  //debug sụt áp
  pinMode(ledPin, OUTPUT);
  esp_reset_reason_t reason = esp_reset_reason();
  if (reason == ESP_RST_POWERON || reason == ESP_RST_BROWNOUT) {
    // nếu ESP32 được khởi động lại
    flashLED();
  }
}
// Nháy led
void flashLED() {
  digitalWrite(ledPin, HIGH);
  delay(500); // LED sáng trong 200ms
  digitalWrite(ledPin, LOW);
  delay(500); // LED tắt trong 200ms
}

void loop()
{
  for (int i = 0; i < 6; i++) {
    bool buttonState = digitalRead(buttonPins[i]);

    // DO action only if buttonstate change
    if (buttonState != prevButtonState[i]) {
      if (buttonState == LOW) {
        digitalWrite(motorPins[i], HIGH);

        //debugging
        Serial.print("Button ");
        Serial.print(i);
        Serial.println(": PRESSED");
        Serial.print("Motor ");
        Serial.print(i);
        Serial.println(": ON");

        // Allow only 1 motor work in one time
        for (int j = 0; j < 6; j++) {
          if (j != i) {
            digitalWrite(motorPins[j], LOW);
          }
        }
      } else { // release button and debugging
        digitalWrite(motorPins[i], LOW);
        Serial.print("Button ");
        Serial.print(i);
        Serial.println(": RELEASED");
        Serial.print("Motor ");
        Serial.print(i);
        Serial.println(": OFF");
      }

      // Cập nhật trạng thái trước đó của nút
      prevButtonState[i] = buttonState;
    }
  }

  // Delay nhỏ để tránh làm quá tải Serial Monitor
  delay(50);
}
