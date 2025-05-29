#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10   // Connect SDA to D10
#define RST_PIN 9   // Connect RST to D9

MFRC522 mfrc522(SS_PIN, RST_PIN); // Create MFRC522 instance

void setup() {
  Serial.begin(115200); // Start serial communication
  SPI.begin();          // Start SPI bus
  mfrc522.PCD_Init();   // Initialize RFID reader
  
  Serial.println("Scan your RFID card to read UID...");
}

void loop() {
  // Look for a new RFID card
  if (mfrc522.PICC_IsNewCardPresent()) {
    // If a card is found, read its UID
    if (mfrc522.PICC_ReadCardSerial()) {
      Serial.print("UID of the card: ");
      
      // Print the UID
      for (byte i = 0; i < mfrc522.uid.size; i++) {
        Serial.print(mfrc522.uid.uidByte[i], HEX);
        Serial.print(" "); // Print UID in HEX format
      }
      
      Serial.println(); // Newline after printing UID
      delay(1000); // Wait a second before reading again
    }
  }
}