# LS API Status

Status date: 2026-08-29

## Implemented

| Area | Status |
| --- | --- |
| BMS identity/status | Implemented |
| USB Serial/JTAG status | Implemented |
| USB recovery hook | Implemented, basic |
| NVS storage wrappers | Implemented |
| Write-on-change storage | Implemented |
| MCP3208 single read | Implemented |
| MCP3208 all-channel read | Implemented |
| MCP3208 burst read | Implemented |
| MCP3208 filter/calibration/range hooks | Implemented |
| MCP3208 hardware info | Implemented |
| MCP3208 diagnostics | Implemented |
| GPIO configure/read/write | Implemented |
| Reserved-pin protection | Implemented |
| Reserved-pin listing | Implemented |
| PWM start/set/stop | Implemented |
| PWM status query | Implemented |
| Board routing test helpers | Implemented |
| Kickstarter monitor demo | Implemented |

## Pending / Future

| Area | Notes |
| --- | --- |
| USB command console | Needed for production/service workflow |
| USB locked service commands | Needed before exposing dangerous operations |
| Boot/recovery procedure | Needs final policy for products without EN/BOOT access |
| Production report format | CSV/PDF or JSON report still pending |
| License/provisioning integration | Future factory workflow |
| Network/WiFi API | Not part of this first S3 API slice |
| Ethernet SPI option | Deferred |

## Current Validation

- Build validated with ESP-IDF 5.5.4.
- Monitor demo flashed and checked on COM8.
- S3 module detected as ESP32-S3 with 16 MB flash and 8 MB PSRAM.
- MCP3208 routing previously tested on CH0..CH7.
