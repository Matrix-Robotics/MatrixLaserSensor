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

## Get Distance

get 16-bits distance data. (unit=mm)

```Arduino
uint16_t getDistance()
```

### Return

- An **uint16_t** number from `21` through `1999`.
- Number as `8191` when the sensor timeout.
