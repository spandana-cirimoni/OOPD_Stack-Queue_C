//==============================================================================
/**
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================
#include <exception>
#include "Array_Base.h"

/**
 * @class Queue
 *
 * Basic queue for abitrary elements.
 */
template <typename T>
class Queue
{
public:
  /// Type definition of the type.
  typedef T type;

  /**
   * @class empty_exception
   *
   * Exception thrown to indicate the queue is empty.
   */
  class empty_exception : public std::exception
  {
  public:
    /// Default constructor.
    empty_exception (void)
      : std::exception () { }

    /**
     * Initializing constructor.
     *
     * @param[in]      msg         Error message.
     */
    empty_exception (const char * msg)
      : std::exception (msg) { }
  };

  /// Default constructor.
  Queue (void);

  /// Copy constructor.
  Queue (const Queue & s);

  /// Destructor.
  ~Queue (void);

  /**
   * Assignment operator
   *
   * @param[in]      rhs           Right-hand side of operator
   * @return         Reference to self
   */
  const Queue & operator = (const Queue & rhs);

  /**
   * Push a new \a element onto the Queue. The element is inserted
   * after all the other elements in the list.
   *
   * @param[in]      element       Element to add to the list
   */
  void enqueue (T element);

  /**
   * Remove the first-most element from the queue.
   *
   * @exception      empty_exception    The queue is empty.
   */
  T dequeue (void);

  /**
   * Test if the queue is empty
   *
   * @retval         true          The queue is empty
   * @retval         false         The queue is not empty
   */
  bool is_empty (void) const;

  /**
   * Number of element on the queue.
   *
   * @return         Size of the queue.
   */
  size_t size (void) const;

  /// Remove all elements from the queue.
  void clear (void);

private:
  // add member variable here
  Array_Base <T> queue_data_;
  size_t rear_;
  size_t front_;
  size_t queue_max_size_;
};

// include the inline files
#include "Queue.inl"

// include the source file since template class
#include "Queue.cpp"