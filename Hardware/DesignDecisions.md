# LED/Driver Current & Voltage

## Assumptions
* Driver IC: MAX6955
* 7 Segment LED: KingBright SC05-11EWA

## Input Data
### 7 Segment LEDs
| Description | Symbol | Value |
|-|-|-|
|Forward Voltage|V<sub>f</sub>|2.0V|
|Forward Current|I<sub>fmax</sub>|20mA|
### LED Driver

## Required Values
* R<sub>set</sub> & C<sub>set</sub>

## R<sub>set</sub> & C<sub>set</sub>
> The RC oscillator uses an external resistor, R<sub>set</sub>, and an external capacitor, C<sub>set</sub>, to set the frequency, fOSC. The allowed range of fOSC is 1MHz to 8MHz. R<sub>set</sub> also sets the peak segment current. The recommended values of R<sub>set</sub> and C<sub>set</sub> set the oscillator to 4MHz, which makes the blink frequencies selectable between 0.5Hz and 1Hz. The recommended value of R<sub>set</sub> also sets the peak current to 40mA, which makes the segment current adjustable from 2.5mA to 37.5mA in 2.5mA steps.

From the dat sheet:
    
I<sub>f</sub> = k<sub>L</sub> / R<sub>set</sub> mA

F<sub>OSC</sub> = k<sub>F</sub> / (R<sub>set</sub>&times;C<sub>set</sub>) MHz

Where:

I<sub>f</sub> is forward segment current in mA <br>
C<sub>set</sub> is the external capacitance in pF<br>
R<sub>set</sub> is the external resistance in k&ohm;<br>
k<sub>L</sub> is a supplied constant equal to 2240<br>
k<sub>F</sub> is a supplied constant equal to 10000<br>

*(The data sheet doesn't provide definitions in italics, the definitions here are supposition)* 

Solving for R<sub>set</sub>:

R<sub>set</sub> = k<sub>L</sub> / I<sub>f</sub> = 2240 / 20 = 112 k&ohm;

The nearest E24 value to 112k&ohm; is 120k&ohm.

Solving the 2<sup>nd</sup> equation for C<sub>set</sub>:

C<sub>set</sub> = k<sub>F</sub> / (R<sub>set</sub>&times; F<sub>OSC</sub>)

C<sub>set</sub> = 10000 / (120 &times; 4) = 20.83pF

and the nearest E24 value to 20.83pF is 20pF. Which gives:

I<sub>f</sub> = 2240 / 120 = 18.6 mA

F<sub>OSC</sub> = 10000 / (120 &times; 20) = 4.16 MHz

## power consumption & maximum operating temperature


| Description | Symbol | Value |
|-|-|-|
|Supply Voltage|V<sub>sup</sub>|3.3V|
|Forward Voltage|V<sub>f</sub>|2.0V|
|Forward Current|I<sub>fmax</sub>|20mA|
|Number of Segments Driven|N|11|
|Duty Cycle set by Intensity Register|DUTY|15/16|

P<sub>d</sub> = ( V<sub>sup</sub> &times; 35mA ) + (V<sub>sup</sub> - V<sub>f</sub> )( DUTY &times; I<sub>fmax</sub> &times; N)

P<sub>d</sub> = ( 3.3 &times; 35mA ) + ( 3.3 - 2.0 )( (15/16) &times; 20 &times; 11) 

P<sub>d</sub> = 115.5 + 1.3 &times; ( 0.9375 * 220 )
P<sub>d</sub> = 0.383W 

This implies:

T<sub>JA</sub> = 1/0.0118 = 85&deg;C/W

T<sub>J(MAX)</sub> = T<sub>A</sub> + (P<sub>D</sub> &times; T<sub>JA</sub>) = 150&deg;C
T<sub>J(MAX)</sub> = T<sub>A</sub> + (0.383 &times; 85) = 150&deg;C
T<sub>JA</sub>) = 150&deg;C

T<sub>A</sub> = ( 150 - 3.26 ) = 117.4 &deg;C

## References
[MAX6955 Datasheet]
