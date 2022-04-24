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
    "English",
    "Portugeese",
    "French",
    "Dutch",
    "Spanish",
    "Danish",
    "Italian",
    "Turkish",
    "Sweedish",
    "German"
}

with open("accented.csv") as inFile:
    not_eof = True
    outFile = open("unaccented.csv", 'w')
    while not_eof:
        file_line = inFile.readline()
        if not file_line:
            print("End Of File")
            not_eof = False
        else:
            content = inFile.readline()
            pair = content.split(',')
            language = pair[1]
            if accepted_languages.__contains__(language):
                stripped_sentence = strip_accents(pair[0]).lower()
                outFile.write(stripped_sentence + ',' + language + '\n')
    outFile.close()


s = strip_accents('àéêöhυ conçu à partir r släcka mig är det dags att åka')

print(s)