#pragma once 
#include <atomic>

/*The atomic library provides components for fine-grained atomic operations allowing for lockless concurrent 
programming. Each atomic operation is indivisible with regards to any other atomic operation that involves 
the same object. Atomic objects are free of data races.

Each instantiation and full specialization of the std::atomic template defines an atomic type. 
If one thread writes to an atomic object while another thread reads from it, the behavior is well-defined
https://en.cppreference.com/w/cpp/language/memory_model

A memory barrier:
    Also known as a membar, memory fence or fence instruction, is a type of barrier instruction 
that causes a central processing unit or compiler to enforce an ordering constraint on memory operations issued 
before and after the barrier instruction. This typically means that operations issued prior to the barrier are 
guaranteed to be performed before operations issued after the barrier.
*/

/*  There will be two threads, they will races for context of storage.
    The result depends on interleaving of threads.
*/
class Storage
{
    private:
        std::atomic<int> content;

    public:
        Storage() : content(0) {}

        void SetContent(int val)
        {
            if (content > 0)
                content = 0;

            content = val;
        }

        int GetContent() const
        {
            return content;
        }
};
