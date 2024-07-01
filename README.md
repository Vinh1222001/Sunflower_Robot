# SUNFLOWER ROBOT

## Overview
Robot này sử dụng webcam của PC để tracking khuôn mặt người và gửi vị trí khuôn mặt đến Arduino thông qua cổng Serial. Từ thông tin đó, Arduino sẽ điều khiển các servo di chuyển để hướng mặt hoa hướng dương về phía người.
## Equipment
Phần cứng:
- Arduino UNO
- 2 Servo SG90 gốc quay 180 độ
Phần mềm:
- Visual Studio
- Thư viện OpenCV `4.10.0` cho Python
- Thư viện pyserial `3.5` cho Python
- Thư viện Servo by `Michael Margolis 1.2.1` trên PlatformIO 
## Result