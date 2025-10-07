class SinglyLinkedListNode:
    def __init__(self,node_data):
        self.data=node_data
        self.next=None
class SinglyLinkedList:
    def __init__(self):
        self.head=None
        self.tail=None

    def insert_node(self,node_data):
        node = SinglyLinkedListNode(node_data)
        if not self.head:
            self.head=node
        else:
            self.tail.next=node
        self.tail=node
def print_linked_list(node):
    while node:
        print(node.data,end=" ")
        node = node.next
def insertNodeAtPosition(head,data,position):
    new_node = SinglyLinkedListNode(data)
    if position == 0:
        new_node.next = head
        return new_node
    current=head
    for _ in range(position-1):
        current = current.next
    new_node.next=current.next
    current.next=new_node

    return head


if __name__ == '__main__':
    n = int(input().strip())
    llist = SinglyLinkedList()

    for _ in range(n):
        llist_item = int(input().strip())
        llist.insert_node(llist_item)

    data = int(input().strip())
    position = int(input().strip())

    llist_head = insertNodeAtPosition(llist.head, data, position)
    print_linked_list(llist_head)