* (Almost) everything can be either zero-initialized or have a dedicated initialization function.
* (Almost) everything can be copied/moved bytewise.
* Memory and buffers are either:
  * Fully (de)allocated by the user (strings)
  * Fully (de)allocated by the library (see next example).
