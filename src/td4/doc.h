/**
 * @file
 * @page td4 4.
 *
 * @section td4_a 4.a
 *
 * @subsection td4_a_s Summary
 * Implement a PosixThread and Thread classes.
 *
 * @subsection td4_a_c Contents
 * We define a PosixThread class that embeds a POSIX thread manager. The two constructors allow to instanciate an object from scratch or from an existing thread.
 * Methods are defined to update or read the thread scheduling policy, start it, wait for its end, or wait for its end with a timeout.
 *
 * The Thread class inherits from this first class.
 * It uses the same mechanism as in the Timer class to be able to pass a static method pointer to the thread configuration POSIX structure, that calls the virtual method `run` implemented by child classes.
 * Methods enable the caller to measure thread execution time.
 *
 * We tested the Thread class in `main.ccp`. The Worker class inherits from it and run a loop that increments an attribute.
 * We create several Workers objects (stored in a vector), start them and then wait for them to end.
 * We print the final results and see that all their incremented attributes have been fully incremented to the iterations number.
 *
 * @subsection td4_a_f Related files
 * - @ref td4_a_main "src/td4/a/main.cpp"
 * - @ref lib_posix_thread "src/td4/a/PosixThread.cpp"
 * - @ref lib_thread "src/td4/a/Thread.cpp"
 * - @ref td4_a_worker "src/td4/a/Worker.cpp"
 *
 * @section td4_b 4.b
 *
 * @subsection td4_b_s Summary
 * Implement a Mutex class.
 *
 * @subsection td4_b_c Contents
 * We implement a Mutex class that embeds a POSIX mutex.
 * It is not designed to be controlled directly so all its methods that handle locking and unlocking are made private.
 * Then we define the subclass Monitor that exposes public methods to wait (with or without a timeout) that a Mutex (whose reference is stored as an attribute) is free, and notify the watchers for these mutex.
 * One interesting point is that since Monitor is a subclass of Mutex it has access to its private methods.
 * Two other subclasses Lock and TryLock inherit from Monitor. Upon instanciation, they lock or try to lock with a timeout a Mutex, and they unlock it when their destructor is called.
 *
 * An example of use is given  in `main.cpp`. We create a pool of workers that inherit from Thread and increment a shared value protected by a Mutex.
 * In the end, the variable value has a correct value 100% of the time: the Mutex effectively protected the variable from concurrent access and race conditions.
 *
 * @subsection td4_b_f Related files
 * - @ref td4_b_main "src/td4/b/main.cpp"
 * - @ref lib_mutex "src/td4/b/Mutex.cpp"
 * - @ref td4_b_worker "src/td4/b/Worker.cpp"
 *
 *
 * @section td4_c 4.c
 *
 * @subsection td4_c_s Summary
 * Implement a Semaphore class.
 *
 * @subsection td4_c_c Contents
 * We define a Semaphore class. It is composed of a token counter capped by a maximum value and protected with a Mutex.
 * It exposes a `give` and `take` method that respectively increment or decrement this counter.
 * If `0` is reached, the `take` method will be blocking until a token is added to it with a call to `give`.
 * An overload of `take` with a timeout exists. It returns `true` if a token was obtained in time, else `false`.
 * This is why we use `notify` at the end of the counter incrementation in `give`, to notify eventually waiting threads that a token was added.
 *
 * We tested it in `main.cpp` by creating a Semaphore and two types of workers: type Producer that gives tokens, and type Consumer that takes tokens.
 *
 * We create a pool of each of these objects, start them in their own threads (they inherit from Thread) and check that after they have all ended, the consumers consumed all the tokens.
 * In order to do that, we try to take from the Semaphore with a timeout and check that it returns `false`.
 *
 * @subsection td4_c_f Related files
 * - @ref td4_c_main "src/td4/c/main.cpp"
 * - @ref lib_semaphore "src/td4/c/Semaphore.cpp"
 * - @ref td4_c_consumer "src/td4/c/Consumer.cpp"
 * - @ref td4_c_producer "src/td4/a/Producer.cpp"
 *
 * @section td4_d 4.d
 *
 * @subsection td4_d_s Summary
 * Implement a FIFO class template.
 *
 * @subsection td4_d_c Contents
 * We define a template that stores values in a standard library queue.
 * The queue is protected with a Mutex to avoid race conditions.
 * It exposes classic queue operations `push` and `pop` (the latter with a timeout overloading) over this queue.
 *
 * We tested it in `main.cpp` with two types of workers: Consumer that pop values from a FIFO of int, and Producer that push values to it.
 * We check that in the end, the FIFO is empty, that is to say all values pushed by producers were consumed by consumers.
 *
 * @subsection td4_d_f Related files
 * - @ref td4_d_main "src/td4/d/main.cpp"
 * - @ref td4_d_consumer "src/td4/d/Consumer.cpp"
 * - @ref td4_d_producer "src/td4/d/Producer.cpp"
 * */
