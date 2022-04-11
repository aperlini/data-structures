class Node :
    def __init__(self, value):
        self.value = value
        self.next = None

class LinkedList :

    def __init__(self):
        self.head = None

    def insert_top(self, node_to_insert : Node):
        node_to_insert.next = self.head
        self.head = node_to_insert

    def insert_bottom(self, node_to_insert : Node):
        current = self.head
        while current.next:
            current = current.next
        current.next = node_to_insert

    def insert_after(self, value : int, node_to_insert : Node): 
        after = self.find(value)
        self.insert(after, node_to_insert)

    def insert_before(self, value : int, node_to_insert : Node):
        p = self.predecessor(value)
        self.insert(p, node_to_insert)

    def insert(self, from_node : Node, to_node : Node):
        to_node.next = from_node.next
        from_node.next = to_node

    def find(self, value : int) -> Node:
        current = self.head
        while current.value != value:
            current = current.next
        return current

    def predecessor(self, value : int) -> Node:
        current = self.head
        while current.next.value != value:
            current = current.next
        return current

    def delete_first(self):
        old_head = self.head
        new_head = old_head.next
        self.head = new_head
        del old_head

    def delete_last(self):
        current = self.head
        while current.next.next:
            current = current.next
        del current.next.next
        current.next = None

    def delete_node(self, value : int):
        d = self.find(value)
        p = self.predecessor(value)
        p.next = d.next
        del d

    def print_nodes(self):
        current = self.head
        while current:
            print(f"{current.value} -> ", end=" ")
            current = current.next
        print("NULL")

    def count_nodes(self) -> int:
        current = self.head
        node_lth=0
        while current:
            node_lth += 1
            current = current.next
        return node_lth

    @classmethod
    def get_class_name(cls):
        return cls.__name__
        

if __name__=='__main__':

    ll = LinkedList()

    ll.insert_top(Node(23))
    ll.insert_top(Node(32))
    ll.insert_top(Node(24))
    ll.insert_top(Node(42))

    ll.print_nodes()
    print(ll.count_nodes())

    ll.insert_bottom(Node(191))

    print(ll.count_nodes())
    ll.print_nodes()

    search = ll.find(42)

    p = ll.predecessor(191)
    print(p.value)

    print(ll.count_nodes())    
    ll.delete_last()
    print(ll.count_nodes())    

    ll.print_nodes()
    ll.delete_first()
    ll.delete_first()
    ll.print_nodes()

    ll.insert_top(Node(101))
    ll.insert_top(Node(102))
    ll.insert_top(Node(103))
    ll.insert_top(Node(104))

    print(ll.count_nodes())
    ll.print_nodes()

    ll.delete_node(101)
    print(ll.count_nodes())
    ll.print_nodes()

    ll.insert_after(102, Node(123))
    ll.print_nodes()

    ll.insert_before(102, Node(321))
    ll.print_nodes()


