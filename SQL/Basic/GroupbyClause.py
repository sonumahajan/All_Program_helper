#problem
#Find the total number of customers from each country in the table (customer ID, customer name, country) using group by( python interface through MYSQL).

#solution
#creating table table through python interface
import mysql.connector
con=mysql.connector.connect(host="localhost",
                                 user="root",
                               password="kvrkscs20", 
                                database="company")
cur=con.cursor();
query="CREATE TABLE customer(cust_id int(3) Primary key,cust_name char(15), country char(15))"
cur.execute(query) 
con.commit()
print("Table created...")

#Inserting a record in to the table through python interface
import mysql.connector
con=mysql.connector.connect(host="localhost",
user="root",
password="kvhrkscs20", 
database="company")

 
cur=con.cursor();
c_i=int(input("Enter Customer Id: "))
c_n=input("Enter Customer Name: ")
c_c=input("Enter Customer Country: ")

query="Insert into customer values({},'{}','{}')".format(c_i,c_n,c_c)
cur.execute(query)
con.commit()
print("Row inserted...")

#Queries group by through python Interface
import mysql.connector
con=mysql.connector.connect( host= "localhost",
                              user="roots",
                              password="kvhrkses20", 
                              database="company")

#cur.execute( "select * from customer")
cur=con.cursor();
cur.execute("select country, count(country) from customer group by country ")
myresult=cur.fetchall()
for x in myresult:
  print(x)


