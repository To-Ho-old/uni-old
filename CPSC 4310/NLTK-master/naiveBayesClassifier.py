# CPSC4310 Assignment #2 Question 4
# By Vincent Cote
from nltk.corpus import brown
from nltk import FreqDist
import nltk
from random import shuffle

# Split documents by id and save them in a list with the category
documents = [(list(brown.words(fileid)), category)
             for category in brown.categories()
             for fileid in brown.fileids(category)]
shuffle(documents)

# Take a set of 4000 words from the entire corpus
all_words = FreqDist(w.lower() for w in brown.words())
word_features = list(all_words)[:4000]

def document_features(document):
    document_words = set(document)
    features = {}
    for word in word_features:
        features['contains({})'.format(word)] = (word in document_words)
    return features

# Arrange the training set to be fed to the naive bayes classifier
featuresets = [(document_features(doc), category) for (doc,category) in documents]
training_set = featuresets[:350]
testing_set = featuresets[350:]
classifier = nltk.NaiveBayesClassifier.train(training_set)

# Test with known data to see how often it gets it right
correct = 0
for doc in testing_set:
    guess = classifier.classify(doc[0])
    actual = doc[1]
    print('Guess = ',guess, ' actual = ', actual)
    if guess == actual:
        correct += 1
print('correct guesses = ', correct, "/", len(testing_set))
