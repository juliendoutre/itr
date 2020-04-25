/**
 * @file
 * @page td2 2.
 *
 * @section td2_a 2.a
 *
 * @subsection td2_a_s Summary
 * Demonstrate race conditions effects.
 *
 * @subsection td2_a_c Contents
 * We create 10 threads and make them increment a counter value passed through a pointer.
 * We can see that the final counter value does not match the expected value (it should be 10 times the iterations number).
 * It is because there is a race condition between the threads since they write a variable at the same time.
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
 * Finally we try several threads and iterations numbers for the `SCHED_RR` scheduling.
 * It gives us the following graph:
 *
 * @image html graph.png "Temps d'exécution"
 * @image latex graph.png "Temps d'exécution"
 *
 * We observe that for every thread number, the execution is almost linear depending in the iterations number.
 * However, the curves for `5` and `6` threads are separated from the others.
 * It is normal : the machine the program was runned on has `4` cores.
 * With more threads than cores, the scheduler has to perform multi-threaded computation on a same core which takes more time.
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
 * We reuse the counter incrementation program but define a POSIX mutex that protects the access to the incremented variable.
 * The execution time is slightly longer for each run but the final value of the variable is always the same and matches the number of threads times the number of iterations performed in each thread.
 *
 * @subsection td2_c_f Related files
 * - @ref td2_c_main "src/td2/c/main.cpp"
 * */
