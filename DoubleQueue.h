#include <pthread.h>

///////////////////////////////////////////////////////////////////////////////
// A DoubleQueue is a class that represents a queue of double values
//
// The queue supports:
// - adding doubles to the end of the queue
// - removing doubles from the end of the queue
// - removing a double from the end of the queue and waiting
//   for a double to be added if there isn't one already.
// The queue is thread safe, with no potential for data races, or deadlocks
///////////////////////////////////////////////////////////////////////////////
class DoubleQueue {
 public:
  // Constructor for a DoubleQueue.
  // Initializes the queue to be empty
  // and ready to handle concurrent operations
  DoubleQueue();

  // Destructor for DoubleQueue.
  // Cleans up any remaining elements in the queue
  // and any synronization methods used for maintaining
  // the state of the queue.
  ~DoubleQueue();

  // Adds a double to the end of the queue
  // This operation is thread safe.
  //
  // Arguments:
  // - val: the double value to add to the end of the queue
  //
  // Returns: nothing
  void add(double val);

  // Removes a double from the front of the queue
  // This operation is thread safe.
  //
  // Arguments:
  // - ret: An output parameter to return the value at the front of the list
  //
  // Returns:
  // - True if a value was successfully removed
  // - False otherwise
  bool remove(double* ret);

  // Removes a double from the front of the queue
  // but if there is no double in the queue, calling thread will block or spin
  // until there is one available
  // This operation is thread safe.
  //
  // Arguments: None
  //
  // Returns:
  // The value removed from the front of the queue
  double wait_remove();

  // Returns the length of the queue currently
  // This operation is thread safe.
  //
  // Arguments: None
  //
  // Returns:
  // The value length of (i.e. number of elements in) the queue
  int length();
 private:
  // define a new internal type used to represent
  // nodes in the Queue
  // Queue can be implemented as a linked list
  typedef struct QueueNode {
    QueueNode* next;
    double value;
    QueueNode(int val=0) : value(val), next(NULL){}
  }QueueNode, *Queue;
  // Fields
  // TODO: Add
};
/*
1. 研究一下这个数据结构怎样才线程安全
2. 这个DS是用来线程间传输数据的 
3. 定长数组实现（size==5我猜）

*/