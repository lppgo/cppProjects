#include <queue>
#include <memory>
#include <mutex>
#include <condition_variable>

template<typename T>
class threadsafe_queue {
 private:
   mutable std::mutex mut; 
   std::queue<T> data_queue;
   std::condition_variable data_cond;
 public:
   threadsafe_queue(){}
   threadsafe_queue(threadsafe_queue const& other) {
     std::lock_guard<std::mutex> lk(other.mut);
     data_queue=other.data_queue;
   }

// push()函数实现向队列添加数据的功能。添加数据后，使用std::condition_variable的notify_one通知取数据时被阻塞的线程。
   void push(T new_value) {
     std::lock_guard<std::mutex> lk(mut);
     data_queue.push(new_value);
     data_cond.notify_one();
   }

// wait_and_pop()函数实现从队列取数据的功能，当队列为空时，线程被挂起，等待有数据时被唤醒。
   void wait_and_pop(T& value) {
     std::unique_lock<std::mutex> lk(mut);
     data_cond.wait(lk,[this]{return !data_queue.empty();});
     value=data_queue.front();
     data_queue.pop();
   }

   std::shared_ptr<T> wait_and_pop() {
     std::unique_lock<std::mutex> lk(mut);
     data_cond.wait(lk,[this]{return !data_queue.empty();});
     std::shared_ptr<T> res(std::make_shared<T>(data_queue.front()));
     data_queue.pop();
     return res;
   }

// try_pop函数提供非阻塞调用下的弹出队列(queue)的功能。弹出成功返回true或者非空shared_ptr，失败则返回false或者nullptr。
   bool try_pop(T& value) {
     std::lock_guard<std::mutex> lk(mut);
     if(data_queue.empty())
       return false;
     value=data_queue.front();
     data_queue.pop();
     return true;
   }

   std::shared_ptr<T> try_pop() {
     std::lock_guard<std::mutex> lk(mut);
     if(data_queue.empty())
       return std::shared_ptr<T>();
     std::shared_ptr<T> res(std::make_shared<T>(data_queue.front()));
     data_queue.pop();
     return res;
   }

   bool empty() const {
     std::lock_guard<std::mutex> lk(mut);
     return data_queue.empty();
   }
};