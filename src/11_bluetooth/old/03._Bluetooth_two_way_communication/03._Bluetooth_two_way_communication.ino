/******************************************************************************************
* FileName: 03._Bluetooth_two_way_communication
* Description : 블루투스를 이용하여 시리얼 통신하는 예제
* Author : 이인정
* Created Date : 2021.06.03
* Reference : 
* modified : 2021.06.03 : LIJ : 헤더 수정
******************************************************************************************/
#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

char names[] = "your_name";          // 자신의 이름을 적어주세요

void setup() {
  Serial.begin(115200);              // 통신속도 설정
  SerialBT.begin(names);             // 자신의 이름으로 된 블루투스 생성
}

void loop() {
  if (Serial.available()) {          // 블루투스로 시리얼 값 넘겨주기
    SerialBT.write(Serial.read());
  }
  if (SerialBT.available()) {        // 블루투스로 시리얼 값 넘겨 받고
    Serial.write(SerialBT.read());   // 시리얼 모니터에 출력
  }
  delay(20);                         // 0.02초 대기
}
//┌────────────────────────────────┐
//│                                                    │
//│     (주)한국공학기술연구원 http://et.ketri.re.kr       │
//│                                                    │
//└────────────────────────────────┘
