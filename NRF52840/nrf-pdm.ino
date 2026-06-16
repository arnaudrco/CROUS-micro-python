/*
  This example reads audio data from the on-board PDM microphones, and prints
  out the samples to the Serial console. The Serial Plotter built into the
  Arduino IDE can be used to plot the audio data (Tools -> Serial Plotter)

  Please try with the Circuit Playground Bluefruit

  This example code is in the public domain.
*/

#include <PDM.h>

#define CLK 20
#define DOUT 22
#define WS 24

// buffer to read samples into, each sample is 16-bits
short sampleBuffer[256];

// number of samples read
volatile int samplesRead;

void setup() {
  Serial.begin(9600);
  while (!Serial) yield();

  // configure the data receive callback
  PDM.onReceive(onPDMdata);

   PDM.setPins(CLK, DOUT, WS);
   
  // optionally set the gain, defaults to 20
  // PDM.setGain(30);

  // initialize PDM with:
  // - one channel (mono mode)
  // - a 16 kHz sample rate
  if (!PDM.begin(1, 16000)) {
    Serial.println("Failed to start PDM!");
    while (1) yield();
  }
}

void loop() {
  // wait for samples to be read
  if (samplesRead) {
    // print samples to the serial monitor or plotter
    for (int i = 0; i < samplesRead; i++) {
      Serial.print(sampleBuffer[i]);
      Serial.print(" ");
    }
    // clear the read count
    samplesRead = 0;
    Serial.println("----");
  }
}

void onPDMdata() {
  // query the number of bytes available
  int bytesAvailable = PDM.available();

  // read into the sample buffer
  PDM.read(sampleBuffer, bytesAvailable);

  // 16-bit, 2 bytes per sample
  samplesRead = bytesAvailable / 2;
}
