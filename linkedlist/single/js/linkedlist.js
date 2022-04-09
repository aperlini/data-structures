class Node {
    constructor(value) {
        this.value = value;
        this.next = null;
    }
}

class LinkedList {

    countNodes(head) {
        let current = head,
            count = 0;
        while (current != null) {
            count++;
            current = current.next;
        }
        return count;
    }

    printNodes(head) {
        let current = head,
            nodes = [];
        while (current != null) {
            nodes.push(current.value);
            current = current.next;
        }
        this.print(nodes.join(' -> '));
    }

    find(head, value) {
        let current = head;
        while (current.value != value) {
            current = current.next;
        }
        return current;
    }

    deleteFirst(head) {
        let newHead = head.next;
        return newHead;
    }

    deleteLast(head) {
        let current = head;
        while (current.next.next != null) {
            current = current.next;
        }
        current.next = null;
    }

    deleteNode(head, value) {
        let p = this.predecessor(head, value);
        let d = this.find(head, value);
        p.next = d.next;
    }

    insertBottom(head, nodeToInsert) {
        let current = head;
        while (current.next != null) {
            current = current.next;
        }
        current.next = nodeToInsert;
    }

    insertTop(head, nodeToInsert) {
        nodeToInsert.next = head;
        return nodeToInsert;
    }

    insert(from_node, toNode) {
        from_node.next = toNode;
    }

    insertAfter(head, value, nodeToInsert) {
        let s = this.find(head, value);
        nodeToInsert.next = s.next;
        this.insert(s, nodeToInsert);
    }

    insertBefore(head, value, nodeToInsert) {
        let p = this.predecessor(head, value);
        nodeToInsert.next = p.next;
        this.insert(p, nodeToInsert)
    }

    predecessor(head, value) {
        let current = head;
        while (current.next.value != value) {
            current = current.next;
        }
        return current;
    }

    print(o) {
        console.log(o);
    }
}

const ll = new LinkedList();
let head = new Node(23);
head = ll.insertTop(head, new Node(32));
head = ll.insertTop(head, new Node(42));
head = ll.insertTop(head, new Node(24));
head = ll.insertTop(head, new Node(99));
head = ll.insertTop(head, new Node(101));
head = ll.insertTop(head, new Node(45));

ll.countNodes(head);

ll.printNodes(head);

let twentythree = ll.find(head, 23);
ll.print(twentythree);

let p42 = ll.predecessor(head, 42);
ll.print(p42);

head = ll.deleteFirst(head);
ll.printNodes(head);

ll.deleteLast(head);
ll.printNodes(head);

ll.deleteNode(head, 24);
ll.printNodes(head);

ll.insertBottom(head, new Node(123));
ll.printNodes(head);

ll.insertAfter(head, 42, new Node(234));
ll.printNodes(head);

ll.insertAfter(head, 99, new Node(345));
ll.printNodes(head);

ll.insertBefore(head, 345, new Node(22));
ll.printNodes(head);

// ll.print(head.next);