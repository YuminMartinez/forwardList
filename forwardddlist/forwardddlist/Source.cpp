
#include "ForwardList.h"

// Test function to demonstrate all functionality
int main() {
    std::cout << "=== ForwardList Implementation Test ===" << std::endl;
    std::cout << std::endl;

    // Test 1: Constructor and basic operations
    std::cout << "Test 1: Constructor and basic operations" << std::endl;
    ForwardList list1;
    std::cout << "Empty list: " << list1 << std::endl;
   
    if (list1.IsEmpty()) {
        std::cout << "Is empty: Yes" << std::endl;
    }
    else {
        std::cout << "Is empty: No" << std::endl;
    }
    std::cout << "Size: " << list1.Size() << std::endl;
    std::cout << std::endl;

    // Test 2: PushBack and PushFront
    std::cout << "Test 2: PushBack and PushFront" << std::endl;
    list1.PushBack(10);
    list1.PushBack(20);
    list1.PushBack(30);
    std::cout << "After PushBack(10, 20, 30): " << list1 << std::endl;

    list1.PushFront(5);
    list1.PushFront(1);
    std::cout << "After PushFront(5, 1): " << list1 << std::endl;
    std::cout << "Size: " << list1.Size() << std::endl;
    std::cout << "Front: " << list1.Front() << std::endl;
    std::cout << "Back: " << list1.Back() << std::endl;
    std::cout << std::endl;

    // Test 3: PopFront and PopBack
    std::cout << "Test 3: PopFront and PopBack" << std::endl;
    list1.PopFront();
    std::cout << "After PopFront(): " << list1 << std::endl;

    list1.PopBack();
    std::cout << "After PopBack(): " << list1 << std::endl;
    std::cout << "Size: " << list1.Size() << std::endl;
    std::cout << std::endl;

    // Test 4: Insert at different positions
    std::cout << "Test 4: Insert at different positions" << std::endl;
    std::cout << "Current list: " << list1 << std::endl;

    list1.Insert(100, 0);  // Insert at beginning
    std::cout << "After Insert(100, 0): " << list1 << std::endl;

    list1.Insert(200, 2);  // Insert in middle
    std::cout << "After Insert(200, 2): " << list1 << std::endl;

    list1.Insert(300, list1.Size());  // Insert at end
    std::cout << "After Insert(300, end): " << list1 << std::endl;
    std::cout << std::endl;

    // Test 5: Erase elements
    std::cout << "Test 5: Erase elements" << std::endl;
    list1.PushBack(20);
    list1.PushBack(20);
    list1.PushFront(20);
    std::cout << "After adding more 20s: " << list1 << std::endl;

    list1.Erase(20);
    std::cout << "After Erase(20): " << list1 << std::endl;
    std::cout << std::endl;

    // Test 6: PushBackAverageNode
    std::cout << "Test 6: PushBackAverageNode" << std::endl;
    ForwardList list2;
    list2.PushBack(10);
    list2.PushBack(20);
    list2.PushBack(30);
    list2.PushBack(40);
    std::cout << "List before average: " << list2 << std::endl;

    list2.PushBackAverageNode();
    std::cout << "After PushBackAverageNode(): " << list2 << std::endl;
    std::cout << "Average was: " << (10 + 20 + 30 + 40) / 4 << std::endl;
    std::cout << std::endl;

    // Test 7: Operator == (equality)
    std::cout << "Test 7: Operator == (equality)" << std::endl;
    ForwardList list3, list4;

    list3.PushBack(1);
    list3.PushBack(2);
    list3.PushBack(3);

    list4.PushBack(1);
    list4.PushBack(2);
    list4.PushBack(3);

    std::cout << "List3: " << list3 << std::endl;
    std::cout << "List4: " << list4 << std::endl;
    std::cout << "Are equal: ";
    if (list3 == list4) {
        std::cout << "Yes";
    }
    else {
        std::cout << "No";
    }
    std::cout << std::endl;

    list4.PushBack(4);
    std::cout << "After adding 4 to list4: " << list4 << std::endl;
    std::cout << "Are equal: ";
    if (list3 == list4) {
        std::cout << "Yes";
    }
    else {
        std::cout << "No";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    // Test 8: Operator + (concatenation)
    std::cout << "Test 8: Operator + (concatenation)" << std::endl;
    ForwardList list5, list6;

    list5.PushBack(1);
    list5.PushBack(2);

    list6.PushBack(3);
    list6.PushBack(4);
    list6.PushBack(5);

    std::cout << "List5: " << list5 << std::endl;
    std::cout << "List6: " << list6 << std::endl;

    ForwardList list7 = list5 + list6;
    std::cout << "List5 + List6: " << list7 << std::endl;
    std::cout << std::endl;

    // Test 9: Edge cases
    std::cout << "Test 9: Edge cases" << std::endl;
    ForwardList emptyList;

    std::cout << "Empty list operations:" << std::endl;
    emptyList.PopFront();  // Should handle gracefully
    emptyList.PopBack();   // Should handle gracefully
    std::cout << "Empty list after pop operations: " << emptyList << std::endl;

    // Test single element operations
    ForwardList singleList;
    singleList.PushBack(42);
    std::cout << "Single element list: " << singleList << std::endl;

    singleList.PopBack();
    std::cout << "After PopBack on single element: " << singleList << std::endl;
    std::cout << "Is empty: ";
    if (singleList.IsEmpty()) {
        std::cout << "Yes";
    }
    else {
        std::cout << "No";
    }
    std::cout << std::endl;
  

    // Test 10: Large operations
    std::cout << "Test 10: Large operations" << std::endl;
    ForwardList largeList;

    // Add many elements
    for (int i = 1; i <= 10; i++) {
        largeList.PushBack(i);
    }
    std::cout << "Large list (1-10): " << largeList << std::endl;

    // Remove some elements
    largeList.Erase(5);
    largeList.Erase(1);
    largeList.Erase(10);
    std::cout << "After erasing 1, 5, 10: " << largeList << std::endl;

    std::cout << std::endl;
    std::cout << "=== All tests completed successfully! ===" << std::endl;

    return 0;
}