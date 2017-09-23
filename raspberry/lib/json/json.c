#include "json.h"


void print_json(json_t *root, char key_out[][11], char val_out[][11], uint8_t *num) {
    print_json_aux(root, 0, key_out, val_out, num);
}

void print_json_aux(json_t *element, int indent,
                    char key_out[][11], char val_out[][11], uint8_t *num)
{
    switch (json_typeof(element)) {
    case JSON_ARRAY:
        print_json_array(element, indent, key_out, val_out, num);
        break;
    case JSON_NULL:
        print_json_null(element, indent);
        break;
    default:
        fprintf(stderr, "unrecognized JSON type %d\n", json_typeof(element));
    }
}

const char *json_plural(int count) {
    return count == 1 ? "" : "s";
}

void print_json_object(json_t *element, int indent,
                       char key_out[], char val_out[])
{
    size_t size;
    const char *key;
    json_t *value;

    size = json_object_size(element);
    json_object_foreach(element, key, value) {
        strcpy(key_out, key);
        strcpy(val_out, json_string_value(value));
    }

}

void print_json_array(json_t *element, int indent,
                      char key_out[][11], char val_out[][11], uint8_t *num) {
    size_t i;
    *num = json_array_size(element);

    for (i = 0; i < *num; i++) {
        print_json_object(json_array_get(element, i), indent + 2, key_out[i], val_out[i]);
    }
}

void print_json_null(json_t *element, int indent) {
    (void)element;
    printf("JSON Null\n");
}


json_t *load_json(const char *text) {
    json_t          *root;
    json_error_t    error;

    root = json_loads(text, 0, &error);

    if (root) {
        return root;
    } else {
        fprintf(stderr, "json error on line %d: %s\n", error.line, error.text);
        return (json_t *)0;
    }
}
