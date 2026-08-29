# LS BMS API

Header: `components/ls_bms/include/ls_bms.h`

The BMS component gives basic board-management information. It is the first API
to initialize because other services can report their status through it later.

## Main Types

`ls_bms_status_t`

- `chip_model`
- `mac`
- `reset_reason`
- `free_heap_bytes`
- `minimum_free_heap_bytes`
- `psram_bytes`
- `boot_failure_count`
- `nvs_ready`
- `safe_mode_recommended`
- `usb_ready`
- `usb_connected`
- `usb_recovery_available`

## Functions

```c
esp_err_t ls_bms_init(void);
esp_err_t ls_bms_get_status(ls_bms_status_t *status);
esp_err_t ls_bms_mark_healthy(void);
esp_err_t ls_bms_clear_safe_mode(void);
const char *ls_bms_reset_reason_name(esp_reset_reason_t reason);
```

## Notes

- `ls_bms_mark_healthy()` should be called after the application has completed a
  stable startup.
- `safe_mode_recommended` is intended for future protection/recovery logic.
- Current demo logs chip, MAC, reset reason, heap and PSRAM.
