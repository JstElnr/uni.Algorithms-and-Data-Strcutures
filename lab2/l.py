class Node:
    def __init__(self, data):
        self.data =data
        self.next =None
def findMaxSum(head):
    max_sum =head.data
    curr_sum =head.data
    node = head.next
    while node:
        curr_sum =max(node.data, curr_sum + node.data)
        max_sum =max(max_sum, curr_sum)
        node =node.next
    return max_sum
if __name__=="__main__":
    n=int(input())
    arr=list(map(int, input().split()))
    head=Node(arr[0])
    curr=head
    for x in arr[1:]:
        curr.next = Node(x)
        curr=curr.next
    print(findMaxSum(head))