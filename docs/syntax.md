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

## Funzionalità

Per comodità di scrittura, `Foobar` e `Bamboo` saranno nomi esemplificativi di due qualsiasi variabile (anche con gli stessi valori).

### Assegnazione

```
let Foobar be 15
let Bamboo be Foobar
```

### Visualizzazione

```
print 5
print Foobar
```

### Operazioni matematiche basilari

Le operazioni matematiche implementate sono le seguenti:
- Addizione
- Sottrazione
- Moltiplicazione
- Divisione

#### Addizione

```
add 7 to Foobar
add Foobar to Bamboo
```

#### Sottrazione

```
sub 4 to Foobar
sub Foobar to Bamboo
```

#### Moltiplicazione

```
mult 10 to Foobar
mult Foobar to Bamboo
```

#### Divisione

```
div 2 to Foobar
div Foobar to Bamboo
```

### IF-THEN-ELSE statement

Gli IF-THEN-ELSE sono il fulcro di questo linguaggio. Nella parte condizionale sono state sviluppate diverse combinazioni di statement con operatori logici e operatori di confronto. 

#### Operatori di confronto

- `>` / `>=`: maggiore stretto e maggiore
- `<` / `<=`: minore stretto e minore
- `==`: uguale
- `!=`: diverso


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
- `and` analogo a `&&`
- `or` analogo a `||`
- `not` analogo a `!`

```matlab
let Foobar be 24
let Bamboo be 1

if (Foobar > 20 and Bamboo) then
  print 20
else 
  print Foobar
end
```

```matlab
let Foobar be 10
let Bamboo be 0

if (Foobar > 20 or not Bamboo) then
  print Foobar
end
```

#### IF statement nidificati con condizioni multiple

```matlab
let Check be 1
let Vx be 1
let Vy be 1
let Vz be 2
let Tot be 0

if ((Vx < 0 or Vy < 0 or Vz < 0) and Check) then
  print 0
else

  add Vx to Tot
  add Vy to Tot
  div Vz to Tot
  
  if (Tot >= 1) then
    print 1
  else 
    if (Tot != 0) then
        print -1
    end
  end
end
```

