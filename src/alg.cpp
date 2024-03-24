// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int cntr = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if ((arr[i] + arr[j] == value) && (arr[i] >= 0 && arr[j] >= 0)) {
        cntr++;
      }
    }
  }
  return cntr;
}
int countPairs2(int *arr, int len, int value) {
  int cntr = 0;
  int t = len - 1;
  while (arr[t] < value) {
    t--;
  }
  for (int i = 0; i < len; i++) {
    for (int j = t; j > i; j--) {
      if ((arr[i] + arr[j] == value) && (arr[i] >= 0 && arr[j] >= 0)) {
        cntr++;
      } else if (arr[i] + arr[j] < value) {
        break;
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
        cntr++;
        int t = midle - 1;
        while ((t > i) && (arr[t]) == arr[midle]) {
          cntr++;
          t--;
        }
        int h = midle + 1;
        while ((i < h) && (arr[h] == arr[midle])) {
          cntr++;
          h++;
        }
        break;
      } else if (arr[midle] > razn) {
        right = midle - 1;
      } else {
        left = midle + 1;
      }
    }
  }
  return cntr;
}
