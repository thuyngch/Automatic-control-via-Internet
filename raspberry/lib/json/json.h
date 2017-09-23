#ifndef JSON_H_
#define JSON_H_


#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <jansson.h>

#define JSON_LEN	10
#define LOGIN_LEN	11


void print_json(json_t *root, char key_out[][LOGIN_LEN], char val_out[][LOGIN_LEN], uint8_t *num);


void print_json_aux(json_t *element, int indent, char key_out[][LOGIN_LEN], char val_out[][LOGIN_LEN], uint8_t *num);
const char *json_plural(int count);
void print_json_object(json_t *element, int indent, char key_out[], char val_out[]);
void print_json_array(json_t *element, int indent, char key_out[][LOGIN_LEN], char val_out[][LOGIN_LEN], uint8_t *num);
void print_json_null(json_t *element, int indent);
json_t *load_json(const char *text);


#endif /* JSON_H_ */