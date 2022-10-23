# CPSC4310 Assignment #2 Question 3
# By Vincent Cote

from nltk.corpus import brown
from nltk.util import ngrams
from random import shuffle

def genBigram(bigram, bigram_list):
    str = ""
    while True:
        w = bigram[1]
        if w != '</s>':
            str = str + " " + w
            for i in range(len(bigram_list)):
                if bigram_list[i][0] == w:
                    bigram = bigram_list[i]
                    bigram_list.pop(i)
                    break
        else:
            return str

def genTrigram(trigram, trigram_list):
    str = ""
    while True:
        w1 = trigram[1]
        w2 = trigram[2]
        if w2 != '</s>':
            str = str + " " + w2
            for i in range(len(trigram_list)):
                if trigram_list[i][0] == w1 and trigram_list[i][1] == w2:
                    trigram = trigram_list[i]
                    trigram_list.pop(i)
                    break
        else:
            return str

cat = brown.categories()
str = "Please choose a category:\n"
for i in range(len(cat)):
    str = str + format(i) + ")" + cat[i] + '\n'

while True:
    catChoice = input(str)
    if int(catChoice) >= 0 and int(catChoice) < len(cat):
        break
while True:
    mode = input('Please choose a mode:\n0)Bigram\n1)Trigram\n')
    if mode == '0' or mode == '1':
        break

sentences = brown.sents(categories=cat[int(catChoice)])
ngram_list = []
for sent in sentences:
    # Convert the sentences using bigram or trigram mode
    x = ngrams(sent, 2 if mode == '0' else 3, True, True, '<s>', '</s>')
    for i in x:
        ngram_list.append(i)

# Shuffle the list to randomize the sentences
shuffle(ngram_list)
if mode == '0':
    for i in range(len(ngram_list)):
        if ngram_list[i][0] == '<s>':
            bigram = ngram_list[i]
            break
    print(genBigram(bigram, ngram_list))
else:
    for i in range(len(ngram_list)):
        if ngram_list[i][0] == '<s>' and ngram_list[i][1] == '<s>':
            trigram = ngram_list[i]
            break
    print(genTrigram(trigram, ngram_list))
