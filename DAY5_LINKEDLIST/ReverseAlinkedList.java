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

    public static Node head;

    public static class Node {

        int data;
        Node next;

        Node(int d) {
            data = d;
            next = null;
        }
    }

    /* Function to reverse the linked list */
    public static Node reverse(Node node) {
        Node prev = null;
        Node current = node;
        Node next = null;
        while (current != null) {
            next = current.next;
            current.next = prev;
            prev = current;
            current = next;
        }
        node = prev;
        return node;
    }

    // prints content of double linked list
    public static void printList(Node node) {
        while (node != null) {
            System.out.print(node.data + " ");
            node = node.next;
        }
    }

    // Driver Code
    public static void main(String[] args) {
        // ReverseLinkedList list = new ReverseLinkedList();
        ReverseLinkedList.head = new Node(85);
        ReverseLinkedList.head.next = new Node(15);
        ReverseLinkedList.head.next.next = new Node(4);
        ReverseLinkedList.head.next.next.next = new Node(20);

        System.out.println("Given linked list");
        ReverseLinkedList.printList(head);
        head = ReverseLinkedList.reverse(head);
        System.out.println("");
        System.out.println("Reversed linked list ");
        ReverseLinkedList.printList(head);
    }
}
// TC - O(N)
// SC - O(1)

/*
 * Reverse Linked List: Iterative
 * We will use three-pointers to traverse through the entire list and
 * interchange links between nodes. One pointer to keep track of the current
 * node in the list. The second one is to keep track of the previous node to the
 * current node and change links. Lastly, a pointer to keep track of nodes in
 * front of current nodes.
 *
 *
 * STEP 1:
 *
 * currrent_p is a pointer to keep track of current nodes. Set it to head.
 * prev_p is a pointer to keep track of previous nodes. Set it to NULL.
 * next_p is a pointer to keep track of the next nodes.
 * STEP 2:
 *
 * Set next_p to point next node to node pointed by current_p.
 * Change link between nodes pointed by current_p and prev_p.
 * Update prev_p to current_p and current_p pointer to next_p.
 * Perform STEP 2 until current_p reaches the end of the list.
 *
 * STEP 3:
 *
 * Set head as prev_p. This makes the head point at the last node.
 * !https://takeuforward.org/data-structure/reverse-a-linked-list/
 * https://www.geeksforgeeks.org/reverse-a-linked-list/
 */
