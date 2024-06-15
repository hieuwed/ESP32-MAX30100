# 1. Giới thiệu
- Sử dụng ESP32 và MAX30100 để đo nhịp tim và nồng độ oxy trong máu
- Hiển thị kết quả đo được trên màn hình OLED 1.3"
# 2. Hướng dẫn sử dụng
## a. Kết nối các linh kiện như sau:


## b. Nạp code vào ESP32:
- Tải và cài đặt Arduino IDE từ [Arduino IDE](https://www.arduino.cc/en/software)
- Mở Arduino IDE và cài đặt các thư viện cần thiết: MAX30100lib, Adafruit_SSD1306, Adafruit_GFX
- Tải mã nguồn từ github và nạp code vào ESP32.
  
## c. Sử dụng thiết bị:
- Cấp nguồn cho ESP32 thông qua dây cáp.
- Đặt ngón tay lên cảm biến MAX30100 và quan sát kết quả trên màn hình OLED.
- Kết quả bao gồm nhịp tim (bpm) và nồng độ oxy trong máu (%SpO2).
- Link video hướng dẫn:

# 3.Danh sách linh kiện:

## 1. ESP32:
- Số lượng: 1
- Link mua: [ESP32](https://shopee.vn/B%E1%BA%A3ng-M%E1%BA%A1ch-Ph%C3%A1t-Tri%E1%BB%83n-ESP32-L%C3%B5i-K%C3%A9p-ESP-32-ESP-32S-ESP-WROOM-32-30P-38P-WiFi-Bluetooth-i.869927552.21777593794?sp_atk=09c16670-26d1-4616-8e48-89e23ca50278&xptdk=09c16670-26d1-4616-8e48-89e23ca50278)
## 2. Cảm biến MAX30100:
- Số lượng: 1
- Link mua: [MAX30100](https://shopee.vn/Module-c%E1%BA%A3m-bi%E1%BA%BFn-nh%E1%BB%8Bp-tim-v%C3%A0-oxy-trong-m%C3%A1u-MAX30100-i.1048311475.20792450869?sp_atk=6d6b3305-d5cc-4c2c-9ae9-b41b2a153110&xptdk=6d6b3305-d5cc-4c2c-9ae9-b41b2a153110)
## 3. Màn hình OLED 1.3" :
- Số lượng: 1
- Link mua: [OLED](https://shopee.vn/M%C3%A0n-H%C3%ACnh-OLED-1.3-128x64-I2C-Xanh-OLED-13-I2C-B-i.171084633.7247756437?sp_atk=d4dcae5c-9b05-49aa-9609-3a1f78fb77ec&xptdk=d4dcae5c-9b05-49aa-9609-3a1f78fb77ec)
## 4. Dây cáp kết nối:
- Số lượng: 1
- Link mua: [dây cáp](https://shopee.vn/Microusb-C%C3%A1p-microusb-d%C3%A2y-nap-code-esp32-d%C3%A2y-s%E1%BA%A1c-%C4%91i%E1%BB%87n-tho%E1%BA%A1i-i.672645516.23476417257?sp_atk=8a2164a8-f0f4-4269-bc28-d33988fe9850&xptdk=8a2164a8-f0f4-4269-bc28-d33988fe9850)
## Breadboard và dây nhảy:
- Số lượng: 1
- Link mua: [Breadboard và dây nhảy](https://shopee.vn/3.3V-5V-MB102-Breadboard-power-module-MB-102-830-points-Solderless-Prototype-Bread-board-kit-65-Flexible-jumper-wires-i.81431289.7134752553?sp_atk=4f67d720-0f57-4553-b23e-49990ff97ccf&xptdk=4f67d720-0f57-4553-b23e-49990ff97ccf)

# 4. Sơ đồ nguyên lý:

![image](https://github.com/hieuwed/ESP32-MAX30100/assets/130844328/8ae57c79-c350-4fb2-8f32-922811f73619)


# 5. Thiết kế phần mềm:
- Đọc dữ liệu từ cảm biến MAX30100:
  - ESP32 sử dụng giao tiếp I2C để lấy dữ liệu từ cảm biến MAX30100.
  - Sử dụng thư viện MAX30100lib để dễ dàng đọc nhịp tim và nồng độ oxy.
  
- Hiển thị dữ liệu lên màn hình OLED:
  - Sử dụng giao tiếp I2C để gửi dữ liệu từ ESP32 đến màn hình OLED 1.3 inch.
  - Sử dụng thư viện Adafruit_SSD1306 và Adafruit_GFX để hiển thị dữ liệu nhịp tim và nồng độ oxy dưới dạng văn bản và đồ họa.

# 6. Tác giả

| Sv thực hiện | MSSV | Github |
|--------------|------|---------------------|
|Vũ Minh Hiếu|20215579|[Here](https://github.com/hieuwed)|
|            |        |      |
|            |        |      |
|            |        |      |



