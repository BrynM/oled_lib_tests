# "Minimal" Arduino OLED Library Tests

I'm using the SH1106 library for a project and am getting cramped for RAM on my
poor little Arduino Micro controlling the project. Since I'm only displaying
text on the OLED, I wanted to compare some libraries that attempt to be small.

Yes, there are many more libraries out there. Most got ruled out for relying on
Adafruit GFX, which SH1106 used and I wanted to avoid. I don't need all of that
functionality and would rather supply my own 8x8 font to conform to the
project's other display (an actual set of four 8x8 LED matrices).


## Collated Results

| Library  | PGMEM | BL PGMEM ▲ | SRAM | BL SRAM ▲ |
|----------|-------|------------|------|-----------|
| Baseline |  5160 |          0 |  185 |         0 |
| SH1106   | 14910 |       9750 | 1514 |      1329 |
| SSOLED   | 11302 |       6142 |  465 |       280 |
| U8X8     | 10818 |       5658 |  606 |       501 |


## Individual Results


### Baseline

A baseline empty sketch that uses the same variables and writes the same data to
Serial rather than a real OLED. This gives a rough estimate of the base library
memory footprints in real use and ensures I'm not letting the compiler optimize
other memory usage away for my comparison.

```
Sketch uses 5160 bytes (17%) of program storage space. Maximum is 28672 bytes.
Global variables use 185 bytes (7%) of dynamic memory, leaving 2375 bytes for local variables. Maximum is 2560 bytes.
```

| MEM Type | Bytes | Baseline ▲ |
|----------|-------|------------|
| PGMEM    |  5160 |          0 |
| SRAM     |   185 |          0 |

#### Downsides

* No OLED.

#### Upsides

*	Lightweight.


### SH1106

https://github.com/sitronlabs/SitronLabs_SinoWealth_SH1106_Arduino_Library

```
Sketch uses 14910 bytes (52%) of program storage space. Maximum is 28672 bytes.
Global variables use 1514 bytes (59%) of dynamic memory, leaving 1046 bytes for local variables. Maximum is 2560 bytes.
```

| MEM Type | Bytes | Baseline ▲ |
|----------|-------|------------|
| PGMEM    | 14910 |       9750 |
| SRAM     |  1514 |       1329 |

#### Downsides

* What i'm currently using and losing hair over.
* Fat.
* Relies on Adafruit GFX.
* Doesn't play well with EEPROMs on same I2C bus.

#### Upsides

* Flexible.
* Relies on Adafruit GFX.


### SS_OLED

https://github.com/bitbank2/ss_oled

```
Sketch uses 11302 bytes (39%) of program storage space. Maximum is 28672 bytes.
Global variables use 465 bytes (18%) of dynamic memory, leaving 2095 bytes for local variables. Maximum is 2560 bytes.
```

| MEM Type | Bytes | Baseline ▲ |
|----------|-------|------------|
| PGMEM    | 11302 |       6142 |
| SRAM     |   465 |        280 |

#### Downsides

* Methods all in global space and require passing the oled object byref.
* Big constructor.
* Unsigned long required sprintf().
* More maintained version "OneBitDisplay" is much larger.

#### Upsides

*	Small SRAM footprint.


### U8X8 (As provided by U8g2)

https://github.com/olikraus/u8g2

```
Sketch uses 10818 bytes (37%) of program storage space. Maximum is 28672 bytes.
Global variables use 606 bytes (23%) of dynamic memory, leaving 1954 bytes for local variables. Maximum is 2560 bytes.
```

| MEM Type | Bytes | Baseline ▲ |
|----------|-------|------------|
| PGMEM    | 10818 |       5658 |
| SRAM     |   606 |        501 |

#### Downsides

* Unsigned long required sprintf().
* Examples are wild for how many platforms/OLEDs they try to support.

#### Upsides

*	Good mix of code quality and smallness.
