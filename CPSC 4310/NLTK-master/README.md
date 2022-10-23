# NLTK
CPSC 4310

If you are missing a corpus please use either one of the two methods:

open a python3.6 console session and download the requested corpus
```
import ntlk

ntlk.download('<NAME_OF_CORPUS>')
```
or

in wordCount.py, after the imports add the download
```
# wordCount.py

from nltk.corpus import stopwords
from nltk.corpus import brown
from nltk.stem import WordNetLemmatizer, PorterStemmer
from nltk.probability import FreqDist
import nltk

ntlk.download('<NAME_OF_CORPUS>')
```