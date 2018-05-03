grammar swl;

program   : 'begin' statement+ 'end';

statement : assign | add | print | ifthenelse | whiledo;

assign     : 'let' ID 'be' (NUMBER | ID) ;
print      : 'print' (NUMBER | ID) ;
add        : 'add' (NUMBER | ID) 'to' ID ;
whiledo    : 'while' bool 'do' statement+ 'end while';
ifthenelse : 'if' bool 'then' statement+ | 'if' bool 'then' statement+ 'else' statement+ ;
bool       : condition LOGIC condition | condition LOGIC bool | bool LOGIC condition | bool LOGIC bool;
condition  : var | '(' var OPTCONF var ')' | var OPTCONF var;
var        : (NUMBER|ID) | 'not' (NUMBER|ID);

ID        : [a-zA-Z]+ ;
NUMBER    : [0-9]+ ;
OPTCONF   : [><=!];
LOGIC     : [and|or]
WS        : [ \n\t]+ -> skip;
ErrorChar : . ;


condition LOGIC condition
