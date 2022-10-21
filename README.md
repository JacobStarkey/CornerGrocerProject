# CornerGrocerProject
  
  This program was made for Corner Grocer in order to analyze their records of the various items that are sold on any given day. The record contains a chronological list
of times that the store has sold during its hours of operation. The store wishes for the program to go through and give a list of all the items sold and the total
quantity sold for each item. As well as to be able to look up a particular item's quantity sold for that day, and lastly to be able to draw up a histogram to give a
visual representation of their sales for the day. In order to accomplish these tasks I had to first figure out a way to take the data that was given and sort through it
and keep track of everything to know how many were there for each item. In order to do this I created a section of code that would create a dictionary and read through
the given list line by line and check to see if the item was already in the dictionary. If the item was already in there then it would increment its quantity by one, if
it was not found then it would add it to the dictionary. This allowed me to pull any information that I would need from the dictionary. The only problem is that I did
not create its own definition to call or a designated dictionary to create once and then call upon from all of the other functions. Creating a separate definition to
call upon would have made everything more organized and easier to read since it wouldn’t all initially look the same and possibly would have helped everything run more
smoothly since it wouldn’t constantly be reading from the file and writing the dictionary. As far as what the most challenging part of the whole project was, it would
have been validating the user's input in C++ and making sure that when the user searched for an item their input would automatically be capitalized to match up with what
the item is in the dictionary. The main skill that I picked up from this project that will be valuable for other projects has to be the ability to work with two
programming languages at once and use Python to manage the files needed since Python works best with files and uses dictionaries. In order to keep the project
maintainable, along with leaving comments throughout, I made sure to keep all of the functions organized to try and reduce the amount of code that was in the main
function. By doing this I was able to break to project into sections so that they can be worked on individually without interfering with other sections of code.
