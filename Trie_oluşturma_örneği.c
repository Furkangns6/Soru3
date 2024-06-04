#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ALPHABET_SIZE 26

struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;
};

struct TrieNode *getNode(void) {
    struct TrieNode *pNode = (struct TrieNode *)malloc(sizeof(struct TrieNode));
    pNode->isEndOfWord = false;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;
    return pNode;
}

void insert(struct TrieNode *root, const char *key) {
    struct TrieNode *pCrawl = root;
    while (*key) {
        int index = *key - 'a';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();
        pCrawl = pCrawl->children[index];
        key++;
    }
    pCrawl->isEndOfWord = true;
}

bool search(struct TrieNode *root, const char *key) {
    struct TrieNode *pCrawl = root;
    while (*key) {
        int index = *key - 'a';
        if (!pCrawl->children[index])
            return false;
        pCrawl = pCrawl->children[index];
        key++;
    }
    return (pCrawl != NULL && pCrawl->isEndOfWord);
}

int main() {
    char keys[][8] = {"muz", "yarasa", "elma"};
    struct TrieNode *root = getNode();
    for (int i = 0; i < sizeof(keys) / sizeof(keys[0]); i++)
        insert(root, keys[i]);
    
    printf("%s --- %s\n", "the", search(root, "muz") ? "Bulundu" : "Bulunamadı");
    printf("%s --- %s\n", "these", search(root, "elma") ? "Bulundu" : "Bulunamadı");
    printf("%s --- %s\n", "their", search(root, "araba") ? "Bulundu" : "Bulunamadı");
