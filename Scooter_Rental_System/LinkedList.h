#pragma once
#include <iostream>
#include "customer.h"
#include "scooter.h"
class Scooter;
class Customer;

template <typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& data) : data(data), next(nullptr) {}
    };
    Node* head;
    int itemCount;

public:
    LinkedList() : head(nullptr), itemCount(0) {}
    ~LinkedList();

    void add(const T& data);
    bool remove(int index);
    T& get(int index) const;
    int size() const;
    bool isEmpty() const;
};