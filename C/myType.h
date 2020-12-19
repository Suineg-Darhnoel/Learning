typedef char* Word;
typedef struct Phrase Phrase;
typedef struct Sent Sent;
typedef struct Doc Doc;

typedef struct Sent{
    Word* words;
    int word_num;
}Sent;

typedef struct Para{
    Sent* sents;
    int sent_num;
}Para;

typedef struct Doc{
    Sent* paras;
    int para_num;
}Doc;

Sent* _init_sent();
Para* _init_para();

Sent* _insert_word(Sent* s, Word w);
Para* _insert_sent(Para* p, Sent* s);

void _show_para(Para* p);
void _free_para(Para* p);
void _show_sent(Sent* s);
void _free_sent(Sent* s);

