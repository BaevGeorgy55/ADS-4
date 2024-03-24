// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int cntr = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        cntr += 1;
      }
    }
  }
  return cntr;
}
int countPairs2(int *arr, int len, int value) {
  int cntr = 0;
  for (int i = 0; i < len; i++) {
    for (int j = len - 1; j > i; j--) {
      if (arr[i] + arr[j] == value) {
        cntr += 1;
      }
    }
  }
  return cntr;
}
int countPairs3(int *arr, int len, int value) {
  int cntr = 0;
  int right, left, midle, razn;
  for (int i = 0; i < len; i++) {
    right = len - 1;
    left = i + 1;
    razn = value - arr[i];
    while (left <= right) {
      midle = (left + right) / 2;
      if (arr[midle] == razn) {
        cntr += 1;
        int t = midle - 1;
        while ((t > i) && (arr[t]) == arr[midle]) {
          cntr += 1;
          t -= 1;
        }
        int h = midle + 1;
        while ((i < h) && (arr[h] == arr[midle])) {
          cntr += 1;
          h += 1;
        }
        break;
      }
      else if (arr[midle] > razn)
        right = midle - 1;
      else
        left = midle + 1;
    }
  }
  return cntr;
}
