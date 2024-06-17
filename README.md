# 1. Giới thiệu
- Sử dụng ESP32 và MAX30100 để đo nhịp tim và nồng độ oxy trong máu
- Hiển thị kết quả đo được trên màn hình OLED 1.3"
- Khi  đặt ngón tay lên cảm biển đo thì module động cơ rung và đèn led sẽ rung và phát sáng
# 2. Hướng dẫn sử dụng
## a. Kết nối các linh kiện như sau:
![image](https://github.com/hieuwed/ESP32-MAX30100/assets/130844328/0a16d3b6-44dd-4ec0-a3b0-8485b8d00726)


## b. Nạp code vào ESP32:
- Tải và cài đặt Arduino IDE từ [Arduino IDE](https://www.arduino.cc/en/software)
- Mở Arduino IDE và cài đặt các thư viện cần thiết: MAX30100lib, U8g2
- Tải mã nguồn từ github và nạp code vào ESP32.
  
## c. Sử dụng thiết bị:
- Cấp nguồn cho ESP32 thông qua dây cáp.
- Đặt ngón tay lên cảm biến MAX30100 và quan sát kết quả trên màn hình OLED.
- Kết quả bao gồm nhịp tim (bpm) và nồng độ oxy trong máu (%SpO2).
- Link video hướng dẫn: [Video hướng dẫn](https://www.youtube.com/watch?v=8mRIQhtyXns)

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
- Link mua: [Dây cáp](https://shopee.vn/Microusb-C%C3%A1p-microusb-d%C3%A2y-nap-code-esp32-d%C3%A2y-s%E1%BA%A1c-%C4%91i%E1%BB%87n-tho%E1%BA%A1i-i.672645516.23476417257?sp_atk=8a2164a8-f0f4-4269-bc28-d33988fe9850&xptdk=8a2164a8-f0f4-4269-bc28-d33988fe9850)

## 5. Module Động Cơ Rung Vibration Motor:
- Số lượng: 1
- Link mua: [Động cơ rung](https://hshop.vn/products/mach-dong-co-rung-viration-motor-1027)

## 6. Đèn led:
- Số lượng: 1
- Link mua: [Đèn led](https://shopee.vn/product/1033689780/23274264349?gad_source=1&gclid=Cj0KCQjwvb-zBhCmARIsAAfUI2vL4jPeUOgdCcff78l6-Rsgru4PlEss2VHTMo0lihB-EUwYgACQgeAaAnGaEALw_wcB)

## 7. Breadboard và dây nhảy:
- Số lượng: 1
- Link mua: [Breadboard và dây nhảy](https://shopee.vn/3.3V-5V-MB102-Breadboard-power-module-MB-102-830-points-Solderless-Prototype-Bread-board-kit-65-Flexible-jumper-wires-i.81431289.7134752553?sp_atk=4f67d720-0f57-4553-b23e-49990ff97ccf&xptdk=4f67d720-0f57-4553-b23e-49990ff97ccf)

# 4. Sơ đồ nguyên lý:

![image](https://github.com/hieuwed/ESP32-MAX30100/assets/130844328/490a95f1-ccae-4d85-9363-c5eadeb3ef95)



# 5. Thiết kế phần mềm:
### Đọc dữ liệu từ cảm biến MAX30100:
- ESP32 sử dụng giao tiếp I2C để lấy dữ liệu từ cảm biến MAX30100 thông qua thư viện MAX30100_PulseOximeter.
- Khi có nhịp tim được phát hiện, cảm biến sẽ gửi tín hiệu đến ESP32.

### Hiển thị dữ liệu lên màn hình OLED:
- Sử dụng giao tiếp I2C để gửi dữ liệu từ ESP32 đến màn hình OLED 1.3 inch.
- Thư viện U8g2lib được sử dụng để hiển thị dữ liệu nhịp tim và nồng độ oxy dưới dạng văn bản và đồ họa.

### Kích hoạt động cơ rung và đèn LED khi cảm biến hoạt động:
- Khi người dùng đặt ngón tay lên cảm biến MAX30100 và bắt đầu đo nhịp tim, ESP32 sẽ kích hoạt module động cơ rung và đèn LED để báo hiệu rằng thiết bị đang hoạt động.
- Động cơ rung và đèn LED sẽ bật khi phát hiện nhịp tim và tự động tắt sau một khoảng thời gian nhất định (400ms cho động cơ rung và 700ms cho đèn LED).

### Cấu hình và khởi tạo:
- Thiết lập các định nghĩa và khởi tạo các thông số cần thiết cho cảm biến, màn hình OLED, module động cơ rung và đèn LED.
- Các chân điều khiển cho động cơ rung và đèn LED được cấu hình là đầu ra.
- Cảm biến MAX30100 được khởi tạo với dòng điện LED hồng ngoại cụ thể để tối ưu hóa cho việc đo lường.

### Kiểm tra và cập nhật dữ liệu:
- Dữ liệu từ cảm biến được cập nhật liên tục trong vòng lặp chính (loop) của chương trình.
- Dữ liệu được hiển thị lên màn hình OLED sau mỗi khoảng thời gian nhất định (1500ms).
- Động cơ rung và đèn LED sẽ tự động tắt sau khi hết thời gian đã định (400ms và 700ms).

# 6. Tác giả

| Sv thực hiện | MSSV | Github |
|--------------|------|---------------------|
|Vũ Minh Hiếu|20215579|[Here](https://github.com/hieuwed)|
|Phạm Tuấn Trung|20215653|[Here](https://github.com/Trunpy28?fbclid=IwZXh0bgNhZW0CMTAAAR2WfkVnNVR_Q5VjGzbPbTsWH3djQhdB4cVWvTIaEaKa5x53BmdxmuxgKNs_aem_ZmFrZWR1bW15MTZieXRlcw)|
|Trần Văn Hưng|20215594|[Here](https://github.com/hwngtv?fbclid=IwZXh0bgNhZW0CMTAAAR2Bc8nAh4pohZu4XdpxH-bwWH5ZFyt_NNVleD971OtStEm1-aNXhyN7ylo_aem_ZmFrZWR1bW15MTZieXRlcw)|
|Nguyễn Đình Tú|20215658|[Here](https://github.com/tunguyen02?fbclid=IwZXh0bgNhZW0CMTAAAR2ssuSG3LiDLH6rn-JjRcK93R_MMki-_RyO19tuN58T2qeNp1nSx7ZuDT8_aem_ZmFrZWR1bW15MTZieXRlcw)|



