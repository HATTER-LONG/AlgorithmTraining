#include "Tools/ListNodeTools.h"

#include <glog/logging.h>

using namespace Catch;
using namespace std;

class MyLinkedList {
public:
    // struct ListNode
    // {
    //     int val;
    //     ListNode* next;
    //     ListNode()
    //             : val(0)
    //             , next(nullptr)
    //     {
    //     }
    //     ListNode(int x)
    //             : val(x)
    //             , next(nullptr)
    //     {
    //     }
    //     ListNode(int x, ListNode* next)
    //             : val(x)
    //             , next(next)
    //     {
    //     }
    // };
    MyLinkedList() : dummyhead(new ListNode(0)), size(0) {}

    int get(int index) {
        if(index < 0 || index > size - 1)
            return -1;
        ListNode* tmp = dummyhead->next;
        while(index--) {
            tmp = tmp->next;
        }
        return tmp->val;
    }

    void addAtHead(int val) {
        dummyhead->next = new ListNode(val, dummyhead->next);
        ++size;
    }

    void addAtTail(int val) {
        ListNode* tmp = dummyhead;
        while(tmp->next != nullptr)
            tmp = tmp->next;
        tmp->next = new ListNode(val);
        ++size;
    }

    void addAtIndex(int index, int val) {
        if(index < 0 || index > size)
            return;

        ListNode* tmp = dummyhead;

        while(index--) {
            tmp = tmp->next;
        }

        tmp->next = new ListNode(val, tmp->next);
        ++size;
    }

    void deleteAtIndex(int index) {
        if(index < 0 || index >= size)
            return;

        ListNode* cur = dummyhead;

        while(index--) {
            cur = cur->next;
        }

        ListNode* delNode = cur->next;
        cur->next = delNode->next;
        delete delNode;
        --size;
    }

    ListNode* dummyhead;
    int size;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

TEST_CASE("Check Solution MyLinkedList class all method work successfully") {
    MyLinkedList solution;
    solution.addAtHead(1);
    auto* left = solution.dummyhead;
    auto* right = initListNode(vector<int>{0, 1});
    checkListNode(left, right);
    REQUIRE(solution.size == 1);

    solution.addAtTail(3);
    left = solution.dummyhead;
    right = initListNode(vector<int>{0, 1, 3});
    checkListNode(left, right);
    REQUIRE(solution.size == 2);

    solution.addAtIndex(1, 2);
    left = solution.dummyhead;
    right = initListNode(vector<int>{0, 1, 2, 3});
    checkListNode(left, right);
    REQUIRE(solution.size == 3);

    REQUIRE(solution.get(1) == 2);

    solution.deleteAtIndex(1);
    left = solution.dummyhead;
    right = initListNode(vector<int>{0, 1, 3});
    checkListNode(left, right);
    REQUIRE(solution.size == 2);

    REQUIRE(solution.get(1) == 3);

    solution.deleteAtIndex(0);
    left = solution.dummyhead;
    right = initListNode(vector<int>{0, 3});
    checkListNode(left, right);
    REQUIRE(solution.size == 1);
}
