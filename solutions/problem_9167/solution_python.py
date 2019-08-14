"""
Baekjoon Online Judge #9167
https://www.acmicpc.net/problem/9167
"""

import re

def symbol(name):
    if name not in counter:
        counter[name] = 0
    counter[name] += 1
    exp_count = len(response[name])
    return response[name][(counter[name] - 1) % exp_count]

def taunt(taunt_num):
    while taunt_num > 0:
        taunt_num -= 1
        line = symbol('taunt')
        while '<' in line:
            newline = ''
            for word in line.split():
                if re.match('<.*>', word) is not None:
                    if word == '<taunt>':
                        taunt_word = symbol(word[1:-1])
                        if '<' not in taunt_word:
                            taunt_word = taunt_word.title()
                        newline += taunt_word
                        taunt_num -= 1
                    elif word == '<noun>!':
                        newline += symbol(word[1:-2])
                        newline += '!'
                    else:
                        newline += symbol(word[1:-1])
                else:
                    newline += word
                newline += ' '
            line = newline.strip()
        line = line[0].upper() + line[1:]
        print('Taunter: %s. ' % line)

counter = dict()
response = {
    'taunt': ['<sentence>', '<taunt> <sentence>', '<noun>!', '<sentence>'],
    'sentence': ['<past-rel> <noun-phrase>', '<present-rel> <noun-phrase>',
                 '<past-rel> <article> <noun>'],
    'noun-phrase': ['<article> <modified-noun>'],
    'modified-noun': ['<noun>', '<modifier> <noun>'],
    'modifier': ['<adjective>', '<adverb> <adjective>'],
    'present-rel': ['Your <present-person> <present-verb>'],
    'past-rel': ['Your <past-person> <past-verb>'],
    'present-person': ['steed', 'king', 'first-born'],
    'past-person': ['mother', 'father', 'grandmother', 'grandfather',
                    'godfather'],
    'noun': ['hamster', 'coconut', 'duck', 'herring', 'newt', 'peril',
             'chicken', 'vole', 'parrot', 'mouse', 'twit'],
    'present-verb': ['is', 'masquerades as'],
    'past-verb': ['was', 'personified'],
    'article': ['a'],
    'adjective': ['silly', 'wicked', 'sordid', 'naughty', 'repulsive',
                  'malodorous', 'ill-tempered'],
    'adverb': ['conspicuously', 'categorically', 'positively', 'cruelly',
               'incontrovertibly']
}
magic_str = 'theholygrail'
pattern = ''
for c in magic_str:
    pattern += '.*[%s%s]' % (c.upper(), c.lower())
pattern += '.*'
first_line = False

while True:
    try:
        if not first_line:
            first_line = True
        else:
            print()
        S = input()
        words = S.split()
        word_count = 0
        for word in words:
            if any([c.isalpha() for c in word]):
                word_count += 1
        taunt_num = word_count // 3 + (1 if word_count % 3 != 0 else 0)
        print('Knight: %s ' % ' '.join(words))
        if re.match(pattern, S) is not None:
            print('Taunter: (A childish hand gesture).')
            taunt_num -= 1
        taunt(taunt_num)
    except EOFError:
        break
