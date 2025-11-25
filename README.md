# Bond Price Calculator (C++)

![Demo screenshot](demo.png)

A robust command line program written in C++ that calculates the present value (price) of a fixed-rate coupon bond.

---

## Features & Error Handling

Unlike very basic calculators, this program includes input validation to keep results sensible and avoid common C++ input bugs:

- **Input Validation**  
  Ensures all financial inputs are sensible:
  - Face Value must be **positive**  
  - Coupon Rate must be **non-negative**  
  - Market Rate (YTM) must be **strictly greater than 0**

- **Zero-Division Protection**  
  Prevents using a zero or negative market rate, which would break the maths in the discounting formula.

- **Integer Fields with Decimal Protection**  
  For fields that must be whole numbers (like **Years** and **Frequency**), the program:
  - Reads into a `double`  
  - Checks if the value is a whole number (`value == floor(value)`)  
  - Only then casts to `int`  

  This cleanly catches cases like `5.5` for Years and asks the user to re-enter a valid **int**.

---

## How to Compile & Run

This project uses only standard C++ libraries: `iostream` and `cmath`

### 1. Compile

Using `g++`:

```bash
g++ bond_calculator.cpp -o bond_calculator
```