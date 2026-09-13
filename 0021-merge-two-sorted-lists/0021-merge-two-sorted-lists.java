class Solution {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {

        // Dummy node to make building the list easier
        ListNode dummy = new ListNode(0);

        ListNode current = dummy;

        // Compare both lists
        while (list1 != null && list2 != null) {

            if (list1.val <= list2.val) {
                current.next = list1;
                list1 = list1.next;
            } 
            else {
                current.next = list2;
                list2 = list2.next;
            }

            current = current.next;
        }

        // Add remaining nodes
        if (list1 != null) {
            current.next = list1;
        } 
        else {
            current.next = list2;
        }

        // Return actual head
        return dummy.next;
    }
}