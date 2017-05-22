# Programs running on LinkIt 7697 that connects to IoT Platform
     
## 【 Overview 】       
                                                                  
* 物聯網架構與應用                 
                                                                                                                                         
                                  
* 通訊協定與網路服務提供商                 
                            
| 通訊協定 | 網路服務提供商 |
|---|---|
| HTTP | ThingSpeak、MediaTek Cloud Sandbox (MCS)、Google Firebase |
| MQTT | ThingSpeak、LASS、MediaTek Cloud Sandbox (MCS)、AWS IoT、IBM Bluemix IoT Platform |
| WebSocket | WoT.City |
                
* 實作架構  
    
## 【 檔案說明 】
      
| 編號 | 資料夾 |  檔案名稱 | 說明  |
|---|---|---|---|
|1| /Arduino  |  / |   |
|2|   |   |   |
|3|   |   |   |

## 【 Board and Sensor 】

* [LinkIt 7697](https://www.seeedstudio.com/LinkIt-7697-p-2818.html)
* [Grove Breakout for LinkIt 7697](https://www.seeedstudio.com/Grove-Breakout-for-LinkIt-7697-p-2835.html)
* [Grove - Temperature & Humidity Sensor Pro](https://www.seeedstudio.com/Grove-Temperature%26Humidity-Sensor-Pro-p-838.html)
* [Grove - OLED Display 1.12"](https://www.seeedstudio.com/Grove-OLED-Display-1.12%22-p-824.html)

## 【 Pin-out Diagram 】
![Imgur](http://i.imgur.com/hhcMv9w.png)

## 【 Integrated Development Environment - IDE 】
 
 * Arduino
   *  [Arduino IDE v1.8.2](https://www.arduino.cc/en/Main/Software)
 * Python
   * [Sublime Text](https://www.sublimetext.com/)
   * [Visual Studio Code](https://code.visualstudio.com/b?utm_expid=101350005-27.GqBWbOBuSRqlazQC_nNSRg.1&utm_referrer=https%3A%2F%2Fwww.google.com.tw%2F)
   * [Jupyter](http://jupyter.org/)
     * Command: ipython notebook

## 【 Firmware 】

## 【 Library 】

* DHT
   *  到 [Seeed Arduino Library Github](https://github.com/Seeed-Studio/Grove_Temperature_And_Humidity_Sensor) 頁面中的右上角下載整個 ZIP 檔
   *  在 Arduino Sketch 中點選```草稿碼``` ➙ ```匯入程式庫``` ➙ ```管理程式庫``` ➙ 右上角搜尋欄位輸入 ```DHT```
* Seeed OLED Display 128*64 library
   *  到 [Seeed OLED library Github](https://github.com/Seeed-Studio/OLED_Display_128X64) 頁面中的右上角下載整個 ZIP 檔
   *  在 Arduino Sketch 中點選```草稿碼``` ➙ ```匯入程式庫``` ➙ ```加入 .ZIP 程式庫```  ➙ 選擇上一步驟所下載的 ZIP 檔
      
## 【 Service 】

* [WoT.City](https://wotcity.com/)
* [Amazon Web Services Cloud](https://aws.amazon.com/tw/)
* [Google Firebase](https://firebase.google.com/)
* [IBM Bluemix](https://console.ng.bluemix.net/)
* [MediaTek Cloud Sandbox](https://mcs.mediatek.com)
* [ThingSpeak](https://thingspeak.com/)
* [ThinkSpeak Data Visualization](nrl.iis.sinica.edu.tw/LASS/PM25.php?site=III&city=台北市&district=信義區&channel=152239&apikey=9ND1FVDPKLQGPDRI)

## 【 Firmware 】

## 【 Tools 】

## 【 JSON Tools 】
 * [JSON Lint](http://jsonlint.com/)
 * [JSON Editor Online](http://www.jsoneditoronline.org/)

## 【 Troubleshooting 】


## 【 Reference 】

* [LinkIt 7697 Developer’s Guide](https://labs.mediatek.com/zh-tw/chipset/MT7697)

## 【 Blog 】
* [Archer @ 部落格](https://github.com/ArcherHuang/MyBlog/blob/master/README.md)

## 【 License 】

The MIT License (MIT)

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

