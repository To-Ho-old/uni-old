import math
from nltk import word_tokenize
from nltk import FreqDist
from nltk.corpus import brown

cat2 = False

# To calculate similarities between documents of the same category only
# uncomment one category from the first list (cat). To calculate
# similarities between two complete categories uncomment one of
# the first list (cat) and one from the second list (cat2)

cat = 'news'
# cat = 'editorial'
# cat = 'reviews'
# cat = 'religion'
# cat = 'hobbies'
# cat = 'lore'
# cat = 'belle_lettres'
# cat = 'government'
# cat = 'learned'
# cat = 'fiction'
# cat = 'mystery'
# cat = 'science_fiction'
# cat = 'adventrue'
# cat = 'romance'
# cat = 'humor'

# cat2 = 'news'
# cat2 = 'editorial'
# cat2 = 'reviews'
# cat2 = 'religion'
# cat2 = 'hobbies'
# cat2 = 'lore'
# cat2 = 'belle_lettres'
# cat2 = 'government'
# cat2 = 'learned'
# cat2 = 'fiction'
# cat2 = 'mystery'
# cat2 = 'science_fiction'
# cat2 = 'adventrue'
# cat2 = 'romance'
# cat2 = 'humor'

# To compare different documents within the cluster change the index
# value for doc1 and doc2
doc1 = 0
doc2 = 1

def get_word_matrix(words):
    list = []
    # print(words)
    words = word_tokenize(words)
    for w in FreqDist(words):
        list.append(w)
    return list


def get_idf_matrix(wrd_matrix, documents, n):
    print('getting idf...')
    n += 0.0
    list = []
    doc_dist = []
    for d in documents:
        # doc_dist.append(FreqDist(word_tokenize(d)))
        doc_dist.append(FreqDist(d))
    for word in wrd_matrix:
        count = 0
        for d in doc_dist:
            if d[word] > 0:
                count = count + 1
        if count > 0:
            list.append(math.log10(n/count))

    return list


def get_tf_matrix(wrd_matrix, documents):
    print('getting tf...')
    list = []
    for d in documents:
        doc_list = []
        doc_freq = FreqDist(d)
        for w in wrd_matrix:
            count = doc_freq[w]
            tf = 1 + math.log10(count) if count > 0 else 0
            # tf = get_tf(w,d)
            doc_list.append(tf)
        list.append(doc_list)
    return list


def get_w_matrix(idf_matrix, tf_matrix):
    print('getting w...')
    list = []
    for d in tf_matrix:
        w_list = []
        i = 0
        n = len(idf_matrix)
        while i < n:
            w_list.append(d[i] * idf_matrix[i])
            i += 1
        list.append(w_list)
    return list


def cosine(d1,d2):
    print('calculating cosine...')
    sum = 0.0
    i = 0
    d1d = 0.0
    d2d = 0.0
    n = len(d1)
    while i < n:
        sum += (d1[i] * d2[i])
        d1d += d1[i] * d1[i]
        d2d += d2[i] * d2[i]
        i += 1
    return (sum/(math.sqrt(d1d) * math.sqrt(d2d))) if d1d > 0 or d2d > 0 else 0



if not cat2:
    fid = brown.fileids(categories=cat)
    docs = []
    for f in fid:
        docs.append(brown.words(fileids=[f]))

else:
    docs = []
    docs.append(brown.words(categories=cat))
    docs.append(brown.words(categories=cat2))



N = len(docs)
all_words = ''
for doc in docs:
    for word in doc:
        all_words = all_words + ' ' + word

word_matrix = get_word_matrix(all_words)
idf_matrix = get_idf_matrix(word_matrix, docs, N)
tf_matrix = get_tf_matrix(word_matrix, docs)
w_matrix = get_w_matrix(idf_matrix, tf_matrix)

print(cosine(w_matrix[doc1], w_matrix[doc2]))

