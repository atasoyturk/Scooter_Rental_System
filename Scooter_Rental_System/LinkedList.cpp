#include "linkedlist.h"
using namespace std;

template <typename T>
LinkedList<T>::~LinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

template <typename T>
void LinkedList<T>::add(const T& data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
    itemCount++;
}

template <typename T>
bool LinkedList<T>::remove(int index) {
    if (index < 0 || index >= itemCount) return false;

    Node* toDelete = nullptr;
    if (index == 0) {
        toDelete = head;
        head = head->next;
    }
    else {
        Node* current = head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        toDelete = current->next;
        current->next = toDelete->next;
    }

    delete toDelete;
    itemCount--;
    return true;
}

template <typename T>
T& LinkedList<T>::get(int index) const {
    if (index < 0 || index >= itemCount) {
        throw std::out_of_range("Index out of bounds");
    }

    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}

template <typename T>
int LinkedList<T>::size() const {
    return itemCount;
}

template <typename T>
bool LinkedList<T>::isEmpty() const {
    return itemCount == 0;
}

template class LinkedList<Scooter>;
template class LinkedList<Customer>;
template class LinkedList<string>;