#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myType.h"

/* main function */
int main()
{
    char name1[] = "I";
    char name2[] = "love";
    Sent* sent1 = _init_sent();
    Sent* sent2 = _init_sent();

    sent1 = _insert_word(sent1, name1);
    sent1 = _insert_word(sent1, name2);

    sent2 = _insert_word(sent2, name2);
    sent2 = _insert_word(sent2, name1);

    Para* pa = _init_para();
    pa = _insert_sent(pa, sent1);
    pa = _insert_sent(pa, sent2);

    _show_para(pa);

    _free_para(pa);
    free(sent1);
    free(sent2);

    return 0;
}

/////////////////// SENTENCE ////////////////////////////
/**************************************
                UTILS
***************************************/
Sent* _init_sent()
{
    Sent* new_sent = (Sent*) malloc(sizeof(Sent));
    new_sent->words = NULL;
    new_sent->word_num = 0;
    return new_sent;
}

void _free_sent(Sent* s)
{
    for (int i=s->word_num-1; i>=0; i--){
        free(s->words[i]);
    }
    free(s->words);
}

void _show_sent(Sent* s)
{
    printf("--<Object<Sent>at(%p)>--\n", s);
    for (int i=0; i < s->word_num; i++){
        printf("---(%d): %s\n", i, s->words[i]);
    }
}

/**************************************************
    FUNCTION USED FOR INSERTING A WORD
    INTO A SENTENCE
***************************************************/
Sent* _insert_word(Sent* s, Word w)
{
    int word_num = ++s->word_num;
    s->words = (Word*) realloc(s->words, word_num*sizeof(Word));
    Word new_word = (Word) malloc(strlen(w)+1);

    if (s->words){
        strcpy(new_word, w);
        s->words[word_num-1] = new_word;
    }

    return s;
}

/////////////////// EOF SENTENCE ////////////////////////////
/////////////////// PARAGRAPH ///////////////////////////
/**************************************
                UTILS
***************************************/
Para* _init_para()
{
    Para* new_para = (Para*) malloc(sizeof(Para));
    new_para->sents = NULL;
    new_para->sent_num = 0;
    return new_para;
}

void _free_para(Para* p)
{
    for (int i = p->sent_num-1; i >= 0; i--){
        _free_sent(&p->sents[i]);
    }
    free(p->sents);
    free(p);
}

void _show_para(Para* p)
{
    Sent* ptr2sent;
    printf("-<Object<Para>at(%p)>-\n", p);
    for (int i=0; i < p->sent_num; i++){
        ptr2sent = &p->sents[i];
        _show_sent(ptr2sent);
    }
}
/**************************************************
    FUNCTION USED FOR INSERTING A SENTENCE
    INTO A PARAGRAPH
***************************************************/
Para* _insert_sent(Para* p, Sent* s)
{
    int sent_num = ++p->sent_num;
    p->sents = (Sent*) realloc(p->sents, sent_num*sizeof(Sent));

    if (p->sents)
    {
        p->sents[sent_num-1] = *s;
    }

    return p;
}

/////////////// EOF PARAGRAPH ///////////////////////////
