# Bit Manipulation

* manipulate specific index to 1 or 0

* manipulate 

  *  set
    * `x |= 1LL << n`

  * Reset
    * `x &= ~(1LL<<n)`
  * XOR
    * `x ^= 1LL << n`
  * check bit
    * `(x >> n) && 1LL `   or `x & (1LL << n)`

* most right 1 bit 

  * useful count of 1 bit

  * useful check power of 2

