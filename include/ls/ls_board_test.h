#pragma once

#include <stdbool.h>
#include <stdint.h>

#include "esp_err.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    uint16_t low_threshold_counts;
    uint16_t active_threshold_counts;
    uint16_t saturated_threshold_counts;
    uint16_t pwm_span_threshold_counts;
    uint16_t burst_samples;
} ls_board_test_adc_config_t;

typedef struct {
    uint8_t channel;
    uint16_t min_counts;
    uint16_t max_counts;
    uint16_t avg_counts;
    uint16_t span_counts;
    uint16_t avg_millivolts;
    bool low;
    bool noise;
    bool active;
    bool saturated;
} ls_board_test_adc_channel_t;

typedef struct {
    bool pass;
    uint8_t active_count;
    uint8_t noise_count;
    uint8_t saturated_count;
    int active_channel;
    ls_board_test_adc_channel_t channels[8];
} ls_board_test_adc_report_t;

typedef struct {
    int gpio;
    const char *name;
} ls_board_test_pin_t;

const ls_board_test_adc_config_t *ls_board_test_default_adc_config(void);
const ls_board_test_pin_t *ls_board_test_square_wave_pins(uint8_t *count);
esp_err_t ls_board_test_start_pwm_sources(void);
esp_err_t ls_board_test_start_square_wave_outputs(void);
esp_err_t ls_board_test_set_square_wave_outputs(bool level);
esp_err_t ls_board_test_read_adc_report(const ls_board_test_adc_config_t *config,
                                        ls_board_test_adc_report_t *report);
void ls_board_test_log_adc_report(const char *label, const ls_board_test_adc_config_t *config,
                                  const ls_board_test_adc_report_t *report);

#ifdef __cplusplus
}
#endif
