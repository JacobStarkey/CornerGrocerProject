import re
import string
from typing import ItemsView


def printsomething():
    print("Hello from python!")

def PrintMe(v):
    print("You sent me: " + v)
    return 100;

def SquareValue(v):
    return v * v

def ListItemsAndAmount():
    # Open the file in read mode
    purchased_items = open(r"PythonModules\PythonTextFile.txt", "r")
  
    #Creates a dictionary to hold the items and the number of times each one was purchased
    items = dict()
  
    for line in purchased_items:
        line = line.strip()             # Remove the leading spaces and newline character
        line = line.title()            
        words = line.split(" ")
  
        # Iterate over each word in line
        for word in words:
            if word in items:                   # Check if the word is already in dictionary
                items[word] = items[word] + 1
            else:
                items[word] = 1
    purchased_items.close()
  
    # Print the contents of dictionary
    for key in list(items.keys()):
        print(" ", key, " ", items[key])


    # Returns the number of times an item was purchased
def FrequencyOfItem(userItem):

    purchased_items = open(r"PythonModules\PythonTextFile.txt", "r")
    
    items = dict()
    for line in purchased_items:
        line = line.strip()
        line = line.title(); 
        words = line.split(" ")
        for word in words:
            if word in items:
                items[word] = items[word] + 1
            else:
                items[word] = 1
    purchased_items.close()
    
    return items[userItem]


def CreateHistogramFile():

    # Creates a dictionary to holds all of the pairs
    purchased_items = open(r"PythonModules\PythonTextFile.txt", "r")
    
    items = dict()
    for line in purchased_items:
        line = line.strip()
        line = line.title()
        words = line.split(" ")
        for word in words:
            if word in items:
                items[word] = items[word] + 1
            else:
                items[word] = 1
    purchased_items.close()

    # Opens the frequency file and writes all of the paird in the dictionary
    with open(r"PythonModules\frequency.dat", 'w') as f: 
        for key, value in items.items(): 
            f.write('%s %s\n' % (key, value))

def DrawHistogram():

   # Recreates the dictionary to call from in order to draw the histogram
    purchased_items = open(r"PythonModules\PythonTextFile.txt", "r")

    items = dict()
    for line in purchased_items:
        line = line.strip()
        line = line.title()
        words = line.split(" ")
        for word in words:
            if word in items:
                items[word] = items[word] + 1
            else:
                items[word] = 1
    purchased_items.close()
    
    for key in list(items.keys()):
        print(" ", key, " ", "*" * int(items[key]))



