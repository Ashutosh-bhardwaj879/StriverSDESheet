/*
 * Delete given node in a Linked List : O(1) approach
 * Problem Statement: Write a function to delete a node in a singly-linked list.
 * You will not be given access to the head of the list instead, you will be
 * given access to the node to be deleted directly. It is guaranteed that the
 * node to be deleted is not a tail node in the list.
 *
 * Examples:
 *
 * Example 1:
 * Input:
 * Linked list: [1,4,2,3]
 * Node = 2
 * Output:
 * Linked list: [1,4,3]
 * Explanation: Access is given to node 2. After deleting nodes, the linked list
 * will be modified to [1,4,3].
 *
 * Example 2:
 * Input:
 * Linked list: [1,2,3,4]
 * Node = 1
 * Output: Linked list: [2,3,4]
 * Explanation:
 * Access is given to node 1. After deleting nodes, the linked list will be
 * modified to [2,3,4].
 */

class DeleteGivenNode {
    public static class Node {
        Node next;
        int data;
    }

    public static class LinkedList {
        Node head;
        Node tail;
        int size;

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

        void printList() {
            Node temp = head;
            while (temp != null) {
                System.out.print(temp.data + " ");
                temp = temp.next;
            }
            System.out.println();
        }

        static Node getNode(Node head, int val) {
            if (head == null) {
                return null;
            }
            Node temp = head;
            while (temp.data != val) {
                temp = temp.next;
            }

            return temp;
        }

        static void deleteNode(Node returned) {
            if (returned == null) {
                return;
            }

            returned.data = returned.next.data;
            returned.next = returned.next.next;
        }
    }

    public static void main(String[] args) {
        LinkedList l1 = new LinkedList();
        l1.addLast(1);
        l1.addLast(2);
        l1.addLast(3);
        l1.addLast(4);
        l1.printList();
        Node returned = LinkedList.getNode(l1.head, 1);
        LinkedList.deleteNode(returned);
        l1.printList();
    }
}
