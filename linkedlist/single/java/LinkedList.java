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

    /**
     * insert new node on top
     * 
     * @param head
     * @param n
     */
    public static Node insertTop(Node head, Node n) {
        n.next = head;
        return n;
    }

    /**
     * insert new node at bottom
     * 
     * @param head
     * @param n
     */
    public static void insertBottom(Node head, Node n) {
        Node current = head;
        while (current.next != null) {
            current = current.next;
        }
        current.next = n;
    }

    /**
     * insert node after
     * 
     * @param head
     * @param value
     * @param newNode
     */
    public static void insertAfter(Node head, int value, Node newNode) {
        insert(find(head, value), newNode);
    }

    /**
     * insert node before
     * 
     * @param head
     * @param value
     * @param newNode
     */
    public static void insertBefore(Node head, int value, Node newNode) {
        insert(predecessor(head, value), newNode);
    }

    /**
     * node insertion
     * 
     * @param from
     * @param to
     */
    public static void insert(Node from, Node to) {
        to.next = from.next;
        from.next = to;
    }

    /**
     * find node with certain value
     * 
     * @param head
     * @param value
     * @return
     */
    public static Node find(Node head, int value) {
        Node current = head;
        while (current.value != value) {
            current = current.next;
        }
        return current;
    }

    /**
     * predecessor of a certain node
     * 
     * @param head
     * @param value
     * @return
     */
    public static Node predecessor(Node head, int value) {
        Node current = head;
        while (current.next.value != value) {
            current = current.next;
        }
        return current;
    }

    /**
     * last node deletion
     * 
     * @param head
     */
    public static void deleteLast(Node head) {
        Node current = head;
        while (current.next.next != null) {
            current = current.next;
        }
        current.next = null;
    }

    /**
     * first node deletion
     * 
     * @param head
     * @return
     */
    public static Node deleteFirst(Node head) {
        Node newHead = head.next;
        head = null;
        return newHead;
    }

    /**
     * delete node at certain position
     * 
     * @param head
     * @param value
     */
    public static void deleteNode(Node head, int value) {
        Node p = predecessor(head, value);
        Node s = find(head, value);
        p.next = s.next;
        s = null;
    }

    public static void main(String[] args) {
        Node head = new Node(4);
        head = insertTop(head, new Node(2));
        head = insertTop(head, new Node(3));
        head = insertTop(head, new Node(10));

        insertBottom(head, new Node(20));
        insertBottom(head, new Node(23));

        Node f = find(head, 23);
        println("found note : " + f.value);

        Node p = predecessor(head, 3);
        printf("predecessor of 3 is %s \n", p.value);

        insertAfter(head, 3, new Node(33));
        insertBefore(head, 20, new Node(45));
        insertBefore(head, 45, new Node(90));

        println(countNodes(head));
        printNodes(head);

        deleteLast(head);

        println(countNodes(head));
        printNodes(head);

        head = deleteFirst(head);

        println(countNodes(head));
        printNodes(head);

        deleteNode(head, 90);

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