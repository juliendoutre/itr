/**
 * @file
 * @page td1 1.
 *
 * @section td1_a 1.a
 *
 * @subsection td1_a_s Summary
 * Implements utils functions to ease the manipulations of the POSIX `timespec` struct.
 *
 *  @subsection td1_a_c Contents
 * We first define functions to convert and convert back such a struct into a number (`double`) of milliseconds, easier to represent.
 * We need special attention for the negative time case. Indeed the specification of the `timespec` struct imposes its nanosecond fields to be always positive.
 *
 * We then define functions to add and substract two timespecs, and get the current time. We use them to override the `+` and `-` operators. Comparison operators are overriden as well.
 *
 * Finally, we define a function to make the current thread wait for a certain time. Note that the kernel scheduler will try to wait the specified time but can return sooner (e.g. interrupt, round-robin task scheduling, etc.). So, when interrupted, the functions return their remaining wait time.
 *
 * We tested these functions, especially the negative time mechanisms, in the `main.cpp` file.
 *
 * @subsection td1_a_f Related files
 * - @ref td1_a_main "src/td1/a/main.cpp"
 * - @ref lib_time "src/td1/a/time.cpp"
 *
 * @section td1_b 1.b
 *
 * @subsection td1_b_s Summary
 * Demonstrates the POSIX timer usage.
 *
 * @subsection td1_b_c Contents
 * We initialize a `counter` integer to `0`. We declare it as `volatile` so the compiler won't try to deduce its value from the `main` code that follows (indeed, the variable is never modified in it, so it could chose to bypass the loops that come later on).
 * We create a POSIX timer and configure it to run the `handler` function every half second. This function increments the `counter` by one.
 *
 * Once the timer is set and started, a loop blocks the main thread until it reaches `15`. Then the timer is deleted and the program exits.
 *
 * @subsection td1_b_f Related files
 * - @ref td1_b_main "src/td1/b/main.cpp"
 *
 * @section td1_c 1.c
 *
 * @subsection td1_c_s Summary
 * Demonstrate how to measure a function execution time.
 *
 * @subsection td1_c_c Contents
 * We define a function to increment a variable until it reaches a defined value.
 *
 * In the main function we get the current time and save it in a variable, execute the function, get the current time after it has finished, compute the difference with the previous time and print it. This represents the function execution time.
 *
 * @subsection td1_c_f Related files
 * - @ref td1_c_main "src/td1/c/main.cpp"
 *
 * @section td1_d 1.d
 *
 * @subsection td1_d_s Summary
 * Find a relation between a function's number of iterations and its execution time.
 *
 * @subsection td1_d_c Contents
 * We use the previous function with a subtle change: we check at each iteration the value of a boolean value (passed to the function through a pointer). If it is false, then the function returns immediately.
 * This boolean variable is defined as volatile to avoid the compiler optimizations.
 * The loop function returns the number of iterations actually executed.
 *
 * Our goal is now to obtain the affine parameters of the function describing the number of loop iterations over time.
 * These parameters are returned in the form of a struct (`Parameters`) by the function `calibrate`.
 * This function gets two samples (a tuple: (second, iterations number)) for two different times, 4 and 6 seconds. Then it computes a linear regression for these two points, thus giving the parameters.
 *
 * @subsection td1_d_f Related files
 * - @ref td1_d_main "src/td1/d/main.cpp"
 *
 * @section td1_e 1.e
 *
 * @subsection td1_e_s Summary
 *
 * Improvements over the previous exercise.
 *
 * @subsection td1_e_c Contents
 * We use the previous mechanism but get a lot more samples, and perform a least square fit linear regression to compute the affine parameters.
 *
 * @subsection td1_e_f Related files
 * - @ref td1_e_main "src/td1/e/main.cpp"
 * */
