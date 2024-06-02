int strcmp(const char* str1, const char* str2) {
  while (*str1 && *str2 && (*str1 == *str2)) {
    str1++;
    str2++;
  }
  return *str1 - *str2;
}

int strlen(const char* str) {
  int length = 0;
  while (*str) {
    length++;
    str++;
  }
  return length;
}