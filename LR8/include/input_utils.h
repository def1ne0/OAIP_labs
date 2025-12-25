#ifndef INPUT_UTILS_H
#define INPUT_UTILS_H

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

void clear_buff();
void input_int(int *input, int (*condition) (int *));
void input_unsigned(int *input);
void input_non_negative_int(int *input);


#ifdef __cplusplus
}
#endif // __cplusplus

#endif // INPUT_UTILS_H