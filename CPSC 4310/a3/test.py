import nltk
from nltk.corpus import brown
from nltk.util import ngrams
from random import shuffle
from nltk.corpus import stopwords
from nltk.probability import FreqDist
from sklearn.metrics.pairwise import cosine_similarity
from sklearn.feature_extraction.text import TfidfVectorizer

cat = brown.categories()
for i in range(len(cat)):
    print(i, ":", cat[i])

while True:
	cat1 = input("Category 1: ")
	if int(cat1) >= 0 and int(cat1) < (len(cat)):
		cat2 = input("Category 2: ")
		if int(cat2) >= 0 and int(cat2) < len(cat):
			break