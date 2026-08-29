# LS Board Test API

Header: `components/ls_board_test/include/ls_board_test.h`

The board-test API is a helper layer for production checks, laboratory routing
tests and the Kickstarter monitor demo.

## PWM Sources

The helper starts two PWM sources:

| Signal | GPIO | Frequency | Duty |
| --- | ---: | ---: | ---: |
| PWM_CH1 | GPIO6 | 8 kHz | 38.00 % |
| PWM_CH2 | GPIO7 | 8 kHz | 76.00 % |

## Square-Wave Pins

The helper can output a 2 Hz square wave on user GPIOs. Reserved ADC SPI, native
USB and BOOT pins are excluded.

## Main Types

- `ls_board_test_adc_config_t`
- `ls_board_test_adc_channel_t`
- `ls_board_test_adc_report_t`
- `ls_board_test_pin_t`

## Functions

```c
const ls_board_test_adc_config_t *ls_board_test_default_adc_config(void);
const ls_board_test_pin_t *ls_board_test_square_wave_pins(uint8_t *count);
esp_err_t ls_board_test_start_pwm_sources(void);
esp_err_t ls_board_test_start_square_wave_outputs(void);
esp_err_t ls_board_test_set_square_wave_outputs(bool level);
esp_err_t ls_board_test_read_adc_report(const ls_board_test_adc_config_t *config,
                                        ls_board_test_adc_report_t *report);
void ls_board_test_log_adc_report(const char *label,
                                  const ls_board_test_adc_config_t *config,
                                  const ls_board_test_adc_report_t *report);
```

## PASS/NO PASS Meaning

- `PASS | ready`: no ADC input is connected, and no noise/saturation is detected.
- `PASS | one channel detected`: one ADC channel detects the PWM test signal.
- `NO PASS`: several channels are active/noisy/saturated or the ADC read failed.

This behavior is useful for demos because the board starts in a clean PASS state
even before a test wire is connected.
