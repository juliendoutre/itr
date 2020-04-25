/**
 * @page td6 6.
 *
 * @section td6_s Summary
 * Implement the ActiveObject paradigm.
 *
 * @section td6_c Contents
 * We define an ActiveObject class that inherits from Thread and stores pointers to Request objects in a FIFO.
 * The Request class is an abstract one that owns a Semaphore.
 *
 * To demonstrate this mechanism we define ActiveCalc that inherits from ActiveObject.
 * CrunchReq inherits from Request. ActiveCalc `async_crunch` creates and adds a CrunchReq to the FIFO and returns a pointer to it.
 * We need to allocate the memory for it on the heap since it is shared by the ActiveObject thread and the main thread.
 * In order to separate the request logic from the payload computation itself, we define a Calculator object whose reference is passed at every CrunchRequest instance. In our example, Calculator returns the square of a double value.
 * The CrunchRequest `execute` method override uses the Calculator object to perform the computation.
 *
 * Finally we create a Client class that inherits from Thread and send multiple requests to the ActiveCalc object. It returns the results trough a method that waits for all the client's request to be done, and return their results in a vector.
 * In the end we print all the clients results and check that all their requests were well treated.
 *
 * @section td6_f Related files
 * -  @ref td6_main "src/td6/main.cpp"
 * -  @ref td6_active_calc "src/td6/ActiveCalc.cpp"
 * -  @ref lib_active_object "src/td6/ActiveObject.cpp"
 * -  @ref td6_calculator "src/td6/Calculator.cpp"
 * -  @ref td6_crunch_req "src/td6/CrunchReq.cpp"
 * -  @ref lib_request "src/td6/Request.cpp"
 * -  @ref td6_terminal_req "src/td6/TerminalReq.cpp"
 * -  @ref td6_client "src/td6/Client.cpp"
 * */
