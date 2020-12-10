# Bit Field

* Compressing memory used unnecessarily in a struct
* Set the bit with `:`
* The struct size is the larger of the sum of bit and biggest size of element type.
* If sum of bit is not exactly divided, the remains suuplied by padding. So struct size is n_byte