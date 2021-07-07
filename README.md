# Solar-Based-Automated-Irrigation-System
An AT89C51 (8051) based project to regulate automated irragation of fields. The entire systrem is powered with solar enegy. To harvest the maximum energy from sun during day time, a solar tracker circuit is also implemented.
### Sub Systems:
 <ol>
  <li>Solar Tracker</li>
  <li>Automated irrigation system based on soil moisture sensor</li>
 </ol>

### Working
Solar tracker syatem: 2 LDRs are used to detect the intensity of the light on the solar panel. Each LDR is placed on either side of the solar panels.And the output of the LDRs are given to the input pins of ADC0808.Using the adc the analog inputs from the ldr is converted to digital. On comparing the outputs of the LDRs the base motor which is used to tilt the axis of Panel is controlled and thus maximum energy is harvested.

Automated irrigation system: The soil moisture is determined using the YL69 and YL38 modules and using this data, if the field requires moisture content, the pump is initiated and  the soil retains the moisture content, the pump is turned off automatically.


### Components Used:
<ol>
 <li>AT89C51</li>
 <li>LDRs</li>
 <li>L293D driver IC(for driving stepper motor)</li>
 <li>NEMA17 bipolar stepper motor</li>
 <li>YL38 module (comparator module for interfacing soil moisture sensor probe to 8051)</li>
 <li>YL69 soil moisture sensor probe</li>
 <li>BC547 (to drive the relay for initiating the pump)</li>
 <li>ADC0808</li>
