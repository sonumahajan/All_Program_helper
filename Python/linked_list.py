#Structure for Node
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

#Class representing different methods of Linked List
class LinkedList:
    def __init__(self):
        self.head = None

    def display(self):
        if self.head == None:
            print('No elements in LinkedList to display')
        else:
            p = self.head
            while p.next != None:
                print(p.data, end='->')
                p = p.next
            print(p.data)

    def insertAtBeginning(self):
        data = input('Insert data into LinkedList:')
        new = Node(data)
        if self.head == None:
            self.head = new
        else:
            new.next = self.head
            self.head = new
        print('After inserting At Beginning:')
        self.display()

    def insertAtEnd(self):
        data = input('Insert data into LinkedList:')
        new = Node(data)
        if self.head == None:
            self.head = new
        else:
            p = self.head
            while p.next != None:
                p = p.next
            p.next = new
        print('After inserting At End:')
        self.display()

    def getLength(self):
        count = 0
        p = self.head
        while p != None:
            p = p.next
            count += 1
        return count

    def insertAtPosition(self):
        pos = int(input('Enter the position to insert:'))
        if self.head == None:
            self.insertAtBeginning()
        elif pos == 0:
            self.insertAtBeginning()
        elif pos == self.getLength()-1:
            self.insertAtEnd()
        else:
            data = input('Insert data into LinkedList:')
            new = Node(data)
            p = q = self.head
            count = 1
            while count != pos:
                p = p.next
                count += 1
            while q.next != p:
                q = q.next
            new.next = p
            q.next = new
        print('After inserting At Position:', pos)
        self.display()

    def deleteAtBeginning(self):
        if self.head == None:
            print('Nothing to delete')
        else:
            p = self.head
            self.head = self.head.next
            del p
        print('After deleting an element at Beginning:')
        self.display()

    def deleteAtEnd(self):
        if self.head == None:
            print('Nothing to delete')
        else:
            p = self.head
            while p.next.next:
                p = p.next
            q = p.next
            p.next = None
            del q
        print('After deleting an element at End:')
        self.display()

    def deleteAtPosition(self):
        print('Number of elements present:', self.getLength())
        pos = int(input('Enter the position you want to delete:'))
        if pos == 0:
            self.deleteAtBeginning()
        elif pos == self.getLength():
            self.deleteAtEnd()
        else:
            count = 1
            p = q = self.head
            while count != pos:
                count += 1
                p = p.next
            while q.next != p:
                q = q.next
            q.next = p.next
            p.next = None
            del p
        print('After deleting an element at Beginning:')
        self.display()


if __name__ == '__main__':
    ll = LinkedList()
    for i in range(5):
        ll.insertAtBeginning()
    for i in range(5):
        ll.insertAtEnd()
    ll.insertAtPosition()
    for i in range(5):
        ll.deleteAtBeginning()
    ll.deleteAtEnd()
    ll.deleteAtPosition()
