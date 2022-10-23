from nltk.corpus import brown
from nltk.util import ngrams
from random import randint
from random import shuffle

def genSentence(bigram, bigram_list):
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

sentences = brown.sents(categories='science_fiction')
bigram_list = []
for sent in sentences:
    x = ngrams(sent, 2, True, True, '<s>', '</s>')
    for i in x:
        bigram_list.append(i)

shuffle(bigram_list)
for i in range(len(bigram_list)):
    if bigram_list[i][0] == '<s>':
        bigram = bigram_list[i]
        break

print(genSentence(bigram, bigram_list))
