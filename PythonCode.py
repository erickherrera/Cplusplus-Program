import re
import string
import os.path
from os import path

def CountAll():
    __location__ = os.path.realpath(os.path.join(os.getcwd(), os.path.dirname(__file__)))
    #Open the input file in read mode
    text = open(os.path.join(__location__, 'Grocery_Items_Input.txt'), "r")
    
    #Create an empty dictionary to store "found" words
    dictionary = dict()

    #Check each line of the input file
    for line in text:
        #remove any errant spaces and newline characters
        line = line.strip()

        #Convert characters to lowercase for better matching
        word = line.lower()
        
        #Check if the word is already in the dictionary
        if word in dictionary:
            #Increment number of times the word appears
            dictionary[word] = dictionary[word] + 1
        else:
            #If the word is not in the dictionary, add it w/ a value of 1
            dictionary[word] = 1

    for key in list (dictionary.keys()):
        print(key.capitalize(), ":", dictionary[key])
    #Close the opened files
    text.close()

def CountInstances(searchTerm):
    __location__ = os.path.realpath(os.path.join(os.getcwd(), os.path.dirname(__file__)))

    #Convert user-inputted search term to lowercase for better matching
    searchTerm = searchTerm.lower()

    #Open the file in read mode
    text = open(os.path.join(__location__, 'Grocery_Items_Input.txt'), "r")

    #Create variable to track how many times the search term has been "found"
    wordCount = 0

    #Check each line of the input file
    for line in text:
        #remove any errant spaces and newline characters
        line = line.strip()

        #Convert characters to lowercase for better matching
        word = line.lower()
        
        #Check if the found word is equal to the user's input
        if word == searchTerm:
            #Increment number of times the word appears
            wordCount += 1

    #Return the number of times the search term was found, as per specification
    return wordCount

    #Close opened file
    text.close()

def Histogram():
    __location__ = os.path.realpath(os.path.join(os.getcwd(), os.path.dirname(__file__)))
    #Open the file in read mode
    text = open(os.path.join(__location__, 'Grocery_Items_Input.txt'), "r")

    #Create a file to write the frequency
    frequency = open(os.path.join(__location__,"frequency.dat"), "w")

    #Create a dictionary to store the words
    dictionary = dict()

    #Check each line of the input file
    for line in text:
        #Remove any white space from each word
        line = line.strip()
        #Convert character to lower case for better matching
        word = line.lower()
        #Check if the word is already on the dictionary
        if word in dictionary:
            dictionary[word] = dictionary[word] + 1
        else:
            dictionary[word] = 1

    #Write each key and value pair into the frequency.dat file
    for key in list(dictionary.keys()): 
        frequency.write(str(key.capitalize()) + " " + str(dictionary[key]))

    #Close both text and frequency files
    text.close()
    frequency.close
