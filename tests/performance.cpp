
#include "list/singly_linked_list.hpp"

#include <chrono>
#include <iostream>
#include <list>
#include <vector>

namespace {

    // https://codereview.stackexchange.com/questions/48872/measuring-execution-time-in-c
    template<typename TimeT = std::chrono::milliseconds>
    struct measure {
        template<typename F, typename... Args>
        static typename TimeT::rep execution(F func, Args &&...args) {
            auto start = std::chrono::system_clock::now();

            // Now call the function with all the parameters you need.
            func(std::forward<Args>(args)...);

            auto duration = std::chrono::duration_cast<TimeT>(std::chrono::system_clock::now() - start);

            return duration.count();
        }
    };


}// namespace

int main() {


    size_t count = 10000;

    ais1002::singly_linked_list<std::string> mylist;
    std::vector<std::string> vector;
    std::list<std::string> list;

    auto t1 = measure<>::execution([&] {
        for (unsigned i = 0; i < count; ++i) {
            mylist.addFirst("per");
        }
    });

    auto t2 = measure<>::execution([&] {
        for (unsigned i = 0; i < count; ++i) {
            vector.insert(vector.begin(), "per");
        }
    });

    auto t3 = measure<>::execution([&] {
        for (unsigned i = 0; i < count; ++i) {
            list.emplace_front("per");
        }
    });

    std::cout << "mylist=" << t1 << ", vector=" << t2 << ", list= " << t3 << std::endl;

    mylist.clear();
    vector = {};
    list.clear();

    t1 = measure<>::execution([&] {
        for (unsigned i = 0; i < count; ++i) {
            mylist.addLast("per");
        }
    });

    t2 = measure<>::execution([&] {
        for (unsigned i = 0; i < count; ++i) {
            vector.emplace_back("per");
        }
    });

    t3 = measure<>::execution([&] {
        for (unsigned i = 0; i < count; ++i) {
            list.emplace_back("per");
        }
    });

    std::cout << "mylist=" << t1 << ", vector=" << t2 << ", list= " << t3 << std::endl;


}