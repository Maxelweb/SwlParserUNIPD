# Swl Parser / UNIPD

## Installazione e controllo

1. Posizionare antlr4 in /home
2. Avviare source setup.sh
3. `antlr4 -Dlanguage=Cpp swl.g4`
4. `make syncheck`
5. `syncheck ./example.swl` --> controlla se la sintassi sia corretta
6. `make translate`
7. `./translate example.swl` --> fa vedere la traduzione

## Files

- `example.swl` --> File SWL col codice da scrivere
- `swl.g4` --> File con la sintassi SWL
- `MyListener.cpp/.h` --> File con le classi di traduzione. Il `.h` contiene le classi che si vanno a usare.
- `swlBaseListener` --> Autogenerato, crea instestazioni per le classi

## Da fare

### Esercizio 1

Estendete la grammatica del linguaggio SWL con le seguenti funzionalità:

- il ciclo while
- il costrutto if-then-else
- operazioni di moltiplicazione e divisione
- espressioni booleane complesse che utilizzano gli operatori logici and, or, not e le parentesi

Scrivete almeno due programmi di esempio in SWL e allegateli alla soluzione.

### Esercizio 2

Modificate il codice del traduttore per fare in modo che funzioni per programmi scritti con la grammatica estesa che avete creato per l'Esercizio 1. Provate il funzionamento del traduttore sui programmi di esempio.

