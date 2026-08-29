#pragma once

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "esp_err.h"
#include "esp_system.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    char chip_model[24];
    uint8_t mac[6];
    esp_reset_reason_t reset_reason;
    uint32_t free_heap_bytes;
    uint32_t minimum_free_heap_bytes;
    uint32_t psram_bytes;
    uint8_t boot_failure_count;
    bool nvs_ready;
    bool safe_mode_recommended;
    bool usb_ready;
    bool usb_connected;
    bool usb_recovery_available;
} ls_bms_status_t;

esp_err_t ls_bms_init(void);
esp_err_t ls_bms_get_status(ls_bms_status_t *status);
esp_err_t ls_bms_mark_healthy(void);
esp_err_t ls_bms_clear_safe_mode(void);
const char *ls_bms_reset_reason_name(esp_reset_reason_t reason);

#ifdef __cplusplus
}
#endif
