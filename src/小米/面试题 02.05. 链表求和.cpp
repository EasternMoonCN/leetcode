#include "../utils/link.cpp"
/**
 * 给定两个用链表表示的整数，每个节点包含一个数位。

这些数位是反向存放的，也就是个位排在链表首部。

编写函数对这两个整数求和，并用链表形式返回结果。



示例：

输入：(7 -> 1 -> 6) + (5 -> 9 -> 2)，即617 + 295
输出：2 -> 1 -> 9，即912
进阶：思考一下，假设这些数位是正向存放的，又该如何解决呢?

示例：

输入：(6 -> 1 -> 7) + (2 -> 9 -> 5)，即617 + 295
输出：9 -> 1 -> 2，即912
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode(), *cur = dummy;
        int over = 0, val = 0, sum;
        while (l1 || l2)
        {
            sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + over;
            val = sum % 10;
            over = sum / 10;
            cur->next = new ListNode(val);
            cur = cur->next;
            if (l1)
            {
                l1 = l1->next;
            }

            if (l2)
            {
                l2 = l2->next;
            }
        }

        if (over)
        {
            cur->next = new ListNode(over);
        }

        return dummy->next;
    }
};