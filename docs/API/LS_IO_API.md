# LS I/O API

Header: `components/ls_io/include/ls_io.h`

The I/O API controls GPIO and PWM while protecting board-reserved pins.

## Reserved Pins

The current board profile reserves:

| GPIO | Reason |
| ---: | --- |
| 0 | boot strap |
| 3 | MCP3208 chip select |
| 11 | MCP3208 MOSI |
| 12 | MCP3208 clock |
| 13 | MCP3208 MISO |
| 19 | USB D- |
| 20 | USB D+ |

## Main Types

- `ls_io_mode_t`
- `ls_io_pull_t`
- `ls_io_config_t`
- `ls_io_status_t`
- `ls_io_reserved_pin_t`
- `ls_io_pwm_status_t`

## Functions

```c
esp_err_t ls_io_init(void);
esp_err_t ls_io_get_status(ls_io_status_t *status);

esp_err_t ls_io_get_reservation(int pin, const char **reservation);
const ls_io_reserved_pin_t *ls_io_reserved_pins(uint8_t *count);

esp_err_t ls_io_configure(const ls_io_config_t *config);
esp_err_t ls_io_write(int pin, bool level);
esp_err_t ls_io_read(int pin, bool *level);

esp_err_t ls_io_pwm_start(int pin, uint32_t frequency_hz, uint16_t duty);
esp_err_t ls_io_pwm_set_duty(int pin, uint16_t duty);
esp_err_t ls_io_pwm_stop(int pin);
esp_err_t ls_io_pwm_get_status(int pin, ls_io_pwm_status_t *status);
uint8_t ls_io_pwm_get_active(ls_io_pwm_status_t *status, uint8_t max_entries);
```

## PWM Limits

- PWM channels: `LS_IO_MAX_PWM_CHANNELS`
- Frequency: `10..20000 Hz`
- Duty: `0..10000`

## Notes

- PWM claims a pin until `ls_io_pwm_stop()` is called.
- `ls_io_get_reservation()` returns `ESP_ERR_NOT_SUPPORTED` for protected pins.
