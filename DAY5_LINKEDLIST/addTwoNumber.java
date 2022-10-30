/*
 * Add two numbers represented as Linked Lists
 * ?Problem Statement: Given the heads of two non-empty linked lists
 * representing two non-negative integers. The digits are stored in reverse
 * order, and each of their nodes contains a single digit. Add the two numbers
 * and return the sum as a linked list.
 *
 * Examples:
 *
 * ?Input Format:
 * (Pointer/Access to the head of the two linked lists)
 *
 * ?num1 = 243, num2 = 564
 *
 * ?l1 = [2,4,3]
 * ?l2 = [5,6,4]
 *
 * ?Result: sum = 807; L = [7,0,8]
 *
 * ?Explanation: Since the digits are stored in reverse order, reverse the
 * numbers first to get the or original number and then add them as → 342 + 465
 * = 807. Refer to the image below.
 */
class AddTwoLinkedList {
    public static class Node {
        Node next;
        int data;
    }

    public static class LinkedList {
        Node head;
        Node tail;
        int size;

        public void printLists(Node head) {
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

        public Node addTwoLinkedList(Node l1, Node l2) {
            Node dummy = new Node();
            Node temp = dummy;

            int carry = 0;
            while (l1 != null || l2 != null || carry == 1) {
                int sum = 0;

                if (l1 != null) {
                    sum += l1.data;
                    l1 = l1.next;
                }

                if (l2 != null) {
                    sum += l2.data;
                    l2 = l2.next;
                }
                sum += carry;

                carry = sum / 10;

                Node node = new Node();
                node.data = sum % 10;
                temp.next = node;
                temp = temp.next;
            }
            return dummy.next;
        }
    }

    public static void main(String[] args) {
        LinkedList l1 = new LinkedList();
        l1.addLast(9);
        l1.addLast(9);
        l1.printLists(l1.head);
        LinkedList l2 = new LinkedList();
        l2.addLast(9);
        l2.printLists(l2.head);
        LinkedList result = new LinkedList();
        Node res = result.addTwoLinkedList(l1.head, l2.head);
        result.printLists(res);
    }
}
/*
 * Time Complexity: O(max(m,n)). Assume that m and n represent the length of l1
 * and l2 respectively, the algorithm above iterates at most max(m,n) times.
 *
 * Space Complexity: O(max(m,n)). The length of the new list is at most
 * max(m,n)+1
 */