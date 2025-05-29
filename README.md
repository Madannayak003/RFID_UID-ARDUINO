# RFID_UID-ARDUINO
To know your RFID Card UID  by this code 

# RFID UID Reader using Arduino and MFRC522

This project reads the **UID** of an RFID card using an **MFRC522** reader and displays it on the **Serial Monitor**. It uses **SPI** communication and is compatible with **Arduino Uno, Nano**, or any board that supports SPI.

## 🛠️ Components Required

Component                   | Quantity |
|---------------------------|----------|
| Arduino Uno/Nano          | 1        |
| MFRC522 RFID Reader       | 1        |
| RFID Tag/Card             | 1+       |
| Jumper Wires              | As needed |
| Breadboard (optional)     | 1        |

## 🔌 Circuit Connections

| MFRC522 Pin | Arduino Pin |
|-------------|-------------|
| SDA (SS)    | D10         |
| SCK         | D13         |
| MOSI        | D11         |
| MISO        | D12         |
| RST         | D9          |
| VCC         | 3.3V        |
| GND         | GND         |

> ⚠️ **Important**: Power the MFRC522 with **3.3V**, not 5V. Using 5V may damage the module.

## 📟 Code Overview

This sketch initializes the RFID reader and continuously checks for RFID cards. When a card is detected, its UID is printed on the serial monitor in HEX format.

### ✅ Arduino Code

```cpp
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
        Serial.print(" ");
      }
      
      Serial.println(); // Newline after printing UID
      delay(1000); // Wait a second before reading again
    }
  }
}
```

Serial Output
When you open the Serial Monitor at 115200 baud, and scan an RFID card, you’ll see:

Scan your RFID card to read UID...
UID of the card: E3 88 39 DA 

>> Libraries Used
MFRC522 by Miguel Balboa
🔗 https://github.com/miguelbalboa/rfid

SPI (built-in Arduino library)
>> Install MFRC522 via Library Manager:
Arduino IDE → Sketch → Include Library → Manage Libraries → Search MFRC522 → Install

License
This project is licensed under the MIT License - see the LICENSE file for details.

Author
Developed by [MADAN R]

