class Liabrary:
    '''liabrary management system'''
    def __init__(self,name,book_list,dict1):
        self.name=name
        self.book_list=book_list
        self.dict=dict1
        for i in self.book_list:
            self.dict[i]=None

    def display_book(self):
       for i,j in enumerate(self.book_list):
           print(i+1,j)

    def lend_book(self,usrname,book_name):
        if self.dict[book_name]==None:
            print("You got the book")
            self.dict[book_name]=usrname
        else:
            print(f'book is own by {self.dict[book_name]}')
        return self.dict

    def add_book(self,book):
        self.book_list.append(book)
        self.dict[book]=None

    def return_book(self,usrname,book_name):
        if self.dict[book_name] != usrname:
            print("Book is not assign to anyone")
        else:
            print("successfully return the book")
            self.dict[book_name] = None


booklist=["math","Wings of fire","Panipath","Physics"]
dict12={}
f=Liabrary("rahul",booklist,dict12)
def main():
    while True:
        print("Enter your name")
        inp=str(input())
        print("Select foloowing option \n 1.Display Books \n 2.Lend Book \n 3.Add Book \n 4. Return book")
        option=int(input())
        if option == 1:
            f.display_book()
        elif option == 2:
            print("Enter book name you want to lend")
            a=str(input())
            if a in booklist:
                f.lend_book(inp,a)
            else:
                print("book is not available in library")
        elif option == 3:
            print("Enter a book name you want to add")
            a=str(input())
            if a not in booklist:
                f.add_book(a)
            else:
                print("Book is already available in library")

        elif option == 4:
            print("Enter book name you want to return")
            a = str(input())
            if a in booklist:
                f.return_book(inp,a)
            else:
                print("book is not available in library")
        else:
            exit()
main()
