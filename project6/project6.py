#!/usr/local/bin/python
import itertools

wordList = []
foundWordList = []
notFoundList = []

rowList = []
columnList = []
diagonalList = []

tempBDiagRow = []
tempFDiagRow = []

frontSpaceListF = []
backSpaceListF = []

frontSpaceListB = []
backSpaceListB = []

# rowColDiag: 0 = row, 1 = col, 2 = diagonal
def findWord(rowOrCol, rowColDiag, number) :
	rolColString = ""
	rowColString = "".join(rowOrCol)
	
	# Loop to find any word in row, column, or diagonal
	for word in wordList :
		if (word in rowColString) :
			if (rowColDiag == 0) :
				foundWordList.append(word + " at row " + str(number + 1))
			elif (rowColDiag == 1) :
				foundWordList.append(word + " at column " + str(number + 1))
			else :
				foundWordList.append(word + " at a diagonal")
			notFoundList.remove(word)

puzzleFile, puzzleFile1, puzzleFileFDiag, puzzleFileBDiag = itertools.tee(open('puzzle.txt', 'r'), 4)
wordFile = open('wordList.txt', 'r')

# Display the puzzle
for line in puzzleFile :
	print(line)

# Add words to wordList and notFoundList
for line in wordFile :
	wordString = line.split()
	wordList.append(wordString[0])
	notFoundList.append(wordString[0])
	
# Creates a list of rows and diagonals
for line in puzzleFile1 :
	rowList.append(line.split())

# Creates a list of columns
columnSize = len(rowList[0])
for i in range(columnSize) :
	# Extra credit if it can be done in a different way
	columnList.append([row[i] for row in rowList])

# Shifts the word puzzle slanting forward to line up diagonals
iterNum = 0
spaceLengthDiag = len(columnList[0]) - 1
for line in puzzleFileFDiag :
	# Add col - 1 spaces before the first line
	if (iterNum == 0) :
		for i in range(spaceLengthDiag) :
			frontSpaceListF.append(' ')
	# Remove one space from front and add one space to back
	elif (iterNum >= 1) :
		frontSpaceListF.remove(' ')
		backSpaceListF.append(' ')
		
	tempFDiagRow.append(frontSpaceListF + line.split() + backSpaceListF)
	iterNum = iterNum + 1

newColumnSize = columnSize + spaceLengthDiag
for i in range(newColumnSize) :
	diagonalList.append(list(diag[i] for diag in tempFDiagRow))
	
# Shifts the word puzzle slanting backward to line up diagonals
iterNum = 0
for line in puzzleFileFDiag :
	# Add col - 1 spaces after the first line
	if (iterNum == 0) :
		for i in range(spaceLengthDiag) :
			backSpaceListF.append(' ')
	# Remove one space from back and add one space to front
	elif (iterNum >= 1) :
		backSpaceListF.remove(' ')
		frontSpaceListF.append(' ')
	
	tempBDiagRow.append(frontSpaceListF + line.split() + backSpaceListF)
	iterNum = iterNum + 1

for i in range(newColumnSize) :
	diagonalList.append(list(diag[i] for diag in tempBDiagRow))
	
# Find words in the rows
for index, row in enumerate(rowList) :
	findWord(row, 0, index)

# Find words in the columns
for index, column in enumerate(columnList) :
	findWord(column, 1, index)

# Find words in the diagonal
for index, diagonal in enumerate(diagonalList) :
	findWord(diagonal, 2, index)

# Print out words that are found
print("Words found: ")
for foundWord in foundWordList :
	print(foundWord)

# Print out words that are not found
print("\nWords not found: ")
for notFoundWord in notFoundList :
	print(notFoundWord)