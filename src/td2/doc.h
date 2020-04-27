/**
 * @file
 * @page td2 2.
 *
 * @section td2_a 2.a
 *
 * @subsection td2_a_s Summary
 * Demonstrate the effects of race conditions.
 *
 * @subsection td2_a_c Contents
 * We create 10 threads and make them increment a counter value passed through a pointer.
 * We can see that the final counter value does not match the expected value (it should be 10 times the number of iterations).
 * This is because there is a race condition between the threads since they make concurrent writes to the same variable.
 * We can see that each run yields a different counter value.
 *
 * @subsection td2_a_f Related files
 * - @ref td2_a_main "src/td2/a/main.cpp"
 *
 * @section td2_b 2.b
 *
 * @subsection td2_b_s Summary
 * Demonstrate the threads number effect.
 *
 * @subsection td2_b_c Contents
 * We reuse the previous code but set different scheduling methods.
 * Finally we try various thread counts and number of iterations for the `SCHED_RR` scheduling.
 * It gives us the following graph:
 *
 * @image html graph.png "Execution time"
 * @image latex graph.png "Execution time"
 *
 * We observe that for each thread count, the execution is almost linear depending in the number of iterations.
 * However, the curves for `5` and `6` threads are separated from the others.
 * It is expected: the program was run on a `4` cores machine.
 * When using more threads than there are cores, the scheduler has to perform multi-threaded computations on a given core, which takes more time.
 *
 * @subsection td2_b_f Related files
 * - @ref td2_b_main "src/td2/b/main.cpp"
 *
 * @section td2_c 2.c
 *
 * @subsection td2_c_s Summary
 * Demonstrate the use of a POSIX mutex.
 *
 * @subsection td2_c_c Contents
 * We reuse the counter incrementation program, but define a POSIX mutex that protects the access to the incremented variable.
 * The execution time is slightly longer for each run, but the final value of the variable is always the same and matches the number of threads times the number of iterations performed in each thread.
 *
 * @subsection td2_c_f Related files
 * - @ref td2_c_main "src/td2/c/main.cpp"
 * */
