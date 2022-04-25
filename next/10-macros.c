// const int N = 100;
#define N 100

#define max(a, b) ((a) < (b) ? (b) : (a))
// Inline functions are since C99 only, not everyone supports them.

#define json_object_object_foreach(obj, key, val)                          \
    char *key = NULL;                                                      \
    struct json_object *val = NULL;                                        \
    struct lh_entry *entry##key;                                           \
    struct lh_entry *entry_next##key = NULL;                               \
    for (entry##key = json_object_get_object(obj)->head;                   \
         (entry##key ? (key = (char *)lh_entry_k(entry##key),              \
                       val = (struct json_object *)lh_entry_v(entry##key), \
                       entry_next##key = entry##key->next, entry##key)     \
                     : 0);                                                 \
         entry##key = entry_next##key)
// `json_object_object_foreach` is harder to optimize because it would need
// pointer-to-function optimization.
