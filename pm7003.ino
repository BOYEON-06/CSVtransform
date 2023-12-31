#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); // RX, TX로 먼지센서의 TX와 RX에 각각 연결됨

void setup() {
  // for debuging 
  Serial.begin(115200);  
  
  // Use software serial
  mySerial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  static int CheckFirst=0;
  static int pm_add[3][5]={0,};
  static int pm_old[3]={0,};
  int chksum=0,res=0;;
  unsigned char pms[32]={0,};
  
  
  if(mySerial.available()>=32){

    for(int j=0; j<32 ; j++){
      pms[j]=mySerial.read();
      if(j<30)
        chksum+=pms[j];
    }

    if(pms[30] != (unsigned char)(chksum>>8) 
        || pms[31]!= (unsigned char)(chksum) ){

      return res;
    }
    if(pms[0]!=0x42 || pms[1]!=0x4d )
      return res;
  // Serial.print("PM2.5: ");
  // Serial.print(pms[12]);
  Serial.print(pms[13]);
  Serial.print("\n");
  // Serial.print("PM10: ");
  // Serial.print(pms[14]);
  Serial.println(pms[15]);
  } 
}
