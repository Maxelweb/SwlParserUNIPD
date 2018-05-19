# Esempio di programma 1

#### [← Torna indietro](./)

## Introduzione

Il seguente programma viene utilizzato per il **calcolo del fattoriale** di un numero `x` tale che `x` è compreso tra 1 e 100 (compresi).

## SWL Code

```matlab
begin 
	let x be 0
	ask x

	if x > 100 || (x < 1 && !x) then 
		print 0
	else
		let Fattoriale be 1
		let y be 1

		while (x >= y) do
			mult y to Fattoriale 
			add 1 to y
		end

		print Fattoriale
	end
end
```

## Traduzione in C++
```cpp
#include <iostream>

using namespace std;

int main() {
    int x = 0;
    cin >> x;
    if (x > 100 || (x < 1 && !x)) {
        cout << 0 << endl;
    } else {
        int Fattoriale = 1;
        int y = 1;
        while ((x >= y)) {
            Fattoriale = Fattoriale*y;
            y += 1;
        }
        cout << Fattoriale << endl;
    }
}
```

## Breve analisi del programma

Si vuole cercare il fattoriale di un numero x. Per farlo utilizziamo due variabili ausiliarie `Fattoriale` e `y` che
partono entrambe da uno. Ciò che si ottiene nella variabile Fattoriale è il fattoriale che parte da 1 moltiplicato per y, 
che viene incrementato di 1 fino a quando la variabile y non coincide con x, che è il numero che stiamo cercando.

## Analisi sintattica

Il programma traduce direttamente le variabili in INT e ciascuna istruzione inline direttamente. Per quanto concerne gli IF e
i WHILE, la traduzione che avviene è molto letterale, dal momento che viene tradotta direttamente la parte all'interno delle condizioni, 
purché queste soddisfino la sintassi simile che si utilizza nel C++.
Nel caso di utilizzo delle parentesi (vedasi il WHILE), queste ultime verranno comunque doppiate, sebbene il funzionamento del programma non ne risentirà. 
