#include <memory> 
template<typename T>
class threadsafe_queue {
 public:
  threadsafe_queue();
  threadsafe_queue(const threadsafe_queue&);
  threadsafe_queue& operator=(const threadsafe_queue&) = delete;

 // push()函数实现向队列添加数据的功能。添加数据后，使用std::condition_variable的notify_one通知取数据时被阻塞的线程。
  void push(T new_value);

  bool try_pop(T& value);
  std::shared_ptr<T> try_pop();

  void wait_and_pop(T& value);
  std::shared_ptr<T> wait_and_pop();

  bool empty() const;
};