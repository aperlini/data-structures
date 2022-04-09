class Node :
    def __init__(self, value):
        self.value = value
        self.next = None

class LinkedList :

    # to be implemented
    # 
    # - count_nodes(head) : int
    # - print_nodes(head) : void
    # - insert_top(head, node_to_insert) : Node
    # - insert_bottom(head, node_to_insert) : void
    # - insert_after(head, value, node_to_insert) : void
    # - insert_before(head, value, node_to_insert) : void
    # - insert(from_node, to_node)
    # - find(head, value) : Node
    # - predecessor(head, value) : Node
    # - delete_last(head) : void
    # - delete_first(head) : Node
    # - delete_node(head, value) : void

    @classmethod
    def get_class_name(cls):
        return cls.__name__
        

if __name__=='__main__':
    ll = LinkedList()
    print(ll.get_class_name())

