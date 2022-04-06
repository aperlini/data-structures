class Node {
    public int value;
    public Node next;

    public Node(int value) {
        this.value = value;
    }

}

public class LinkedList {
    /**
     * Counting Nodes starting at head
     * 
     * @param head
     * @return
     */
    public static int countNodes(Node head) {
        Node current = head;
        int count = 0;
        while (current != null) {
            current = current.next;
            count += 1;
        }
        return count;
    }

    /**
     * Printing nodes
     * 
     * @param head
     */
    public static void printNodes(Node head) {
        Node current = head;
        while (current != null) {
            printf("%s -> ", current.value);
            current = current.next;
        }
        println("null");
    }

    public static void main(String[] args) {
        Node head = new Node(4);
        Node n2 = new Node(2);
        Node n3 = new Node(3);
        Node n4 = new Node(10);

        head.next = n2;
        n2.next = n3;
        n3.next = n4;
        println(countNodes(head));
        printNodes(head);
    }

    /**
     * Simple println shortcut
     * 
     * @param o
     */
    public static void println(Object o) {
        System.out.println(o);
    }

    /**
     * simple printf shortcut
     * 
     * @param format
     * @param o
     */
    public static void printf(String format, Object... o) {
        System.out.printf(format, o);
    }

}