#pragma once

#include <stdbool.h>
#include <stdint.h>

#include "esp_err.h"

#ifdef __cplusplus
extern "C" {
#endif

enum {
    LS_IO_MAX_PWM_CHANNELS = 4,
    LS_IO_PWM_MIN_FREQUENCY_HZ = 10,
    LS_IO_PWM_MAX_FREQUENCY_HZ = 20000,
    LS_IO_PWM_DUTY_MAX = 10000,
};

typedef enum {
    LS_IO_MODE_DISABLED = 0,
    LS_IO_MODE_INPUT,
    LS_IO_MODE_OUTPUT,
} ls_io_mode_t;

typedef enum {
    LS_IO_PULL_NONE = 0,
    LS_IO_PULL_UP,
    LS_IO_PULL_DOWN,
} ls_io_pull_t;

typedef struct {
    int pin;
    ls_io_mode_t mode;
    ls_io_pull_t pull;
    bool initial_level;
} ls_io_config_t;

typedef struct {
    bool initialized;
    uint8_t pwm_channels_active;
} ls_io_status_t;

typedef struct {
    int pin;
    const char *reservation;
} ls_io_reserved_pin_t;

typedef struct {
    bool active;
    int pin;
    uint8_t channel;
    uint8_t timer;
    uint32_t frequency_hz;
    uint16_t duty;
} ls_io_pwm_status_t;

esp_err_t ls_io_init(void);
esp_err_t ls_io_get_status(ls_io_status_t *status);

/* Returns ESP_ERR_NOT_SUPPORTED for pins reserved by this board profile. */
esp_err_t ls_io_get_reservation(int pin, const char **reservation);
const ls_io_reserved_pin_t *ls_io_reserved_pins(uint8_t *count);

esp_err_t ls_io_configure(const ls_io_config_t *config);
esp_err_t ls_io_write(int pin, bool level);
esp_err_t ls_io_read(int pin, bool *level);

/* Duty is expressed in 0..10000 basis points. PWM claims the pin until stopped. */
esp_err_t ls_io_pwm_start(int pin, uint32_t frequency_hz, uint16_t duty);
esp_err_t ls_io_pwm_set_duty(int pin, uint16_t duty);
esp_err_t ls_io_pwm_stop(int pin);
esp_err_t ls_io_pwm_get_status(int pin, ls_io_pwm_status_t *status);
uint8_t ls_io_pwm_get_active(ls_io_pwm_status_t *status, uint8_t max_entries);

#ifdef __cplusplus
}
#endif
