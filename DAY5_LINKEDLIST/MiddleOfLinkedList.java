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
class MiddleOfLinkedList {
    public static class Node {
        Node next;
        int data;
    }

    public static class LinkedList {
        Node head;
        Node tail;
        int size;

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

        public void addFirst(int value) {
            Node temp = new Node();
            temp.data = value;
            temp.next = head;
            head = temp;
            if (size == 0) {
                tail = temp;
            }
            size++;
        }

        public Node middleOfLinkedList(Node head) {
            Node fast = head;
            Node slow = head;

            while (fast != null && fast.next != null) {
                slow = slow.next;
                fast = fast.next.next;
            }
            return slow;
        }

        public void printLists(Node head) {
            Node temp = head;
            while (temp != null) {
                System.out.print(temp.data + " ");
                temp = temp.next;
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        LinkedList l = new LinkedList();
        l.addFirst(1);
        l.addFirst(2);
        l.addFirst(3);
        l.addFirst(4);
        l.printList();
        Node returnedHead = l.middleOfLinkedList(l.head);
        l.printLists(returnedHead);
    }
}

/*
 * TC - O(N/2)
 * SC - O(1)
 */
/*
 * TORTOISE METHOD
 */