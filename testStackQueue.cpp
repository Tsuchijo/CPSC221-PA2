/**
 * @file        testStackQueue.cpp
 * @description Basic test cases for CPSC 221 2023S PA2 - Stack and Queue
 *              Add your own code to this!
 *
 */

#define CATCH_CONFIG_MAIN
#include <iostream>
#include "cs221util/catch.hpp"

#include "stack.h"
#include "queue.h"

using namespace std;

TEST_CASE("Stack::basic functions", "[weight=1][part=stack]") {
    cout << "Testing Stack..." << endl;
    Stack<int> intStack;
    vector<int> result;
    vector<int> expected;

    for (int i = 10; i > 0; i--) {
        expected.push_back(i);
    }
    for (int i = 1; i <= 10; i++) {
        intStack.Push(i);
    }
    cout << intStack.Peek() << endl;
    while (!intStack.IsEmpty()) {
        result.push_back(intStack.Pop());
        //cout << intStack.Pop() << " ";
    }
    REQUIRE(result == expected);
}
TEST_CASE("Queue::basic functions", "[weight=1][part=queue]") {
    //cout << "Testing Queue..." << endl;
    Queue<int> intQueue;
    vector<int> result;
    vector<int> expected;
    for (int i = 1; i <= 10; i++) {
        expected.push_back(i);
    }
    for (int i = 1; i <= 10; i++) {
        intQueue.Enqueue(i);
    }
    //cout << intStack.peek() << endl;
    while (!intQueue.IsEmpty()) {
        result.push_back(intQueue.Dequeue());
        //cout << intStack.pop() << " ";
    }
    REQUIRE(result == expected);
}

