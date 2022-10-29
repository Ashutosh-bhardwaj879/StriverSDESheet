/*
*Remove N-th node from the end of a Linked List
*Problem Statement: Given a linked list, and a number N. Find the Nth node from the end of this linked list and delete it. Return the head of the new modified linked list.

?Example 1 :

?Input: head = [1,2,3,4,5], n = 2

?Output: [1,2,3,5]


?Example 3:

?Input: head = [1,2,3], n = 3

?Output: [2,3]
 */
class RemoveNthNode {
    public static class Node {
        Node next;
        int data;
    }

    public static class LinkedList {
        Node head;
        Node tail;
        int size;

        static void printLists(Node head) {
            Node temp = head;
            while (temp != null) {
                System.out.print(temp.data + " ");
                temp = temp.next;
            }
            System.out.println();
        }

        void addLast(int val) {
            Node temp = new Node();
            temp.data = val;
            temp.next = null;
            if (size == 0) {
                head = tail = temp;
            } else {
                tail.next = temp;
                tail = temp;
            }
            size++;
        }

        static Node removeNthNode(Node head, int n) {
            Node start = new Node();
            start.next = head;
            Node fast = start;
            Node slow = start;

            for (int i = 1; i <= n; ++i)
                fast = fast.next;

            while (fast.next != null) {
                fast = fast.next;
                slow = slow.next;
            }

            slow.next = slow.next.next;

            return start.next;
        }
    }

    public static void main(String[] args) {
        LinkedList l1 = new LinkedList();
        l1.addLast(1);
        l1.addLast(2);
        l1.addLast(3);
        l1.addLast(4);
        LinkedList.printLists(l1.head);
        Node returned = LinkedList.removeNthNode(l1.head, 4);
        LinkedList.printLists(returned);
    }
}
/*
 * Time Complexity: O(N)
 *
 * Space Complexity: O(1)
 */