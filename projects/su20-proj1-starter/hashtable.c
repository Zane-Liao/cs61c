#include "hashtable.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * This creates a new hash table of the specified size and with
 * the given hash function and comparison function.
 */
HashTable *createHashTable(int size, unsigned int (*hashFunction)(void *),
                           int (*equalFunction)(void *, void *)) {
  int i = 0;
  HashTable *newTable = malloc(sizeof(HashTable));
  newTable->size = size;
  newTable->data = malloc(sizeof(struct HashBucket *) * size);
  for (i = 0; i < size; ++i) {
    newTable->data[i] = NULL;
  }
  newTable->hashFunction = hashFunction;
  newTable->equalFunction = equalFunction;
  return newTable;
}

/*
 * This inserts a key/data pair into a hash table.  To use this
 * to store strings, simply cast the char * to a void * (e.g., to store
 * the string referred to by the declaration char *string, you would
 * call insertData(someHashTable, (void *) string, (void *) string).
 * Because we only need a set data structure for this spell checker,
 * we can use the string as both the key and data.
 */
void insertData(HashTable *table, void *key, void *data) {
  // -- TODO --
  // HINT:
  // 1. Find the right hash bucket location with table->hashFunction.
  // 2. Allocate a new hash bucket struct.
  // 3. Append to the linked list or create it if it does not yet exist.
  unsigned int index = table->hashFunction(key) % table->size;
  struct HashBucket *newbucket = (struct HashBucket *)malloc(sizeof(struct HashBucket));
  if (!newbucket) {
    fprintf( stderr,"Memory allocation falied");
    return;
  } 
  newbucket->data = data;
  newbucket->key = key;
  newbucket->next = NULL;
  struct HashBucket *temp = table->data[index];
  if (temp == NULL) {
    table->data[index] = newbucket;
  } else {
    struct HashBucket *prev = NULL;
    while (table->equalFunction(temp->key, key)) {
        temp->data = data;
        free(newbucket);
        return;
    }
    prev = temp;
    temp = temp->next;
    prev->next = newbucket;
  }
}

/*
 * This returns the corresponding data for a given key.
 * It returns NULL if the key is not found. 
 */
void *findData(HashTable *table, void *key) {
  // -- TODO --
  // HINT:
  // 1. Find the right hash bucket with table->hashFunction.
  // 2. Walk the linked list and check for equality with table->equalFunction.
  unsigned int index = table->hashFunction(key) % table->size;
  struct HashBucket *temp = table->data[index];
  while (temp) {
    if (table->equalFunction(temp->key, key)) {
      return temp->data;
    }
    temp = temp->next;
  }
  return NULL;
}