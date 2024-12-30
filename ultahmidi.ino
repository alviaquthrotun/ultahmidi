#include <MIDI.h>

// Define pin for the speaker
const int speakerPin = 8;

// Define the note frequencies (in Hz)
const int NOTE_C4 = 262;
const int NOTE_D4 = 294;
const int NOTE_E4 = 330;
const int NOTE_F4 = 349;
const int NOTE_G4 = 392;
const int NOTE_A4 = 440;
const int NOTE_B4 = 494;
const int NOTE_C5 = 523;

// Define the melody for "Happy Birthday"
const int melody[] = {
  NOTE_G4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_C5, NOTE_B4,
  NOTE_G4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_D5, NOTE_C5,
  NOTE_G4, NOTE_G4, NOTE_G5, NOTE_E5, NOTE_C5, NOTE_B4, NOTE_A4,
  NOTE_F5, NOTE_F5, NOTE_E5, NOTE_C5, NOTE_D5, NOTE_C5
};

// Define the note durations (4 = quarter note, 8 = eighth note, etc.)
const int noteDurations[] = {
  4, 4, 4, 4, 4, 2,
  4, 4, 4, 4, 4, 2,
  4, 4, 4, 4, 4, 4, 2,
  4, 4, 4, 4, 4, 2
};

void setup() {
  // Initialize the speaker pin as an output
  pinMode(speakerPin, OUTPUT);
}

void loop() {
  // Iterate over the notes of the melody
  for (int thisNote = 0; thisNote < sizeof(melody) / sizeof(melody[0]); thisNote++) {
    // Calculate the note duration in milliseconds
    int noteDuration = 1000 / noteDurations[thisNote];
    // Play the note on the speaker
    tone(speakerPin, melody[thisNote], noteDuration);
    // Pause for the note duration plus 30% to distinguish between notes
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // Stop the tone on the speaker
    noTone(speakerPin);
  }
  // Add a delay before repeating the melody
  delay(2000);
}