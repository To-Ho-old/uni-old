#Tony Ho
#CPSC4310
#Assignment 3 Question 5
#Calculate cosine similarity with tf-idf
import nltk
#nltk.download('brown')
#nltk.download('stopwords')
from nltk.corpus import brown
from nltk.util import ngrams
from random import shuffle
from nltk.corpus import stopwords
from nltk.probability import FreqDist
import math
from nltk import word_tokenize
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.metrics.pairwise import cosine_similarity

print("Calculate cosine similarity within one or between two categories.")
print("Input two categories to calculate cosine similarity between two categories.")
print("Input the same number for bot categories to calculate cosine similarity within that category.\n")
print("Categories:")
cat = brown.categories()
for i in range(len(cat)):
    print(i, cat[i])

while True:
	cat1 = input("Category 1: ")
	if int(cat1) >= 0 and int(cat1) < len(cat):
		cat2 = input("Category 2: ")
		if int(cat2) >= 0 and int(cat2) < len(cat):
			break
docs = []
if(int(cat1) == int(cat2)):
	id = brown.fileids(categories = cat[int(cat1)])
	for i in id:
		docs.append(brown.words(fileids = [i]))
else:
	docs.append(brown.words(categories = cat[int(cat1)]))
	docs.append(brown.words(categories = cat[int(cat2)]))

print ("Calculating document(s) cosine similarity:")
N = len(docs)
all_words = ''
for d in docs:
    for w in d:
        all_words = all_words + ' ' + w

word_matrix = []
words = word_tokenize(all_words)
for i in FreqDist(words):
	word_matrix.append(i)

#Calculate tf
def tf_matrix(word_matrix, docs):
	tf_matrix = []
	for i in docs:
		doc_list = []
		doc_freqency = FreqDist(i)
		for w in word_matrix:
			count = doc_freqency[w]
			if count > 0:
				tf = 1 + math.log10(count)
			else:
				tf = 0
			doc_list.append(tf)
		tf_matrix.append(doc_list)
	return tf_matrix
	
#Calculate ifd
def idf_matrix(word_matrix, docs, N):
	idf_matrix = []
	doc_distance = []
	N += 0.0
	for d in docs:
		doc_distance.append(FreqDist(d))
	for w in word_matrix:
		df = 0
		for x in doc_distance:
			if x[w] > 0:
				df = df + 1
		if df  > 0:
			idf_matrix.append(math.log10(N/df))
	return idf_matrix
		
#Calculate w
def w_matrix(tf_matrix, idf_matrix):
	w_matrix = []
	for i in tf_matrix:
		w = []
		y = 0
		l = len(idf_matrix)
		while y < l:
			w.append(i[y] * idf_matrix[y])
			y = y + 1
		w_matrix.append(w)
	return w_matrix

idf = idf_matrix(word_matrix, docs, N)
tf = tf_matrix(word_matrix, docs)
w = w_matrix(tf, idf)
doc1 = 0;
doc2 = 1
doc1_w_matrix = w[doc1]
doc2_w_matrix = w[doc2]
vw_sum = 0.0
i = 0
v2 = 0.0
w2 = 0.0
doc1_l = len(doc1_w_matrix)
while i < doc1_l:
	vw_sum = vw_sum + (doc1_w_matrix[i] * doc2_w_matrix[i])
	v2 = v2 + (math.pow(doc1_w_matrix[i], 2))
	w2 = w2 + (math.pow(doc2_w_matrix[i], 2))
	i = i + 1
if v2 > 0 or w2 > 0:
	cosine = (vw_sum/(math.sqrt(v2) * math.sqrt(w2)))
else:
	cosine = 0

if(int(cat1) == int(cat2)):
	print("The cosine similarity of", cat[int(cat1)],":", cosine)
else:
	print("The cosine similarity between", cat[int(cat1)], "and", cat[int(cat2)],":", cosine)