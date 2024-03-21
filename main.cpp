// Pin Definitions
const int buttonPin = 2; // Push button connected to digital pin 2
const int ledPin = 13;   // LED connected to digital pin 13

// Morse code mappings (assuming standard Morse code)
const char* morseCode[] = {
  ".-",   // A
  "-...", // B
  "-.-.", // C
  "-..",  // D
  ".",    // E
  "..-.", // F
  "--.",  // G
  "....", // H
  "..",   // I
  ".---", // J
  "-.-",  // K
  ".-..", // L
  "--",   // M
  "-.",   // N
  "---",  // O
  ".--.", // P
  "--.-", // Q
  ".-.",  // R
  "...",  // S
  "-",    // T
  "..-",  // U
  "...-", // V
  ".--",  // W
  "-..-", // X
  "-.--", // Y
  "--.."  // Z
};

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Read the state of the push button
  int buttonState = digitalRead(buttonPin);

  // If the button is pressed, encode and display Morse code
  if (buttonState == HIGH) {
    // Replace with your Morse code encoding logic
    String message = "HELLO"; // Example message
    encodeAndDisplayMorse(message);
    delay(1000); // Delay for readability
  }
}

void encodeAndDisplayMorse(String message) {
  for (int i = 0; i < message.length(); i++) {
    char character = toupper(message.charAt(i)); // Convert to uppercase
    if (character >= 'A' && character <= 'Z') {
      int index = character - 'A';
      const char* code = morseCode[index];
      
      for (int j = 0; code[j] != '\0'; j++) {
        if (code[j] == '.') {
          dot();
        } else if (code[j] == '-') {
          dash();
        }
        delay(100); // Dot duration, adjust as needed
      }
      delay(200); // Inter-character space, adjust as needed
    }
  }
}

void dot() {
  digitalWrite(ledPin, HIGH);
  delay(100); // Dot duration, adjust as needed
  digitalWrite(ledPin, LOW);
}

void dash() {
  digitalWrite(ledPin, HIGH);
  delay(300); // Dash duration, adjust as needed
  digitalWrite(ledPin, LOW);
}
