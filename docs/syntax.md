# Sintassi del linguaggio

#### [← Torna indietro](./)

## Introduzione

Il linguaggio implementato parte dall'esempio realizzato dal professore e si va ad estendere su una sintassi affine.

```matlab
begin
    let a be 5
    let b be 10
    add 3 to b
    add b to a
    add a to b
    print b
    print 3
end
```

L'implementazione è molto basica, ma comunque piuttosto elaborata nella parte condizionale degli IF e dei WHILE, dal momento 
che per accettare plurimi costrutti logici è stata implementata la ricorsione. 


Nella parte seguente, per comodità di scrittura, si ometteranno i tag di apertura e si useranno `Foobar` e `Bamboo` come nomi esemplificativi di due qualsiasi variabili (anche con gli stessi valori).

## Apertura

Il programma ha in apertura due tag fondamentali che vanno inseriti rispettivamente all'inizio e alla fine del programma:

```matlab
begin
    [...]
end
```

### Assegnazione

```matlab
let Foobar be 15
let Bamboo be Foobar
```
> **NOTA:** L'assegnazione si basa sempre sull'utilizzo di variabili di tipo INT. 


### Visualizzazione

```mat
print 5
print Foobar
```
> **NOTA:** Il print viene eseguito tramite `cout` con un ritorno a capo dopo la variabile.


### Operazioni matematiche basilari

Le operazioni matematiche implementate sono le seguenti:
- Addizione
- Sottrazione
- Moltiplicazione
- Divisione

#### Addizione

```matlab
add 7 to Foobar
add Foobar to Bamboo
```

#### Sottrazione

```matlab
sub 4 to Foobar
sub Foobar to Bamboo
```

#### Moltiplicazione

```matlab
mult 10 to Foobar
mult Foobar to Bamboo
```

#### Divisione

```matlab
div 2 to Foobar
div Foobar to Bamboo
```

### If-then-else

Gli IF-THEN-ELSE sono il fulcro di questo linguaggio. Nella parte condizionale sono state sviluppate diverse combinazioni di statement con operatori logici e operatori di confronto. 

#### Operatori di confronto

- `>` / `>=`: maggiore stretto e maggiore
- `<` / `<=`: minore stretto e minore
- `==`: uguale
- `!=`: diverso

```matlab
if [condizione] then
  [...]
(else)
  [...]
end
```

> **NOTA:** L'utilizzo delle parentesi è facoltativo e con modalità identica al C++.

#### Condizione singola

- Senza parentesi

```matlab
let Flag be 1

if Flag then
  print 10
else 
  print 5
end
```

- Con le parentesi

```matlab
let Foobar be 20

if (Foobar > 20) then
  print 20
else 
  print Foobar
end
```

#### Condizioni multiple

All'interno degli IF si possono inserire le condizioni logiche più conosciute per connettere più predicati: 
- `&&`: condizionale logica **and**
- `||` : condizionale logica **or**
- `!` : condizionale logica **not**

```matlab
if (Foobar > 20 && Bamboo) then
  print 20
else 
  print Foobar
end
```

```matlab
if (Foobar > 20 || !(Bamboo)) then
  print Foobar
end
```

#### If-then-else nidificati con condizioni multiple

```matlab
let Check be 1
let Vx be 1
let Vy be 1
let Vz be 2
let Tot be 0

if ((Vx < 0 || Vy < 0 || Vz < 0) && Check) then
  print 0
else

  add Vx to Tot
  add Vy to Tot
  div Vz to Tot
  
  if (Tot >= 1) then
    print 1
  else 
    if (Tot != 0) then
        print 0
    end
  end
end
```

### While-do

Il while-do è esattamente il `while` con una sintassi identica al if-then-else nella parte condizionale.


```matlab
while [condizione] do
  [statement]
end
```

> **NOTA:** Anche in questo caso, l'utilizzo delle parentesi è facoltativo e con modalità identica al C++.
> **NOTA 2:** Si rammenta che essendo il while un ciclo, affinchè si possa uscire da esso c'è bisogno di una condizione di falsità.

