# LS MCP3208 API

Header: `components/ls_mcp3208/include/ls_mcp3208.h`

This is the preferred public name for the external ADC API. Older `ls_adc.h`
symbols remain available for compatibility.

## Hardware Profile

- ADC: MCP3208
- Channels: 8
- Resolution: 12 bit
- Reference: 2500 mV
- SPI host: SPI2
- CS: GPIO3
- MOSI: GPIO11
- CLK: GPIO12
- MISO: GPIO13

## Main Types

The `ls_mcp3208_*` types are aliases of the compatibility `ls_adc_*` types:

- `ls_mcp3208_filter_t`
- `ls_mcp3208_filter_config_t`
- `ls_mcp3208_calibration_t`
- `ls_mcp3208_range_t`
- `ls_mcp3208_sample_t`
- `ls_mcp3208_status_t`
- `ls_mcp3208_burst_t`
- `ls_mcp3208_hardware_info_t`

## Main Functions

```c
ls_mcp3208_init();
ls_mcp3208_get_hardware_info(info);
ls_mcp3208_get_status(status);
ls_mcp3208_reset_diagnostics();

ls_mcp3208_read_raw(channel, raw);
ls_mcp3208_sample(channel, sample);
ls_mcp3208_read_raw_all(raw);
ls_mcp3208_sample_all(samples);

ls_mcp3208_read_burst(channel, sample_count, burst);
ls_mcp3208_read_burst_all(sample_count, bursts);

ls_mcp3208_set_filter(channel, config);
ls_mcp3208_get_filter(channel, config);
ls_mcp3208_reset_filter(channel);

ls_mcp3208_set_calibration(channel, calibration);
ls_mcp3208_get_calibration(channel, calibration);
ls_mcp3208_set_range(channel, range);
ls_mcp3208_get_range(channel, range);
```

## Limits

- Channels: `0..7`
- Burst samples: max `LS_MCP3208_MAX_BURST_SAMPLES`
- Raw counts: `0..4095`

## Notes

- `ls_mcp3208_read_burst()` is used by the board-test component, so production
  validation and application code share the same acquisition path.
- Direct PWM-to-ADC wiring validates routing, not precision calibration.
