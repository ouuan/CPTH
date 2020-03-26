## MonotonousQueue

Monotonous queue can be used to find the maximum value in a FIFO queue in linear time. There's a validate function to determine whether an element should be in the queue. You can push new element into the queue and get the maximum value in the queue.

`MonotonousQueue<T, cmp>`:
- T: The type to store
- cmp: A comparor which has the `()` function. The default value is `std::less<T>`. If you want to get the minimum value in the queue, you may want to use `std::greater<T>`.

`explicit MonotonousQueue(std::function<bool(const T &)> validate)`: Construct a monotonous queue with the given validate function, the default validate function is always return true.

`void setValidate(std::function<bool(const T &)> validate)`: Set the validate function.

`bool empty() const`: Remove invalid elements and return whether the queue is empty or not.

`void clear()`: Remove all elements in the queue.

`void push(const T &x)`: Push an element into the queue.

`T top()`: Remove invalid elements and return the maximum element in the queue. You shouldn't call this function when the queue has no valid element.
