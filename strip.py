import unicodedata

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
    'Portugeese',
    "French",
    "Dutch",
    "Spanish",
    "Danish",
    "Italian",
    "Turkish",
    "Sweedish",
    "German"
}

with open('accented.csv', 'r') as inFile:
    not_eof = True
    outFile = open('unaccented.csv', 'w')
    while not_eof:
        print("zero")
        content = inFile.readline()
        print(content)
        if not content:
            print("End Of File")
            not_eof = False
        else:
            pair = content.split(',')
            print(pair[0])
            language = pair[1]
            print(language)
            if accepted_languages.__contains__(language):
                stripped_sentence = strip_accents(pair[0]).lower()
                outFile.write("{0},{1}\n".format(stripped_sentence, language))
    outFile.close()


s = strip_accents('àéêöhυ conçu à partir r släcka mig är det dags att åka')

print(s)