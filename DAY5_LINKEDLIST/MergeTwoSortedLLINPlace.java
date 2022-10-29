/*
 * * Merge two sorted Linked Lists
*In this article, we will solve the most asked coding interview question: ” Merge two sorted Linked Lists “

?Problem Statement: Given two singly linked lists that are sorted in increasing order of node values, merge two sorted linked lists and return them as a sorted list. The list should be made by splicing together the nodes of the first two lists.

!Example 1:

!Input Format :
!l1 = {3,7,10}, l2 = {1,2,5,8,10}

!Output :
!{1,2,3,5,7,8,10,10}
*https://takeuforward.org/data-structure/merge-two-sorted-linked-lists/
 */
class MergeTwoSortedLLINPlace {
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

        Node mergeListInPlace(Node one, Node two) {

            if (one == null) {
                return two;
            }
            if (two == null) {
                return one;
            }
            if (one.data > two.data) {
                // swap l1 and l2
                Node temp = one;
                one = two;
                two = temp;
            }
            Node res = one;

            while (one != null && two != null) {
                Node tmp = null;
                while (one != null && one.data <= two.data) {
                    tmp = one;
                    one = one.next;
                }
                if (tmp != null) {
                    tmp.next = two;
                }
                Node temp = one;
                one = two;
                two = temp;

            }
            return res;
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
        LinkedList l1 = new LinkedList();
        l1.addLast(0);
        // l1.addLast(3);
        // l1.addLast(5);
        l1.printLists(l1.head);
        LinkedList l2 = new LinkedList();
        l2.addLast(1);
        l2.addLast(2);
        // l2.addLast(6);
        l2.printLists(l2.head);

        LinkedList res = new LinkedList();
        Node returned = res.mergeListInPlace(l1.head, l2.head);
        res.printLists(returned);
    }
}
/*
 * TC = O(N1+N2)
 * SC= O(1)
 */