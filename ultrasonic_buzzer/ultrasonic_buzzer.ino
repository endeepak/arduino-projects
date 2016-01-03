// From http://www.instructables.com/id/Hack-an-HC-SR04-to-a-3-pin-sensor/?ALLSTEPS
// From https://bitbucket.org/teckel12/arduino-new-ping/wiki/Home#!download-install
// ---------------------------------------------------------------------------
// NewPing library sketch that interfaces with all but the SRF06 sensor using
// only one Arduino pin. You can also interface with the SRF06 using one pin
// if you install a 0.1uf capacitor on the trigger and echo pins of the sensor
// then tie the trigger pin to the Arduino pin (doesn't work with Teensy).
// ---------------------------------------------------------------------------

#include <NewPing.h>

#define PING_PIN  12  // Arduino pin tied to both trigger and echo pins on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
#define BUZZER_PIN 8
#define LED_PIN 13
#define NOTE_A6  1760

NewPing sonar(PING_PIN, PING_PIN, MAX_DISTANCE); // NewPing setup of pin and maximum distance.

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600); // Open serial monitor at 115200 baud to see ping results.
}

void loop() {
  delay(300);                      // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  unsigned int uS = sonar.ping(); // Send ping, get ping time in microseconds (uS).
  int distanceInCms = uS / US_ROUNDTRIP_CM;
  Serial.print("Ping: ");
  Serial.print(distanceInCms); // Convert ping time to distance and print result (0 = outside set distance range, no ping echo)
  Serial.println("cm");

  if(distanceInCms != NO_ECHO && distanceInCms < 20) {
      digitalWrite(BUZZER_PIN, HIGH);
      digitalWrite(LED_PIN, HIGH);
  } else  {
       digitalWrite(BUZZER_PIN, LOW); 
       digitalWrite(LED_PIN, LOW); 
  }
}
