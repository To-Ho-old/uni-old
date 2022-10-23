from nltk.corpus import brown
from nltk.util import ngrams
from random import randint
from random import shuffle

def genSentence(trigram, trigram_list):
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

sentences = brown.sents(categories='science_fiction')
trigram_list = []
for sent in sentences:
    x = ngrams(sent, 3, True, True, '<s>', '</s>')
    for i in x:
        trigram_list.append(i)

shuffle(trigram_list)
for i in range(len(trigram_list)):
    if trigram_list[i][0] == '<s>' and trigram_list[i][1] == '<s>':
        trigram = trigram_list[i]
        break

print(genSentence(trigram, trigram_list))
