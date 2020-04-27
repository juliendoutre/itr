/**
 * @file
 * @page td3 3.
 *
 * @section td3_a 3.a
 *
 * @subsection td3_a_s Summary
 * Implement a Chrono class.
 *
 * @subsection td3_a_c Contents
 * We define a Chrono class with utils methods to start, stop and get an elapsed time.
 * We use the following convention: if the `stopTime` is `0`, then it means the Chrono is running (since the `stopTime` is less than the `startTime`).
 * The startTime is set to the current time at object instanciation but is updated at each `restart` call.
 * The elapsed time returned by the `lap` method is the `stopTime` minus the `startTime` if the Chrono is stopped, and the current time minus the `startTime` if it is running.
 *
 *
 * The class is tested in `main.ccp` with a few test functions, asserting its lap values in different configurations.
 * @subsection td3_a_f Related files
 * - @ref td3_a_main "src/td3/a/main.cpp"
 * - @ref lib_chrono "src/td3/a/Chrono.cpp"
 *
 * @section td3_b 3.b
 *
 * @subsection td3_b_s Summary
 * Implement a Timer class.
 *
 * @subsection td3_b_c Contents
 * We define a Timer class that embeds a POSIX timer.
 * Obviously, the Timer constructor and destructor are public.
 * It has two other public methods: `start` and `stop`. They are accessible to the user, since they are used to control the Timer.
 * However, the class is abstract. It means it cannot be constructed directly, but only through child classes that implement its virtual and protected method `callback`.
 * It is the method that is executed when the timer expires. It is protected so that only child classes can access it.
 * However, the `start` method needs to pass to the POSIX timer struct a pointer to this function. It is not possible if it is implemented by a child function.
 * To overcome that, we define a private static method whose job is to call the virtual child method.
 * The static method has a well-known address (which does not depend on the child implementation) that can be passed to the timer POSIX struct.
 *
 * We define another abstract function that inherits from Timer: PeriodicTimer. Its definition simply overrides the `start` method to configure the POSIX timer to execute the callback method at each period, instead of at expiration.
 *
 * We tested this set of classes through the CountDown class that inherits from PeriodicTimer. It implements `callback` with a simple mechanism: it decrements an attribute value and prints it out.
 * We create a class instance in `main.cpp` (it is not abstract) and call its `start` method to run it with a period of 100ms.
 * We use our timespec_wait function to block the main thread a certain time (1s), and thus wait for the CountDown object counter's value to reach 0.
 *
 * @subsection td3_b_f Related files
 * - @ref td3_b_main "src/td3/b/main.cpp"
 * - @ref td3_b_countdown "src/td3/b/CountDown.cpp"
 * - @ref lib_timer "src/td3/b/Timer.cpp"
 * - @ref lib_periodic_timer "src/td3/b/PeriodicTimer.cpp"
 *
 *
 * @section td3_c 3.c
 *
 * @subsection td3_c_s Summary
 * Find a relation between a function's number of iterations and its execution time with an object oriented architecture.
 *
 * @subsection td3_c_c Contents
 * We want to recode @ref td1_d with classes.
 *
 * The Looper class runs a loop and yields at will (through its method `getSample`) the number of iterations it has executed. It can be stopped at will as well using `stopLoop`.
 *
 * The Calibrator class inherits from PeriodicTimer. It initializes a Looper and collects a certain amount of samples every period. Then, it performs a linear regression (least square fit) over the collected samples to get the affine parameters of the function (number of iterations of the Looper function) over (execution time).
 * Once the Calibrator has been initialized, it can be passed as an argument to the CpuLoop constructor. This class inherits from Looper so it has the same behavior.
 * But it is also time controllable: since the Looper was calibrated, we can compute the number of iterations for a certain time and execute them. We are sure that it will run the correct time with a certain accuracy.
 *
 * @subsection td3_c_f Related files
 * - @ref td3_c_main "src/td3/c/main.cpp"
 * - @ref td3_c_cpu_loop "src/td3/c/CpuLoop.cpp"
 * - @ref td3_c_looper "src/td3/c/Looper.cpp"
 * */
