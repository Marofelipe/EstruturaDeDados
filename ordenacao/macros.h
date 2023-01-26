#define Item int
#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define lessaq(A, B) (key(A) <= key(B))
#define exch(A, B) {Item aux; aux = A;A = B;B = aux; }
#define cmp(A, B) (key(A) == key(B))