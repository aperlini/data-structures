class Node {
    constructor(value) {
        this.value = value;
        this.next = null;
    }
}

class LinkedList {
    /**
     * To be implemented : 
     * 
     * - countNodes(head) : int
     * - printNodes(head) : void
     * - insertTop(head, nodeToInsert) : Node
     * - insertBottom(head, nodeToInsert) : void
     * - insertAfter(head, value, nodeToInsert) : void
     * - insertBefore(head, value, nodeToInsert) : void
     * - insert(from_node, toNode)
     * - find(head, value) : Node
     * - predecessor(head, value) : Node
     * - deleteLast(head) : void
     * - deleteFirst(head) : Node
     * - deleteNode(head, value) : void
     * 
     */

    size() {
        return 42;
    }
}

const ll = new LinkedList();
console.log(ll.size());