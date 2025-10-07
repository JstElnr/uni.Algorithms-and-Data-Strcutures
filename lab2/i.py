class Node:
    def __init__(self,data):
        self.data=data
        self.prev=None
        self.next=None
class DoublyLinkedList:
    def __init__(self):
        self.head=None
        self.tail=None
    def add_front(self,data):
        new=Node(data)
        if not self.head:
            self.head=self.tail=new
        else:
            new.next=self.head
            self.head.prev=new
            self.head=new
        print("ok")
    def add_back(self,data):
        new=Node(data)
        if not self.tail:
            self.head=self.tail=new
        else:
            self.tail.next=new
            new.prev=self.tail
            self.tail=new
        print("ok")
    def erase_front(self):
        if not self.head:
            print("error")
            return
        print(self.head.data)
        self.head=self.head.next
        if self.head:
            self.head.prev=None
        else:
            self.tail=None
    def erase_back(self):
        if not self.tail:
            print("error")
            return
        print(self.tail.data)
        self.tail=self.tail.prev
        if self.tail:
            self.tail.next=None
        else:
            self.head=None
    def front(self):
        if not self.head:
            print("error")
        else:
            print(self.head.data)
    def back(self):
        if not self.tail:
            print("error")
        else:
            print(self.tail.data)
    def clear(self):
        self.head=None
        self.tail=None
        print("ok")
dll=DoublyLinkedList()
while True:
    try:
        cmd=input().strip().split()
    except:
        break
    if not cmd:break
    if cmd[0]=="exit":
        print("goodbye")
        break
    elif cmd[0]=="add_front":
        dll.add_front(cmd[1])
    elif cmd[0]=="add_back":
        dll.add_back(cmd[1])
    elif cmd[0]=="erase_front":
        dll.erase_front()
    elif cmd[0]=="erase_back":
        dll.erase_back()
    elif cmd[0]=="front":
        dll.front()
    elif cmd[0]=="back":
        dll.back()
    elif cmd[0]=="clear":
        dll.clear()