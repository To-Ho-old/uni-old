import gensim.downloader as api
from gensim.models import TfidfModel
from gensim.corpora import Dictionary


dataset = api.load("text8")
dct = Dictionary(dataset)  # fit dictionary
corpus = [dct.doc2bow(line) for line in dataset]  # convert corpus to BoW format

print(corpus)

# model = TfidfModel(corpus)  # fit model
# vector = model[corpus[0]]  # apply model to the first corpus document
# print(vector)