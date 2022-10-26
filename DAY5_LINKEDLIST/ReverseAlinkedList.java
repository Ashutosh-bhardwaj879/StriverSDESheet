/*
 * Reverse a Linked List
?Problem Statement: Given the head of a singly linked list, write a program to reverse the linked list, and return the head pointer to the reversed list.

!Examples:

!Input Format:
!head = [3,6,8,10]
!This means the given linked list is 3->6->8->10 with head pointer at node 3.

!Result:
!Output = [10,6,8,3]
!This means, after reversal, the list should be 10->6->8->3 with the head pointer at node 10.
 */

//  * Definition for singly-linked list.
class ReverseLinkedList {
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

        public void removeFirst() {
            if (size == 0) {
                System.out.println("linkedlist is empty");
            } else if (size == 1) {
                head = tail = null;
                size = 0;
            } else {
                head = head.next;
                size--;
            }
        }

        public void reversePI() {
            Node prev = null;
            Node current = head;

            while (current != null) {
                Node upcoming = current.next;
                current.next = prev;
                prev = current;
                current = upcoming;
            }
            Node temp = head;
            head = tail;
            tail = temp;
        }
    }

    public static void main(String[] args) {
        LinkedList l = new LinkedList();
        l.addFirst(1);
        l.addFirst(2);
        l.addFirst(3);
        l.addFirst(4);
        l.printList();
        l.reversePI();
        l.printList();
    }
}