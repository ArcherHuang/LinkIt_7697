# Welcome to LinkIt 7697 

## Contents

- [Overview](#overview)
- [檔案說明](#file-description)
- [開發板與感測器](#board-and-sensor)
- [Pinout Diagram](#pinout-diagram)
- [IDE](#integrated-development-environment)
- [CP2102N USB-to-UART 驅動程式](#cp2102n-usb-to-uart)
- [Arduino IDE 設定](#arduino-ide)
- [BlocklyDuino Editor](#blocklyduino-editor)
- [Library](#library)
- [JSON Tools](#json-tools)
- [Online UUID Generator](#online-uuid-generator)
- [Fritzing Software Download](#fritzing)
- [Tools Software Download](#tools)
- [Service](#service)
- [Reference](#reference)
- [Blog](#blog)
- [License](#license)

## Overview       
[Back](#contents)

* 通訊協定與網路服務提供商                 
                            
| 通訊協定 | 網路服務提供商 |
|---|---|
| HTTP | ThingSpeak、MediaTek Cloud Sandbox (MCS)、Google Firebase |
| MQTT | ThingSpeak、LASS、MediaTek Cloud Sandbox (MCS)、AWS IoT、IBM Bluemix IoT Platform |
| WebSocket | WoT.City | 
    
## File Description
[Back](#contents)     

| 編號 | 資料夾 |  檔案名稱 | 說明  |
|---|---|---|---|
|1| /Arduino  |  / |   |
|2|   |   |   |
|3|   |   |   |

## Board and Sensor
[Back](#contents)

* [LinkIt 7697](https://www.seeedstudio.com/LinkIt-7697-p-2818.html)
* [Grove Breakout for LinkIt 7697](https://www.seeedstudio.com/Grove-Breakout-for-LinkIt-7697-p-2835.html)
* [Grove - Temperature & Humidity Sensor Pro](https://www.seeedstudio.com/Grove-Temperature%26Humidity-Sensor-Pro-p-838.html)
* [Grove - OLED Display 0.96"](https://www.seeedstudio.com/Grove-OLED-Display-0.96%22-p-781.html)
* [Grove - Ultrasonic Ranger](https://www.seeedstudio.com/Grove-Ultrasonic-Ranger-p-960.html)
* [Grove - Relay](https://www.seeedstudio.com/Grove-Relay-p-769.html)
* [Grove - Light Sensor](https://www.seeedstudio.com/Grove-Light-Sensor-v1.2-p-2727.html)
* [Grove - LED Bar](https://www.seeedstudio.com/Grove-LED-Bar-v2.0-p-2474.html)
* [Grove – Servo](https://www.seeedstudio.com/Grove-Servo-p-1241.html)

## Pinout Diagram
[Back](#contents)

![Imgur](http://i.imgur.com/hhcMv9w.png)

## Integrated Development Environment
[Back](#contents)

 * Arduino
   *  [Arduino IDE v1.8.2](https://www.arduino.cc/en/Main/Software)
   
## CP2102N USB to UART 
[Back](#contents)

 * http://www.silabs.com/products/development-tools/software/usb-to-uart-bridge-vcp-drivers
 
## Arduino IDE
[Back](#contents)

 * 檔案(File) ➙ 偏好設定(Preferences) ➙ Additional Boards Manager URLs
   * http://download.labs.mediatek.com/package_mtk_linkit_7697_index.json 
   
## BlocklyDuino Editor
[Back](#contents)

 * [Online BlocklyDuino Editor](https://mediatek-labs.github.io/BlocklyDuino-for-LinkIt/blockly/apps/blocklyduino/index.html)   
 * [Offline BlocklyDuino Editor](https://github.com/MediaTek-Labs/BlocklyDuino-for-LinkIt)

## Library
[Back](#contents)

* LinkIt 7697 peripheral drivers for arduino
   * https://github.com/MediaTek-Labs/linkit-7697-peripheral-drivers-for-arduino
   
*  Starter Kit 內的 Grove 周邊的驅動程式
   * https://github.com/MediaTek-Labs/linkit-7697-peripheral-drivers-for-arduino

* DHT
   *  到 [Seeed Arduino Library Github](https://github.com/Seeed-Studio/Grove_Temperature_And_Humidity_Sensor) 頁面中的右上角下載整個 ZIP 檔
   *  在 Arduino Sketch 中點選```草稿碼``` ➙ ```匯入程式庫``` ➙ ```加入 .ZIP 程式庫```  ➙ 選擇上一步驟所下載的 ZIP 檔

* Seeed OLED Display 128*64 library

   *  到 [Seeed OLED library Github](https://github.com/Seeed-Studio/OLED_Display_128X64) 頁面中的右上角下載整個 ZIP 檔
   *  在 Arduino Sketch 中點選```草稿碼``` ➙ ```匯入程式庫``` ➙ ```加入 .ZIP 程式庫```  ➙ 選擇上一步驟所下載的 ZIP 檔
      
## Service
[Back](#contents)

* [MCS](https://mcs.mediatek.com/)
* [MCS Lite](https://github.com/MCS-Lite/mcs-lite-app/releases)

## JSON Tools
[Back](#contents)

 * [JSON Lint](http://jsonlint.com/)
 * [JSON Editor Online](http://www.jsoneditoronline.org/)

## Online UUID Generator
[Back](#contents)

* [UUID Generator](https://www.uuidgenerator.net/)

## Fritzing
[Back](#contents)

* [Software Download](http://fritzing.org/home/)

## Tools
[Back](#contents)

*  登入
   * Windows 端
      * [Putty](https://www.chiark.greenend.org.uk/~sgtatham/putty/latest.html)
*  傳送檔案 
   * Windows 端
      * [WinSCP](https://winscp.net/eng/download.php)

## Reference
[Back](#contents)

* [LinkIt 7697 Developer’s Guide](https://labs.mediatek.com/zh-tw/chipset/MT7697)
* [Seeed Wiki](http://wiki.seeed.cc/)

## Blog
[Back](#contents)

* [Archer @ 部落格](https://github.com/ArcherHuang/MyBlog/blob/master/README.md)

## License
[Back](#contents)

The MIT License (MIT)

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

