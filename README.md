# ESP32C3 ShowChangeableNumber

利用esp32c3最小开发板和0.96‘’OLED显示屏显示动态数字

## 前言

U8g2库是一个非常强大的文本显示库，本次程序的目的是利用该库显示一个动态数字（changeable number）。

该库的示例中有Show Chinese的代码，本代码也可以显示部分汉字。

我使用的是在Arduino的库管理器中直接下载的U8g2 by oliver（version：2.33.15）

## 开发板管理器地址

```
http://arduino.esp8266.com/stable/package_esp8266com_index.json
https://dl.espressif.com/dl/package_esp32_index.json
https://github.com/espressif/arduino-esp32/releases/download/2.0.5/package_esp32_index.json
```

**使用esp32——ESP32C3 Dev Module**

## 源代码(Source Code)

```c
#include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h>
#include <HardwareSerial.h>

// U8G2_SSD1306_128X64_NONAME_1_2ND_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);  // 软件IIC
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/U8X8_PIN_NONE, /* clock=*/9, /* data=*/10);

int t=0;

void setup(void) {
	// Serial.begin(115200);
  u8g2.begin(); 
  u8g2.enableUTF8Print();		// enable UTF8 support for the Arduino print() function
  u8g2.setFont(u8g2_font_unifont_t_chinese2);  // use chinese2 for all the glyphs of "你好世界"
  
}

void loop(void) {
  t++;
  u8g2.setFontDirection(0);
  u8g2.firstPage();
  do {
    u8g2.setCursor(1, 15);  // 设置显示坐标(x,y)
    u8g2.print("Number:");
    u8g2.setCursor(1, 30);
    u8g2.print("数字:");
    u8g2.setCursor(1, 45);
    u8g2.print(t);		// 显示动态自加数字

  } while ( u8g2.nextPage() );
}

```

