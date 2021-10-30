#ifndef sdds_Word_H // replace with relevant names
#define sdds_Word_H
const int MAX_WORD_LEN = 21;
struct Word
{
    char letters[MAX_WORD_LEN];
    int count;
};
namespace sdds
{

    void programTitle();
    void wordStats(bool logOn);
    int searchWords(const Word words[], int num, const char word[]);
    void print(const Word* w, bool gotoNextLine);
    void report(const Word words[], int noOfWords, int longestWord);
    void swap(Word* p1, Word* p2);
    void sort(Word words[], int cnt);
    void addWord(Word words[], int* index, const char newWord[]);
    void totalWordsStat(int totNoWrds, int totalOverAll, int longestWord);
    void toLowerCaseAndAlphabeticCopy(char des[], const char source[]);
}
#pragma once

#endif