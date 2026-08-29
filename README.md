# LoongSocket LS-W1 S3 N16R8 SDK

Public SDK package for the LoongSocket LS-W1 S3 N16R8 module.

This repository contains the customer-facing API surface:

- Public headers in `include/ls/`.
- API documentation in `docs/API/`.
- Example code in `examples/`.
- Reserved `lib/` folder for precompiled libraries.

This SDK does not contain private firmware sources, factory tools, license keys or production scripts.

## Module

- Module part number: `LS-W1-1119-38P-S3U-N16R8`
- MCU family: ESP32-S3
- Flash: 16 MB
- PSRAM: 8 MB
- Target ESP-IDF: 5.5.4

## Current status

Prototype SDK structure.

The headers and documentation are included. Precompiled `.a` libraries will be added when the private firmware API boundary is frozen.

## Folders

| Path | Content |
| --- | --- |
| `include/ls/` | Public LS API headers. |
| `lib/` | Precompiled libraries, added by release packaging. |
| `examples/` | Minimal usage examples. |
| `docs/API/` | API reference in Markdown, Word and PDF. |
| `docs/hardware/` | Public hardware notes and pinout material. |
| `docs/release/` | Changelog and versioning notes. |
| `tools/` | Public helper tools when needed. |

## Versioning

SDK versions follow semantic versioning:

```text
MAJOR.MINOR.PATCH
```

The SDK version must match the compatible private firmware/API release.
