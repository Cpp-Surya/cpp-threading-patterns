#include "ProducerConsumerApp.h"

void ProducerConsumerApp::producer(){
    std::unique_lock<std::mutex> lck(mtx);
    for(int i=0;i<3;i++){
        cv.wait(lck,[&](){return !is_task_available;});
        data++;
        std::cout<<"Producer: Task "<<data<<" added"<<std::endl;
        is_task_available = true;
        cv.notify_one();
    }
    all_tasks_processed = true;
}

void ProducerConsumerApp::consumer(int id){
    {
    std::unique_lock<std::mutex> lck(mtx);
    cv.wait(lck,[&](){return is_task_available;});
    std::cout<<"Consumer "<<id<<" Executing Task "<<data<<std::endl;
    is_task_available = false;
    cv.notify_one();
    }
    while(!all_tasks_processed);
    std::cout<<"Consumer "<<id<<" exiting."<<std::endl;
}
