// SDS011 dust sensor example
// -----------------------------
//
// By R. Zschiegner (rz@madavi.de).
// April 2016

#include <SDS011.h>

int p10, p25;
int error;

SDS011 my_sds;

void setup() {
  //while(!Serial);
  Serial.begin(9600);
  Serial.println("SDS Test");
	my_sds.begin(&Serial1);
  my_sds.wakeup();
  delay(30000);
}

void loop() {
	error = my_sds.readInt(&p25, &p10);
	if (!error) {
		Serial.println("P2.5: " + String(p25));
		Serial.println("P10:  " + String(p10));
	}
  else {
    Serial.print("Error: ");
    Serial.println(error);
  }
	delay(10000);
}
