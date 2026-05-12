#include "hashmap.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>

unsigned long int hashmap_fnv1a(void *data, unsigned long int len) {
  unsigned char *p = (unsigned char *)data;
  unsigned long int h = 2166136261UL;

  for (unsigned long int i = 0; i < len; i++) {
    h = (h ^ p[i]) * 16777619;
  }

  return h;
}

int hashmap_hash(char *str, int max_hash) {
  unsigned long int fnv1a_hash = hashmap_fnv1a((void *)str, strlen(str));
  return (int)(fnv1a_hash % (unsigned long int)(max_hash + 1));
}

struct hashmap_s {
  int size;
  struct hashmap_field *fields;
};

struct hashmap_field {
  int size;
  struct hashmap_entry *entries;
};

struct hashmap_entry {
  char *key;
  void *val;
  size_t len;
};

hashmap_t hashmap_new(int size) {
  /* BUG-3 */
  /* Fixes 3 */
  if (size <= 0) {
    return NULL;
  }

  /* BUG-1 */
  hashmap_t map = (hashmap_t)malloc(sizeof(struct hashmap_s));

  /* Fixes 1 */
  if (map == NULL) {
    return NULL;
  }

  /* BUG-2 */
  struct hashmap_field *fields =
      (struct hashmap_field *)malloc(sizeof(struct hashmap_field) * (size_t)size);

  /* Fixes 2 */
  if (fields == NULL) {
    free(map);
    return NULL;
  }

  for (int i = 0; i < size; i++) {
    fields[i].size = 0;
    fields[i].entries = NULL;
  }

  map->size = size;
  map->fields = fields;

  return map;
}

void hashmap_free(hashmap_t map) {
  /* BUG-4 */
  /* Fixes 4 */
  if (map == NULL) {
    return;
  }

  for (int i = 0; i < map->size; i++) {
    struct hashmap_field *field = map->fields + i;

    for (int j = 0; j < field->size; j++) {
      struct hashmap_entry *entry = field->entries + j;
      free(entry->key);

      /* The hashmap no longer owns entry->val.
         It only stores the pointer supplied by the caller. */
    }

    free(field->entries);
  }
}

void hashmap_set(hashmap_t map, char *key, void *value, size_t length) {
  /* BUG-5 */
  /* Fixes 5 */
  if (map == NULL || map->fields == NULL || key == NULL) {
    return;
  }

  int hash = hashmap_hash(key, map->size - 1);
  struct hashmap_field *field = map->fields + hash;
  struct hashmap_entry *entry = NULL;

  for (int i = 0; i < field->size; i++) {
    entry = field->entries + i;

    if (strcmp(entry->key, key) == 0) {
      if (value == NULL) {
        free(entry->key);

        field->size--;

        if (entry != field->entries + field->size) {
          *entry = field->entries[field->size];
        }

        if (field->size == 0) {
          free(field->entries);
          field->entries = NULL;
        } else {
          /* BUG-10 */
          /* Fixes 10 */
          struct hashmap_entry *shrunk =
              (struct hashmap_entry *)realloc(
                  field->entries,
                  sizeof(struct hashmap_entry) * (size_t)field->size);

          if (shrunk != NULL) {
            field->entries = shrunk;
          }
        }

        return;
      }

      /* BUG-9 */
      /* Fixes 9 */
      entry->val = value;
      entry->len = length;
      return;
    }
  }

  if (value == NULL) {
    return;
  }

  /* BUG-6 */
  /* BUG-7 */
  /* Fixes 6 and 7 */
  struct hashmap_entry *new_entries =
      (struct hashmap_entry *)realloc(
          field->entries,
          sizeof(struct hashmap_entry) * (size_t)(field->size + 1));

  if (new_entries == NULL) {
    return;
  }

  field->entries = new_entries;
  entry = &field->entries[field->size];

  entry->key = NULL;
  entry->val = NULL;
  entry->len = 0;

  field->size++;

  /* BUG-8 */
  /* Fixes 8 */
  entry->key = key;

  /* BUG-9 */
  /* Fixes 9 */
  entry->val = value;
  entry->len = length;
}

void *hashmap_get(hashmap_t map, char *key) {
  /* BUG-11 */
  /* Fixes 11 */
  if (map == NULL || map->fields == NULL || key == NULL) {
    return NULL;
  }

  int hash = hashmap_hash(key, map->size - 1);
  struct hashmap_field *field = map->fields + hash;

  for (int i = 0; i < field->size; i++) {
    struct hashmap_entry *entry = field->entries + i;

    if (strcmp(entry->key, key) == 0) {
      /* BUG-12 */
      void *val = malloc(entry->len);

      /* Fixes 12 */
      if (val == NULL) {
        return NULL;
      }

      memcpy(val, entry->val, entry->len);
      return val;
    }
  }

  return NULL;
}

int main() {
  hashmap_t map = hashmap_new(8);

  if (map == NULL) {
    return 1;
  }

  char *key = "42";
  int value = 42;
  hashmap_set(map, key, &value, sizeof(int));

  int *ret = (int *)hashmap_get(map, key);

  if (ret == NULL) {
    hashmap_free(map);
    return 1;
  }

  assert(*ret == value);

  /* BUG-13 */
  /* Fixes 13 */
  free(ret);

  hashmap_free(map);
  return 0;
}