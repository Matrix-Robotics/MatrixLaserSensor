## Begin

Reset and initialize sensor to default state.

```Arduino
bool begin()
```
### Return

- A **boolean** result of initialization. (`true` / `false`)
<br /><br /><br />
***
<br />

## Set Sample Rate

Set filter to stabilize Euler angle output.

```Arduino
void setSR(uint8_t rate)
```

### Parameters

- `uint8_t` is the sample rate of sensor from 1 to 64.

<br /><br /><br />
***
<br />

## Get Distance

get 11-bits **RGB** or **CMYK** format data.

```Arduino
uint16_t getDistance()
```

### Return

- An **uint16_t** number from `0` through `2047`.
