#pragma once

#include <stdbool.h>
#include <stdint.h>

#include "esp_err.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    bool initialized;
    bool driver_owned;
    bool connected;
    uint32_t init_failures;
    uint32_t recovery_attempts;
    esp_err_t last_error;
} ls_usb_status_t;

esp_err_t ls_usb_init(void);
esp_err_t ls_usb_get_status(ls_usb_status_t *status);
esp_err_t ls_usb_recover(void);

#ifdef __cplusplus
}
#endif
