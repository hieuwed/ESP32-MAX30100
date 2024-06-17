#include <Wire.h>
#include "MAX30100_PulseOximeter.h"
#include <U8g2lib.h>

#define OLED_SCK_PIN 22
#define OLED_SDA_PIN 21
#define VIBRATION_MOTOR_PIN 4 // Định nghĩa chân điều khiển động cơ rung
#define LED_PIN 2             // Định nghĩa chân điều khiển đèn LED

PulseOximeter pox;
U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE, OLED_SCK_PIN, OLED_SDA_PIN);

uint32_t previousSensorUpdate = 0;
uint32_t previousPrint = 0;
bool dataReady = false;   // Cờ cho biết dữ liệu đã sẵn sàng để in ra màn hình
bool isPrinting = false;  // Cờ cho biết đang trong quá trình in dữ liệu ra màn hình
unsigned long currentMillis = 0;

unsigned long vibrationStartTime = 0; // Biến lưu thời gian bắt đầu rung
bool isVibrating = false;              // Cờ cho biết động cơ đang rung
unsigned long ledStartTime = 0;        // Biến lưu thời gian bắt đầu bật LED
bool isLedOn = false;                  // Cờ cho biết đèn LED đang bật

void onBeatDetected() {
  Serial.println("Beat!");
  // Kích hoạt động cơ rung và đèn LED khi phát hiện nhịp tim
  digitalWrite(VIBRATION_MOTOR_PIN, HIGH);
  vibrationStartTime = millis(); // Lưu lại thời gian bắt đầu rung
  isVibrating = true;            // Đặt cờ đang rung

  digitalWrite(LED_PIN, HIGH);   // Bật đèn LED
  ledStartTime = millis();       // Lưu lại thời gian bắt đầu bật LED
  isLedOn = true;                // Đặt cờ đèn LED đang bật
}

void setup(void) {
  Serial.begin(115200);

  // Initialize OLED display
  Serial.print("Initializing OLED display...");
  if (!u8g2.begin()) {
    Serial.println("FAILED");
    for (;;);
  } else {
    Serial.println("SUCCESS");
  }
  u8g2.setFont(u8g2_font_ncenB08_tr); // Chọn phông chữ

  // Initialize vibration motor pin
  pinMode(VIBRATION_MOTOR_PIN, OUTPUT);  // Cấu hình chân điều khiển VIBRATION_MOTOR_PIN như đầu ra
  digitalWrite(VIBRATION_MOTOR_PIN, LOW);

  // Initialize LED pin
  pinMode(LED_PIN, OUTPUT);  // Cấu hình chân điều khiển LED_PIN như đầu ra
  digitalWrite(LED_PIN, LOW);

  Serial.print("Initializing pulse oximeter...");

  if (!pox.begin()) {
    Serial.println("FAILED");
    for (;;);
  } else {
    Serial.println("SUCCESS");
  }

  pox.setIRLedCurrent(MAX30100_LED_CURR_7_6MA);
  pox.setOnBeatDetectedCallback(onBeatDetected);
}

void drawSolidHeart(int x, int y) {
  u8g2.drawDisc(x + 6, y + 6, 6);
  u8g2.drawDisc(x + 18, y + 6, 6);
  u8g2.drawTriangle(x, y + 8, x + 24, y + 8, x + 12, y + 24);
  u8g2.drawBox(x + 6, y + 6, 12, 10);
}

void loop(void) {
  currentMillis = millis();

  // Cập nhật dữ liệu từ cảm biến
  if (!isPrinting && (currentMillis - previousSensorUpdate >= 10)) {
    pox.update();
    previousSensorUpdate = millis();

    // In dữ liệu ra Serial
    Serial.print("HeartRate=");
    Serial.print(int(pox.getHeartRate()));
    Serial.print(" bpm, SpO2=");
    Serial.print(int(pox.getSpO2()));
    Serial.println(" %");
    // Đánh dấu dữ liệu đã sẵn sàng để in ra màn hình
    dataReady = true;
  }

  // Kiểm tra và tắt động cơ rung sau 400ms
  if (isVibrating && (currentMillis - vibrationStartTime >= 400)) {
    digitalWrite(VIBRATION_MOTOR_PIN, LOW);
    isVibrating = false; // Đặt lại cờ đang rung
  }

  // Kiểm tra và tắt đèn LED sau 700ms
  if (isLedOn && (currentMillis - ledStartTime >= 700)) {
    digitalWrite(LED_PIN, LOW);
    isLedOn = false; // Đặt lại cờ đèn LED đang bật
  }

  // In dữ liệu ra màn hình
  if (!isPrinting && (currentMillis - previousPrint >= 1500) && dataReady) {
    isPrinting = true; // Đánh dấu đang in ra màn hình
    u8g2.clearBuffer();  
    
    // Vẽ trái tim ở giữa dòng phía trên
    int heartX = (u8g2.getDisplayWidth() - 24) / 2;  // Tính toán để đặt trái tim vào giữa màn hình
    drawSolidHeart(heartX, 0);

    // In heart rate
    u8g2.drawStr(0, 35, "HeartRate=");
    u8g2.setCursor(70, 35);
    u8g2.print(int(pox.getHeartRate()));
    u8g2.print(" bpm");

    // In SpO2
    u8g2.drawStr(0, 50, "SpO2=");
    u8g2.setCursor(70, 50);
    u8g2.print(int(pox.getSpO2()));
    u8g2.print(" %");

    // Gửi buffer lên màn hình
    u8g2.sendBuffer();
    // Đánh dấu dữ liệu đã in xong
    isPrinting = false;
    previousPrint = millis();
  }
}
