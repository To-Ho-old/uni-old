# CPSC4310 Assignment #2 Question 4
# By Vincent Cote

from nltk.corpus import stopwords
from nltk.corpus import brown
from nltk.probability import FreqDist
# from nltk import NaiveBayesClassifier, classify
from random import shuffle
from math import floor

stop_words = set(stopwords.words('english'))
punctuation = set({'.', '!', '?', ';', ',', '\'\'', '(', ')', '``', '--', ':'})

def filter_text(word_list):
    new_list = []
    for w in word_list:
        if w.lower() not in stop_words and w not in punctuation:
            new_list.append(w)
    return new_list

documents = [(list(filter_text(brown.words(fileid))), category) for category in brown.categories() for fileid in brown.fileids(category)]

# fd = FreqDist(documents[0][0])
# print(fd['going'])


shuffle(documents)

training_set = documents[:350]
testing_set = documents[350:]

all_words = []
for doc in training_set:
    for word in doc[0]:
        all_words.append(word)
size_of_vocab = len(FreqDist(all_words))

categories_in_set = []
for i in range(len(training_set)):
    categories_in_set.append(training_set[i][1])
categories_in_set = FreqDist(categories_in_set)
# print(categories_in_set.most_common())

def test_document(test_doc):
    highest_prob = 0
    cat_guess = ""
    for category in brown.categories():
        p_of_c = categories_in_set[category] / len(training_set)
        p_of_d_given_c = 1
        for word in test_doc:
            p_of_d_given_c = p_of_d_given_c * p(word, category)
            print(p_of_d_given_c)
        print('p_of_c = ', p_of_d_given_c, ' and given_c = ', p_of_d_given_c)
        x = p_of_c * p_of_d_given_c
        print('x = ', x)
        if x > highest_prob:
            highest_prob = x
            cat_guess = category
    return cat_guess

def p(x,c):
    word_in_cat = 1
    total_words_in_cat = 0
    for sets in range(len(training_set)):
        if training_set[sets][1] == c:
            total_words_in_cat = total_words_in_cat + len(training_set[sets][0])
            temp = FreqDist(training_set[sets][0])
            word_in_cat = word_in_cat + temp[x]
    # print('word_in_cat = ', word_in_cat, ' total_words = ', total_words_in_cat, ' cat in set = ', categories_in_set[c])
    return word_in_cat / (total_words_in_cat + categories_in_set[c])

print(test_document(testing_set[0][0]))
print('actual ', testing_set[0][1])


# for x in range(len(training_set)):
#     # temp = FreqDist(training_set[x][0])
#     print(training_set[x][0])



# stop_words = set(stopwords.words('english'))
# punctuation = set({'.', '!', '?', ';', ',', '\'\'', '(', ')', '``', '--', ':'})
# # categories = brown.categories()

# def filter_text(word_list):
#     new_list = []
#     for w in word_list:
#         if w.lower() not in stop_words and w not in punctuation:
#             new_list.append(w)
#     return new_list

# documents = []
# for category in brown.categories():
#     types = FreqDist(filter_text(brown.words(categories=category)))
#     temp_list = [category]
#     temp_list.append(types)
#     documents.append(temp_list)

# all_words = FreqDist(filter_text(brown.words()))

# def p(feature, c):

# def filter_text(word_list):
#     new_list = []
#     for w in word_list:
#         if w.lower() not in stop_words and w not in punctuation:
#             new_list.append(w)
#     return new_list

# documents = []
# for category in brown.categories():
#     temp_list = []
#     for word in brown.words(categories=category):
#         if word.lower() not in stop_words and word not in punctuation:
#             temp_list.append(word)
#     documents.append((temp_list, category))



# documents = [(list(brown.words(fileid)), category) for category in brown.categories() for fileid in brown.fileids(category)]

# shuffle(documents)

# all_words = []
# for word in brown.words():
#     if word.lower() not in stop_words and word not in punctuation:
#         all_words.append(word.lower())

# all_words = FreqDist(all_words)

# word_features = list(all_words.keys())[:3000]

# def find_features(document):
#     words = set(document)
#     features = {}
#     for w in word_features:
#         features['contains(%s)' % w] = (w in words)
#     return features

# feature_set = [(find_features(doc), category) for (doc, category) in documents]

# training_set = feature_set[:2000]
# testing_set = feature_set[2000:]

# classifier = NaiveBayesClassifier.train(training_set)
# print('accuracy: ', (classify.accuracy(classifier, testing_set) * 100))
# classifier.show_most_informative_features(15)




# trainingData = []
# for category in brown.categories():
#     types = FreqDist(filter_text(brown.words(categories=category)))
#     temp_list = [category]
#     temp_list.append(types)
#     trainingData.append(temp_list)

# # for (x, y) in trainingData[0][1]:
# #     print(x + " " + y)

# print(trainingData[0][1])


# trainingData = []
# for cat in categories:
#     sentences = brown.sents(categories=cat)
#     # Only taking 70% of the sentences
#     for i in range(floor(len(sentences) * 0.7)):
#         temp_list = [cat]
#         temp_list.append(filter_text(sentences[i]))
#         trainingData.append(temp_list)

# print(trainingData[1])

