#include "ForwardList.h"
// Constructor
ForwardList::ForwardList() : m_first(nullptr), m_last(nullptr), m_size(0) {
}

// Destructor
ForwardList::~ForwardList() {
    while (!IsEmpty()) {
        PopFront();
    }
}

// Inserts one element at the back of the list
void ForwardList::PushBack(int value) {
    Node* newNode = new Node(value, nullptr);

    if (IsEmpty()) {
        m_first = m_last = newNode;
    }
    else {
        m_last->m_next = newNode;
        m_last = newNode;
    }
    m_size++;
}

// Removes last element at the back of the list
void ForwardList::PopBack() {
    if (IsEmpty()) {
        return;
    }

    if (m_size == 1) {
        delete m_first;
        m_first = m_last = nullptr;
    }
    else {
        // Find the second to last node
        Node* current = m_first;
        while (current->m_next != m_last) {
            current = current->m_next;
        }
        delete m_last;
        m_last = current;
        m_last->m_next = nullptr;
    }
    m_size--;
}

// Inserts one element at the front of the list
void ForwardList::PushFront(int value) {
    Node* newNode = new Node(value, m_first);

    if (IsEmpty()) {
        m_first = m_last = newNode;
    }
    else {
        m_first = newNode;
    }
    m_size++;
}

// Removes first element at the front of the list
void ForwardList::PopFront() {
    if (IsEmpty()) {
        return;
    }

    Node* temp = m_first;
    m_first = m_first->m_next;
    delete temp;

    if (m_first == nullptr) {
        m_last = nullptr;
    }
    m_size--;
}

// Checks if the list is empty or not
bool ForwardList::IsEmpty() const {
    return m_size == 0;
}

// Returns the element at the front of the list
int ForwardList::Front() const {
    if (IsEmpty()) {
        throw std::runtime_error("List is empty");
    }
    return m_first->m_value;
}

// Returns the element at the back of the list
int ForwardList::Back() const {
    if (IsEmpty()) {
        throw std::runtime_error("List is empty");
    }
    return m_last->m_value;
}

// Returns the size of the list
int ForwardList::Size() const {
    return m_size;
}

// Removes all the elements from the list that are equal to value
void ForwardList::Erase(int value) {
    while (m_first != nullptr && m_first->m_value == value) {
        PopFront();
    }

    if (IsEmpty()) {
        return;
    }

    Node* current = m_first;
    while (current->m_next != nullptr) {
        if (current->m_next->m_value == value) {
            Node* nodeToDelete = current->m_next;
            current->m_next = nodeToDelete->m_next;

            if (nodeToDelete == m_last) {
                m_last = current;
            }

            delete nodeToDelete;
            m_size--;
        }
        else {
            current = current->m_next;
        }
    }
}

// Inserts the element with value at a specific position within the list
void ForwardList::Insert(int value, int position) {
    if (position < 0 || position > m_size) {
        throw std::out_of_range("Position out of range");
    }

    if (position == 0) {
        PushFront(value);
        return;
    }

    if (position == m_size) {
        PushBack(value);
        return;
    }

    Node* current = m_first;
    for (int i = 0; i < position - 1; i++) {
        current = current->m_next;
    }

    Node* newNode = new Node(value, current->m_next);
    current->m_next = newNode;
    m_size++;
}

// Pushes back a new node whose value is the average of all the nodes values in the list
void ForwardList::PushBackAverageNode() {
    if (IsEmpty()) {
        return;
    }

    int sum = 0;
    Node* current = m_first;
    while (current != nullptr) {
        sum += current->m_value;
        current = current->m_next;
    }

    int average = sum / m_size;
    PushBack(average);
}

// Compares the content of lists l1 and l2. Returns true if both are equal, false otherwise.
bool operator==(const ForwardList& l1, const ForwardList& l2) {
    if (l1.m_size != l2.m_size) {
        return false;
    }

    ForwardList::Node* current1 = l1.m_first;
    ForwardList::Node* current2 = l2.m_first;

    while (current1 != nullptr && current2 != nullptr) {
        if (current1->m_value != current2->m_value) {
            return false;
        }
        current1 = current1->m_next;
        current2 = current2->m_next;
    }

    return true;
}

// Concatenates nodes with lists l1 and l2 and returns the resulting list.
ForwardList operator+(const ForwardList& l1, const ForwardList& l2) {
    ForwardList result;

    // Copy elements from l1
    ForwardList::Node* current = l1.m_first;
    while (current != nullptr) {
        result.PushBack(current->m_value);
        current = current->m_next;
    }

    // Copy elements from l2
    current = l2.m_first;
    while (current != nullptr) {
        result.PushBack(current->m_value);
        current = current->m_next;
    }

    return result;
}

// Outputs the elements of the list into an output stream object
std::ostream& operator<<(std::ostream& o, const ForwardList& l) {
    o << "[";
    ForwardList::Node* current = l.m_first;
    bool first = true;

    while (current != nullptr) {
        if (!first) {
            o << ", ";
        }
        o << current->m_value;
        current = current->m_next;
        first = false;
    }
    o << "]";

    return o;
}