import nltk
sent = 'You had a thought.'

t_sent = nltk.tokenize.sent_tokenize(sent)

for word in t_sent:
    w = nltk.word_tokenize(word)
    tag = nltk.pos_tag(w)
    print(tag)