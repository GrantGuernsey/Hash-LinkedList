#ifndef LIST
#define LIST

#include <iostream>
using namespace std;

template <typename T>
class List{
private:
    /* NODE CLASS */
    class Node{
    public:
        T data;
        Node* prev;
        Node* next;

        Node(T data, Node* prev, Node* next = nullptr){
            this->data = data;
            this->prev = prev;
            this->next = next;
        }
    };

    /* ERROR CLASSES */
    class Empty{};
    class DNE{};

    /* LIST ATTRIBUTES */
    Node* head;
    int len, itr;

    /* LIST HELPERS */
    void clear(Node* cur){
        //Base Case
        if (cur == nullptr) return;

        //Recursion
        clear(cur->next);

        //Deletion
        if (cur != head) cur->prev->next = nullptr;
        else head = nullptr;
        delete cur;
    }

public:
    /* LIST CONSTRUCTOR AND DESTRUCTOR */
    List(){
        head = nullptr;
        len = 0;
        itr = 0;
    }
    ~List(){
        clear(head);
    }

    /* LIST UTILITY METHODS */
    bool isEmpty(){
        return (head == nullptr) && (len == 0);
    }
    int getLen(){
        return len;
    }
    int getCompCount(){
        return itr;
    }

    /* CONVERSION METHOD */
    void makeArray(T* arr){
        //Set-up
        int idx = 0;
        Node* cur = head;
    
        //Fill array
        while (cur != nullptr){
            arr[idx] = cur->data;
            cur = cur->next;
            idx += 1;
        }
    }

    /* LIST METHODS */
    void addItem(T data){
        //Empty list insertion
        if (head == nullptr){
            head = new Node(data, nullptr);
        }

        //Non-empty list insertion
        else{
            Node* cur = head;
            while (cur->next != nullptr && cur->data < data){
                cur = cur->next;
            }

            //Insert at head
            if (cur == head){
                head->prev = new Node(data, nullptr, head);
                head = head->prev;
            }

            //Insert at tail
            else if (cur->next == nullptr && cur->data < data){
                cur->next = new Node(data, cur);
            }

            //Insert elsewhere
            else{
                cur->prev->next = new Node(data, cur->prev, cur);
                cur->prev = cur->prev->next;
            }
        }

        len += 1;
    }
    bool contains(T trgt){
        //Search loop
        Node* cur = head;
        while (cur != nullptr && cur->data != trgt){
            cur = cur->next;
        }

        //Return
        if (cur == nullptr) return false;
        return true;
    }
    T getItem(T trgt){
        //Empty list handling
        if (isEmpty()) throw Empty();

        //Search loop
        Node* cur = head;
        while (cur != nullptr && cur->data != trgt){
            cur = cur->next;
            itr += 1;
        }

        //Return
        if (cur == nullptr) throw DNE();
        return cur->data;
    }
    T removeItem(T trgt){
        //Search loop
        Node* cur = head;
        while (cur != nullptr && cur->data != trgt){
            cur = cur->next;
        }

        //Not found
        if (cur == nullptr) throw DNE();

        //Deletion
        if (cur != head){
            cur->prev->next = cur->next;
            if (cur->next != nullptr) cur->next->prev = cur->prev;
        }
        else head = head->next;

        //Return
        T val = cur->data;
        len -= 1;
        delete cur;
        return val;
    }
};

#endif