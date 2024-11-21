// Содержание:
// На отрезках

// сорт. по неубыванию последний элемент < x
// сорт. по неубыванию последний элемент <= x
// сорт. по неубыванию последний элемент == x
// сорт. по неубыванию первый элемент > x
// сорт. по неубыванию первый элемент >= x
// сорт. по неубыванию первый элемент == x
// сорт. по невозрастанию последний элемент > x
// сорт. по невозрастанию последний элемент >= x
// сорт. по невозрастанию последний элемент == x
// сорт. по невозрастанию первый элемент < x
// сорт. по невозрастанию первый элемент <= x
// сорт. по невозрастанию первый элемент == x
// f() возвращает сначала true, потом false последний f() == true
// f() возвращает сначала false, потом true первый f() == true

////////////////////////////////////////////////////////////////////////////////
// На полуинтервалах

// сорт. по неубыванию последний элемент < x
// сорт. по неубыванию последний элемент <= x
// сорт. по неубыванию последний элемент == x
// сорт. по неубыванию первый элемент > x
// сорт. по неубыванию первый элемент >= x
// сорт. по неубыванию первый элемент == x
// f() возвращает сначала true, потом false последний f() == true
// f() возвращает сначала false, потом true первый f() == true


// сорт. по неубыванию последний элемент < x
int l = 0, r = a.size() - 1;
while (l + 1 < r) {
  int m = l + (r - l) / 2;
  if (a[m] < x)
    l = m;
  else
    r = m;
}
if (a[r] < x)
  return r;
if (a[l] < x)
  return l;
return -1;

// сорт. по неубыванию последний элемент <= x
int l = 0, r = a.size() - 1;
while (l + 1 < r) {
  int m = l + (r - l) / 2;
  if (a[m] <= x)
    l = m;
  else
    r = m;
}
if (a[r] <= x)
  return r;
if (a[l] <= x)
  return l;
return -1;

// сорт. по неубыванию последний элемент == x
int l = 0, r = a.size() - 1;
while (l + 1 < r) {
  int m = l + (r - l) / 2;
  if (a[m] <= x)
    l = m;
  else
    r = m;
}
if (a[r] == x)
  return r;
if (a[l] == x)
  return l;
return -1;

// сорт. по неубыванию первый элемент > x
int l = 0, r = a.size() - 1;
while (l + 1 < r) {
  int m = l + (r - l) / 2;
  if (a[m] <= x) // if (a[m] > x)
    l = m;       //   r = m;
  else           // else
    r = m;       //   l = m;
}
if (a[l] > x)
  return l;
if (a[r] > x)
  return r;
return -1;

// сорт. по неубыванию первый элемент >= x
int l = 0, r = a.size() - 1;
while (l + 1 < r) {
  int m = l + (r - l) / 2;
  if (a[m] < x) // if (a[m] >= x)
    l = m;      //   r = m;
  else          // else
    r = m;      //   l = m;
}
if (a[l] >= x)
  return l;
if (a[r] >= x)
  return r;
return -1;

// сорт. по неубыванию первый элемент == x
int l = 0, r = a.size() - 1;
while (l + 1 < r) {
  int m = l + (r - l) / 2;
  if (a[m] < x) // if (a[m] >= x)
    l = m;      //   r = m;
  else          // else
    r = m;      //   l = m;
}
if (a[l] == x)
  return l;
if (a[r] == x)
  return r;
return -1;

// сорт. по невозрастанию последний элемент > x
int l = 0, r = a.size() - 1;
while (l + 1 < r) {
  int m = l + (r - l) / 2;
  if (a[m] > x)
    l = m;
  else
    r = m;
}
if (a[r] > x)
  return r;
if (a[l] > x)
  return l;
return -1;

// сорт. по невозрастанию последний элемент >= x
int l = 0, r = a.size() - 1;
while (l + 1 < r) {
  int m = l + (r - l) / 2;
  if (a[m] >= x)
    l = m;
  else
    r = m;
}
if (a[r] >= x)
  return r;
if (a[l] >= x)
  return l;
return -1;

// сорт. по невозрастанию последний элемент == x
int l = 0, r = a.size() - 1;
while (l + 1 < r) {
  int m = l + (r - l) / 2;
  if (a[m] >= x)
    l = m;
  else
    r = m;
}
if (a[r] == x)
  return r;
if (a[l] == x)
  return l;
return -1;

// сорт. по невозрастанию первый элемент < x
int l = 0, r = a.size() - 1;
while (l + 1 < r) {
  int m = l + (r - l) / 2;
  if (a[m] >= x) // if (a[m] < x)
    l = m;       //   r = m;
  else           // else
    r = m;       //   l = m;
}
if (a[l] < x)
  return l;
if (a[r] < x)
  return r;
return -1;

// сорт. по невозрастанию первый элемент <= x
int l = 0, r = a.size() - 1;
while (l + 1 < r) {
  int m = l + (r - l) / 2;
  if (a[m] > x) // if (a[m] <= x)
    l = m;      //   r = m;
  else          // else
    r = m;      //   l = m;
}
if (a[l] <= x)
  return l;
if (a[r] <= x)
  return r;
return -1;

// сорт. по невозрастанию первый элемент == x
int l = 0, r = a.size() - 1;
while (l + 1 < r) {
  int m = l + (r - l) / 2;
  if (a[m] > x) // if (a[m] <= x)
    l = m;      //   r = m;
  else          // else
    r = m;      //   l = m;
}
if (a[l] == x)
  return l;
if (a[r] == x)
  return r;
return -1;

// f() возвращает сначала true, потом false последний f() == true
int l = 0, r = a.size() - 1;
while (l + 1 < r) {
  int m = l + (r - l) / 2;
  if (f(a[m]))
    l = m;
  else
    r = m;
}
if (f(a[r]))
  return r;
if (f(a[l])
  return l;
return -1;

// f() возвращает сначала false, потом true первый f() == true
int l = 0, r = a.size() - 1;
while (l + 1 < r) {
  int m = l + (r - l) / 2;
  if (!f(a[m])) // if (f(a[m]))
    l = m;      //   r = m;
  else          // else
    r = m;      //   l = m;
}
if (f(a[l])
  return l;
if (f(a[r]))
  return r;
return -1;

////////////////////////////////////////////////////////////////////////////////

// сорт. по неубыванию последний элемент < x
int l = -1, r = a.size();
while (l + 1 < r) {
  int m = l + (r - l) / 2;
  if (a[m] < x)
    l = m;
  else
    r = m;
}
if (l != -1)
    return l;
return -1;

// сорт. по неубыванию последний элемент <= x
int l = -1, r = a.size();
while (l + 1 < r) {
  int m = l + (r - l) / 2;
  if (a[m] <= x)
    l = m;
  else
    r = m;
}
if (l != -1)
    return l;
return -1;

// сорт. по неубыванию последний элемент == x
int l = -1, r = a.size();
while (l + 1 < r) {
  int m = l + (r - l) / 2;
  if (a[m] <= x)
    l = m;
  else
    r = m;
}
if (l != -1 && a[l] == x)
    return l;
return -1;

// f() возвращает сначала false, потом true первый f() == true
int l = -1, r = a.size();
while (l + 1 < r) {
  int m = l + (r - l) / 2;
  if (f(a[m]))
    r = m;
  else
    l = m;
}
if (r != size)
    return r;
return -1;

// сорт. по неубыванию первый элемент > x
int l = -1, r = a.size();
while (l + 1 < r) {
  int m = l + (r - l) / 2;
  if (a[m] > x)
    r = m;
  else
    l = m;
}
if (r != size)
    return r;
return -1;

// сорт. по неубыванию первый элемент >= x
int l = -1, r = a.size();
while (l + 1 < r) {
  int m = l + (r - l) / 2;
  if (a[m] >= x)
    r = m;
  else
    l = m;
}
if (r != size)
    return r;
return -1;

// сорт. по неубыванию первый элемент == x
int l = -1, r = a.size();
while (l + 1 < r) {
  int m = l + (r - l) / 2;
  if (a[m] >= x)
    r = m;
  else
    l = m;
}
if (r != size && a[r] == x)
    return r;
return -1;

// f() возвращает сначала true, потом false последний f() == true
int l = -1, r = a.size();
while (l + 1 < r) {
  int m = l + (r - l) / 2;
  if (f(a[m]))
    l = m;
  else
    r = m;
}
if (l != -1)
    return l;
return -1;

// f() возвращает сначала false, потом true первый f() == true
int l = -1, r = a.size();
while (l + 1 < r) {
  int m = l + (r - l) / 2;
  if (f(a[m]))
    r = m;
  else
    l = m;
}
if (r != size)
    return r;
return -1;