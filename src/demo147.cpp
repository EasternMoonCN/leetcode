#include "utils/link.h"

/**
 * 插入排序：
 *  分为已排序区域（head——》lastsorted），待排序区域（cur——〉），每次从待排序取出一个基准位置（cur），放到已排序区域合适位置
 */
class Solution
{
public:
    ListNode *insertionSortList(ListNode *head)
    {
        ListNode *dummy = new ListNode(0, head), *lastSorted = head, *cur = head->next, *prev = nullptr;
        while (cur)
        {
            if (lastSorted->val > cur->val)
            {
                prev = dummy;
                while (prev->next && prev->next->val < cur->val) {
                    prev = prev->next;
                }
                lastSorted->next = cur->next;
                cur->next = prev->next;
                prev->next = cur;
            } else {
                lastSorted = lastSorted->next;
                
            }
            // 下一个基准位置，且断开原先的连接
            cur = lastSorted->next;
        }
        return dummy->next;
    }
};

int main()
{
    ListNode *head = new ListNode(4, new ListNode(2, new ListNode(1, new ListNode(3))));
    Solution().insertionSortList(head);
}