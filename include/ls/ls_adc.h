#pragma once

#include <stdbool.h>
#include <stdint.h>

#include "esp_err.h"

#ifdef __cplusplus
extern "C" {
#endif

enum {
    LS_ADC_CHANNEL_COUNT = 8,
    LS_ADC_MAX_MOVING_AVERAGE_SAMPLES = 16,
    LS_ADC_MAX_BURST_SAMPLES = 4096,
    LS_ADC_FLAG_RANGE_LOW = 1U << 0,
    LS_ADC_FLAG_RANGE_HIGH = 1U << 1,
};

typedef enum {
    LS_ADC_FILTER_NONE = 0,
    LS_ADC_FILTER_EMA,
    LS_ADC_FILTER_MOVING_AVERAGE,
    LS_ADC_FILTER_MEDIAN_3,
} ls_adc_filter_t;

typedef struct {
    ls_adc_filter_t type;
    uint8_t ema_alpha_percent;
    uint8_t moving_average_samples;
} ls_adc_filter_config_t;

typedef struct {
    uint16_t raw_low_counts;
    uint16_t raw_high_counts;
    int32_t engineering_low_milli;
    int32_t engineering_high_milli;
} ls_adc_calibration_t;

typedef struct {
    bool enabled;
    uint16_t minimum_counts;
    uint16_t maximum_counts;
} ls_adc_range_t;

typedef struct {
    uint8_t channel;
    uint16_t raw_counts;
    uint16_t filtered_counts;
    uint16_t millivolts;
    int32_t engineering_milli;
    uint8_t flags;
    ls_adc_filter_t filter;
} ls_adc_sample_t;

typedef struct {
    bool initialized;
    uint16_t reference_millivolts;
    uint32_t spi_clock_hz;
    uint32_t total_reads;
    uint32_t failed_reads;
    esp_err_t last_error;
    uint8_t last_channel;
} ls_adc_status_t;

typedef struct {
    uint8_t channel;
    uint16_t samples;
    uint16_t min_counts;
    uint16_t max_counts;
    uint16_t avg_counts;
    uint16_t span_counts;
    uint16_t avg_millivolts;
} ls_adc_burst_t;

typedef struct {
    uint8_t channels;
    uint8_t resolution_bits;
    uint16_t max_counts;
    uint16_t reference_millivolts;
    uint32_t spi_clock_hz;
    int spi_host;
    int pin_cs;
    int pin_mosi;
    int pin_clock;
    int pin_miso;
} ls_adc_hardware_info_t;

esp_err_t ls_adc_init(void);
esp_err_t ls_adc_get_hardware_info(ls_adc_hardware_info_t *info);
esp_err_t ls_adc_get_status(ls_adc_status_t *status);
esp_err_t ls_adc_reset_diagnostics(void);
uint16_t ls_adc_raw_to_millivolts(uint16_t raw_counts);
esp_err_t ls_adc_read_raw(uint8_t channel, uint16_t *raw_counts);
esp_err_t ls_adc_sample(uint8_t channel, ls_adc_sample_t *sample);
esp_err_t ls_adc_read_raw_all(uint16_t raw_counts[LS_ADC_CHANNEL_COUNT]);
esp_err_t ls_adc_sample_all(ls_adc_sample_t samples[LS_ADC_CHANNEL_COUNT]);
esp_err_t ls_adc_read_burst(uint8_t channel, uint16_t sample_count, ls_adc_burst_t *burst);
esp_err_t ls_adc_read_burst_all(uint16_t sample_count, ls_adc_burst_t bursts[LS_ADC_CHANNEL_COUNT]);
esp_err_t ls_adc_set_filter(uint8_t channel, const ls_adc_filter_config_t *config);
esp_err_t ls_adc_get_filter(uint8_t channel, ls_adc_filter_config_t *config);
esp_err_t ls_adc_reset_filter(uint8_t channel);
esp_err_t ls_adc_set_calibration(uint8_t channel, const ls_adc_calibration_t *calibration);
esp_err_t ls_adc_get_calibration(uint8_t channel, ls_adc_calibration_t *calibration);
esp_err_t ls_adc_set_range(uint8_t channel, const ls_adc_range_t *range);
esp_err_t ls_adc_get_range(uint8_t channel, ls_adc_range_t *range);

#ifdef __cplusplus
}
#endif
