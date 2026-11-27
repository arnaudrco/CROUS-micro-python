// #define I2S_SD 32


#include "BluetoothA2DPSource.h"
#include "driver/i2s.h"

BluetoothA2DPSource a2dp_source;

// Config I2S pour INMP441
#define I2S_PORT I2S_NUM_0
#define I2S_SD 32
#define I2S_WS 25
#define I2S_SCK 26

void setupI2S() {
  i2s_config_t i2s_config = {
    .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_RX),
    .sample_rate = 44100,
    .bits_per_sample = I2S_BITS_PER_SAMPLE_32BIT,
    .channel_format = I2S_CHANNEL_FMT_ONLY_LEFT,
    .communication_format = I2S_COMM_FORMAT_STAND_I2S,
    .intr_alloc_flags = ESP_INTR_FLAG_LEVEL1,
    .dma_buf_count = 8,
    .dma_buf_len = 64,
    .use_apll = false,
    .tx_desc_auto_clear = true,
    .fixed_mclk = 0
  };
  i2s_pin_config_t pin_config = {
    .bck_io_num = I2S_SCK,
    .ws_io_num = I2S_WS,
    .data_out_num = I2S_PIN_NO_CHANGE,
    .data_in_num = I2S_SD
  };
  i2s_driver_install(I2S_PORT, &i2s_config, 0, NULL);
  i2s_set_pin(I2S_PORT, &pin_config);
  i2s_set_clk(I2S_PORT, 44100, I2S_BITS_PER_SAMPLE_32BIT, I2S_CHANNEL_MONO);
}

// C'est cette fonction qui est appelée par le BT pour avoir du son
int32_t get_data(Frame *data, int32_t len) {
  size_t bytes_read = 0;
  // On lit l'I2S en 32 bits
  i2s_read(I2S_PORT, data, len * 4, &bytes_read, portMAX_DELAY);
  
  // INMP441 sort en 24 bits dans du 32 bits, il faut décaler
  // et convertir en stéréo 16 bits pour A2DP
  for (int i = len-1; i >= 0; i--) {
    int32_t sample = data[i].channel1 >> 8; // on passe en 24->16 bits
    // On duplique en stéréo
    data[i].channel1 = sample;
    data[i].channel2 = sample;
  }
  return len;
}

void setup() {
  Serial.begin(115200);
  setupI2S();
  a2dp_source.set_auto_reconnect(true);
  a2dp_source.start("JBL Go 3", get_data);
  Serial.println("En attente de connexion BT...");
}

void loop() {
}
