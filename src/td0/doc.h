/**
 * @page td0 0.
 *
 * @section Summary
 * Example of communication on a bus with a hardware peripheral storing numbers in a fifo data structure.
 * - `0xfc000000` is the device writing port address.
 * - `0xfc000004` is the device reading port address.
 * - `0xfc000008` is the address of a port giving the number of elements stored in the queue.
 * @section Purpose
 * This demonstrates the use of the `volatile` keyword, telling the compiler a variable \
 * can be overwritten with values at anytime and that this behavior should not be optimized.
 * @section files Related files
 * -  @ref td0_main "src/td0/main.c"
 * */
