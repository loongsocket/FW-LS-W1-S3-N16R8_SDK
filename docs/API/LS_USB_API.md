# LS USB API

Header: `components/ls_usb/include/ls_usb.h`

The USB component tracks the native ESP32-S3 USB Serial/JTAG service and exposes
a small recovery API.

## Main Types

`ls_usb_status_t`

- `initialized`
- `driver_owned`
- `connected`
- `init_failures`
- `recovery_attempts`
- `last_error`

## Functions

```c
esp_err_t ls_usb_init(void);
esp_err_t ls_usb_get_status(ls_usb_status_t *status);
esp_err_t ls_usb_recover(void);
```

## Notes

- The S3 module has no easy external access to EN/BOOT in the final product, so
  USB robustness is important.
- Keep USB commands explicit and safe. Future production commands should be
  gated by service mode or password.
