COMPILER = c++  

DRIVER = main
FILE1 = LinkedList
FILE2 = Node

$(DRIVER) : $(DRIVER).o   #the first character on the next line is a tab 
	$(COMPILER) -o  $(DRIVER) $(DRIVER).o 

$(DRIVER).o :  $(DRIVER).cpp  $(FILE1).h $(FILE2).h
	$(COMPILER) -c  $(DRIVER).cpp   
	
clean:
	 rm -f main.o
