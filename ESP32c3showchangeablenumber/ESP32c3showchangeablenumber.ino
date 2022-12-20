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
  u8g2.setFont(u8g2_font_unifont_t_chinese2);  // chinese2中的汉字都可以显示
  
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
