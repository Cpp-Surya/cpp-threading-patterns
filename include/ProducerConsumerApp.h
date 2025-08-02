#ifndef CPP_THREADING_PATTERNS_PRODUCER_CONSUMER_APP_H_
#define CPP_THREADING_PATTERNS_PRODUCER_CONSUMER_APP_H_

#include <queue>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <iostream>

class ProducerConsumerApp{
    public:
        void producer();
        void consumer(int id);
        std::thread consumer_threads[3];
        private:
            std::mutex mtx;
            std::condition_variable cv;
            bool is_task_available{false};
            bool all_tasks_processed{false};
            int data{0};
};

#endif // CPP_THREADING_PATTERNS_PRODUCER_CONSUMER_APP_H_
