/*
 * Find middle element in a Linked List
Problem Statement: Given the head of a singly linked list, return the middle node of the linked list. If there are two middle nodes, return the second middle node.

Examples:

Input Format:
( Pointer / Access to the head of a Linked list )
head = [1,2,3,4,5]

Result: [3,4,5]
( As we will return the middle of Linked list the further linked list will be still available )

Explanation: The middle node of the list is node 3 as in the below image.

Input Format:
Input: head = [1,2,3,4,5,6]

Result: [4,5,6]

Explanation:
Since the list has two middle nodes with values 3 and 4, we return the second one
 */
class MiddleOfLinkList {
    public static class Node {
        Node next;
        int data;
    }

    public static class LinkedList {
        int size;
        Node head;
        Node tail;

        public void printLists(Node head) {
            Node temp = head;
            while (temp != null) {
                System.out.print(temp.data + " ");
                temp = temp.next;
            }
            System.out.println();
        }

        public void addFirst(int val) {
            Node temp = new Node();
            temp.data = val;
            temp.next = head;
            head = temp;
            if (size == 0) {
                tail = temp;
            }
            size++;
        }

        public void printList() {
            if (head == null) {
                System.out.println("linkedlist is empty");
            }
            Node temp = head;
            while (temp != null) {
                System.out.print(temp.data + " ");
                temp = temp.next;
            }
            System.out.println();
        }

        public Node middleOfLinkList(Node head) {
            // we will first ocount the number of nodes
            Node temp = head;
            int count = 0;
            while (temp != null) {
                count++;
                temp = temp.next;
            }
            // pointing tetmp to head again
            temp = head;

            for (int i = 0; i < count / 2; i++) {
                temp = temp.next;
            }

            return temp;
        }
    }

    public static void main(String[] args) {
        LinkedList ll = new LinkedList();
        ll.addFirst(1);
        ll.addFirst(2);
        ll.addFirst(3);
        ll.addFirst(4);
        // ll.addFirst(5);
        ll.printLists(ll.head);
        Node returnedNode = ll.middleOfLinkList(ll.head);
        ll.printLists(returnedNode);
    }
}
/*
 * TC - O(N) + o(N/2)
 * sc - o(1)
 */
/*
 * https://takeuforward.org/data-structure/find-middle-element-in-a-linked-list/
 */