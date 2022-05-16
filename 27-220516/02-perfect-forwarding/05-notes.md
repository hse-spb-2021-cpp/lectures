* Use perfect forwarding when your function only wants to pass some of its arguments to the next function.
* Perfect forwarding never copies anything, it only passes references.
  The complex syntax is to make sure "a value category is preserved", i.e. the correct lvalue/rvalue reference is chosen.
* Perfect forwarding does not inspect the function called. It adapts for the caller.
* Use `ref`/`cref` if passing references is not good. E.g. passing a reference to a new thread is dangerous:
  ```c++
  void some_thread(std::vector<int> vec) { .... }
  std::thread t(some_thread, create_vector());  // temporary likely dies before the thread starts.
  ```
