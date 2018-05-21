# Esempio di programma 2

#### [← Torna indietro](./)

## Introduzione

Questo semplice programma di esempio tratta della stampa della media dato in input un numero, che andrà sommato alla media precedente. Il programma termina quando viene inserito un numero negativo.

## SWL Code

```matlab
begin
   let sum be 0
   let avg be 0
   let counter be 0
   let n be 0
   while n >= 0 do
       ask n
       if n>=0 then
           add n to sum
           add 1 to counter
           sub avg to avg
           add sum to avg
           div counter to avg
           print avg
       end
   end
end
```

## Traduzione in C++


```cpp
#include <iostream>

using namespace std;

int main() {
    int sum = 0;
    int avg = 0;
    int counter = 0;
    int n = 0;
    while (n >= 0)
    {
        cin >> n; 
        if (n >= 0) {
            sum += n;
            counter += 1;
            avg -= avg;
            avg += sum;
            avg = avg/counter;
            cout << avg << endl;
        }
    }
}
```

