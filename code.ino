// i added comments to the whole ting (^B

// include the dht sensor lib
#include <DHT.h>

// define the digital pin that its connected to
#define DHTPIN 2

// define the type of DHT sensor being used - in this case its dht11
#define DHTTYPE DHT11

// set the baudrate
#define BAUD_RATE 9600

// create an instance of the sensor
DHT dht(DHTPIN, DHTTYPE);

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize serial communication at the defined baud rate
  Serial.begin(BAUD_RATE);

  // initialize the DHT sensor
  dht.begin();
}

// loop function runs over and over again forever which is why its there
void loop() {
  // read humidity from the sensor
  float humidity = dht.readHumidity();

  // read temp as Celsius from the DHT sensor
  float temperature = dht.readTemperature();

  // check that if any reads failed and print an error message to the serial port
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return; // exit the loop to avoid printing invalid data
  }

  // print the humidity to the serial port
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print("%  ");

  // print the temperature to the serial port
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println("C");

  // wait 2 seconds before reading the sensor again
  delay(2000);
}
