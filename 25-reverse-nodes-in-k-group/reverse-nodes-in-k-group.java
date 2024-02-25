/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        
        int count = 0;

        ListNode curr = head;

        while((count < k) && (curr != null))
        {
            curr = curr.next;
            count++;
        }
        
        if(count < k)
            return head;
        
        count = 0;

        ListNode prev = null ; curr = head;

        while(count < k)
        {
            ListNode temp = curr.next;
            curr.next = prev;
            prev = curr;
            curr = temp;
            count++;
        }

        head.next = reverseKGroup(curr,k);

        return prev;
    }
}