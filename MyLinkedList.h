#pragma once
#include <iostream>
#include <stdexcept> // std::out_of_range, std::invalid_argument

template <typename T>
class MyLinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    size_t listSize;

public:
    MyLinkedList() : head(nullptr), tail(nullptr), listSize(0) {}

    void add(const T& item) {
        Node* newNode = new Node(item);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        listSize++;
    }

    void insert(size_t index, const T& item) {
        if (index > listSize)
            throw std::out_of_range("Insert: index " + std::to_string(index) + " is out of range");

        Node* newNode = new Node(item);
        if (index == 0) {
            newNode->next = head;
            head = newNode;
            if (tail == nullptr) tail = newNode;
        } else {
            Node* current = head;
            for (size_t i = 0; i < index - 1; ++i)
                current = current->next;
            newNode->next = current->next;
            current->next = newNode;
            if (newNode->next == nullptr) tail = newNode;
        }
        listSize++;
    }

    void remove(int index) {
        if (index < 0 || index >= (int)listSize)
            throw std::out_of_range("Remove: index " + std::to_string(index) + " is out of range");

        Node* toDelete = nullptr;
        if (index == 0) {
            toDelete = head;
            head = head->next;
            if (head == nullptr) tail = nullptr;
        } else {
            Node* current = head;
            for (int i = 0; i < index - 1; ++i)
                current = current->next;
            toDelete = current->next;
            current->next = toDelete->next;
            if (toDelete->next == nullptr) tail = current;
        }
        delete toDelete;
        listSize--;
    }

    T get(int index) const {
        if (index < 0 || index >= (int)listSize)
            throw std::out_of_range("Get: index " + std::to_string(index) + " is out of range");

        Node* current = head;
        for (int i = 0; i < index; ++i)
            current = current->next;
        return current->data;
    }

    size_t length() const { return listSize; }

    ~MyLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};