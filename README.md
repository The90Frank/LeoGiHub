# LeoGiHub

Arduino Leonardo firmware that turns racing simulation hardware (pedals, shifter, button matrix, hand brake) into a USB gamepad via HID.

## Supported inputs

| Input | Pin | Type | Gamepad mapping |
|---|---|---|---|
| Button matrix (12 buttons) | A5 | Analog | Buttons 1-12 |
| Shifter X axis | A4 | Analog | — |
| Shifter Y axis | A3 | Analog | — |
| Reverse gear | 2 | Digital | — |
| Shifter (gears 1-6 + R) | — | Computed | Buttons 14-20 |
| Accelerator | A0 | Analog | RX axis |
| Brake | A1 | Analog | RY axis |
| Clutch | A2 | Analog | RZ axis |
| Hand brake | A6 | Analog | Z axis |

## How it works

- Reads analog and digital inputs from the racing hardware at 100ms intervals
- Normalizes ADC values to HID-compatible axis ranges (16-bit for pedals, 8-bit for clutch/handbrake)
- Detects gear position from shifter X/Y coordinates and reverse button state
- Sends gamepad updates only when input changes to avoid data flooding

## Dependencies

- [HID-Project](https://github.com/NicoHood/HID) - Gamepad HID emulation for Arduino Leonardo

## License

Apache License 2.0 - see [LICENSE](LICENSE) for details.
