import unicodedata
import pandas as pd
import csv
import re
import random

import warnings
warnings.simplefilter("ignore")

def strip_accents(text):
    try:
        text = unicode(text, 'utf-8')
    except NameError: # unicode is a default on python 3 
        pass
    text = unicodedata.normalize('NFD', text)\
           .encode('ascii', 'ignore')\
           .decode("utf-8")
    return str(text)

accepted_languages = {
    'English',
    # 'Portugeese',
    'French',
    # 'Dutch',
    'Spanish',
    # 'Danish',
    'Italian',
    # 'Turkish',
    # 'Sweedish',
    'German'
}

data = pd.read_csv("accented.csv")
data["Language"].value_counts()
X = data["Text"]
Y = data["Language"]


data_list = []
lang_list = []
i = 0
while i < len(X):
    if accepted_languages.__contains__(Y[i]):
        text = X[i]
        text = re.sub(r'[^a-zA-Z ]+', '', text)
        text = re.sub(r'[[]]', ' ', text)
        text = strip_accents(text).lower()
        splits = text.split()
        for x in splits:
            if not data_list.__contains__(x):
                data_list.append(x)
                lang_list.append(Y[i])
    i += 1

c = []
for x, y in zip(data_list, lang_list):
    temp = [x, y]
    c.append(temp)
random.shuffle(c)

# lst_str = str(c)[1:-1]
# print(lst_str)

flat_list_training = []
flat_list_testing = []
i = 0
for sublist in c:
    for item in sublist:
        if i % 4 < 2:
            flat_list_training.append(item)
        else:
            flat_list_testing.append(item)
        i += 1
print(i)

with open('unaccented.csv', 'w', encoding='UTF8') as f:
    writer = csv.writer(f)
    writer.writerow(flat_list_training)

with open('testing.csv', 'w', encoding='UTF8') as f:
    writer = csv.writer(f)
    writer.writerow(flat_list_testing)
