#pragma once
#include "HeadFiles.h"

#undef CATCH_CONFIG_FALLBACK_STRINGIFIER
#define CATCH_CONFIG_FALLBACK_STRINGIFIER(value) transListNode2Str(value)

#include <catch2/catch_all.hpp>

class IsEqualListNode : public Catch::Matchers::MatcherBase<ListNode> {
public:
    IsEqualListNode(ListNode& ListNodeParam) : m_listNode(ListNodeParam) {}
    bool match(ListNode const& Arg) const override {
        const ListNode* LeftPtr = &Arg;
        const ListNode* RightPtr = &m_listNode;
        while(LeftPtr != nullptr && RightPtr != nullptr) {
            if(LeftPtr->val != RightPtr->val) {
                return false;
            }
            LeftPtr = LeftPtr->next;
            RightPtr = RightPtr->next;
        }
        if(LeftPtr != nullptr || RightPtr != nullptr) {
            return false;
        }
        return true;
    }

    virtual std::string describe() const override {
        std::string LeftValue = transListNode2Str(m_listNode);
        LeftValue = "\nThe ListNode mismatching\n" + LeftValue;
        return LeftValue;
    }

private:
    const ListNode& m_listNode;
};
