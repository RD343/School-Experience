COMPILER = c++  

DRIVER = Menu
FILE1 = Card
FILE2 = Deck
FILE3 = RPSTools

$(DRIVER) : $(DRIVER).o   #the first character on the next line is a tab 
	$(COMPILER) -o  $(DRIVER) $(DRIVER).o 

$(DRIVER).o :  $(DRIVER).cpp  $(FILE1).h $(FILE1).cpp $(FILE2).h $(FILE2).cpp $(FILE3).cpp
	$(COMPILER) -c  $(DRIVER).cpp

clean:
	 rm -f Menu.o
